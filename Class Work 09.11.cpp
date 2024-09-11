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
	int vibor, numb_2;
	while (true)	
	{
		cout << "Choose action:\n";

		cout << "1. osincki\n";
		cout << "2. esli parnoe chislo x 3, esli net to / 2\n";
		cout << "3. kalkulator\n";
		cout << "0. Exit\n";

		cin >> vibor;

		if (vibor == 0) {
			break;
		}

		float a, b, c, d, e;
		switch (vibor)
		{
		case('1'):
			cout << "vvedit 5 osinok\n";
			cin >> a >> b >> c >> d >> e;
			if ((a + b + c + d + e) / 5 >= 4) {
				cout << (a + b + c + d + e) / 5 << "\n dopychen";
			}
			else{
				cout << (a + b + c + d + e) / 5 << "\n ne dopychen";
			}
			break;
		case('2'):
			cout << "type the number";
			cin >> numb_2;
			if (numb_2 % 2 == 0) {
				cout << numb_2 * 3 << endl;
			}
			else
			{
				cout << numb_2 / 2 << endl;
			}
			break;
		case('3'):
			cout << "kalkulator";
			break;
		default:
			break;
		}



		cout << "\033[2J\033[1;1H";
	}


	return 0;
}
