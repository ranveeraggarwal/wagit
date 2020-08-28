//
// Created by Ranveer Aggarwal on 28/08/20.
//

#include <exception>
#include <string>
#include <utility>

#ifndef WAGIT_GITEXCEPTIONS_H
#define WAGIT_GITEXCEPTIONS_H

namespace WAGit
{
    namespace Exceptions
    {
        struct NotAGitRepositoryException : public std::exception {
            std::string exceptionMessage;

            explicit NotAGitRepositoryException(const std::string& path)
                    : exceptionMessage("Not a Git repository " + path)
            {}

            [[nodiscard]] const char * what () const noexcept override {
                return this->exceptionMessage.c_str();
            }
        };

    }
}

#endif //WAGIT_GITEXCEPTIONS_H
