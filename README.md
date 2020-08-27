WAGit
===

Yet another implementation of Git.

# Installation
## Dependencies
I couldn't find a decent dependency manager for C++, so this needs to be manual for now. Might write a Python script later.    

### Argh - For parsing command line arguments
In the root directory, first clone the submodule by doing

    git submodule update --init
    
Then, you'll need to install argh via cmake. To do so, change to the submodule directory and run cmake
    
    cd argh
    cmake .
    
Followed by

    make install

Remember to clean up the submodule directory after you're done, by running

    git clean -d -f

And move back to the root directory. You'll only have to do this once.
