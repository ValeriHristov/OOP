#include <iostream>
#include "Grade.h"
#include "Student.h"

int main()
{
	Grade a("Subject with a long name!",5);
	Grade b;
	a.Print();
	b.Print();

	Student s1;
	Student s2(66666, "Babev", 10);

	s1.Print();
	s2.Print();
	return 0;
}