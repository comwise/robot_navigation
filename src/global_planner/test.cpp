#include <cstdint>
#include <string>
#include <iostream>
#include <exception>

int main()
{
    int quit_code = 0;
    bool is_exit_ok = false;

    try {

    } catch (const std::exception &e) {
        std::cout << "global planner run exception, " << e.what();
        quit_code = -2;
        is_exit_ok = true;
    }
    return quit_code;
}
