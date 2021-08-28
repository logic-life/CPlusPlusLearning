# emplace emplace_back emplace_front
**直接调用对象的构造函数，无需像insert、push_back()、push_front()一样调用拷贝构造函数生成临时对象，然后赋值，最后再析构，浪费内存资源**

# vector
**内存空间扩张时会调用拷贝构造函数，将原先的数据对象拷贝到新的内存空间中，然后再析构原先的数据空间**