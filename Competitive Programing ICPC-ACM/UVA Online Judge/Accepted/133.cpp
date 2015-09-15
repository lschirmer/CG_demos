/*
Leonardo Quatrin Campagnolo - 2910019
Solution of problem 133 - The Dole Queue
*/
#include <list>
#include <iostream>
#include <cstdio>

int N, k, m;
std::list<int> list1;
std::list<int> list2;

void increment()
{
    int officer2_increment = (k) % list2.size();
    int officer1_increment = (m) % list1.size();
    while(officer2_increment > 0)
    {
        list2.push_back(list2.front());
        list2.pop_front();
        officer2_increment--;
    }

    while(officer1_increment > 0)
    {
        list1.push_front(list1.back());
        list1.pop_back();
        officer1_increment--;
    }

}

void getSelected()
{
    if(list1.front() == list2.back())
    {
        std::cout.width(3);
        std::cout << list1.front()+1;

        list2.remove(list1.front());
        list1.remove(list1.front());
    }else{
        std::cout.width(3);
        std::cout << list2.back()+1;

        list1.remove(list2.back());
        list2.remove(list2.back());

        std::cout.width(3);
        std::cout << list1.front()+1;

        list2.remove(list1.front());
        list1.remove(list1.front());
    }
}

int main()
{
    while(std::cin >> N >> k >> m > 0 && N > 0)
    {
        list1.clear();
        for(int i = 0 ; i < N ; i++)
            list1.push_back(i);
        list2 = list1;

        while(true)
        {
            increment();
            getSelected();
            if(!list1.empty())
            {
                std::cout << ",";
            }else
            {
                break;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
