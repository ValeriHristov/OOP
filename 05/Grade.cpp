#include <iostream>

#include "Grade.h"

Grade::Grade() : value(0)
{
	this->SetSubject("no subject");
}

Grade::Grade(const char* subject, int value)
{
	this->SetSubject(subject);
	this->SetValue(value);
}

Grade::Grade(const Grade & other)
{
	this->SetSubject(other.GetSubject());
	this->SetValue(other.GetValue());
}

void Grade::SetValue(int value)
{
	if (value<2 || value>6)
	{
		std::cout << "Invalid grade!\n";
		this->value = 0;
		return;
	}
	this->value = value;
}

void Grade::SetSubject(const char* subject)
{
	int i = 0;
	while (subject[i] != 0 && i<MAX_LENGTH - 1)
	{
		this->subject[i] = subject[i];
		i++;
	}
	this->subject[i] = 0;
}

int Grade::GetValue() const
{
	return this->value;
}

const char* Grade::GetSubject() const
{
	return this->subject;
}

void Grade::Print() const
{
	std::cout << this->GetSubject() << " " << this->GetValue() << "\n";
}