#include <iostream>
#include "string.h"
using namespace std;

struct s3
{
    char c;
    int i;
};

struct s4
{
    char c1;
    s3 s;
    char c2;
};

// 指针值没有修改，但是指针指向的对象值修改
char *remove_str(char *str, char ch)
{
    char *p = str;
    char *q = str;
    while (*p != '\0')
    {
        while (*p == ch)
            p++;
        *q++ = *p++;
    }
    return str;
}

void strLen(int *p)
{
    cout << sizeof(p) << endl;
}

int main(int argc, char *argv[])
{
    char *a = new char[10];
    string str = "abcd";
    int c[6] = {1, 2, 3, 4, 5, 6};
    int(&p)[6] = c;
    strcpy(a, "abcdcccd");
    cout << remove_str(a, 'c') << endl;
    strLen(p);
    cout << sizeof(s3) << sizeof(s4) << endl;
    cout << str.size();
    return 0;
}