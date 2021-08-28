#include <iostream>
#include <vector>
using namespace std;

template <class T>
vector<T> insertSort(vector<T> vec)
{
    //定义vec的长度为size;
    typename vector<T>::size_type size = vec.size();
    //从第二个元素进行排序
    for (size_t i = 1; i < size;i++)
    {   
        int preIndex = i - 1;
        T current = vec[i];
        // while (preIndex >= 0 && vec[preIndex] > current)
        // { 
        //     vec[preIndex + 1] = vec[preIndex];
        //     preIndex--;
        // }
        for (; preIndex >= 0 && vec[preIndex] > current; preIndex--)
        {
                vec[preIndex + 1] = vec[preIndex];
        }
            vec[preIndex + 1] = current;
    }

    return vec;
}