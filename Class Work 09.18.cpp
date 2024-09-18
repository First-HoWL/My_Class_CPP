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


	const int rows = 7, columns = 7;

	int array[rows][columns], choose_numb, new_numb;
	int min_massiv[rows], max_massiv[rows];
	char choose;
	float seredne, sum = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = randint(-20, 20);
		}

	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;

	}

	// #1
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			sum += array[i][j];
		}
	}

	// #2
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			sum += array[i][j];
		}
		seredne = sum / (rows * columns);

	}

	// #3
	for (int i = 0; i < rows; i++) {
		bubble_sort(array[i], columns);
		min_massiv[i] = array[i][columns - 1];
	}
	bubble_sort(min_massiv, rows);

	// #4
	for (int i = 0; i < rows; i++) {
		bubble_sort(array[i], columns);
		max_massiv[i] = array[i][0];
	}
	bubble_sort(max_massiv, rows);

	cout << "summa: " << sum << endl;
	cout << "seredne: " << seredne << endl;
	cout << "min: " << min_massiv[rows - 1] << endl;
	cout << "max: " << max_massiv[0] << endl;
	sum = 0;



	/*
	const int rows = 18, columns = 35;

	int array[rows][columns], choose_numb, new_numb;
	char choose;
	float stipendia, sum = 0;

	for (int i = 1; i < rows - 1; i++) {
		for (int j = 1; j < columns - 1; j++)
		{
			array[i][j] = randint(0, 2);
		}
		
	}
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j] == 0 || array[i][j] == 1) {
				cout << " ";
			}
			else {
				cout << "H";
			}
		}
		cout << endl;

	}
	*/

	/*
	SetColor(2, 0);
	system("cls");
	*/
	

	return 0;
}

