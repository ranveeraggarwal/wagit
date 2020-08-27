//
// Created by Ranveer Aggarwal on 27/08/20.
//

#include "FileSystem.h"
#include <string>

#ifndef WAGIT_REPOSITORY_H
#define WAGIT_REPOSITORY_H


class Repository
{
    FileSystem workTree;
    FileSystem gitDirectory;
    int config;  // ToDO: Make a legit config object

    Repository(std::string path)
    {

    }
};


#endif //WAGIT_REPOSITORY_H
