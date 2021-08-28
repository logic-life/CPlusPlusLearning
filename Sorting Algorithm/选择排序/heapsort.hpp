#include <iostream>
#include <vector>
//先定义最大堆的生成方法
void heapify(std::vector<int> &arr, int n, int i)
{//如果生成的节点位置大小超过最大边界值，着退出循环
    if (i >= n)
        return;
    else
    {   //i节点对应的左右子节点位置为：c1,c2,默认最大节点位置为max
        int c1 = 2 * i + 1;
        int c2 = 2 * i + 2;
        int max = i;
        //如果节点位置还在边界值内，寻找树子结构中的最大值
        if (c1 < n && arr[c1] > arr[max])
            max = c1;
        if (c2 < n && arr[c2] > arr[max])
            max = c2;
            //如果最大值的位置不是父节点的话就进行交换
        if (max != i)
        {
            std::swap(arr[max], arr[i]);
            //递归原先子节点
            heapify(arr, n, max);
        }
    }
}
//从最后一个节点的父节点开始遍历调用heapify(),生成一个最大堆
void buildHeap(std::vector<int> &arr)
{   //数组的元素数量为size
    int size = arr.size();
    //最后一个节点的位置为size-1
    int last_node = size - 1;
    //对应的父节点位置为（last_node-1）/2向下取整
    int parent = (last_node - 1) / 2;
    //循环遍历
    for (int i = parent; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}
//堆排序
void heapSort(std::vector<int> &arr){
    //先建最大堆
    buildHeap(arr);
    for (int i = arr.size() - 1; i >= 0;i--){
        //将第一个节点和最后一个节点交换
        std::swap(arr[0], arr[i]);
        //将最后一个节点截断，然后再进行heapify()
        heapify(arr, i, 0);
    }
}