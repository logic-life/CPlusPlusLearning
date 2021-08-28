#include <iostream>
#include <cassert>
using namespace std;

int strlen(const char *str)
{
    assert(str != NULL);
    return str == '\0' ? 0 : 1 + strlen(++str);
}

char *strcat(char *str_dest, const char *str_src)
{
    char *head = str_dest;
    assert(str_dest != nullptr && str_src != nullptr);
    while (*str_dest)
        str_dest++;
    while (*str_dest++ = *str_src++)
        ;
    return head;
}