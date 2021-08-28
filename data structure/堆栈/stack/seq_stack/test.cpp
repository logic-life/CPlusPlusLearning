#include "sequential_stack.h"

int main(int argc, char *argv[])
{

    SeqStack *p = new SeqStack();
    initStack(p);
    for (int i = 0; i < 100; i++)
        push(p, i);
}