#include "sequential_stack.h"

int main(int argc, char *argv[])
{

    SeqStack *p = new SeqStack();
    int i = 0;
    initStack(p);
    while (1)
    {
        /* code */
        i++;
    }

    for (int i = 0; i < 100; i++)
        push(p, i);
}