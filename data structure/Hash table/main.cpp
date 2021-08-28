#include <iostream>

using namespace std;

typedef int status;

constexpr auto SUCCESS = 1;
constexpr auto UNSUCCESS = 0;
constexpr auto HASHSIZE = 12;
constexpr auto NULLKEY = -32768;

//哈希表结构的定义
typedef struct Hashtable
{
    int *elem; //数据元素存储基址，动态分配数组
    int count; //当前数据元素个数
} Hashtable;

int m = 0; //散列表的表长，全局变量

/*相关的函数声明*/
status Inithashtable(Hashtable *H);
int Hash(int key);
void Inserthash(Hashtable *H, int key);
status Searchhash(Hashtable H, int key, int *addr);
void Createhash(Hashtable H, int array[], int n);
void Showhash(Hashtable H);

//初始化散列表(哈希表)
status Inithashtable(Hashtable *H)
{
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return true;
}

//散列函数
int Hash(int key)
{
    return key % m; //除留余数法
}

//插入关键字进散列表
void Inserthash(Hashtable *H, int key)
{
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY)
    {
        addr = (addr + 1) % m;
    }
    H->elem[addr] = key;
}

//散列表查找关键字
status Searchhash(Hashtable H, int key, int *addr)
{
    *addr = Hash(key);
    while (H.elem[*addr] != key)
    {
        *addr = (*addr + 1) % m;
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
        {
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}

//创建哈希表
void Createhash(Hashtable H, int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Inserthash(&H, array[i]);
    }
}

//打印哈希表的值
void Showhash(Hashtable H)
{
    int num = H.count;
    for (int i = 0; i < num; i++)
    {
        cout << "第" << i << "个数字为：" << H.elem[i] << endl;
    }
}

int main()
{
    int a[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    int p;
    Hashtable H;

    Inithashtable(&H);
    cout << "初始化后，打印的结果为：" << endl;
    Showhash(H);

    Createhash(H, a, HASHSIZE);
    cout << "初始化后，打印的结果为：" << endl;
    Showhash(H);

    int result = Searchhash(H, 67, &p);
    cout << "67的地址是：" << p;

    return 0;
}
