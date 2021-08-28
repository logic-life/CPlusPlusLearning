#include "link_stack.h"

int main(int argc, char *argv[])
{

    ListStack top;
    initStack(top);
    std::cout << "当前栈是否为空：" << stackEmpty(top);
    for (char i = 'a'; i < 'h'; i++)
        pushStack(top, i);
    popStack(top);
    std::cout << "栈顶元素为：" << getTop(top);
    return 0;
}