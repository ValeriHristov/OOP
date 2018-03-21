#pragma once
#include "Grade.h"

class Student
{
private:
	int fn;
	char name[MAX_LENGTH];
	Grade* grades;
	unsigned int gradesCount;

public:
	Student();
	Student(int fn, const char* name,unsigned int gradesCount);
	~Student();

	void SetFn(int fn);
	void SetName(const char* name);

	int GetFn() const;
	const char* GetName() const;

	void Print() const;
};