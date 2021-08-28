#include "memory_forget_to_delete.h"
#include "memory_leak_second.h"

int main() {
	//第一种情况，当给void指针释放内存时，会造成内存泄露
	/*void *str1 = new memory_leak_first('a', 3);
	memory_leak_first  *str2 = new memory_leak_first('c', 3);
	delete str1;
	delete str2;*/
	//第二种情况，忘记给释放内存
	//set_new_handler(out_of_memory);
	//while (1) {
	//
	//	new int[1000];
	//
	//}
	//第三种情况，释放内存不完全
	Test* object1 = new Test[100];
	Test *object2 = new Test[100];
	delete[]object1;
	delete[]object2;
	system("pause");
	return 0;
}