#include <iostream>

#include "Grade.h"
#include "Student.h"
void clearConsole()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}
void print(bool* alive[], int n)
{
	clearConsole();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (alive[i][j])
			{
				std::cout << "#";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
}

void initialize(bool* alive[], int n)
{
	/*for (size_t i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			alive[i][j] = false;
		}
	}
	alive[0][0] = true;
	alive[1][1] = true;
	alive[1][2] = true;
	alive[0][2] = true;
	alive[2][1] = true;*/

	for (size_t i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num = rand();
			bool lives = num % 2;
			alive[i][j] = lives;
		}
	}
}

void create(bool**& alive, int size)
{
	alive = new bool*[size];
	for (int i = 0; i < size; i++)
	{
		alive[i] = new bool[size];
	}
}

void copy(bool** from, bool** to, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			to[i][j] = from[i][j];
		}
	}
}

int isAlive(bool** alive, int size, int i, int j)
{
	if (i >= 0 && i < size && j >= 0 && j < size)
	{
		if (alive[i][j])
		{
			return 1;
		}
	}
	return 0;
}

int getLivingNeighbours(bool** alive, int i, int j, int size)
{
	int counter = 0;
	counter += isAlive(alive, size, i - 1, j - 1);
	counter += isAlive(alive, size, i, j - 1);
	counter += isAlive(alive, size, i + 1, j - 1);
	counter += isAlive(alive, size, i - 1, j);
	counter += isAlive(alive, size, i + 1, j);
	counter += isAlive(alive, size, i - 1, j + 1);
	counter += isAlive(alive, size, i, j + 1);
	counter += isAlive(alive, size, i + 1, j + 1);
	return counter;
}



void run(bool**& alive, int size)
{
	bool** temp = nullptr;
	create(temp, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int neighbours = getLivingNeighbours(alive, i, j, size);
			bool isAlive = alive[i][j];
			if (isAlive)
			{
				if (neighbours < 2)
				{
					temp[i][j] = false;
				}
				else if (neighbours>3)
				{
					temp[i][j] = false;
				}
				else
				{
					temp[i][j] = true;
				}
			}
			else
			{
				if (neighbours == 3)
				{
					temp[i][j] = true;
				}
				else
				{
					temp[i][j] = false;
				}
			}
		}
	}
	alive = temp;

}
#include "C:\Users\valeri.h\Documents\Visual Studio 2015\Projects\OOP\OOP\Sorted.cpp"
int main()
{
	//Grade a("Subject with a long name!", 5);
	//Grade b;


	//Student s1;
	//Student s2(66666, "Babev", 10);

	//Grade d("Dis", 6);
	//Grade e("Algebra", 2);
	//Grade f("Dis", 4);

	//Student st(61978, "Valeri", 3);
	//
	//st.AddGrades(d);
	//st.AddGrades(e);
	//st.AddGrades(f);

	//std::cout << st.GetAverage() << std::endl;
	//std::cout << st.GetAverage("Dis") << std::endl;
	//std::cout << st.GetAverage("Algebra") << std::endl;


	return 0;
}


