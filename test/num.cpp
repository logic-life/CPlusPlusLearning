
#include <iostream>

using namespace std;

int main()
{
    //     输入一个正整数
    long int num;
    cin >> num;
    for (int i = 2; i * i <= num;)
    {
        if (num % i == 0)
        {
            num = num / i;
            cout << i << " ";
        }
        else
            i++;
    }

    return 0;
}