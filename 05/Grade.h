#pragma once
const int MAX_LENGTH = 15;
class Grade
{
private:
	char subject[MAX_LENGTH];
	int value;
public:
	Grade();
	Grade(const char* subject, int value);
	Grade(const Grade& other);
	void SetValue(int value);
	void SetSubject(const char* subject);

	int GetValue() const;
	const char* GetSubject() const;

	void Print() const;

};
