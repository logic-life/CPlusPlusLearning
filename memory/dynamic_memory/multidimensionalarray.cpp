#include <iostream>
#define ROW 10
#define COL 10

int main(int argc, char *argv[])
{
    //定义一个动态二维数组
    double **_2DArray = new double *[ROW];
    for (int i = 0; i < COL; i++)
    {
        _2DArray[i] = new double[COL];
    }
    //释放一个动态二维数组
    for (int i = 0; i < COL; i++)
        delete[] _2DArray[i];

    delete[] _2DArray;
    return 0;
}