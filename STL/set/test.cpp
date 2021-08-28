#include <iostream>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
    int i_a[] = {0, 1, 3, 4, 5};
    set<int> iset(i_a, i_a + 5);
    //max_size()返回集合中最多元素数量
    cout << "max_size:" << iset.max_size() << endl;
    // 返回集合中当前元素个数
    cout << "size:" << iset.size() << endl;
    //  返回元素在集合中的个数，对于set而言，不允许重复的元素，因此只能为0/1,而multiset中有意义
    cout << "count:" << iset.count(3) << endl;
    // 插入一个元素,可以返回当前插入元素的位置，是否插入成功
    iset.insert(2).first;
    iset.insert(2).second;
    // 可以插入一组数据
    int arr[] = {4, 7, 8};
    iset.insert(arr, arr + 3);
    cout << "size:" << iset.size() << endl;
    //也可以指定位置插入
    iset.insert(iset.end(), 2);


    //查找元素
    auto iter = iset.find(4);
    if(iter!=iset.end())
        cout << "3 found" << endl;
    //set中不允许通过迭代器更改set中的元素
    //*iter = 9;错误！！！

    //删除一个具体元素
    iset.erase(7);
    //删除set中第一个元素
    iset.erase(iset.begin());
    //删除set中指定迭代器范围的元素
    iset.erase(iset.begin(), iset.end());
    cout<<"size:"<<iset.size() << endl;
    iset.insert(arr, arr + 3);
    cout << "size:" << iset.size() << endl;
    //清空iset
    iset.clear();
    cout << "size:" << iset.size() << endl;
    return 0;
}