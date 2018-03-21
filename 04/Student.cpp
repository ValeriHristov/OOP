#include <iostream>

#include "Student.h"

Student::Student() : fn(0), grades(nullptr), gradesCount(0)
{
	this->SetName("no name");
}

Student::Student(int fn, const char* name, unsigned int gradesCount)
{
	this->SetFn(fn);
	this->SetName(name);
	if (gradesCount > 0)
	{
		this->gradesCount = gradesCount;
		this->grades = new Grade[gradesCount];
	}
}

Student::~Student()
{
	delete[] this->grades;
}

void Student::SetFn(int fn)
{
	if (fn < 0)
	{
		std::cout << "Invalid fn!\n";
		this->fn = 0;
		return;
	}
	this->fn = fn;
}

void Student::SetName(const char* name)
{
	int i = 0;
	while (name[i] != 0 && i < MAX_LENGTH - 1)
	{
		this->name[i] = name[i];
		i++;
	}
	this->name[i] = 0;
}

int Student::GetFn() const
{
	return this->fn;
}

const char* Student::GetName() const
{
	return this->name;
}

void Student::Print() const
{
	std::cout << this->GetName() << " " << this->GetFn() << "\n";
}
