/*单链表的结点定义*/
template <class T>
struct LinkNode
{
    T data;
    LinkNode<T> *next;
    LinkNode(LinkNode<T> *ptr = nullptr) next(ptr) {}
    LinkNode(const T &item, LinkNode<T> *ptr = nullptr) data(item), next(ptr) {}
};

/*带头结点的单链表定义*/
template <class T>
class LinkList
{
public:
    // 无参数的构造函数
    LinkList() head(new LinkNode<T>) {}
    // 带参数的构造函数
    LinkList(const T &item)(new LinkNode<T>(item)) {}
    // 拷贝构造函数
    LinkList(const LinkList<T> &list);
    // 析构函数
    ~LinkeList(){clear()};
    // 拷贝赋值运算
    LinkList<T> &operator=(const LinkList<T> &list);
    // 链表清空,保留头结点
    void clear();
    // 获取链表长度
    int length() const;
    // 获取链表头结点
    LinkNode<T> *getHead() const;
    //设置链表头结点
    void setHead(LinkNode<T> *p);
    // 查找数据的位置，返回第一个等于该数据的结点指针
    LinkNode<T> *find(T &item);
    // 返回指定位置的指针
    LinkNode<T> *locate(int pos);
    // 在指定位置pos之后插入item的结点，失败返回false
    bool insert(T &item, int pos);
    // 删除指定位置pos的结点，失败返回false,item对应删除结点的值
    bool remove(T &item, int pos);
    // 返回指定位置pos的值，失败返回false
    bool getData(T &item, int pos);
    // 设置指定位置pos的值,失败返回false
    bool setData(T &item, int pos);
    // 判断链表是否为空
    bool isEmpty() const;
    // 打印链表
    void print() const;
    // 链表排序
    void sort();
    // 链表逆转
    void reverse();

private:
    LinkNode<T> *head;
};

// 返回链表中的第pos号元素的地址，超出链表范围则返回NULL
template <class T>
LinkNode<T> *LinkList<T>::locate(int pos)
{
    // 头结点的存在相当于数组中的第0号元素
    LinkNode<T> *p = this->head;
    // 计数
    int count = 0;
    // 查找的元素不在链表的长度范围内
    if (pos < 0)
        return nullptr;
    while (p != nullptr && count < pos)
    {
        p = p->next;
        count++;
    }
    return p;
}

template <class T>
bool LinkList<T>::insert(T &item, int pos)
{
    LinkNode<T> *p = locate(pos);
    if (p == nullptr)
        return false;
    LinkList<T> *node = new LinkNode<T>(item);
    if (node == nullptr)
        throw string("内存分配失败");
    node->next = p->next;
    p->next = node;
    return true;
}

template <class T>
bool LinkList<T>::remove(T &item, int pos)
{
    // 先找到待删除结点的提前一个结点
    LinkNode<T> *p = locate(pos - 1);
    // 删除的结点不存在，则删除失败
    if (p == nullptr || p->next == nullptr)
        return false;
    LinkNode<T> *del = p->next;
    p->next = del->next;
    item = del->data;
    delete del;
}

template <class T>
void LinkList<T>::clear()
{
    LinkNode<T> *p = nullptr;
    // 遍历链表，依次删除头结点后面的结点，并将头结点指向下一个结点
    while (head->next != nullptr)
    {
        p = head->next;
        head->next = p->next;
        delete p;
    }
}

template <class T>
void LinkList<T>::print() const
{
    // 该函数不会改变成员变量的值,添加const
    int count = 0;
    LinkNode<T> *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
        std::cout << p->data << " ";
        if (++count % 10 == 0)
            std::cout << std::endl;
    }
}

template <class T>
int LinkList<T>::length() const
{
    // 该函数不会改变成员变量的值,添加const
    int count = 0;
    LinkNode<T> *p = head->next;
    while (p != nullptr)
    {
        p = p->next;
        count++;
    }
    return count;
}

template <class T>
void LinkList<T>::reverse()
{
    // 创建三个结点pre，cur,next保存前结点当前结点以及后一个结点
    LinkNode<T> *pre = head->next;
    LinkNode<T> *cur = pre->next;
    LinkNode<T> *next = nullptr;
    // 将第一个结点的next置为nullptr
    pre->next = nullptr;
    while (cur)
    {
        // 先保存下一个结点
        next = cur->next;
        // 将当前结点的指针指向上一个结点
        cur->next = pre;
        // 将结点依次下移
        pre = cur;
        cur = next;
    }
    // 最后将头结点指向最后
    head->next = pre;
}