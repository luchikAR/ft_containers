#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "include/vector.hpp"

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

    std::cout << ansi::reset;
}