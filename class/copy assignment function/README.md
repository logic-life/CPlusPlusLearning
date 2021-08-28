# 拷贝赋值运算符
1、返回值的类型要声明为该类型的引用，并在函数结束前返回实例自身的引用。这有这样才能允许连续赋值。
********
2、将传入的形参设置为常量引用，这样可以避免形参为非引用调用拷贝构造函数；同时常量引用也可以防止函数对实参的改变。
********
3、要释放是实例自身已有的内存，否则在分配新内存之前未删除自身已有的空间，会造成内存泄露。
********
4、函数开头要判断是否出现自我复制，否则会在释放内存时，出现释放被复制的内存，从而找不到赋值的内容。
********
```
 CMystring &CMystring::operator=(const CMystring &str)
 {
     std::cout << "赋值构造运算符" << std::endl;
     if (this != &str)
     {
         delete[] my_data;
         my_data = new char[strlen(str.my_data) + 1];
         strcpy(my_data, str.my_data);
         return *this;
     }
     return *this;
 }
```
[拷贝赋值运算符](./cmystring.h)
