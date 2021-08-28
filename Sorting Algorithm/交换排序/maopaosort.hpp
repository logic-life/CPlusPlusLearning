#include <iostream>
#include <vector>
using namespace std;


vector<int> maopaoSort(vector<int> array){
    
    int num_array = array.size();
    //外部循环，每次循环找出当前最大值依次排在最后一位，倒数第二位
    for (int i = 0; i < num_array; i++){
        for (int j = 0; j < num_array - 1 - i;j++){
            if(array[j]>array[j+1])
                swap(array[j],array[j+1]);
        }  
    }
    return array;
}