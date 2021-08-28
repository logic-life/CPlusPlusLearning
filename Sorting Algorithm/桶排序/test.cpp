#include "bucketSort.hpp"

int main(int argc,char *argv[])
{
    std::vector<int> vec = {1,2,5,4,3,67,98,10,34,23,31,33,12,16,78,90,67,38};
    bucketSort(vec);
    for(auto i:vec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}