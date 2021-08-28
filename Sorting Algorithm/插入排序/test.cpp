#include "insertsort.hpp"

int main(int argc, char *argv[])
{

    vector<int> array = {1, 4, 3, 2, 7, 6, 9, 8};
    // for (auto i : maopaoSort(array))
    //     cout << i;
    for (auto i : insertSort(array))
        cout << i;
    return 0;
}
