#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    //创建一个整形链表
    list<int> i_list;
    //依次插入五个数据
    i_list.push_back(0);
    i_list.push_back(2);
    i_list.push_back(1);
    i_list.push_back(4);
    i_list.push_back(6);
    cout << "size:" << i_list.size() << endl;
    for (auto i : i_list)
        cout << i << " ";
    cout << endl;
    list<int>::iterator ite;
    //查找元素
    ite = find(i_list.begin(), i_list.end(), 2);
    if (ite != i_list.end())
    //在查找到的元素位置上插入一个元素
        i_list.insert(ite, 99);
    for (auto i : i_list)
        cout << i << " ";
    cout << endl;
    //删除元素
    cout << *i_list.erase(ite) << endl;
    i_list.push_front(99);
    for (auto i : i_list)
        cout << i << " ";
    cout << endl;
    //排序
    i_list.sort();
    //删除连续相同的元素
    i_list.unique();
    for (auto i : i_list)
        cout << i << " ";
    cout << endl;
    //插入另一个链表的元素
    list<int> n_list = {1,2,3};
    i_list.splice(i_list.end(),n_list);
    for (auto i : i_list)
        cout << i << " ";
    cout << endl;
    i_list.reverse();
    for (auto i : i_list)
        cout << i << " ";
    cout << endl;
    return 0;
}
