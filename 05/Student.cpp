#include <iostream>

#include "Student.h"

bool Compare(const char* s1, const char* s2)
{
	if (strlen(s1) != strlen(s2))
	{
		return false;
	}
	int i = 0;
	while (s1[i] != 0)
	{
		if (s1[i] != s2[i])
		{
			return false;
		}
		i++;
	}
	return true;
}

Student::Student() : fn(0), grades(nullptr), maxGrades(0), gradesCount(0)
{
	this->SetName("no name");
}

Student::Student(int fn, const char* name, unsigned int maxGrades)
{
	this->SetFn(fn);
	this->SetName(name);
	this->gradesCount = 0;
	if (maxGrades > 0)
	{
		this->maxGrades = maxGrades;
		this->grades = new Grade[maxGrades];
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

void Student::AddGrades(Grade g)
{
	if (gradesCount >= maxGrades) {
		std::cout << "Grades are maximal! / Error!" << std::endl;
		return;
	}
	else {
		grades[gradesCount] = g;
		gradesCount++;
	}
}

double Student::GetAverage() const
{
	double sum = 0;
	for (int i = 0; i < gradesCount; i++) {
		sum += grades[i].GetValue();
	}
	sum /= gradesCount;
	return sum;
}

double Student::GetAverage(const char * subject)
{
	int j = 0;
	int countSubj = 0;
	double sum = 0;
	for (int i = 0; i < gradesCount; i++)
	{
		const char* p = grades[i].GetSubject();
		if (Compare(p, subject))
		{
			sum += grades[i].GetValue();
			countSubj++;
		}
	}
	sum /= countSubj;
	return sum;
}

void Student::Print() const
{
	std::cout << this->GetName() << " " << this->GetFn() << "\n";
}