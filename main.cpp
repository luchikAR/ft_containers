#include <iostream>
#include <vector> 
#include "vector.hpp"

int main()
{
    {
        // std::cout << "-----test-----" << std::endl;
        std::vector<int> sv_int1;
        std::vector<int> sv_int2(4, 5);

        std::cout << ansi::foreground_green;
        std::cout << "-----me main-----\n";
        std::cout << "std v(4,5): " << sv_int2[0] << std::endl;
        std::cout << ansi::foreground_cyan;
        try
        {
            ft::vector<int> v_int1;
        }
        catch(const std::exception& e)
        {
            std::cerr << "test 1: v_int1\n";
            std::cerr << e.what() << '\n';
        }
        try
        {
            ft::vector<int> v_int2(4, 5);
            // std::cout << "ft v(4,5): " << v_int2[0] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "test 2: v_int2(4, 5)\n";
            std::cerr << e.what() << '\n';
        }
        std::cout << ansi::reset;
    }
    return 0;
}