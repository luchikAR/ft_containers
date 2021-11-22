#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "vector.hpp"

void ft_cout_vector(std::vector<int> x)
{
    std::cout << "{ ";
    for (size_t i = 0; i < x.size(); i++)
    {
        if (i + 1 < x.size() )
            std::cout << x[i] << ",";
        else
             std::cout << x[i];
    }
    std::cout << " }" << std::endl;
}

void ft_cout_vector(ft::vector<int> x)
{
    std::cout << "{ ";
    for (size_t i = 0; i < x.size(); i++)
    {
        if (i + 1 < x.size() )
            std::cout << x[i] << ",";
        else
             std::cout << x[i];
    }
    std::cout << " }" << std::endl;
}

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

    std::cout << "-------std::constructor-------\n";
    // std::cout << "std:: v: " << sv_int1[0] << std::endl; // seg fault
    std::cout << "std:: v(4): " << sv_int2[0] << std::endl;
    std::cout << "std:: v(4,5): size = " << sv_int3.size() << " "; ft_cout_vector(sv_int3);
    std::cout << "std:: v(Prt,Ptr): size = " << sv_int4.size() << " "; ft_cout_vector(sv_int4);
    std::cout << "---------ft::Capacity---------\n";
    std::cout << "std:: v(): [max_size] = " << sv_int1.max_size() << std::endl;
    
    std::vector<int> sv_int5;
    for (int i=1; i<10; i++) sv_int5.push_back(i);
    sv_int5.resize(5);
    sv_int5.resize(8,100);
    sv_int5.resize(12);
    std::cout << "std:: [resize] sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);

    // std::cout << ansi::reset;
    std::cout << ansi::foreground_yellow; /* тест ft::vector */

    ft::vector<int> v_int1;
    ft::vector<int> v_int2(4);
    ft::vector<int> v_int3(4, 5);
    ft::vector<int> v_int4(v1PtrA, v2PtrA);
    ft::vector<int> v_int5 = v_int3;

    std::cout << "---------ft::Constructor---------\n";
    // try {
    // std::cout << "ft:: v: " << v_int1[0] << std::endl;
    // }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    std::cout << "ft:: v(4): " << v_int2[0] << std::endl;
    std::cout << "ft:: v(4,5): size = " << v_int3.size() << " "; ft_cout_vector(v_int3);
    std::cout << "ft:: v()=v(): size = " << v_int5.size() << " "; ft_cout_vector(v_int5);
    std::cout << "ft:: v(Prt,Ptr): size = " << v_int4.size() << " "; ft_cout_vector(v_int4);

    std::cout << "---------ft::Capacity---------\n";
    std::cout << "ft:: v(): [max_size] = " << v_int1.max_size() << std::endl;

    ft::vector<int> v_int6;
    for (int i=1; i<10; i++) v_int6.push_back(i);
    v_int6.resize(5);
    v_int6.resize(8,100);
    v_int6.resize(12);

    std::cout << "ft:: [resize] \nsz = " << v_int6.size() << " "; ft_cout_vector(v_int6);
    v_int6.resize(7);
    std::cout << "sz = " << v_int6.size() << " "; ft_cout_vector(v_int6);
    std::cout << std::endl;

    std::cout << "ft:: [empty] = " << v_int6.empty() << std::endl;
    std::cout << "ft:: [reserve] cap before = " << v_int6.capacity() << std::endl;
    v_int6.reserve(40);
    std::cout << "cap after(grow) = " << v_int6.capacity() << " "; ft_cout_vector(v_int6);
    v_int6.reserve(20);
    std::cout << "cap after(low) = " << v_int6.capacity() << " "; ft_cout_vector(v_int6);
    std::cout << std::endl;

    std::cout << v_int6.back() << "\n";

    std::cout << ansi::reset;
    
    return 0;
}