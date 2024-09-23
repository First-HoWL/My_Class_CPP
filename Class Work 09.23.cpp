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

void pryamokyt(int h, int len) {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < len; j++)
			cout << "#";

		cout << '\n';
	}
}

void bubble_sort(int array[], const int len) {
	bool is_changed = true;
	int a;
	for (int n = 0; n < len - 1; n++)
	{
		is_changed = false;
		for (int i = 0; i < len - n - 1; i++) {
			if (array[i] < array[i + 1]) {
				swap(array[i], array[i + 1]);
				is_changed = true;
			}
		}
		if (is_changed == false)
		{
			break;
		}
	}
}

void cout_masiv(int array[], const int len) {
	cout << "masiv polnosty:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << i + 1 << ". " << array[i];
		cout << "\n";
	}
}

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int factorial(int chislo) {
	int a = 1;
	for (int i = 1; i < chislo + 1; i++) {
		a = a * i;
	}
	return a;
}

bool proste_chislo(int a) {
	for (int i = 2; i < a - 1; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	srand(time(NULL));

	int k;
	cout << "Chislo: ";
	cin >> k;
	for (int i = 1; i < 10 + 1; i++) {
		cout << k << " x " << i << " = " << k * i << endl;
	}

		/*

	char choosed;
	cout << "Menu:\n";
	cout << "Choose option: \n1. Pryamokytnik \n2. Faktorial \n3. Chi proste chislo?" << endl;
	cin >> choosed;

	system("cls");
	switch (choosed)
	{
	case'1':{
		int h = 0;
		int len = 0;

		cout << "Visota i shirena:" << endl;

		SetColor(2, 0);
		cin >> h >> len;
		SetColor(7, 0);
		pryamokyt(h, len);
		break;
	}
	case'2': {
		int faktorial1 = 0;
		cout << "faktorial chila:" << endl;

		SetColor(2, 0);
		cin >> faktorial1;
		SetColor(7, 0);
		cout << factorial(faktorial1);
		break;
	}
	case'3': {
		int a, b;
		cout << "vache chislo: ";
		SetColor(2, 0);
		cin >> a;
		SetColor(7, 0);
		b = proste_chislo(a);
		if (b == false) {
			cout << "Chislo ne proste \n";
		}
		else {
			cout << "Chislo proste\n";
		}
		break;
	}
	default:
		break;
	}
	*/

	return 0;
}
