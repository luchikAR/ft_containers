#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "vector.hpp"

int main()
{
    std::vector<int> sv_int1;
    std::vector<int> sv_int2(4);
    std::vector<int> sv_int3(4, 5);

    std::vector <int> v1;
    std::vector <int>::iterator v1Iter;
    std::vector <int>:: allocator_type v1Alloc;
    for (int i = 1 ; i <= 7 ; i++ ) { v1.push_back( 3 * i ); }
    std::allocator<int>::pointer v1PtrA = v1Alloc.address( *find( v1.begin( ), v1.end( ), 6 ) );
    std::allocator<int>::pointer v2PtrA = v1Alloc.address( *find( v1.begin( ), v1.end( ), 15 ) );
    std::vector<int> sv_int4(v1PtrA, v2PtrA);

    std::cout << ansi::foreground_green; /* тест std::vector */
    std::cout << "-----me main-----\n";

    // std::cout << "std:: v: " << sv_int1[0] << std::endl; // seg fault
    std::cout << "std:: v(4): " << sv_int2[0] << std::endl;
    std::cout << "std:: v(4,5): size = " << sv_int3.size() << " [0] = " << sv_int3[0] << std::endl;
    std::cout << "std:: v(Prt,Ptr): size = " << sv_int4.size() << " [0] = " << sv_int4[0] << std::endl;

    std::cout << ansi::reset; // для теста моих выводов внутри vector

    ft::vector<int> v_int1;
    ft::vector<int> v_int2(4);
    ft::vector<int> v_int3(4, 5);
    ft::vector<int> v_int4(v1PtrA, v2PtrA);

    std::cout << ansi::foreground_cyan; /* тест ft::vector */
    // try {
    // std::cout << "ft:: v: " << v_int1[0] << std::endl;
    // }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    std::cout << "ft:: v(4): " << v_int2[0] << std::endl;
    std::cout << "ft:: v(4,5): size = " << v_int3.size() << " [0] = " << v_int3[0] << std::endl;
    std::cout << "std:: v(Prt,Ptr): size = " << v_int4.size() << " [0] = " << v_int4[0] << std::endl;

    std::cout << ansi::reset;
    
    return 0;
}