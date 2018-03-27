#include <iostream>

#include "Grade.h"
#include "Student.h"

int main()
{
	Grade a("Subject with a long name!", 5);
	Grade b;


	Student s1;
	Student s2(66666, "Babev", 10);

	Grade d("Dis", 6);
	Grade e("Algebra", 2);
	Grade f("Dis", 4);

	Student st(61978, "Valeri", 3);
	
	st.AddGrades(d);
	st.AddGrades(e);
	st.AddGrades(f);

	std::cout << st.GetAverage() << std::endl;
	std::cout << st.GetAverage("Dis") << std::endl;
	std::cout << st.GetAverage("Algebra") << std::endl;

	return 0;
}


