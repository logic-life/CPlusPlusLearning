# NULL 和 nullptr和0
**在C++中NULL表示一个宏，如下所示：**
```
/* Define NULL pointer value */
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else  /* __cplusplus */
#define NULL    ((void *)0)
#endif  /* __cplusplus */
#endif  /* NULL */
```
**定义为0，而0在C++中可以表示为空指针。然而在使用过程中会造成二义性**
**例如：**
```
func(int a,int *b);
func(int a,int b);
void Test(){
    func(m,NULL);//调用时会出现二义性，无法区别调用是哪个函数，使用0更能让人警觉！
    func(m,0)//调用函数二
    func(m,static_cast<int *>(0))//调用函数一
    func(m,nullptr);//调用函数一
}
```
[nullandnullptr](./nullandnullptr.cpp)
****************
C语言中NULL表示(void *),空指针可以转换为任何类型的指针
