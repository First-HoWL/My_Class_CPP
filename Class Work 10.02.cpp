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

void cout_masiv(int array[], int len, int a, int b) {
	for (int i = 0; i < len; i++)
	{
		if (i == a || i == b) {
			SetColor(5, 0);
			cout << array[i];
			SetColor(7, 0);
			cout << ", ";
		}
		else if (i > a && i < b) {
			SetColor(2, 0);
			cout << array[i];
			SetColor(7, 0);
			cout << ", ";
		}
		else {
			cout << array[i] << ", ";
		}

	}
	cout << "\b\b." << endl;
}

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

float seredne_arefmetichne(int array[], int len) {
	float seredne = 0;
	for (int i = 0; i < len; i++) {
		seredne += array[i];
	}
	seredne = seredne / len;
	return seredne;
}

int minimum(int array[], int len) {
	int min = 10000, min_mis = 0;
	for (int i = 0; i < len; i++) {
		if (array[i] < min) {
			min = array[i];
			min_mis = i;
		}
	}
	return min_mis;
}

int maximum(int array[], int len) {
	int max = 0, max_mis = 0;
	for (int i = 0; i < len; i++) {
		if (array[i] > max) {
			max = array[i];
			max_mis = i;
		}
	}
	return max_mis;
}


int main()
{
	srand(time(0));
	int size1 = 0, num_f_0 = -1, num_s_0 = -1;
	float sum = 0, avg = 0;
	char vibor;
	bool stop = false;

	cout << "Misyaciv: ";
	cin >> size1;

	int* array1 = new int[size1];

	for (int i = 0; i < size1; i++) {
		array1[i] = randint(200, 1000);
	}

	while (true) {

		for (int i = 0; i < size1; i++) {
			cout << array1[i] << "$\t";
		}
		cout << "\b\b\n";
		cout << "min: " << array1[minimum(array1, size1)] << "$\t";
		cout << "max: " << array1[maximum(array1, size1)] << "$\t";
		cout << "avg: " << seredne_arefmetichne(array1, size1) << "$\n";

		cout << "\n -1. Zaverchit roboty";
		cout << "\n -2. Dodaty misyac\n >>";
		cin >> vibor;

		switch (vibor)
		{
		case'1': {
			stop = true;
			break;
		}
		case'2': {
			size1++;
			cout << "Vvedite novii mesyzc\n >>";
			cin >> array1[size1 - 1];
			break;
		}
		default:
			break;
		}
		if (stop == true) {
			break;
		}
	}
	

	delete[] array1;
	return 0;
}
