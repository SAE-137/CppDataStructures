// CppDataStructures.cpp: определяет точку входа для приложения.
//

#include "CppDataStructures.h"



int main() {
	ForwardList<int> list;

	for (int i = 0; i < 10; ++i) {
		list.pushBack(i);
	}
	std::cout << list.size();
}
