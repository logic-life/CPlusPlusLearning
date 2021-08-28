# cin
**cin 对空格、换行符(\n)敏感,cin>>等价于cin.operator>>(),调用成员函数operator>>()进行数据读取。**

**cin从缓存区读取数据时，若缓冲区中的第一个字符是空格、tab或换行这些分割符，cin>>会将其忽略，继续读取下一个字符，若缓冲区为空，则继续等待。但是如果读取成功，字符后面的分隔符是残留在缓冲区，cin>>不做处理。**

**使用noskipws流控制不略过空白字符**
```
cin>>noskipws>>input;
```
**cin状态符**
```
goodbit:无错误
eofbit:已到达文件尾
failbit:非致命的输入/输出错误，可挽回
badbit:致命的输入/输出错误,无法挽回
s.eof()：若流s的eofbit置位，则返回true；
s.fail()：若流s的failbit置位，则返回true；
s.bad()：若流s的badbit置位，则返回true；
s.good()：若流s的goodbit置位，则返回true；
s.clear(flags)：清空状态标志位，并将给定的标志位flags置为1，返回void。
s.setstate(flags)：根据给定的flags条件状态标志位，将流s中对应的条件状态位置为1，返回void。
s.rdstate()：返回流s的当前条件状态，返回值类型为strm::iostate。strm::iostate 机器相关的整形名,由各个iostream类定义,用于定义条件状态。

    char ch, str[20];
    cin.getline(str, 5);
    cout << "flag1:" << cin.good() << endl; // 查看goodbit状态，即是否有异常
    cin.clear();                            // 清除错误标志
    cout << "flag1:" << cin.good() << endl; // 清除标志后再查看异常状态
    cin >> ch;
    cout << "str:" << str << endl;
    cout << "ch :" << ch << endl;
```

# cin.get的用法
```
int cin.get();
istream& cin.get(char& var);
istream& get ( char* s, streamsize n );
istream& get ( char* s,  streamsize  n, char delim )
```
```
    char a;
    char b;
    a=cin.get();
    cin.get(b);
    cout<<a<<b<<endl;
```
**cin.get()的返回值是int类型，成功：读取字符的ASCII码值，遇到文件结束符时，返回EOF，即-1，Windows下标准输入输入文件结束符为Ctrl+z，Linux为Ctrl+d。cin.get(char var)如果成功返回的是cin对象，因此可以支持链式操作，如cin.get(b).get(c)。**

**读取一行可以使用istream& get ( char* s, streamsize n )或者istream& get ( char* s, size_t n, streamsize delim )。二者的区别是前者默认以换行符结束，后者可指定结束符。n表示目标空间的大小**

```
#include <iostream>
using namespace std;

int main()
{
    char a;
    char array[20]={NULL}; 
    cin.get(array,20);
    cin.get(a);
    cout<<array<<" "<<(int)a<<endl;
    system("pause");
    return 0;
}
```

# getline()
**读取数据时，并非像cin一样忽略第一个换行符，getline()会将残存的换行符，在不阻塞请求键盘输入的条件下，直接读取，送入目标字符串，后将换行符替换为'\n'。因此test为空串！**
```
istream& getline(char* s, streamsize count); //默认以换行符结束
istream& getline(char* s, streamsize count, char delim);
```
```
char a;
    int b;
    float c;
    string str;
    cin >> a >> b >> c >> str;
    cout << a << " " << b << " " << c << " " << str << endl;

    string test;
    getline(cin, test); //不阻塞
    cout << "test:" << test << endl;
```

