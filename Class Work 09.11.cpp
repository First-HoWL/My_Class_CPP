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
	a = (randint(10, 25));

	for (int i = 0; i < 1000000; i++) {
		cout << randint(1, 1000000);
		if (i % a == 0){
			cout << "\n";
			a = (randint(15, 30));
		}
	}
	

	return 0;
}
