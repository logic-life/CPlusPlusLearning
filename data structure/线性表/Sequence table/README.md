# 顺序表

## 顺序表的基本运算

1. 构建一个空的线性表，InitList(L)；
2. 求表长ListLength(L)，返回线性表L中的结点数；
3. 取表中第i个结点GetNode(L,i)；
4. 按值查找LocateNode(L,x),在L中查找第一个值为x的结点，并返回该结点在表L中的位置，如果不存在就返回0；
5. 插入InsertList(L,i,x),在表L的第i个结点之前插入一个值为x的结点，并将表长加一；
6. 删除DeleteList(L,i),删除表L的第i个结点，表L的长度减一。

## 顺序表的定义

### 顺序存储结构

* 存储线性表的结点
* 需要一个变量标识线性表的长度

```apache
# define ListSize 100 			//表空间的大小
typedef int DataType;			//定义数据类型
typedef struct{
	DataType data[ListSize];	//数组存储表结点
	int length;			//线性表的表长
}SeqList;
```

### 顺序表初始化

```
void InitList(SeqList *L)
{ // 顺序表初始化，长度为0，结点数组结点置为NULL
    L->length = 0;
    for (int i = 1; i <= ListSize; i++)
        L->data[i - 1] = NULL;
}
```

### 返回表长

```
int ListLength(SeqList *L)
{
    // 返回顺序表的长度
    return L->length;
}
```

### 取表第i个结点

```
Datatype GetNode(SeqList *L, int i)
{
    // 获取顺序表的第i个结点
    // 超过数组检索范围，则返回错误信息
    if (i < 1 || i > L->length)
    {
        std::cout << "position error !" << std::endl;
        error();
    }
    return L->data[i - 1];
}
```

### 按值查找x结点的第一个位置

```
int LocateNode(SeqList *L, Datatype x)
{
    // 返回顺序表第一个值为x的结点的位置
    for (int j = 1; j <= L->length; j++)
    {
        if (x == L->data[j - 1])
            return j;
    }
    // 不在顺序表内，返回0
    return 0;
}
```

### 插入运算

```
//向顺序表SeqList中第i个位置前插入一个结点
void InsertList(SeqList *L, int i, Datatype x)
{   // 超出数组插入范围，则不插入结点,插入结点范围[1,length+1]
    if (i < 1 || i > L->length + 1)
    {
        std::cout << "position error !" << std::endl;
        return;
    }
    // 当前顺序表长度>=ListSize,数组长度溢出，不插入结点
    if (L->length >= ListSize)
    {
        std::cout << "overflow !" << std::endl;
        return;
    }
    // 在第i个结点位置插入结点，并将后面的结点依次后移
    for (int j = L->length - 1; j >= i - 1; j--)
        L->data[j + 1] = L->data[j];
    L->length++;
    L->data[i - 1] = x;
    return;
}
```

### 删除运算

```
//删除顺序表SeqList中第i个结点,并返回删除的结点
Datatype DeleteList(SeqList *L, int i)
{ // 超出数组删除范围[1,length],则不删除结点
    if (i < 1 || i > L->length)
    {
        std::cout << "position error !" << std::endl;
        error();
    }
    // 保存删除的结点
    Datatype x = L->data[i - 1];
    // 将第i个结点后面的结点依次前移
    for (int j = i; j <= L->length; j++)
        L->data[j - 1] = L->data[j];
    // 删除最后位置的结点，顺序表长度减一
    L->data[L->length] = NULL;
    L->length--;
    return x;
}
```
