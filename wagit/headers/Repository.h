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

    /*!
     * The main repository class to manage everything
     */
    class Repository
    {
    public:
        /*!
         * The repository constructor
         * @param path Path to the repository
         * @param force Force create repository. We'll be using this during
         * init as well
         */
        Repository(const Path& path, bool force = false);

        /*!
         * Gets the actual path to a corresponding file inside the .git directory
         * For instance, if I am looking for .git/refs/tags, I will call
         * GetRepoPath({"refs", "tags"});
         * @param pathToFile path to the file we're looking for, with each sub-path
         * a part of the vector
         * @return the path to the file
         */
        Path GetRepoPath(const std::vector<String>& pathToFile);

        /*!
         * ToDo: Find a better name for this function.
         * Same as GetRepoPath, but create directory if absent. For example,
         * GetOrCreateRepoFile({"refs", "remotes", "origin", "HEAD"}, path, true)
         * will create .git/refs/remotes/origin
         * @param filePath path to the file we're looking for, with each sub-path
         * a part of the vector
         * @param path this is where the path will be returned to
         * @param mkdir make the directory while looking for this file
         * @return success/failure
         */
        bool GetOrCreateRepoFile(const std::vector<String> &filePath, Path &path, bool mkdir = false);

        /*!
         * Same as GetRepoPath, but will create directory if mkdir.
         * @param dirPath path to the directory we're looking for, with each sub-path
         * a part of the vector
         * @param path this is where the path will be returned to
         * @param mkdir make the directory while looking for this file
         * @return success/failure
         */
        bool GetOrCreateRepoDirectory(const std::vector<String> &dirPath, Path &path, bool mkdir = false);

        Path GetWorkTree();
    private:
        /*!
        * WorkTree is the project directory where the git repository will be
        */
        Path workTree;

        /*!
         * GitDirectory is the .git folder which will store all things git
         */
        Path gitDirectory;

        /*!
         * config is the configuration file (an ini file), that will be
         * .git/config
         */
        GitConfig config;
    };
}

#endif //WAGIT_REPOSITORY_H
