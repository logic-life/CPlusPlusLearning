#include <iostream>
#include "seq_list.h"

int main(int argc, char *argv[])
{
    SeqList *L = new SeqList();
    Datatype min, max;
    int min_position, max_position;
    // 列表初始化
    InitList(L);

    try
    {
        for (int i = 0; i < 9; i++)
            InsertList(L, i + 1, Datatype(i));

        std::cout << "线性表的长度为：" << ListLength(L) << std::endl;

        std::cout << "当前结点为：" << GetNode(L, 3) << std::endl;

        std::cout << "8所在的位置为：" << LocateNode(L, 8) << std::endl;

        DeleteList(L, 4);

        std::cout << "线性表的长度为：" << ListLength(L) << std::endl;

        ReverseList(L);

        ReadList(L);

        MaxMinList(L, min, max, min_position, max_position);

        std::cout << min << max << min_position << max_position << std::endl;
    }
    catch (std::string s)
    {
        std::cerr << s << std::endl;
    }
}