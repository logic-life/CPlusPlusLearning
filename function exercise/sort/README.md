# sort(first_pointer,end_pointer,cmp)
> include <algorithm>
> using namespace std;

+ first_pointer :第一个参数是数组的首地址，一般写上数组名就可以，因为数组名是一个指针常量。
+ end_pointer :第二个参数相对较好理解，即排序末尾地址的下一地址。
+ cmp :默认可以不填，如果不填sort会默认按数组升序排序。也就是1,2,3,4排序。也可以自定义一个排序函数，改排序方式为降序什么的，也就是4,3,2,1这样；或者指定lambda表达式或者函数

<font face="楷体" color="a6a5c4" size=5>该函数可以给数组，或者链表list、向量排序。</font>

实现原理：sort并不是简单的快速排序，它对普通的快速排序进行了优化，此外，它还结合了插入排序和推排序。系统会根据你的数据形式和数据量自动选择合适的排序方法，这并不是说它每次排序只选择一种方法，它是在一次完整排序中不同的情况选用不同方法，比如给一个数据量较大的数组排序，开始采用快速排序，分段递归，分段之后每一段的数据量达到一个较小值后它就不继续往下递归，而是选择插入排序，如果递归的太深，他会选择推排序。

```
//情况一：在结构体内部重载
typedef struct Student{
int id;
string name;
double grade;

bool operator<(const Student& s)
{
    return id>s.id;//降序排列
    //return id<s.id;//升序排列
}
};
vector<Student> V;
sort(V.begin(),V.end());
//情况二：在外部重载
vector<Student> V;
bool operator<(const Student& s1, const Student& s2)
{
    return s1.id>s2.id;//降序排列
    //return s1.id<s2.id;//升序排列
}
    sort(V.begin(),V.end());
//注意：一定要重载<运算符，因为系统默认是降序，用的是<运算符。
```
```
方法四：声明比较类（少用）

struct Less
{
    bool operator()(const Student& s1, const Student& s2)
    {
        return s1.id<s2.id; //升序排列
    }
};
sort(sutVector.begin(),stuVector.end(),Less());
```
```
一个list（链表）使用sort()实例：

#include "stdafx.h"
#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include "stdlib.h"
#include <stdio.h>

using namespace std;

//给list起一个别名LISTINT
typedef list<int> LISTINT;
//再起一个别名 LISTCHAR
typedef list<int> LISTCHAR;

int _tmain(int argc, _TCHAR* argv[])
{

//用list容器处理整型数据
//用LISTINT创建一个名为listOne的list对象
LISTINT listOne;
//声明i为迭代器
LISTINT::iterator i;

//从前面向listOne容器中添加数据
listOne.push_front (2);
listOne.push_front (1);

//从队尾向listOne容器中添加数据

listOne.push_back (5);
listOne.push_back (4);
listOne.push_back (9);
listOne.push_back (7);
listOne.push_back (12);

//从前向后显示listOne中的数据,排序前的链表
cout<<"listOne.begin()--- listOne.end():"<<endl;
for (i = listOne.begin(); i != listOne.end(); ++i)
cout << *i << " ";
cout << endl;

listOne.sort(); //用sort()函数排序,默认升序
//排序完毕后的列表
cout<<"listOne.begin()--- listOne.end():"<<endl;
for (i = listOne.begin(); i != listOne.end(); ++i)
cout << *i << " ";
cout << endl;
system("pause"); //按任意键后退出
return 0;
}
```

