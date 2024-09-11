#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
}

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int main()
{
	SetColor(2, 0);
	int a, b, c;
	while (true)
	{
		cout << "Choose action:\n";

		cout << "1. osincki\n";
		cout << "2. esli parnoe chislo x 3, esli net to / 2\n";
		cout << "3. kalkulator\n";

		cout << "\033[2J\033[1;1H";
	}
	

	return 0;
}
