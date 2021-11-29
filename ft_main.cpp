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
    sv_int5.resize(7);
    ft_cout_vector(sv_int5);
    sv_int5.assign(v1PtrA, v2PtrA);
    std::cout << "std:: [assign] sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);
    sv_int5.assign(5, 5);
    std::cout << "std:: [assign] sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);

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
    for (int i = 1; i < 10; i++) v_int6.push_back(i);
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

    std::cout << "---------ft::Element access---------\n";
    const ft::vector<int> v_int7(3, 7);
    ft::vector<int> v_int8(3, 7);
    std::cout << "ft:: [1] = " << v_int8[1] << std::endl;
    std::cout << "ft:: const[1] = " << v_int7[1] << std::endl;
    std::cout << "ft:: at[1] = " << v_int8.at(1) << std::endl;
    std::cout << "ft:: const at[1] = " << v_int7.at(1) << std::endl;
    v_int8.push_back(11);
    std::cout << "ft:: [front] = " << v_int8.front() << std::endl;
    std::cout << "ft:: [back] = " << v_int8.back() << std::endl;

    std::cout << "---------ft::Iterators---------\n";
    std::cout << "выведем от начала до конца ft::vector" << std::endl;
    for (ft::vector<int>::iterator it = v_int6.begin() ; it != v_int6.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << "выведем в обратном порядке ft::vector" << std::endl;
    for (ft::vector<int>::reverse_iterator it = v_int6.rbegin() ; it != v_int6.rend(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "выведем от начала до конца std::vector" << std::endl;
    for (std::vector<int>::iterator it = sv_int5.begin() ; it != sv_int5.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << "выведем в обратном порядке std::vector" << std::endl;
    for (std::vector<int>::reverse_iterator it = sv_int5.rbegin() ; it != sv_int5.rend(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << "---------ft::Modifiers---------\n";

    ft::vector<int> v_int9;
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);
    v_int9.push_back(10);
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);
    v_int9.push_back(11);
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);
    v_int9.clear();
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);

    v_int9.assign(v1PtrA, v2PtrA);
    std::cout << "ft:: [assign] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);
    v_int9.assign(5, 5);
    std::cout << "ft:: [assign] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);

    int sum = 0;
    while (!v_int9.empty())
    {
        sum += v_int9.back();
        v_int9.pop_back();
    }
    std::cout << "ft:: [pop_back] sum = " << sum << " sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);

    for (int i = 1; i <= 10; i++) v_int9.push_back(i);
    std::cout << "ft:: [erase][befor] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);
    ft::vector<int>::iterator it_res = v_int9.erase(v_int9.begin() + 5);
    // std::cout << "res = " << *it_res << std::endl;
    std::cout << "ft:: [erase][after] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);
    it_res = v_int9.erase (v_int9.begin(), v_int9.begin() + 3);
    // std::cout << "res = " << *it_res << std::endl;
    std::cout << "ft:: [erase][after] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);

    ft::vector<int> myvector (3, 100);
    ft::vector<int>::iterator it = myvector.begin();
    it = myvector.insert ( it , 200 );
    myvector.insert (it, 2, 300);
    it = myvector.begin();
    ft::vector<int> anothervector (2, 400);
    myvector.insert (it + 2, anothervector.begin(), anothervector.end());
    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray + 3);
    std::cout << "ft:: [insert] = ";  ft_cout_vector(myvector);

    ft::vector<int> v_int_1 (3,100);
    ft::vector<int> v_int_2 (5,333);
    std::cout << "ft:: [swap][befor][1] = "; ft_cout_vector(v_int_1);
    std::cout << "ft:: [swap][befor][2] = "; ft_cout_vector(v_int_2);
    v_int_1.swap(v_int_2);
    std::cout << "ft:: [swap][after][1] = "; ft_cout_vector(v_int_1);
    std::cout << "ft:: [swap][after][2] = "; ft_cout_vector(v_int_2);

	//-----------------------Allocator-----------------------//

    ft::vector<int> myvector1;
    int*    p;
    unsigned int i;
    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector1.get_allocator().allocate(5);
    // construct values in-place on the array:
    for (i=0; i<5; i++) myvector1.get_allocator().construct(&p[i],i);
    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';
    // destroy and deallocate:
    for (i=0; i<5; i++) myvector1.get_allocator().destroy(&p[i]);
    myvector1.get_allocator().deallocate(p,5);

	//-----------------------Relational operators-----------------------//
    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (2,200);   // two ints with a value of 200

    std::cout << "---------Relational operators---------" << std::endl;
    if (foo == bar) std::cout << "foo and bar are equal\n";
    if (foo != bar) std::cout << "foo and bar are not equal\n";
    if (foo <  bar) std::cout << "foo is less than bar\n";
    if (foo >  bar) std::cout << "foo is greater than bar\n";
    if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
    if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

    std::cout << ansi::reset;
    return 0;
}