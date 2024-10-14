#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
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

void cout_matrix(int** array, int rows, int coll) {
	for (int row = 0; row < rows; row++) {
		for (int collumns = 0; collumns < coll; collumns++)
			cout << array[row][collumns] << "\t";
		cout << endl;
	}
}

void fill_matrix(int** array, int rows, int coll) {
	for (int row = 0; row < rows; row++)
		for (int collumns = 0; collumns < coll; collumns++)
			array[row][collumns] = randint(-50, 50);
}

void transponyvannya_matrix(int** array, int rows, int coll) {
	for (int j = 0; j < rows; j++) {
		for (int i = j; i < coll; i++) {
			swap(array[j][i], array[i][j]);
		}
	}
}

void cout_masiv(int array[], int len) {
	for (int i = 0; i < len; i++)
		cout << array[i] << ", ";
		cout << "\n";
}
void GoToXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, coord);
}

int min_array(int array[], int len, int from) {
	int a = 100000, b;
	for (int i = from; i < len; i++) {
		if (array[i] < a){
			a = array[i];
			b = i;
		}
	}
	return b;
}

void sort(int array[], int len) {
	for (int i = 0; i < len; i++) {
		swap(array[i], array[min_array(array, len, i)]);
	}
}

int main()
{
	srand(time(0));

	int array[10];
	int len = 10;
	for (int i = 0; i < len; i++)
		array[i] = randint(-10, 10);

	cout_masiv(array, len);
	sort(array, len);
	cout_masiv(array, len);

	return 0;

	/*
	int rows = 10, coll = 10;
	int** array = new int* [rows];

	for (int i = 0; i < rows; i++)
		array[i] = new int[coll];


	fill_matrix(array, rows, coll);

	cout_matrix(array, rows, coll);
	cout << endl;

	transponyvannya_matrix(array, rows, coll);

	cout_matrix(array, rows, coll);
	cout << endl;



	for (int i = 0; i < rows; i++)
		delete[] array[i];
	delete[] array;
	return 0;
	*/
}
