#include "Application.hpp"
#include <exception>
#include <iostream>

int main(int argc, char const* argv[])
{
    try {
        Application app;
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
