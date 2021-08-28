#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{

    int **p = new int *[10];
    for (int i = 0; i < 10; i++)
        p[i] = new int[10];

    for (int i = 0; i < 100; i++)
        p[i / 10][i % 10] = i;

    for (int i = 0; i < 100; i++)
        cout << p[i / 10][i % 10] << " ";

    string str = "abcd";
    for (auto i : str)
        cout << (i == 'a') << atoi('a') << endl;
    return 0;
}