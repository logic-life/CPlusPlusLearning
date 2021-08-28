# 数据封装的问题

> 只要将结构体类型定义在头文件中，库的使用者就可以看到该定义，并按照成员格
> 式直接访问，而不调用存取函数

***解决方法:
将结构体类型的具体细节定义在源文件中，所有针对该类型量的操作都只能通过函
数接口来进行，从而隐藏实现细节***

````
eg:信息隐藏示例
/* 头文件“dynarray.h”*/
struct DYNINTS; typedef struct DYNINTS * PDYNINTS;
/* 源文件“dynarray.cpp”*/
struct DYNINTS{
unsigned int capacity; unsigned int count; int * items; bool modified;
};
````

# 链表

+ 链表的节点是动态分配内存的，所以节点逻辑上连续，物理地址不连续。
+ 头指针失去链表头地址，整个链表就会丢失；任意节点next失去下一地址，后续链表都会丢失
+ 双向链表、单向链表

# 函数指针

> 函数指针可以直接赋值(同种类型)              函数指针名称=函数名称

```
char * DoTransformObjectIntoString( ADT object )
{ return PtTransformIntoString( (PPOINT)object ); }
as_string = DoTransformObjectIntoString;
```
