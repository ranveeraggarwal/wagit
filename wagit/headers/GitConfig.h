//
// Created by Ranveer Aggarwal on 28/08/20.
//

#include <filesystem>

#include "../includes/INIReader.h"

#ifndef WAGIT_GITCONFIG_H
#define WAGIT_GITCONFIG_H
namespace WAGit
{
    namespace FS = std::filesystem;
    using Path = FS::path;

    class GitConfig
    {
        long version;
        bool fileMode;
        bool bare;
    public:
        void InitConfig(const Path& path);
        long GetVersion() const;
        bool GetFileMode() const;
        bool IsBare() const;
    };
}

#endif //WAGIT_GITCONFIG_H
