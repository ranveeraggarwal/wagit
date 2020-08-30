//
// Created by Ranveer Aggarwal on 28/08/20.
//

#include <exception>
#include <filesystem>
#include <string>
#include <utility>

#ifndef WAGIT_GITEXCEPTIONS_H
#define WAGIT_GITEXCEPTIONS_H

namespace WAGit::Exceptions
{
    namespace FS = std::filesystem;

    using Exception = std::exception;
    using Path = FS::path;
    using String = std::string;

    /*!
     * Used for anything file/directory related
     */
    struct PathException : public Exception {
        String exceptionMessage;

        explicit PathException(String message, const Path &path)
                : exceptionMessage(std::move(message) + " " + path.u8string())
        {}

        [[nodiscard]] const char * what () const noexcept override
        {
            return this->exceptionMessage.c_str();
        }
    };

    struct GeneralException : public Exception {
        String exceptionMessage;

        explicit GeneralException(String message)
                : exceptionMessage(std::move(message))
        {}

        [[nodiscard]] const char * what () const noexcept override
        {
            return this->exceptionMessage.c_str();
        }
    };

}

#endif //WAGIT_GITEXCEPTIONS_H
