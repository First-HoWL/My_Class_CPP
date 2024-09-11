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
	char vibor, znak;
	int numb_2;
	while (true) {
		cout << "Choose action:\n";

		cout << "1. osincki\n";
		cout << "2. esli parnoe chislo x 3, esli net to / 2\n";
		cout << "3. kalkulator\n";
		cout << "0. Exit\n";
		cout << " >> ";

		cin >> vibor;

		if (vibor == '0') {
			break;
		}
		else if (vibor != '1', '2', '3') {
			cout << "\033[2J\033[1;1H";
			SetColor(4, 0);
			for (int n = 0; n < 10; n++) {
				cout << "ERORR!!!!!!\n";
				Sleep(1000);
			}
			SetColor(2, 0);
			break;
		}
		cout << "\033[2J\033[1;1H";
		float a, b, c, d, e;
		switch (vibor)
		{
		case '1':
			cout << "vvedit 5 osinok\n";
			cin >> a >> b >> c >> d >> e;
			cout << "\033[2J\033[1;1H";
			if ((a + b + c + d + e) / 5 >= 4) {
				cout <<(a + b + c + d + e) / 5 << ", dopychen \n\n";
			}
			else {
				cout <<(a + b + c + d + e) / 5 << "\n ne dopychen \n\n";
			}
			break;
		case '2':
			cout << "type the number: ";
			cin >> numb_2;
			if (numb_2 % 2 == 0) {
				cout << numb_2 * 3 << endl;
			}
			else
			{
				cout << numb_2 / 2 << endl;
			}
			break;
		case '3':
			int fir, sec;

			cout << "kalkulator \n";
			cout << "perche chislo: ";
			cin >> fir;

			cout << "dryge chislo: ";
			cin >> sec;

			cout << "znak: ";
			cin >> znak;
			cout << "\033[2J\033[1;1H";
			switch (znak)
			{
			case '+':
				cout << fir << " + " << sec << " = " << fir + sec << endl;
				break;

			case '-':
				cout << fir << " - " << sec << " = " << fir - sec << endl;
				break;

			case '*':
				cout << fir << " * " << sec << " = " << fir * sec << endl;
				break;

			case '/':
				cout << fir << " / " << sec << " = " << fir / sec << endl;
				break;
								
			default:
				break;
			}
			break;
		default:
			break;
		}

	}


	return 0;
}
