#include <iostream>
#include <memory>
#include <algorithm>

#include <vector>
#include <stack>
#include <map>
#include <deque>

#include "include/vector.hpp"
#include "include/stack.hpp"
#include "include/map.hpp"
#include "include/pair.hpp"
#include "include/RBTree.hpp"

#define GREEN std::cout<<ansi::foreground_green;
#define YELLOW std::cout << ansi::foreground_yellow;
#define BlUE std::cout << ansi::foreground_blue;

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

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

void ft_cout_map(std::map<char,int> x)
{
    for (std::map<char,int>::iterator it = x.begin(); it != x.end(); it++)
        std::cout << "  [key]= " << it->first << " [value]= " << it->second << std::endl; 
}

void ft_cout_map(ft::map<char,int> x)
{
    for (ft::map<char,int>::iterator it = x.begin(); it != x.end(); it++)
        std::cout << "  [key]= " << it->first << " [value]= " << it->second << std::endl; 
}

int main()
{
    BlUE
    std::cout << "###### Vector ######\n";

    /*
    {
    std::cout << "-------Constructor-------\n";
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

    ft::vector<int> v_int1;
    ft::vector<int> v_int2(4);
    ft::vector<int> v_int3(4, 5);
    ft::vector<int> v_int4(v1PtrA, v2PtrA);
    ft::vector<int> v_int5 = v_int4;

    GREEN    
    std::cout << "std:: v(4): " << sv_int2[0] << std::endl;
    std::cout << "std:: v(4,5): size = " << sv_int3.size() << " "; ft_cout_vector(sv_int3);
    std::cout << "std:: v(Prt,Ptr): size = " << sv_int4.size() << " "; ft_cout_vector(sv_int4);
    YELLOW
    std::cout << "ft:: v(4): " << v_int2[0] << std::endl;
    std::cout << "ft:: v(4,5): size = " << v_int3.size() << " "; ft_cout_vector(v_int3);
    std::cout << "ft:: v(Prt,Ptr): size = " << v_int4.size() << " "; ft_cout_vector(v_int4);
    std::cout << "ft:: v()=v(): size = " << v_int5.size() << " "; ft_cout_vector(v_int5);

    std::cout << "---------Capacity---------\n";

    GREEN
    std::cout << "std:: [max_size][sv_int1] = " << sv_int1.max_size() << std::endl;
    std::vector<int> sv_int5;
    for (int i=1; i<10; i++) sv_int5.push_back(i);
    sv_int5.resize(5);
    sv_int5.resize(8,100);
    sv_int5.resize(12);
    std::cout << "std:: [resize] \nsz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);
    sv_int5.resize(7); 
    std::cout << "sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);
    
    std::cout << "std:: [empty] = " << sv_int5.empty() << std::endl;
    std::cout << "std:: [reserve] cap before = " << sv_int5.capacity() << std::endl;
    sv_int5.reserve(40);
    std::cout << "\tcap after(grow) = " << sv_int5.capacity() << " "; ft_cout_vector(sv_int5);
    sv_int5.reserve(20);
    std::cout << "\tcap after(low) = " << sv_int5.capacity() << " "; ft_cout_vector(sv_int5);
    std::cout << std::endl;

    YELLOW
    std::cout << "ft:: [max_size][v_int1] = " << v_int1.max_size() << std::endl;
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
    std::cout << "\tcap after(grow) = " << v_int6.capacity() << " "; ft_cout_vector(v_int6);
    v_int6.reserve(20);
    std::cout << "\tcap after(low) = " << v_int6.capacity() << " "; ft_cout_vector(v_int6);
    std::cout << std::endl;

    std::cout << "---------Element access---------\n";

    GREEN

    const ft::vector<int> sv_int6(3, 7);
    ft::vector<int> sv_int7(3, 7);
    std::cout << "ft:: [1] = " << sv_int7[1] << std::endl;
    std::cout << "ft:: const[1] = " << sv_int6[1] << std::endl;
    std::cout << "ft:: at[1] = " << sv_int7.at(1) << std::endl;
    std::cout << "ft:: const at[1] = " << sv_int6.at(1) << std::endl;
    std::cout << "[push back] int[11]" << std::endl;
    sv_int7.push_back(11);
    std::cout << "ft:: [front] = " << sv_int7.front() << std::endl;
    std::cout << "ft:: [back] = " << sv_int7.back() << std::endl;

    YELLOW
    const ft::vector<int> v_int7(3, 7);
    ft::vector<int> v_int8(3, 7);
    std::cout << "ft:: [1] = " << v_int8[1] << std::endl;
    std::cout << "ft:: const[1] = " << v_int7[1] << std::endl;
    std::cout << "ft:: at[1] = " << v_int8.at(1) << std::endl;
    std::cout << "ft:: const at[1] = " << v_int7.at(1) << std::endl;
    std::cout << "[push back] int[11]" << std::endl;
    v_int8.push_back(11);
    std::cout << "ft:: [front] = " << v_int8.front() << std::endl;
    std::cout << "ft:: [back] = " << v_int8.back() << std::endl;

    std::cout << "---------Iterators---------\n";
    GREEN
    std::cout << "выведем от начала до конца std::vector" << std::endl;
    for (std::vector<int>::iterator it = sv_int5.begin() ; it != sv_int5.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << "выведем в обратном порядке std::vector" << std::endl;
    for (std::vector<int>::reverse_iterator it = sv_int5.rbegin() ; it != sv_int5.rend(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    YELLOW
    std::cout << "выведем от начала до конца ft::vector" << std::endl;
    for (ft::vector<int>::iterator it = v_int6.begin() ; it != v_int6.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << "выведем в обратном порядке ft::vector" << std::endl;
    for (ft::vector<int>::reverse_iterator it = v_int6.rbegin() ; it != v_int6.rend(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "---------ft::Modifiers---------\n";

    GREEN
    std::vector<int> sv_int9;
    std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " "; ft_cout_vector(sv_int9);
    sv_int9.push_back(10);
    std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " "; ft_cout_vector(sv_int9);
    sv_int9.push_back(11);
    std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " "; ft_cout_vector(sv_int9);
    sv_int9.clear();
    std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " "; ft_cout_vector(sv_int9);

    YELLOW
    ft::vector<int> v_int9;
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);
    v_int9.push_back(10);
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);
    v_int9.push_back(11);
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);
    v_int9.clear();
    std::cout << "ft:: v_9: size = " << v_int9.size() << " cap = " << v_int9.capacity() << " "; ft_cout_vector(v_int9);

    GREEN
    sv_int5.assign(v1PtrA, v2PtrA);
    std::cout << "std:: [assign] sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);
    sv_int5.assign(5, 5);
    std::cout << "std:: [assign] sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);
    
    YELLOW
    v_int9.assign(v1PtrA, v2PtrA);
    std::cout << "ft:: [assign] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);
    v_int9.assign(5, 5);
    std::cout << "ft:: [assign] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);

    GREEN
    int std_sum = 0;
    while (!sv_int5.empty()) {
        std_sum += sv_int5.back();
        sv_int5.pop_back();
    }
    std::cout << "std:: [pop_back] sum = " << std_sum << " sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);

    YELLOW
    int sum = 0;
    while (!v_int9.empty()) {
        sum += v_int9.back();
        v_int9.pop_back();
    }
    std::cout << "ft:: [pop_back] sum = " << sum << " sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);

    GREEN
    for (int i = 1; i <= 10; i++) sv_int5.push_back(i);
    std::cout << "std:: [erase][befor] sz = " << sv_int5.size() << " "; ft_cout_vector(sv_int5);
    std::vector<int>::iterator it_std_res = sv_int5.erase(sv_int5.begin() + 5);
    std::cout << "std:: [erase][after] sz = " << sv_int5.size() << " res = " << *it_std_res << " "; ft_cout_vector(sv_int5);
    it_std_res = sv_int5.erase (sv_int5.begin(), sv_int5.begin() + 3);
    std::cout << "std:: [erase][after] sz = " << sv_int5.size() << " res = " << *it_std_res << " "; ft_cout_vector(sv_int5);

    YELLOW
    for (int i = 1; i <= 10; i++) v_int9.push_back(i);
    std::cout << "ft:: [erase][befor] sz = " << v_int9.size() << " "; ft_cout_vector(v_int9);
    ft::vector<int>::iterator it_res = v_int9.erase(v_int9.begin() + 5);
    std::cout << "ft:: [erase][after] sz = " << v_int9.size() << " res = " << *it_res << " "; ft_cout_vector(v_int9);
    it_res = v_int9.erase (v_int9.begin(), v_int9.begin() + 3);
    std::cout << "ft:: [erase][after] sz = " << v_int9.size() << " res = " << *it_res << " "; ft_cout_vector(v_int9);

    GREEN
    {
        std::vector<int> myvector_std (3, 100);
        std::vector<int>::iterator it_std = myvector_std.begin();
        it_std = myvector_std.insert ( it_std , 200 );
        myvector_std.insert (it_std, 2, 300);
        it_std = myvector_std.begin();
        std::vector<int> anothervector_str (2, 400);
        myvector_std.insert (it_std + 2, anothervector_str.begin(), anothervector_str.end());
        int myarray [] = { 501,502,503 };
        myvector_std.insert (myvector_std.begin(), myarray, myarray + 3);
        std::cout << "std:: [insert] = ";  ft_cout_vector(myvector_std);
    }
    YELLOW
    {
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
    }

    std::cout << "---------Allocator---------\n";
    GREEN
    {
        std::vector<int> myvector1_std;
        int*    p;
        unsigned int i;
        // allocate an array with space for 5 elements using vector's allocator:
        p = myvector1_std.get_allocator().allocate(5);
        // construct values in-place on the array:
        for (i=0; i<5; i++) myvector1_std.get_allocator().construct(&p[i],i);
        std::cout << "The allocated array contains:";
        for (i=0; i<5; i++) std::cout << ' ' << p[i];
        std::cout << '\n';
        // destroy and deallocate:
        for (i=0; i<5; i++) myvector1_std.get_allocator().destroy(&p[i]);
        myvector1_std.get_allocator().deallocate(p,5);
    }
    YELLOW
    {
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
    }

    std::cout << "---------Relational operators---------" << std::endl;
    GREEN
    {
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (2,200);   // two ints with a value of 200

        if (foo == bar) std::cout << "foo and bar are equal\n";
        if (foo != bar) std::cout << "foo and bar are not equal\n";
        if (foo <  bar) std::cout << "foo is less than bar\n";
        if (foo >  bar) std::cout << "foo is greater than bar\n";
        if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
    }
    YELLOW
    {
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (2,200);   // two ints with a value of 200

        if (foo == bar) std::cout << "foo and bar are equal\n";
        if (foo != bar) std::cout << "foo and bar are not equal\n";
        if (foo <  bar) std::cout << "foo is less than bar\n";
        if (foo >  bar) std::cout << "foo is greater than bar\n";
        if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
    }
    }
    */
    
    BlUE
    std::cout << "###### Stack ######\n";
    /*
    {
        std::cout << "-------Constructor-------\n";
        std::deque<int> mydeque (3,100);          // deque with 3 elements
        std::vector<int> myvector (2,200);        // vector with 2 elements
        std::stack<int> first;                    // empty stack
        std::stack<int,std::deque<int> > second (mydeque);         // stack initialized to copy of deque
        std::stack<int,std::vector<int> > third;  // empty stack using vector
        std::stack<int,std::vector<int> > fourth (myvector);
        GREEN
        std::cout << "std:: size of first: " << first.size() << '\n';
        std::cout << "std:: size of second: " << second.size() << '\n';
        std::cout << "std:: size of third: " << third.size() << '\n';
        std::cout << "std:: size of fourth: " << fourth.size() << '\n';

        std::deque<int> mydeque_ft (3,100);          // deque with 3 elements
        ft::vector<int> myvector_ft (2,200);        // vector with 2 elements
        ft::stack<int> first_ft;                    // empty stack
        ft::stack<int, std::deque<int> > second_ft (mydeque);         // stack initialized to copy of deque
        ft::stack<int, ft::vector<int> > third_ft;  // empty stack using vector
        ft::stack<int, ft::vector<int> > fourth_ft (myvector_ft);
        YELLOW
        std::cout << "ft:: size of first: " << first_ft.size() << '\n';
        std::cout << "ft:: size of second: " << second_ft.size() << '\n';
        std::cout << "ft:: size of third: " << third_ft.size() << '\n';
        std::cout << "ft:: size of fourth: " << fourth_ft.size() << '\n';

        std::cout << "-------Member functions-------\n";
        GREEN
        {
            std::stack<int> mystack;
            int sum (0);
            for (int i=1;i<=10;i++) mystack.push(i);
            while (!mystack.empty()) {
                sum += mystack.top();
                mystack.pop();
            }
            std::cout << "std:: total sum: " << sum << '\n';
        }
        YELLOW
        {
            ft::stack<int> mystack;
            int sum (0);
            for (int i=1;i<=10;i++) mystack.push(i);
            while (!mystack.empty()) {
                sum += mystack.top();
                mystack.pop();
            }
            std::cout << "ft:: total sum: " << sum << '\n';
        }
        std::vector<int> mystack1;
        for (int i=1;i<=10;i++) mystack1.push_back(i);
        std::vector<int> mystack2;
        for (int i=1;i<=5;i++) mystack2.push_back(i);
        GREEN
        {
            std::stack<int, std::vector<int> > foo (mystack1);   // three ints with a value of 100
            std::stack<int, std::vector<int> > bar (mystack2);   // two ints with a value of 200

            if (foo == bar) std::cout << "foo and bar are equal\n";
            if (foo != bar) std::cout << "foo and bar are not equal\n";
            if (foo <  bar) std::cout << "foo is less than bar\n";
            if (foo >  bar) std::cout << "foo is greater than bar\n";
            if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
            if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
        }
        YELLOW
        {
            ft::stack<int, std::vector<int> > foo (mystack1);   // three ints with a value of 100
            ft::stack<int, std::vector<int> > bar (mystack2);   // two ints with a value of 200

            if (foo == bar) std::cout << "foo and bar are equal\n";
            if (foo != bar) std::cout << "foo and bar are not equal\n";
            if (foo <  bar) std::cout << "foo is less than bar\n";
            if (foo >  bar) std::cout << "foo is greater than bar\n";
            if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
            if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
        }
    }
    */

    BlUE
    std::cout << "###### map ######\n";
    // /*
    std::cout << "-------ft:pair-------\n";
    GREEN
    {
        std::pair <std::string, double> product1;                     // default constructor
        std::pair <std::string, double> product2 ("tomatoes", 2.30);   // value init
        std::pair <std::string, double> product3 (product2);          // copy constructor
        product1 = std::make_pair(std::string("lightbulbs"), 0.99);   // using make_pair (move)
        product2.first = "shoes";                  // the type of first is string
        product2.second = 39.90;                   // the type of second is double
        std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
        std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
        std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    }
    YELLOW
    {
        ft::pair <std::string, double> product1;                     // default constructor
        ft::pair <std::string, double> product2 ("tomatoes", 2.30);   // value init
        ft::pair <std::string, double> product3 (product2);          // copy constructor
        product1 = ft::make_pair(std::string("lightbulbs"), 0.99);   // using make_pair (move)
        product2.first = "shoes";                  // the type of first is string
        product2.second = 39.90;                   // the type of second is double
        std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
        std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
        std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    }
    // */


//    /*
    BlUE std::cout << "-------Constructor-------\n";
    GREEN
    std::map<char,int> first;
    std::cout << "empty std::map :" << std::endl; ft_cout_map(first);
    first['a'] = 10;
    first['b'] = 30;
    first['e'];
    std::cout << "No empty std::map :" << std::endl; ft_cout_map(first);
    std::map<char,int> second (first.begin(),first.end());
    std::map<char,int> third (second);
    std::map<char, int, classcomp> fourth;                 // class as Compare
    bool(*fn_pt)(char, char) = fncomp;
    std::map<char, int, bool(*)(char,char) > fifth (fn_pt); // function pointer as Compare

    YELLOW
    ft::map<char,int> first_ft;
    std::cout << "empty ft::map :" << std::endl;  ft_cout_map(first_ft);
    first_ft['a'] = 10;
    first_ft['b'] = 30;
    first_ft['e'];
    std::cout << "No empty ft::map :" << std::endl;  ft_cout_map(first);
    ft::map<char,int>   second_ft (first_ft.begin(),first_ft.end());
    ft::map<char,int>   third_ft (second_ft);
    ft::map<char, int, classcomp> fourth_ft;                 // class as Compare
    bool(*fn_pt_ft)(char, char) = fncomp;
    ft::map<char, int, bool(*)(char,char) > fifthf (fn_pt_ft); // function pointer as Compare

    BlUE std::cout << "-------Iterators-------\n";
    GREEN
    std::cout << "std::map  revers :" << std::endl;
    for (std::map<char,int>::reverse_iterator it = first.rbegin(); it != first.rend(); it++)
         std::cout << "  [key]= " << it->first << " [value]= " << it->second << std::endl; 

    YELLOW
    std::cout << "ft::map  revers :" << std::endl;
    for (ft::map<char,int>::reverse_iterator it = first_ft.rbegin(); it != first_ft.rend(); it++)
        std::cout << "  [key]= " << it->first << " [value]= " << it->second << std::endl; 

    BlUE std::cout << "-------Capacity-------\n";

    GREEN
    std::cout << "std::map  first.empty() :" <<  first.empty() << std::endl;
    std::cout << "std::map  first.size() :" <<  first.size() << std::endl;
    std::cout << "std::map  first.max_size() :" <<  first.max_size() << std::endl;

    YELLOW
    std::cout << "ft::map  first_ft.empty() :" <<  first_ft.empty() << std::endl;
    std::cout << "ft::map  first_ft.size() :" <<  first_ft.size() << std::endl;
    std::cout << "ft::map  first_ft.max_size() :" <<  first_ft.max_size() << std::endl;

    BlUE std::cout << "-------Element access-------\n";

    std::cout << "it has already been !!!" << std::endl;

    BlUE std::cout << "-------Modifiers-------\n";

    GREEN
    std::cout << "std::map  first.erase() :" << std::endl;
    first.erase('a'); ft_cout_map(first);
    std::cout << "std::map  first.insert() :" << std::endl;
    first.insert( std::pair<char,int>('a',200) ); ft_cout_map(first);

    YELLOW
    std::cout << "ft::map  first_ft.erase() :" << std::endl;
    first_ft.erase('a'); ft_cout_map(first_ft);
    std::cout << "ft::map  first_ft.insert() :" << std::endl;
    first_ft.insert( ft::pair<char,int>('a',200) ); ft_cout_map(first_ft);

    BlUE std::cout << "Test SWAP :" << std::endl;
    GREEN
    {
        std::map<char,int> foo,bar;
        foo['x']=100;
        foo['y']=200;
        bar['a']=11;
        bar['b']=22;
        bar['c']=33;
        foo.swap(bar);
        std::cout << "foo contains:\n";
        for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "bar contains:\n";
        for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }
    YELLOW
    {
        ft::map<char,int> foo,bar;
        foo['x']=100;
        foo['y']=200;
        bar['a']=11;
        bar['b']=22;
        bar['c']=33;
        foo.swap(bar);
        std::cout << "foo contains:\n";
        for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "bar contains:\n";
        for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }

    GREEN
    std::cout << "std::map  first.clear() :" << std::endl;
    first.clear();
    std::cout << "std::map  first.size() :" <<  first.size() << std::endl;

    YELLOW
    std::cout << "ft::map  first_ft.clear() :" << std::endl;
    first_ft.clear();
    std::cout << "ft::map  first_ft.size() :" <<  first_ft.size() << std::endl;

    BlUE std::cout << "-------Observers-------\n";

    std::cout << "Test key_compare :" << std::endl;
    GREEN
    {
        std::map<char,int> mymap;
        std::map<char,int>::key_compare mycomp = mymap.key_comp();
        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;
        std::cout << "mymap contains:\n";
        char highest = mymap.rbegin()->first;     // key value of last element
        std::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );
        std::cout << '\n';
    }
    YELLOW
    {
        ft::map<char,int> mymap;
        ft::map<char,int>::key_compare mycomp = mymap.key_comp();
        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;
        std::cout << "mymap contains:\n";
        char highest = mymap.rbegin()->first;     // key value of last element
        ft::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );
        std::cout << '\n';
    }

    BlUE std::cout << "Test value_comp :" << std::endl;
    GREEN
    {
        std::map<char,int> mymap;
        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;
        std::cout << "mymap contains:\n";
        std::pair<char,int> highest = *mymap.rbegin();          // last element
        std::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );
    }
    YELLOW
    {
        ft::map<char,int> mymap;
        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;
        std::cout << "mymap contains:\n";
        ft::pair<char,int> highest = *mymap.rbegin();          // last element
        ft::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );
    }

    BlUE std::cout << "-------Operations-------\n";
    first['a'] = 10;
    first['b'] = 20;
    first_ft['a'] = 10;
    first_ft['b'] = 20;

    GREEN
    std::cout << "std::map  first.find() :" << std::endl;
    std::cout << "a => " << first.find('a')->second << '\n';
    std::cout << "std::map  first.count() :  " << first.count('a') << '\n';

    YELLOW
    std::cout << "ft::map  first_ft.find() :" << std::endl;
    std::cout << "a => " << first_ft.find('a')->second << '\n';
    std::cout << "ft::map  first_ft.count() :  " << first_ft.count('a') << '\n';

    BlUE std::cout << "Test lower_bound and upper_bound: " << std::endl;
    GREEN
    {
        std::map<char,int> mymap;
        std::map<char,int>::iterator itlow,itup;
        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;
        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)
        mymap.erase(itlow,itup);        // erases [itlow,itup)
        // print content:
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    YELLOW
    {
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator itlow,itup;
        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;
        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)
        mymap.erase(itlow,itup);        // erases [itlow,itup)
        // print content:
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    BlUE std::cout << "Test equal_range: " << std::endl;
    GREEN
    {
        std::map<char,int> mymap;
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');
        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';
        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
    YELLOW
    {
        ft::map<char,int> mymap;
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');
        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';
        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }

    // */

    std::cout << ansi::reset;
    return 0;
}