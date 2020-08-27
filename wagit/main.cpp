#include <iostream>
#include "argh.h"

int main(int, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;

    argh::parser cmdl(argv);

    if (cmdl[{ "-v", "--verbose" }])
        std::cout << "Hello, verbosity!\n";

    return 0;
}
