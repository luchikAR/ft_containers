#include <iostream>
#include <memory>
#include <algorithm>
#include <ctime>

#include <vector>

#include "include/vector.hpp"

#define GREEN std::cout << ansi::foreground_green;
#define YELLOW std::cout << ansi::foreground_yellow;
#define BlUE std::cout << ansi::foreground_blue;

void ft_cout_vector(std::vector<int> x)
{
    std::cout << "{ ";
    for (size_t i = 0; i < x.size(); i++)
    {
        if (i + 1 < x.size())
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
        if (i + 1 < x.size())
            std::cout << x[i] << ",";
        else
            std::cout << x[i];
    }
    std::cout << " }" << std::endl;
}

int main()
{
    unsigned int start_time = clock(); // начальное время
    // здесь фрагмент кода, время выполнения которого нужно измерить
    {
        std::vector<int> sv_int1;
        std::vector<int> sv_int2(4);
        std::vector<int> sv_int3(4, 5);

        std::vector<int> v1;
        std::vector<int>::iterator v1Iter;
        std::vector<int>::allocator_type v1Alloc;
        for (int i = 1; i <= 7; i++)
        {
            v1.push_back(3 * i);
        }
        std::allocator<int>::pointer v1PtrA = v1Alloc.address(*find(v1.begin(), v1.end(), 6));
        std::allocator<int>::pointer v2PtrA = v1Alloc.address(*find(v1.begin(), v1.end(), 15));
        std::vector<int> sv_int4(v1PtrA, v2PtrA);

        GREEN
        std::cout << "std:: v(4): " << sv_int2[0] << std::endl;
        std::cout << "std:: v(4,5): size = " << sv_int3.size() << " ";
        ft_cout_vector(sv_int3);
        std::cout << "std:: v(Prt,Ptr): size = " << sv_int4.size() << " ";
        ft_cout_vector(sv_int4);

        std::cout << "---------Capacity---------\n";

        GREEN
        std::cout << "std:: [max_size][sv_int1] = " << sv_int1.max_size() << std::endl;
        std::vector<int> sv_int5;
        for (int i = 1; i < 10; i++)
            sv_int5.push_back(i);
        sv_int5.resize(5);
        sv_int5.resize(8, 100);
        sv_int5.resize(12);
        std::cout << "std:: [resize] \nsz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);
        sv_int5.resize(7);
        std::cout << "sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);

        std::cout << "std:: [empty] = " << sv_int5.empty() << std::endl;
        std::cout << "std:: [reserve] cap before = " << sv_int5.capacity() << std::endl;
        sv_int5.reserve(40);
        std::cout << "\tcap after(grow) = " << sv_int5.capacity() << " ";
        ft_cout_vector(sv_int5);
        sv_int5.reserve(20);
        std::cout << "\tcap after(low) = " << sv_int5.capacity() << " ";
        ft_cout_vector(sv_int5);
        std::cout << std::endl;

        std::cout << "---------Element access---------\n";

        GREEN

        const std::vector<int> sv_int6(3, 7);
        std::vector<int> sv_int7(3, 7);
        std::cout << "std:: [1] = " << sv_int7[1] << std::endl;
        std::cout << "ft:: const[1] = " << sv_int6[1] << std::endl;
        std::cout << "ft:: at[1] = " << sv_int7.at(1) << std::endl;
        std::cout << "ft:: const at[1] = " << sv_int6.at(1) << std::endl;
        std::cout << "[push back] int[11]" << std::endl;
        sv_int7.push_back(11);
        std::cout << "ft:: [front] = " << sv_int7.front() << std::endl;
        std::cout << "ft:: [back] = " << sv_int7.back() << std::endl;

        std::cout << "---------Iterators---------\n";
        GREEN
        std::cout << "выведем от начала до конца std::vector" << std::endl;
        for (std::vector<int>::iterator it = sv_int5.begin(); it != sv_int5.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl
                  << "выведем в обратном порядке std::vector" << std::endl;
        for (std::vector<int>::reverse_iterator it = sv_int5.rbegin(); it != sv_int5.rend(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;

        std::cout << "---------ft::Modifiers---------\n";

        GREEN
        std::vector<int> sv_int9;
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);
        sv_int9.push_back(10);
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);
        sv_int9.push_back(11);
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);
        sv_int9.clear();
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);

        GREEN
        sv_int5.assign(v1PtrA, v2PtrA);
        std::cout << "std:: [assign] sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);
        sv_int5.assign(5, 5);
        std::cout << "std:: [assign] sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);

        GREEN
        int std_sum = 0;
        while (!sv_int5.empty())
        {
            std_sum += sv_int5.back();
            sv_int5.pop_back();
        }
        std::cout << "std:: [pop_back] sum = " << std_sum << " sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);

        GREEN
        for (int i = 1; i <= 10; i++)
            sv_int5.push_back(i);
        std::cout << "std:: [erase][befor] sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);
        std::vector<int>::iterator it_std_res = sv_int5.erase(sv_int5.begin() + 5);
        std::cout << "std:: [erase][after] sz = " << sv_int5.size() << " res = " << *it_std_res << " ";
        ft_cout_vector(sv_int5);
        it_std_res = sv_int5.erase(sv_int5.begin(), sv_int5.begin() + 3);
        std::cout << "std:: [erase][after] sz = " << sv_int5.size() << " res = " << *it_std_res << " ";
        ft_cout_vector(sv_int5);
        GREEN
        {
            std::vector<int> myvector_std(3, 100);
            std::vector<int>::iterator it_std = myvector_std.begin();
            it_std = myvector_std.insert(it_std, 200);
            myvector_std.insert(it_std, 2, 300);
            it_std = myvector_std.begin();
            std::vector<int> anothervector_str(2, 400);
            myvector_std.insert(it_std + 2, anothervector_str.begin(), anothervector_str.end());
            int myarray[] = {501, 502, 503};
            myvector_std.insert(myvector_std.begin(), myarray, myarray + 3);
            std::cout << "std:: [insert] = ";
            ft_cout_vector(myvector_std);
        }
        std::cout << "---------Allocator---------\n";
        GREEN
        {
            std::vector<int> myvector1_std;
            int *p;
            unsigned int i;
            // allocate an array with space for 5 elements using vector's allocator:
            p = myvector1_std.get_allocator().allocate(5);
            // construct values in-place on the array:
            for (i = 0; i < 5; i++)
                myvector1_std.get_allocator().construct(&p[i], i);
            std::cout << "The allocated array contains:";
            for (i = 0; i < 5; i++)
                std::cout << ' ' << p[i];
            std::cout << '\n';
            // destroy and deallocate:
            for (i = 0; i < 5; i++)
                myvector1_std.get_allocator().destroy(&p[i]);
            myvector1_std.get_allocator().deallocate(p, 5);
        }
        {
            std::vector<int> foo(3, 100); // three ints with a value of 100
            std::vector<int> bar(2, 200); // two ints with a value of 200

            if (foo == bar)
                std::cout << "foo and bar are equal\n";
            if (foo != bar)
                std::cout << "foo and bar are not equal\n";
            if (foo < bar)
                std::cout << "foo is less than bar\n";
            if (foo > bar)
                std::cout << "foo is greater than bar\n";
            if (foo <= bar)
                std::cout << "foo is less than or equal to bar\n";
            if (foo >= bar)
                std::cout << "foo is greater than or equal to bar\n";
        }
    }
    unsigned int end_time = clock();                    // конечное время
    unsigned int search_time = (end_time - start_time); // искомое время
    // std::cout << "std::time = " << search_time << std::endl;
    
    start_time = clock();
    {
        ft::vector<int> sv_int1;
        ft::vector<int> sv_int2(4);
        ft::vector<int> sv_int3(4, 5);

        ft::vector<int> v1;
        ft::vector<int>::iterator v1Iter;
        ft::vector<int>::allocator_type v1Alloc;
        for (int i = 1; i <= 7; i++)
        {
            v1.push_back(3 * i);
        }
        std::allocator<int>::pointer v1PtrA = v1Alloc.address(*find(v1.begin(), v1.end(), 6));
        std::allocator<int>::pointer v2PtrA = v1Alloc.address(*find(v1.begin(), v1.end(), 15));
        ft::vector<int> sv_int4(v1PtrA, v2PtrA);

        YELLOW
        std::cout << "std:: v(4): " << sv_int2[0] << std::endl;
        std::cout << "std:: v(4,5): size = " << sv_int3.size() << " ";
        ft_cout_vector(sv_int3);
        std::cout << "std:: v(Prt,Ptr): size = " << sv_int4.size() << " ";
        ft_cout_vector(sv_int4);

        std::cout << "---------Capacity---------\n";

        std::cout << "std:: [max_size][sv_int1] = " << sv_int1.max_size() << std::endl;
        ft::vector<int> sv_int5;
        for (int i = 1; i < 10; i++)
            sv_int5.push_back(i);
        sv_int5.resize(5);
        sv_int5.resize(8, 100);
        sv_int5.resize(12);
        std::cout << "std:: [resize] \nsz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);
        sv_int5.resize(7);
        std::cout << "sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);

        std::cout << "std:: [empty] = " << sv_int5.empty() << std::endl;
        std::cout << "std:: [reserve] cap before = " << sv_int5.capacity() << std::endl;
        sv_int5.reserve(40);
        std::cout << "\tcap after(grow) = " << sv_int5.capacity() << " ";
        ft_cout_vector(sv_int5);
        sv_int5.reserve(20);
        std::cout << "\tcap after(low) = " << sv_int5.capacity() << " ";
        ft_cout_vector(sv_int5);
        std::cout << std::endl;

        std::cout << "---------Element access---------\n";

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

        std::cout << "---------Iterators---------\n";
    
        std::cout << "выведем от начала до конца std::vector" << std::endl;
        for (ft::vector<int>::iterator it = sv_int5.begin(); it != sv_int5.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl
                  << "выведем в обратном порядке std::vector" << std::endl;
        for (ft::vector<int>::reverse_iterator it = sv_int5.rbegin(); it != sv_int5.rend(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;

        std::cout << "---------ft::Modifiers---------\n";

    
        ft::vector<int> sv_int9;
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);
        sv_int9.push_back(10);
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);
        sv_int9.push_back(11);
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);
        sv_int9.clear();
        std::cout << "std:: v_9: size = " << sv_int9.size() << " cap = " << sv_int9.capacity() << " ";
        ft_cout_vector(sv_int9);

        sv_int5.assign(v1PtrA, v2PtrA);
        std::cout << "std:: [assign] sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);
        sv_int5.assign(5, 5);
        std::cout << "std:: [assign] sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);

        int std_sum = 0;
        while (!sv_int5.empty())
        {
            std_sum += sv_int5.back();
            sv_int5.pop_back();
        }
        std::cout << "std:: [pop_back] sum = " << std_sum << " sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);

        for (int i = 1; i <= 10; i++)
            sv_int5.push_back(i);
        std::cout << "std:: [erase][befor] sz = " << sv_int5.size() << " ";
        ft_cout_vector(sv_int5);
        ft::vector<int>::iterator it_std_res = sv_int5.erase(sv_int5.begin() + 5);
        std::cout << "std:: [erase][after] sz = " << sv_int5.size() << " res = " << *it_std_res << " ";
        ft_cout_vector(sv_int5);
        it_std_res = sv_int5.erase(sv_int5.begin(), sv_int5.begin() + 3);
        std::cout << "std:: [erase][after] sz = " << sv_int5.size() << " res = " << *it_std_res << " ";
        ft_cout_vector(sv_int5);
        {
            ft::vector<int> myvector_std(3, 100);
            ft::vector<int>::iterator it_std = myvector_std.begin();
            it_std = myvector_std.insert(it_std, 200);
            myvector_std.insert(it_std, 2, 300);
            it_std = myvector_std.begin();
            ft::vector<int> anothervector_str(2, 400);
            myvector_std.insert(it_std + 2, anothervector_str.begin(), anothervector_str.end());
            int myarray[] = {501, 502, 503};
            myvector_std.insert(myvector_std.begin(), myarray, myarray + 3);
            std::cout << "std:: [insert] = ";
            ft_cout_vector(myvector_std);
        }
        std::cout << "---------Allocator---------\n";
        {
            ft::vector<int> myvector1_std;
            int *p;
            unsigned int i;
            // allocate an array with space for 5 elements using vector's allocator:
            p = myvector1_std.get_allocator().allocate(5);
            // construct values in-place on the array:
            for (i = 0; i < 5; i++)
                myvector1_std.get_allocator().construct(&p[i], i);
            std::cout << "The allocated array contains:";
            for (i = 0; i < 5; i++)
                std::cout << ' ' << p[i];
            std::cout << '\n';
            // destroy and deallocate:
            for (i = 0; i < 5; i++)
                myvector1_std.get_allocator().destroy(&p[i]);
            myvector1_std.get_allocator().deallocate(p, 5);
        }
        {
            ft::vector<int> foo(3, 100); // three ints with a value of 100
            ft::vector<int> bar(2, 200); // two ints with a value of 200

            if (foo == bar)
                std::cout << "foo and bar are equal\n";
            if (foo != bar)
                std::cout << "foo and bar are not equal\n";
            if (foo < bar)
                std::cout << "foo is less than bar\n";
            if (foo > bar)
                std::cout << "foo is greater than bar\n";
            if (foo <= bar)
                std::cout << "foo is less than or equal to bar\n";
            if (foo >= bar)
                std::cout << "foo is greater than or equal to bar\n";
        }
    }
    end_time = clock();                    // конечное время
    unsigned int search_time2 = (end_time - start_time); // искомое время
    BlUE
    std::cout << "std::time = " << search_time << std::endl;
    std::cout << "ft::time = " << search_time2 << std::endl;
    
    std::cout << ansi::reset;
}