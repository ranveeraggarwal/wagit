#include <iostream>
#include <string>
#include "argh.h"

/*
 * Temporary function to return a string for unimplemented commands.
 */
std::string CommandNotImplementedWarning(const std::string& command)
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
        std::cout << CommandNotImplementedWarning(command) << std::endl;
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