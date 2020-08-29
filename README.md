WAGit
===

Yet another implementation of Git.

# Installation
## Dependencies
I couldn't find a decent dependency manager for C++, so this needs to be manual for now. Might write a Python script later.    

### Installing Dependencies
#### Argh
In the root directory, first clone the submodule by doing

    git submodule update --init
    
Then, you'll need to install argh via cmake. To do so, change to the submodule directory and run cmake
    
    cd dependencies/argh
    cmake .
    
Followed by

    make install

Remember to clean up the submodule directory after you're done, by running

    git clean -d -f

And move back to the root directory. You'll only have to do this once.

#### Inih
I have added the header for this in the project itself - no installation needed.

# Reading Material
Some amazing reading material we found while building this:

* C++ 17+ filesystem API: https://carlosvin.github.io/posts/recursive-directory-iterator/en/