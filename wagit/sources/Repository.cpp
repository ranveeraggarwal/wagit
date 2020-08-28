//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include "../headers/Repository.h"

namespace WAGit
{
    Repository::Repository(const Path &path, bool force)
    {
        this->workTree = path;
        this->gitDirectory = path / "/.git";

        if (!(force || FS::is_directory(this->gitDirectory)))
            throw Exceptions::NotAGitRepositoryException(this->gitDirectory.u8string());

        Path configFile = GetRepoPath("config");
        if (!force && !FS::exists(configFile))
            throw Exceptions::GeneralException("Configuration file missing");

        this->config.InitConfig(configFile);

        if (!force && this->config.GetVersion() != 0)
            throw Exceptions::GeneralException("Repository Version Not Supported");
    }

    Path Repository::GetRepoPath(const String &filename)
    {
        Path path(this->gitDirectory);
        path /= "/";
        path /= filename;

        return path;
    }
}