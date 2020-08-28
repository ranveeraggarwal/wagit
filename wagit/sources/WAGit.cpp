//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include "../headers/WAGit.h"

namespace WAGit
{
    Repository CreateRepository(const Path& path)
    {
        Repository repository(path, true);

        if (FS::exists(repository.GetWorkTree()))
        {
            if (!FS::is_directory(repository.GetWorkTree()))
                throw Exceptions::GeneralException("The specified path is not a directory");
            if (!FS::is_empty(repository.GetWorkTree()))
                throw Exceptions::GeneralException("The specified directory is not empty.");
        }
        else
        {
            FS::create_directories(repository.GetWorkTree());
        }

        Path branchesPath, objectsPath, tagsPath, headsPath;
        repository.GetOrCreateRepoDirectory({"branches"}, branchesPath, true);
        repository.GetOrCreateRepoDirectory({"objects"}, objectsPath, true);
        repository.GetOrCreateRepoDirectory({"refs", "tags"}, tagsPath, true);
        repository.GetOrCreateRepoDirectory({"refs", "heads"}, headsPath, true);

        return repository;
    }
}