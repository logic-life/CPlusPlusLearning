# 宏编写
**\ 反斜杠GG代表该行尚未结束，会串接下一行。**
**如果宏中有多于一个语句，就需要do{/*****/}while(0)包裹成单个语句。**
```
#define M() a(); b()
if (cond)
    M();
else
    c();

/* 预处理后 */

if (cond)
    a(); b(); /* b(); 在 if 之外     */
else          /* <- else 缺乏对应 if */
    c();
```
**只使用{}也不能解决问题**
```
#define M() { a(); b(); }

/* 预处理后 */

if (cond)
    { a(); b(); }; /* 最后的分号代表 if 语句结束 */
else               /* else 缺乏对应 if */
    c(); 
```
**可以使用do while**
```
#define M() do { a(); b(); } while(0)

/* 预处理后 */

if (cond)
    do { a(); b(); } while(0);
else
    c();

```