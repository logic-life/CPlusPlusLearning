#include <iostream>
#include <vector>
using namespace std;

template <class T>
vector<T> chooseSort(vector<T> vec)
{
    //定义数组元素个数
    typename vector<T>::size_type size = vec.size();

    //依次选出未排序区域的最小值
    for (int i = 0; i < size - 1; i++)
    { //初始化未排序区域最小值序数
        typename vector<T>::size_type min_vec = i;//使用模板类时，无法区分vector<T>::size_type 是否是变量还是类型，需要typename表明为类型
        for (int j = i + 1; j < size; j++)
        {

            if (vec[min_vec] > vec[j])
                min_vec = j;
        }
        swap(vec[min_vec], vec[i]);
    }
    return vec;
}