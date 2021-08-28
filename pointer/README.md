# 指针

## 指针数组
```
 const char *aPointerArray[MAX] = {"zhangsan", "lisi", "zhaowu", "hanliu"};
    for (int i = 0; i < MAX; i++)
        std::cout << aPointerArray[i] << std::endl;
```
[指针数组](https://github.com/logic-life/C-learning/blob/main/array/pointertoarray.cpp)

## 数组指针
```
 char c[][8] = {"apple", "orange", "banana"};
    char(*pointer)[8] = &c[2];
    char a[] = {"name"};
    char *p = a;//相当于&a[0]
    //m = &c[1];
    cout << typeid(pointer).name()
         << "\n"
         << typeid(c[2]).name() << endl;
    cout << **pointer << "\n"
         << *pointer << p << endl;
```

## 函数指针
**使用函数改变指针变量的值**
```
unsigned long time_now;
    getSeconds(&time_now);
    std::cout << "输出当前时间：" << time_now << std::endl;
```
    