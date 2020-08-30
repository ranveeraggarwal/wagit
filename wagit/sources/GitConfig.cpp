//
// Created by Ranveer Aggarwal on 29/08/20.
//

#include "../headers/GitConfig.h"

namespace WAGit
{
    void GitConfig::InitConfig(const Path &path)
    {
        mINI::INIFile iniFile((FS::absolute(path)).string());
        mINI::INIStructure config;
        if (iniFile.read(config))
        {
            if (config.has("core"))
            {
                if (config["core"].has("repositoryformatversion"))
                    this->version_ = std::stoi(config["core"]["repositoryformatversion"]);
                if (config["core"].has("filemode"))
                    this->fileMode_ = config["core"]["filemode"] == "true";
                if (config["core"].has("bare"))
                    this->bare_ = config["core"]["bare"] == "true";
            }
        }
    }

    long GitConfig::GetVersion() const
    {
        return this->version_;
    }

    bool GitConfig::GetFileMode() const {
        return this->fileMode_;
    }

    bool GitConfig::IsBare() const {
        return this->bare_;
    }
}
