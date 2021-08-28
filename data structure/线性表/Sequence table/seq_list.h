#include <iostream>
#include <cmath>
#define ListSize 100  //顺序表最大长度
typedef int Datatype; //顺序表数据类型
typedef struct
{
    Datatype data[ListSize]; //存储结点数组
    int length;              // 结点长度
} SeqList;

void InitList(SeqList *L)
{ // 顺序表初始化，长度为0，结点数组结点置为NULL
    L->length = 0;
    for (int i = 1; i <= ListSize; i++)
        L->data[i - 1] = Datatype(NULL);
}

int ListLength(SeqList *L)
{
    // 返回顺序表的长度
    return L->length;
}

Datatype GetNode(SeqList *L, int i)
{
    // 获取顺序表的第i个结点
    // 超过数组检索范围，则返回错误信息
    if (i < 1 || i > L->length)
        throw std::string("getnode position error !");
    return L->data[i - 1];
}

int LocateNode(SeqList *L, Datatype x)
{
    // 返回顺序表第一个值为x的结点的位置
    for (int j = 1; j <= L->length; j++)
    {
        if (x == L->data[j - 1])
            return j;
    }
    // 不在顺序表内，返回0
    return 0;
}
void InsertList(SeqList *L, int i, Datatype x)
{
    //向顺序表SeqList中第i个位置前插入一个结点
    //  超出数组插入范围，则不插入结点,插入结点范围[1,length+1]
    if (i < 1 || i > L->length + 1)
        throw std::string("insert position error !");

    //  当前顺序表长度>=ListSize,数组长度溢出，不插入结点
    if (L->length >= ListSize)
        throw std::string("overflow !");

    // 在第i个结点位置插入结点，并将后面的结点依次后移
    for (int j = L->length - 1; j >= i - 1; j--)
        L->data[j + 1] = L->data[j];
    L->length++;
    L->data[i - 1] = x;
    return;
}

Datatype DeleteList(SeqList *L, int i)
{

    //删除顺序表SeqList中第i个结点,并返回删除的结点
    // 超出数组删除范围[1,length],则不删除结点
    if (i < 1 || i > L->length)
        throw std::string("delete position error !");

    // 保存删除的结点
    Datatype x = L->data[i - 1];
    // 将第i个结点后面的结点依次前移
    for (int j = i; j <= L->length; j++)
        L->data[j - 1] = L->data[j];
    // 删除最后位置的结点，顺序表长度减一
    L->data[L->length] = Datatype(NULL);
    L->length--;
    return x;
}

// 翻转线性表
void ReverseList(SeqList *L)
{
    // 设线性表为a1、a2、a3、a4、a5、a6，
    // 那么翻转之后就是a6、a5、a4、a3、a2、a1
    // 中间元素所在位置为ceil(length/2)
    int mid_position = ceil(L->length / 2);
    // 将中间元素之前的元素和之后的元素两两交换
    for (int i = 0; i < mid_position; i++)
        std::swap(L->data[i], L->data[L->length - 1 - i]);
}

// 线性表读取
void ReadList(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
        std::cout << L->data[i];
    std::cout << std::endl;
}

// 线性表最大最小值位置及其数值
void MaxMinList(SeqList *L, Datatype &min, Datatype &max, int &min_position, int &max_position)
{
    max = L->data[0];
    min = max;
    max_position = 0;
    min_position = max_position;
    // 循环遍历，依次比较最大最小值
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] > max)
        {
            max = L->data[i];
            max_position = i;
        }
        if (L->data[i] < min)
        {
            min = L->data[i];
            min_position = i;
        }
    }
}