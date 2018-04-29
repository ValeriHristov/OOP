#pragma once
#include <fstream>

class Building
{
public:
	Building();
	Building(int height, double area, const char* address);
	Building(const Building&);
	Building& operator=(const Building&);
	~Building();

	int getHeight() const;
	double getArea() const;
	const char* getAddress() const;

	void setHeight(int height);
	void setArea(double area);
	void setAddress(const char* address);
private:
	void copyBuilding(const Building&);
	void clearBuilding();
private:
	int height;
	double area;
	char* address;
};

std::ostream& operator<<(std::ostream& os, const Building&);