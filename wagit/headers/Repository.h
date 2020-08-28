//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include <filesystem>
#include <string>

#include "GitConfig.h"
#include "GitExceptions.h"

#ifndef WAGIT_REPOSITORY_H
#define WAGIT_REPOSITORY_H

namespace WAGit
{
    namespace FS = std::filesystem;
    using Path = FS::path;
    using String = std::string;

    class Repository
    {
        Path workTree;
        Path gitDirectory;
        GitConfig config;

    public:
        Repository(const Path& path, bool force = false);
        Path GetRepoFile(const String& filename);
    };
}

#endif //WAGIT_REPOSITORY_H
