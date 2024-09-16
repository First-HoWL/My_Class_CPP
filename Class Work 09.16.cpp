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

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int main()
{
	srand(time(NULL));
	
	const int len = 10;
	int array[len];
	

	for (int i = 0; i < len; i++) {
		array[i] = randint(1, 100);
	}
	
	cout << "masiv polnosty:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << array[i];
		if (i != len - 1) {
			cout << ", ";
		}
	}

	cout << "\ntolko parni:" << endl;
	for (int i = 0; i < len; i++)
	{
		if (array[i] % 2 == 0) {
			cout << array[i] << ", ";
		}
	}

	cout << "\nsorted:" << endl;
	bubble_sort(array, len);

	for (int i = 0; i < len; i++)
	{
		cout << array[i];
		if (i != len - 1) {
			cout << ", ";
		}
	}
	

	


	/*
	SetColor(2, 0);
	system("cls");
	 */
	

	return 0;
}
