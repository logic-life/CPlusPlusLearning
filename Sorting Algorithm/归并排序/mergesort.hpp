#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &array, int left, int mid, int right)
{
    //初始化
    vector<int> vec(right-left+1,0);
    int l = left, r = mid + 1;
    int i = 0;
    //依次选出最小值
    for (; l <= mid && r <= right;)
    {
        vec[i++] = array[l] < array[r] ? array[l++] : array[r++];
    }

    while (l <= mid)
        vec[i++]=array[l++];

    while (r <= right)
        vec[i++]=array[r++];

     for (int i = 0; i < right-left+1;i++)
         array[i+left] = vec[i];//vec是从0开始的

}
void dividedArray(vector<int> &array, int left, int right)
{

    if (left < right)
    {
        int mid = (left + right) / 2;
        dividedArray(array, left, mid);
        dividedArray(array, mid + 1, right);
        mergeSort(array, left, mid, right);

    }
}