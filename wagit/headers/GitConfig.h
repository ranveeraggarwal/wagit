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
    public:
        /*!
         * Initializes the configuration based on ini file
         * @param path the path to the ini file
         */
        void InitConfig(const Path &path);

        long GetVersion() const;
        bool GetFileMode() const;
        bool IsBare() const;

    private:
        long version_ = 0;
        bool fileMode_ = false;
        bool bare_ = false;
    };
}

#endif //WAGIT_GITCONFIG_H
