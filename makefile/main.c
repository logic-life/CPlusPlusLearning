#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(void)
{
    int a = 10, b = 13;
    float x = 33.33, y = 9.87;
    printf("int a+b is:%d\n", addInt(a, b));
    printf("int a-b:%d\n", subInt(a, b));
    printf("float a+b is:%f\n", addFloat(a, b));
    printf("float a-b:%f\n", subFloat(a, b));
    return 0;
}
