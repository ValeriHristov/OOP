
#include "String.h"

String::String(char * str) :str(nullptr) {
	this->setStr(str);
	this->setLength(this->len(str));
}

String::String() : str(nullptr) {
	this->setLength(0);
}

String::String(const String & str) : str(nullptr)
{
	this->setLength(str.getLength());
	this->setStr(str.getStr());
}

String::~String() {
	delete[] this->str;
}

String String::operator+(String b) {
	int totalLength = this->length + b.getLength();


	char * summedArray = new char[totalLength + 1];

	for (int i = 0; i < this->length; i++) {
		summedArray[i] = this->str[i];
	}

	for (int i = this->length; i < totalLength; i++) {
		summedArray[i] = b.getStr()[i - length];
	}

	summedArray[totalLength] = '\0';
	String result(summedArray);
	delete[] summedArray;
	return  result;

}

String& String::operator=(const String& b) {
	this->setStr(b.getStr());
	this->setLength(b.getLength());

	return *this;
}

char * String::getStr() const {
	return str;
}

int String::getLength() const {
	return length;
}

int String::len(char * str) const {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

void String::setStr(char * str) {
	delete[] this->str;

	int l = this->len(str);
	this->str = new char[l + 1];

	for (int i = 0; i < l; i++) {
		this->str[i] = str[i];
	}
	this->str[l] = '\0';
}

void String::setLength(int length) {
	this->length = length;
}

