#include <iostream>
#include <string.h>
#define HASHSIZE 10

using namespace std;
typedef unsigned int uint;
struct Node
{
    uint key;
    string value;
    Node *next;
    Node() : key(0), value(""), next(nullptr) {}
    Node(const uint x) : key(x), value(""), next(nullptr) {}
    Node(const uint x, const string str) : key(x), value(str), next(nullptr) {}
    Node(const uint x, const string str, Node *next) : key(x), value(str), next(next) {}
};

class HashTable
{
private:
    /* data */
    Node *node[HASHSIZE];

public:
    HashTable(/* args */);
    uint hashFunction(const uint key);
    bool hashTableInsert(const uint key, const string value);
    Node *hashTableSearch(const uint key);
    bool hashTableDelete(const uint key);
    ~HashTable();
};

//生成一个HASHSIZE大小的哈希表
HashTable::HashTable()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        node[i] = nullptr;
    }
}
//定义哈希函数：Time33定义方式
uint HashTable::hashFunction(uint key)
{
    uint hash_value = key % HASHSIZE;
    // for (; *key; key++)
    // {
    //     hash_value = hash_value * 33 + *key;
    // }

    return hash_value;
}
//哈希表查询操作
Node *HashTable::hashTableSearch(const uint key)
{

    uint index = hashFunction(key);
    Node *np = node[index];
    //如果表头为空，查询失败
    if (np == nullptr)
        return nullptr;
    {
        //如果对应的键值在表头，返回表头
        if (np->key == key)
            return np;
        else
        {
            //指针顺着表头遍历查询，直至表结束。
            for (; np->next; np = np->next)
            { //找到关键字相同的数
                if (key == (np->next->key))
                    //返回查找成功的地址
                    return np->next;
            }
            //未查找到对应的键值
            return nullptr;
        }
    }
}
//哈希表插入操作
bool HashTable::hashTableInsert(const uint key, const string value)
{
    uint index;
    Node *np;
    //判断np对应节点的哈希值槽是否为空，空就插入一个新值
    if (!(np = hashTableSearch(key)))
    { //为新生的节点申请内存，如果堆区没有剩余空间，就返回插入失败
        np = new Node(key, value);
        if (!np)
            return false;
        index = hashFunction(key);
        //判断表头是否为空
        if (node[index] == nullptr)
        {
            node[index] = np;
        }
        else
        { //表头不为空时，就使用头插法，将节点插入在头结点的下一个位置
            np->next = node[index]->next;
            node[index]->next = np;
        }
    }
    //返回插入成功
    return true;
}

//哈希表删除操作
bool HashTable::hashTableDelete(const uint key)
{
    Node *np;
    Node *pointer;
    //查找要删除的键值
    if (!(np = hashTableSearch(key)))
        //未找到,np为NULL时，返回操作失败
        return false;
    else
    { //删除元素为头结点
        if (np == node[hashFunction(key)])
        {
            node[hashFunction(key)] = node[hashFunction(key)]->next;
            delete np;
        }
        else
        { //待删除元素不为头结点
            for (pointer = node[hashFunction(key)]; pointer->next != np; pointer = pointer->next)
                ;
            pointer->next = np->next;
            delete np;
        }
        return true;
    }
}

HashTable::~HashTable()
{
    Node *pointer;
    Node *p;
    //遍历哈希表的表头
    for (int i = 0; i < HASHSIZE; i++)
    { //遍历哈希表表头指向的链表
        for (pointer = node[i]; pointer;)
        {
            p = pointer;
            //指向下一个节点
            pointer = pointer->next;
            //释放当前节点的内存
            delete p;
        }
    }
}
