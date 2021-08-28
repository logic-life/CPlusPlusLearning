#include "maopaosort.hpp"
#include "quicksort.hpp"

int main(int argc, char *argv[])
{

    vector<int> array = {1, 4, 3, 2, 7, 6, 9, 8};
    // for (auto i : maopaoSort(array))
    //     cout << i;
    quickSort(array,0,array.size()-1);

    for (auto i : array)
        cout << i;
    return 0;
}
