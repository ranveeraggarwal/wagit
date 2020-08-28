//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include <filesystem>
#include <string>
#include <vector>

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

        Path GetRepoPath(const std::vector<String>& filepath);
        bool GetOrCreateRepoFile(const std::vector<String> &filePath, Path &path, bool mkdir = false);
        bool GetOrCreateRepoDirectory(const std::vector<String> &dirPath, Path &path, bool mkdir = false);

        Path GetWorkTree();
    };
}

#endif //WAGIT_REPOSITORY_H
