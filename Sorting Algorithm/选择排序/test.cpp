#include "choosesort.hpp"
#include "heapsort.hpp"
int main(int argc, char *argv[])
{
    vector<int> vec = {3,2,1,5,9,76,17,32};
    // for(auto i:chooseSort(vec))
    //     cout << i<<" ";
    heapSort(vec);
    for (auto i : vec)
        cout << i << " ";

    return 0;
}