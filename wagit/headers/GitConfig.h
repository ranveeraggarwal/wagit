//
// Created by Ranveer Aggarwal on 28/08/20.
//

#ifndef WAGIT_GITCONFIG_H
#define WAGIT_GITCONFIG_H
namespace WAGit
{
    namespace FS = std::filesystem;
    using Path = FS::path;

    class GitConfig
    {
        int version;
    public:
        void InitConfig(const Path& path)
        {
            this->version = 0;
        }

        int GetVersion()
        {
            return this->version;
        }
    };
}

#endif //WAGIT_GITCONFIG_H
