#include "Building.h"
#include <iostream>
#include <cstring>

Building::Building() : height(0), area(0.0), address(nullptr)
{
	std::cout << "Building default constructor!!\n";
}

Building::Building(int height, double area, const char * address) : address(nullptr)
{
	std::cout << "Building constructor with parameters !!\n";
	this->setHeight(height);
	this->setArea(area);
	this->setAddress(address);
}

Building::Building(const Building& other): address(nullptr)
{
	std::cout << "Building  copy constructor!!\n";
	this->copyBuilding(other);
}

Building & Building::operator=(const Building& rhs)
{
	if (this != &rhs)
	{
		this->clearBuilding();
		this->copyBuilding(rhs);
	}

	return *this;
}

Building::~Building()
{
	this->clearBuilding();
}

int Building::getHeight() const
{
	return this->height;
}

double Building::getArea() const
{
	return this->area;
}

const char * Building::getAddress() const
{
	if (this->address == nullptr)
	{
		return "No address!\n";
	}
	return this->address;
}

void Building::setHeight(int height)
{
	this->height = height;
}

void Building::setArea(double area)
{
	this->area = area;
}

void Building::setAddress(const char * address)
{
	delete[] this->address;
	if (address == nullptr)
	{
		this->address = nullptr;
		return;
	}
	int length = strlen(address);
	this->address = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->address[i] = address[i];
	}
	this->address[length] = '\0';
}

void Building::copyBuilding(const Building& other)
{
	this->setHeight(other.height);
	this->setArea(other.area);
	this->setAddress(other.address);
}

void Building::clearBuilding()
{
	delete[] this->address;
	this->address = nullptr;
}

std::ostream & operator<<(std::ostream & os, const Building& building)
{
	os << "Height:  " << building.getHeight() << "\n"
		<< "Area: " << building.getArea() << "\n"
		<< "Address: " << building.getAddress() << "\n";

	return os;
}
