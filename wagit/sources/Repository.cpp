//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include "../headers/Repository.h"

namespace WAGit
{
    Repository::Repository(const Path &path, bool force)
    {
        this->workTree_ = path;
        this->gitDirectory_ = path / ".git";

        if (!(force || FS::is_directory(this->gitDirectory_)))
            throw Exceptions::PathException("Not a Git repository", this->gitDirectory_);

        Path configFile = GetRepoPath({"config"});
        if (!force && !FS::exists(configFile))
            throw Exceptions::GeneralException("Configuration file missing");

        this->config_.InitConfig(configFile);

        if (!force && this->config_.GetVersion() != 0)
            throw Exceptions::GeneralException("Repository Version Not Supported");
    }

    Path Repository::GetRepoPath(const std::vector<String> &pathToFile)
    {
        Path path(this->gitDirectory_);
        for (const auto& subPath: pathToFile)
        {
             path /= subPath;
        }

        return path;
    }

    bool Repository::GetOrCreateRepoFile(const std::vector<String> &filePath, Path &path, bool mkdir) {
        std::vector<String> dirPath = filePath;
        dirPath.pop_back();
        if (GetOrCreateRepoDirectory(dirPath, path, mkdir))
        {
            path = GetRepoPath(filePath);
            return true;
        }
        return false;
    }

    bool Repository::GetOrCreateRepoDirectory(const std::vector<String> &dirPath, Path &path, bool mkdir) {
        path = GetRepoPath(dirPath);

        if (FS::exists(path))
        {
            if (FS::is_directory(path))
                return true;
            else
                throw Exceptions::PathException("Not a directory", path);
        }

        if (mkdir)
        {
            FS::create_directories(path);
            return true;
        }
        return false;
    }

    Path Repository::GetWorkTree() {
        return this->workTree_;
    }
}