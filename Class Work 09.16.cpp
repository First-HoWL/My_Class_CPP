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

int main()
{
	srand(time(NULL));
	
	const int len = 10;
	int array[len], choose_numb, new_numb;
	char choose;
	float stipendia, sum = 0;

	for (int i = 0; i < len; i++) {
		array[i] = randint(1, 12);
	}
	
	while (true)
	{
		cout << "Menu: \n1. Vivid osinok \n2. Izmenit osinky \n3. Stipendia \n0.Exit" << endl;
		cin >> choose;

		system("cls");

		if (choose == '0') {
			break;
		}
		else if (choose == '1') {
			cout_masiv(array, len);
		}
		else if (choose == '2') {
			cout << "What num you want to choose" << endl;
			cin >> choose_numb;
			cout << "What num you want to type" << endl;
			cin >> new_numb;
			array[choose_numb - 1] = new_numb;
		}
		else if (choose == '3') {
			for (int i = 0; i < len; i++) {
				sum += array[i];
			}
			stipendia = sum / len;
			cout << "Stipendia: " << stipendia << endl;
			if (stipendia >= 10.7) {
				cout << "stipendii bit" << endl;
			}
			else {
				cout << "stipendii ne bit" << endl;
			}
			sum = 0;
		}
		

	}

	


	


	/*
	SetColor(2, 0);
	system("cls");
	 */
	

	return 0;
}
