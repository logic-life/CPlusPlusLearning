#pragma once
#include <iostream>

using namespace std;

class memory_leak_first {
private:
	void *point;
	int size;
	char name;
public:
	memory_leak_first(char a,int c):name(a),size(c) { 
		point = new char[size];
		cout << "name" << name << "size=" << size << endl;
	};
	~memory_leak_first()
	{
		delete [] point;
		cout << "name" << name << "size=" << size << endl;
	}
};