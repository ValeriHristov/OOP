#pragma once
#include "Building.h"

class House : public Building
{
public:
	House();
	House(int height, double area, const char * address, int storeys, const char* ownerName);
	House(const House&);
	House& operator=(const House&);
	~House();

	int getStoreys() const;
	const char* getOwnerName() const;

	void setStoreys(int storeys);
	void setOwnerName(const char* ownerName);

	void print() const;
private:
	int storeys;
	char* ownerName;
};

std::ostream& operator<<(std::ostream& os, const House&);