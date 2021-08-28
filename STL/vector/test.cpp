#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int pos = 0;
    vector<int> i_v(2, 9);
    //读取向量空间中的元素个数
    cout << "size=" << i_v.size() << endl;
    //读取向量空间中的空间大小
    cout << "capacity:" << i_v.capacity() << endl;
    //从尾端插入元素
    i_v.push_back(3);
    cout << "size=" << i_v.size() << endl;
    cout << "max_size" << i_v.max_size() << endl;
    cout << "capacity:" << i_v.capacity() << endl;
    //stl中的查找成功找到就返回最先找到元素的迭代器，否则返回end()
    vector<int>::iterator iter = find(i_v.begin(), i_v.end(), 9);
    if (iter != i_v.end())
        //删除指定迭代器位置的元素
        i_v.erase(iter);
    cout << "size=" << i_v.size() << endl;
    cout << "max_size" << i_v.max_size() << endl;
    cout << "capacity:" << i_v.capacity() << endl;
    //取代试图访问内存里的非法值的做法，at()可以分辨是否访问出界并且在出界时抛出一个异常
    for (int i = 0; i < 2; i++)
        cout << i_v.at(i) << " ";
    //back()返回向量中最后一个元素的引用，front()则返回第一个元素的引用
    cout << endl;
    cout << "front:" << i_v.front() << " back:" << i_v.back() << endl;
    // iterator insert( iterator loc, const TYPE &val );
    // void insert(iterator loc, size_type num, const TYPE &val);
    // void insert(iterator loc, input_iterator start, input_iterator end);
    // 三种使用方法insert()
    i_v.insert(i_v.end(), 8); 
    //逆序迭代器，从队尾输出到队头
    for (auto i = i_v.rbegin(); i != i_v.rend(); i++)
        cout << *i << " ";
    //预留size空间
    i_v.reserve(20);
    cout << "size=" << i_v.size() << endl;
    cout << "capacity:" << i_v.capacity() << endl;
    //改变vector的大小，且将新创建的元素赋值val
    i_v.resize(20, 9);
    //和其他vector交换值
    //i_v.swap(i.rbegin());
    //将最尾端元素取出
    i_v.pop_back();
    return 0;
}