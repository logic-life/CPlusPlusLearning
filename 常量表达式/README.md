# 常量表达式
## 1、定义：
+ 是指值不会改变并且在编译过程就能够得到计算结果的表达式。
## 2、作用：
+ 使写出的代码执行效率更高，充分使用编译时的计算能力
```
//为了使函数获取编译时的计算能力
constexpr int multiply(int x,int y){
    return x*y;
}
//在编译时计算,正常是不允许将函数初始化const 类型
const int val =multiply(10,10);
```
+ 允许函数被应用在以前调用宏的所有场合
```
constexpr int getDefaultArraySize(int multiplier){
    return 10*multiplier;
}
int my_array[getDefaultArraySize(3)];
```
## 3、常见的几种类型
+ 字面值(算术类型、引用、指针、枚举都属于字面值类型)
+ 使用常量表达式初始化的const对象
```
//指针和引用都能够定义为constexpr,但是初始值受到限制，constexpr指针的初始值必须为nullptr或者0，或者存储于某个固定地址中的对象
constexpr int *p=nullptr;//p为一个指向整数的常量指针
```
## 4、注意点
+ constexpr会将所指向的对象设置为顶层const
+ constexpr函数只能有一个return语句(有特例)
+ constexpr函数只能调用其他constexpr函数
+ 只能使用全局constexpr变量
+ 和inline函数不同，可以使用递归
```
constexpr int factorial(int n){
    return n>0?n*factorial(n-1):1;
}

```
+ constexpr同样可以在运行时被使用，只要调用函数的参数为非常量
```
int n;
cin >>n;
factorial(n);
```

