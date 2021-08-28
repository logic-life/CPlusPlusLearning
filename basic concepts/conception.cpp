#include <iostream>

using namespace std;
int k = 1;
int main()
{
    int i = 1;
    char *j;
    static int m = 1;
    char *n = "hello"; //变量n位于栈上，其内容为一地址，指向文字常量区的"hello",因此“hello”在内存中 只有一份拷贝，而char a[]="hello",表示在栈上有一个6元素的数组，并将“hello”拷贝到数组中，因此“hello”含有两份拷贝。
    printf("栈区地址是：0X%x\n", &i);
    j = (char *)malloc(2);
    free(j);
    printf("栈区地址是：0X%x\n", &j);
    printf("全局变量地址是：0X%x\n", &k);
    printf("静态变量地址是：0X%x\n", &m);
    printf("文字常量地址是：0X%x\n", n);
    printf("程序区地址是：0X%x\n", &main);

    return 1;
}