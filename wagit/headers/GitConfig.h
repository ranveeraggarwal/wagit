//
// Created by Ranveer Aggarwal on 28/08/20.
//

#include <filesystem>

#define MINI_CASE_SENSITIVE
#include "../includes/ini.h"

#ifndef WAGIT_GITCONFIG_H
#define WAGIT_GITCONFIG_H
namespace WAGit
{
    namespace FS = std::filesystem;

    using Path = FS::path;

    /*!
     * The repository's config
     */
    class GitConfig
    {
        long version = 0;
        bool fileMode = false;
        bool bare = false;

    public:
        /*!
         * Initializes the configuration based on ini file
         * @param path the path to the ini file
         */
        void InitConfig(const Path& path);

        long GetVersion() const;
        bool GetFileMode() const;
        bool IsBare() const;
    };
}

#endif //WAGIT_GITCONFIG_H
