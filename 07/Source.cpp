#include "String.h"
#include <iostream>

int main() {
	String a("Working string?\n");
	String b(a);
	//std::cout << a.getStr() << b.getStr();
	String c = a + b;
	//std::cout << c.getStr();
	c = a + "Yeah, it's a magical string!\n";
	std::cout << c.getStr();
}