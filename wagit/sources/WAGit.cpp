//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include "../headers/WAGit.h"

namespace WAGit
{
    Repository CreateRepository(const Path &path)
    {
        Repository repository(path, true);

        // let's first get the worktree
        if (FS::exists(repository.GetWorkTree()))
        {
            if (!FS::is_directory(repository.GetWorkTree()))
                throw Exceptions::PathException("The specified path is not a directory",
                                                repository.GetWorkTree());
            if (!FS::is_empty(repository.GetWorkTree()))
                throw Exceptions::PathException("The specified directory is not empty.",
                                                repository.GetWorkTree());
        }
        else
        {
            FS::create_directories(repository.GetWorkTree());
        }

        // now we create the required directories
        Path branchesPath, objectsPath, tagsPath, headsPath;
        repository.GetOrCreateRepoDirectory({"branches"}, branchesPath, true);
        repository.GetOrCreateRepoDirectory({"objects"}, objectsPath, true);
        repository.GetOrCreateRepoDirectory({"refs", "tags"}, tagsPath, true);
        repository.GetOrCreateRepoDirectory({"refs", "heads"}, headsPath, true);

        // and the required paths
        Path descriptionFilePath, headFilePath, configFilePath;
        std::ofstream ofStream;

        // .git/description file
        repository.GetOrCreateRepoFile({"description"}, descriptionFilePath);
        ofStream.open(descriptionFilePath);
        ofStream << "Unnamed repository; edit this file 'description' to name the repository.\n";
        ofStream.close();
        ofStream.clear();

        // .git/HEAD
        repository.GetOrCreateRepoFile({"HEAD"}, headFilePath);
        ofStream.open(headFilePath);
        ofStream << "ref: refs/heads/master\n";
        ofStream.close();
        ofStream.clear();

        // build a basic config file
        repository.GetOrCreateRepoFile({"config"}, configFilePath);
        mINI::INIFile iniFile(FS::absolute(configFilePath));
        mINI::INIStructure config;
        config["core"]["repositoryformatversion"] = "0";
        config["core"]["filemode"] = "false";
        config["core"]["bare"] = "false";
        iniFile.write(config, true);

        return repository;
    }
}