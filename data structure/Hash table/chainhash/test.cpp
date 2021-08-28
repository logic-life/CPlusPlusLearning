#include "chainhashtable.h"
#include <string.h>
#include <vector>

int main(int argc, char *argv[])
{
    vector<string> hash_vec = {"zhangsan", "lisi", "wangwu", "zhaoliu", "sunce", "lisanye"};
    HashTable hash_name;
    hash_name.hashTableInsert(1, hash_vec[1]);
    hash_name.hashTableInsert(2, hash_vec[2]);
    hash_name.hashTableInsert(12, hash_vec[3]);
    hash_name.hashTableInsert(22, hash_vec[4]);
    hash_name.hashTableInsert(3, hash_vec[5]);
    hash_name.hashTableInsert(4, hash_vec[0]);
    cout << hash_name.hashTableSearch(4)->value << endl;
    cout << hash_name.hashTableSearch(3)->value << endl;
    cout << hash_name.hashTableSearch(22)->value << endl;
    cout << "删除一个元素" << endl;
    cout << hash_name.hashTableDelete(22) << endl;
    if (hash_name.hashTableSearch(22) == nullptr)
        cout << "未查找到该元素" << endl;
    return 0;
}
