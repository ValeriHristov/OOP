#pragma once

class String
{
private:
	char* str;
	int length;
	int len(char * str) const;
	void setStr(char * str);
	void setLength(int length);
public:
	String(char * str);

	String();

	String(const String& str);

	~String();

	String& operator=(const String& b);

	String operator+(String b);

	char * getStr() const;

	int getLength() const;
};