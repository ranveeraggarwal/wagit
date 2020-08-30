//
// Created by Ranveer Aggarwal on 30/08/20.
//

#include <filesystem>

#include "Repository.h"

#ifndef WAGIT_UTILS_H
#define WAGIT_UTILS_H

namespace WAGit
{
    namespace FS = std::filesystem;

    using Path = FS::path;

    /*!
     * Some common utility functions
     */
    class Utils
    {
        /*!
         * Recursively finds the repository the current folder is a port of.
         * @param path path of the current folder where this is run
         * @param repository the repository object to be returned
         * @return true if there is a repository somewhere in the parent
         * chain leading up to /, false otherwise
         */
        bool FindRepository(const Path &path, Repository &repository)
        {
            if (FS::exists(FS::absolute(path / ".git")))
            {
                repository = Repository(path);
                return true;
            }

            Path parent = path.parent_path();

            // This will only happen in case the current path is /
            if (parent == path)
                return false;

            return FindRepository(parent, repository);
        }
    };
}

#endif //WAGIT_UTILS_H
