#include "memory_forget_to_delete.h"
#include "memory_leak_second.h"

int main() {
	//��һ�����������voidָ���ͷ��ڴ�ʱ��������ڴ�й¶
	/*void *str1 = new memory_leak_first('a', 3);
	memory_leak_first  *str2 = new memory_leak_first('c', 3);
	delete str1;
	delete str2;*/
	//�ڶ�����������Ǹ��ͷ��ڴ�
	//set_new_handler(out_of_memory);
	//while (1) {
	//
	//	new int[1000];
	//
	//}
	//������������ͷ��ڴ治��ȫ
	Test* object1 = new Test[100];
	Test *object2 = new Test[100];
	delete[]object1;
	delete[]object2;
	system("pause");
	return 0;
}