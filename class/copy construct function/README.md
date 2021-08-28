# 拷贝构造函数
##  拷贝初始化发生情况
1、使用=定义变量时
```
string str1="99999-1000";
string str2=str1;
string str3=string(100,'9');
```
**以上均发生拷贝初始化**
**************************
2、将一个对象作为实参传递给一个非引用类型的形参
```

class MyCopyConstruct{
private:
    int value;
public:
    MyCopyConstruct(int   initialization_value  ){
        value=initialization_value;
    }
    //error: invalid constructor; you probably meant ‘MyCopyConstruct (const MyCopyConstruct&)
     MyCopyConstruct(MyCopyConstruct initialization_object){ 
         value=initialization_object.value;
  }
     //MyCopyConstruct(const MyCopyConstruct & initialization_object){
     //   value=initialization_object.value;
    // }
    void PrintValue(){
        cout<<"value \n"<<value<<endl;
    }

};
```
***拷贝构造函数的第一个参数必须是一个引用类型,否则调用拷贝构造函数时，就会在拷贝构造函数中调用拷贝构造函数，从而出现无休止的递归调用，导致堆溢出！***
**************************
3、用花括号列表初始化一个数组中的元素或者一个聚合类中的成员
[]()
**************************
4、某些类类型例如标准库容器或者调用其insert或push成员时，容器会对其元素进行拷贝初始化
[]()
**************************
