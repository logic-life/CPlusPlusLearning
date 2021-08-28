#include <queue>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    queue<int> i_q;
    vector<int> vec = {1, 23, 45};
    i_q.emplace(6);
    //队尾添加元素
    i_q.push(1);
    i_q.push(3);
    i_q.push(5);
    i_q.push(7);
    //与一个队列交换元素
    i_q.swap(i_q);
    //返回队列中的元素
    cout << i_q.size() << endl;
    //返回队列最后一个元素
    cout << i_q.back() << endl;
    //返回队首元素
    cout << i_q.front() << endl;

    if (!i_q.empty())
        cout << "队列不为空！" << endl;
    else
        cout << "队列为空！" << endl;
    return 0;
}