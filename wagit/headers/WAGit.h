//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include <iostream>

#include "Repository.h"

#include "../includes/ini.h"

#ifndef WAGIT_WAGIT_H
#define WAGIT_WAGIT_H

namespace WAGit
{
    /*!
     * Create repository functionality. This is the function that will be
     * called by git init
     * @param path the path to the repository
     */
    Repository CreateRepository(const Path& path);
}

#endif //WAGIT_WAGIT_H
