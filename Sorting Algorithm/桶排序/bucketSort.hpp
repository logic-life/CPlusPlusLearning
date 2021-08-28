#include <iostream>
#include <vector>
#define MAX 10

int partition_c(std::vector<int> &vec, int left, int right);
void quickSort(std::vector<int> &vec, int left, int right);

int hashFunc(int val)
{
    return val % MAX;
}
void bucketSort(std::vector<int> &arr)
{
    int size = arr.size();
    //划分为十个间隔
    std::vector<int> temp(0,0);
    std::vector<std::vector<int>> vec;
    //初始化桶
    for (int i = 0; i < MAX; i++)
        vec.push_back(temp);
    //将数据依据余数存入各个间隔中,按照十位大小
    for (auto i : arr)
        vec[i / MAX].push_back(i);
    //对于每一个间隔中的元素进行快速排序
    for (int i = 0; i < MAX;i++)
        quickSort(vec[i], 0, vec[i].size() - 1);
    //将排好序的桶返回原数组
    int p = 0;
    for (int i = 0; i < MAX; i++)
        for(auto j:vec[i])
            arr[p++] = j;
}

void quickSort(std::vector<int> &vec, int left, int right)
{
    if (right > left)
    {
        int mid = partition_c(vec, left, right);
        quickSort(vec, left, mid - 1);
        quickSort(vec, mid + 1, right);
    }
}

int partition_c(std::vector<int> &vec, int left, int right)
{
    //设置左右哨兵
    int l = left;
    int r = right;
    //设置比较值,最左边的值
    int key_value = vec[left];
    //遍历
    while (l < r)
    { //******关键点在于相等时的处理，当前值可以等于比较值******
        //右侧值应该大于比较值，大于就向左前进一位，否则保持不动
        while (vec[r] >= key_value && l < r)
            --r;
        //左侧值应该小于比较值，小于哨兵就向前进一位，否则保持不动
        while (vec[l] <= key_value && l < r)
            ++l;

        //判断当前左哨兵位置是否在右哨兵的左侧
        if (l < r)
            //交换左右哨兵指向的值
            std::swap(vec[l], vec[r]);
    }
    //  如果哨兵相遇，将相遇值和比较值交换
    vec[left] = vec[l];
    vec[l] = key_value;
    //返回哨兵相遇的位置
    return l;
}