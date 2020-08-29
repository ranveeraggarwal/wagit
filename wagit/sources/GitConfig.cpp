//
// Created by Ranveer Aggarwal on 29/08/20.
//

#include "../headers/GitConfig.h"

namespace WAGit
{
    void GitConfig::InitConfig(const Path &path)
    {
        INIReader configReader((FS::absolute(path)).u8string());
        this->version = configReader.GetInteger("core", "repositoryformatversion", 0);
        this->fileMode = configReader.GetBoolean("core", "filemode", false);
        this->bare = configReader.GetBoolean("core", "bare", false);
    }

    long GitConfig::GetVersion() const
    {
        return this->version;
    }

    bool GitConfig::GetFileMode() const {
        return this->fileMode;
    }

    bool GitConfig::IsBare() const {
        return this->bare;
    }
}
