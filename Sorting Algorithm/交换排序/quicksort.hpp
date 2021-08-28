#include <iostream>
#include <vector>

using namespace std;

int partition_c(vector<int> &vec, int left, int right);

void quickSort(vector<int> &vec, int left, int right)
{
    if (right > left)
    {
        int mid = partition_c(vec, left, right);
        quickSort(vec, left, mid - 1);
        quickSort(vec, mid + 1, right);
       
    }
}

int partition_c(vector<int> &vec, int left, int right)
{
    //设置左右哨兵
    int l = left;
    int r = right;
    //设置比较值,最左边的值
    int key_value = vec[left];
    //遍历
    while (l < r)
    {   //******关键点在于相等时的处理，当前值可以等于比较值******
        //右侧值应该大于比较值，大于就向左前进一位，否则保持不动
        while (vec[r] >= key_value && l < r)
            --r;
        //左侧值应该小于比较值，小于哨兵就向前进一位，否则保持不动
        while (vec[l] <= key_value && l < r)
            ++l;
      
        //判断当前左哨兵位置是否在右哨兵的左侧
        if (l < r)
            //交换左右哨兵指向的值
            swap(vec[l], vec[r]);
    }
    //  如果哨兵相遇，将相遇值和比较值交换
    vec[left] = vec[l];
    vec[l] = key_value;
    //返回哨兵相遇的位置
    return l;
}