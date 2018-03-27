#pragma once

#include "Grade.h"

class Student
{
private:
	int fn;
	char name[MAX_LENGTH];
	Grade* grades;
	unsigned int maxGrades;
	unsigned int gradesCount;

public:
	Student();
	Student(int fn, const char* name, unsigned int maxGrades);
	~Student();

	void SetFn(int fn);
	void SetName(const char* name);

	int GetFn() const;
	const char* GetName() const;

	void AddGrades(Grade g);
	double GetAverage() const;
	double GetAverage(const char* subject);


	void Print() const;
};

