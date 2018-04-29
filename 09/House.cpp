#include "House.h"
#include <iostream>

House::House() : Building(), storeys(0), ownerName(nullptr)
{
	std::cout << "House default constructor!!\n";
}

House::House(int height, double area, const char * address, int storeys, const char * ownerName) :
	Building(height, area, address), ownerName(nullptr)
{
	std::cout << "House constructor with parameters!!\n";
	this->setStoreys(storeys);
	this->setOwnerName(ownerName);
}

House::House(const House& house) : Building(house), ownerName(nullptr)
{
	std::cout << "House copy constructor!!\n";
	this->setStoreys(house.storeys);
	this->setOwnerName(house.ownerName);
}

House & House::operator=(const House& rhs)
{
	if (this != &rhs)
	{
		Building::operator=(rhs);
		this->setStoreys(rhs.storeys);
		this->setOwnerName(rhs.ownerName);
	}

	return *this;
}

House::~House()
{
	delete[] this->ownerName;
}

int House::getStoreys() const
{
	return this->storeys;
}

const char * House::getOwnerName() const
{
	if (this->ownerName == nullptr)
	{
		return "No owner\n";
	}

	return this->ownerName;
}

void House::setStoreys(int storeys)
{
	this->storeys = storeys;
}

void House::setOwnerName(const char * ownerName)
{
	delete[] this->ownerName;
	if (ownerName == nullptr)
	{
		this->ownerName = nullptr;
		return;
	}
	int length = strlen(ownerName);
	this->ownerName = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->ownerName[i] = ownerName[i];
	}
	this->ownerName[length] = '\0';
}

void House::print() const
{
	std::cout << "Building: \n";
	std::cout 
		<< "Height:  " << this->getHeight() << "\n"
		<< "Area: " << this->getArea() << "\n"
		<< "Address: " << this->getAddress() << "\n";

	std::cout << "House: \n";
	std::cout 
		<< "Storeys count: " << this->getStoreys() << "\n"
		<< "Owner name: " << this->getOwnerName() << "\n";
}


std::ostream & operator<<(std::ostream & os, const House& house)
{
	// Wrong! dont do it at your house!!!
	// os << house
	//	<< "Storeys count: " << house.getStoreys()
	//	<< "Owner name: " << house.getOwnerName();
	return os;
}
