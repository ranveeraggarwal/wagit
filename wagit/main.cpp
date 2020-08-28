#include <filesystem>
#include <iostream>
#include <string>

#include "argh.h"
#include "headers/WAGit.h"

namespace FS = std::filesystem;
using String = std::string;
using Path = FS::path;

/*
 * Temporary function to return a string for unimplemented commands.
 */
std::string CommandNotImplementedWarning(const String& command)
{
    return "git " + command + " : Implementation Pending";
}

int main(int, char* argv[]) {
    argh::parser cmdl(argv);
    std::string command = cmdl[1];

    if (command.empty())
    {
        std::cout << "No command supplied" << std::endl;
    }
    else if (command == "add")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "cat-file")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "checkout")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "commit")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "hash-object")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "init")
    {
        Path repoPath(cmdl[2]);
        WAGit::CreateRepository(repoPath);
    }
    else if (command == "log")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "ls-tree")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "merge")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "rebase")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "rev-parse")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "rm")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "show-ref")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else if (command == "tag")
    {
        std::cout << CommandNotImplementedWarning(command) << std::endl;
    }
    else
    {
        std::cout << "Command Unsupported\n";
    }

    return 0;
}