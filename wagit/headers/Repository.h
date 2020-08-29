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
        /*
         * - WorkTree is the project directory where the git repository will be.
         * - GitDirectory is the .git folder which will store all things git.
         * - config is the configuration file (an ini file), that will be
         * .git/config.
         */
        Path workTree;
        Path gitDirectory;
        GitConfig config;

    public:
        Repository(const Path& path, bool force = false);

        /*
         * Get's the actual path to a corresponding file inside the .git directory
         * For instance, if I am looking for .git/refs/tags, I will call
         * GetRepoPath({"refs", "tags"});
         */
        Path GetRepoPath(const std::vector<String>& pathToFile);

        /*
         * ToDo: Find a better name for this function.
         * Same as GetRepoPath, but create directory if absent. For example,
         * GetOrCreateRepoFile({"refs", "remotes", "origin", "HEAD"}, path, true)
         * will create .git/refs/remotes/origin.
         */
        bool GetOrCreateRepoFile(const std::vector<String> &filePath, Path &path, bool mkdir = false);

        /*
         * Same as GetRepoPath, but will create directory if mkdir.
         */
        bool GetOrCreateRepoDirectory(const std::vector<String> &dirPath, Path &path, bool mkdir = false);

        Path GetWorkTree();
    };
}

#endif //WAGIT_REPOSITORY_H
