#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip> 
using namespace std;

struct Point {
	double x, y;
};

struct date {
	int d, m, y;

	bool isCorrect()
	{
		if (m < 1 || m > 12)
			return false;
		if (d < 1 || d > getDaysInMonth())
			return false;
		if (y < 0)
			return false;

		return true;
	}

	int days() {
		int years_in_days = y * 365;
		for (int i = 0; i <= y; i++)
			if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)
				years_in_days++;

		int mounth_in_days = 0;
		for (int i = 0; i < m; i++) {
			mounth_in_days += getDaysInMonth(i, y);
		}
		return years_in_days + mounth_in_days + d;
	}

	bool isLeapYear()
	{
		return isLeapYear(y);
	}

	bool isLeapYear(int _year)
	{
		return _year % 400 == 0 || _year % 4 == 0 && _year % 100 != 0;
	}

	int getDaysInMonth()
	{
		return getDaysInMonth(m, y);
	}

	int getDaysInMonth(int _month, int year)
	{
		switch (_month)
		{
		case 1: return 31;
		case 2: return isLeapYear(year) ? 29 : 28;
		case 3: return 31;
		case 4: return 30;
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
		default: return 0;
		}
	}

	void print_date()
	{
		cout << (d < 10 ? "0" : "") << d << "." << (m < 10 ? "0" : "") << m << "." << y;
	}
};

struct Time
{
	int h, m, s;

	bool is_correct() {
		if (h < 0 || h > 23)
			return false;
		if (m < 0 || m > 59)
			return false;
		if (s < 0 || s > 59)
			return false;
		return true;
	}

	Time riznica_vremeni(Time b) {
		int secconds = (b.seconds() - seconds());
		Time new_time;

		new_time.h = secconds / 3600;
		new_time.m = (secconds % 3600) / 60;
		new_time.s = (secconds % 3600) % 60;

		return new_time;
	}
	int seconds() {
		return (((h * 60) + m) * 60) + s;
	}

};

void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
}

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

void GoToXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, coord);
}

void coutField(char field[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << field[i][j] << " | ";
		cout << "\b\b ";
		if (i != 2)
			cout << "\n---------\n";
	}
}

void coutField(char field[3][3], int y1, int x1, int y2, int x2, int y3, int x3) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == y1 && j == x1 || i == y2 && j == x2 || i == y3 && j == x3) {
				SetColor(2, 0);
				cout << field[i][j];
				SetColor(7, 0);
				cout << " | ";
			}
			else
				cout << field[i][j] << " | ";
		}
		cout << "\b\b ";
		if (i != 2)
			cout << "\n---------\n";
	}
}

bool makeMove(char field[3][3], int x, int y, char player) {
	if ((x > 0 && x < 4) && (y > 0 && y < 4) && field[y - 1][x - 1] == ' ') {
		field[y - 1][x - 1] = player;
		return true;
	}
	return false;
}

bool isWin(char field[3][3], char player) {
	if (field[0][0] == player && field[1][1] == player && field[2][2] == player) {
		coutField(field, 0, 0, 1, 1, 2, 2);
		return true;
	}

	if (field[0][0] == player && field[1][0] == player && field[2][0] == player) {
		coutField(field, 0, 0, 1, 0, 2, 0);
		return true;
	}
	if (field[0][0] == player && field[0][1] == player && field[0][2] == player) {
		coutField(field, 0, 0, 0, 1, 0, 2);
		return true;
	}
	if (field[2][0] == player && field[1][1] == player && field[0][2] == player) {
		coutField(field, 2, 0, 1, 1, 0, 2);
		return true;
	}
	if (field[2][0] == player && field[2][1] == player && field[2][2] == player) {
		coutField(field, 2, 0, 2, 1, 2, 2);
		return true;
	}
	if (field[0][2] == player && field[1][2] == player && field[2][2] == player) {
		coutField(field, 0, 2, 1, 2, 2, 2);
		return true;
	}
	if (field[1][0] == player && field[1][1] == player && field[1][2] == player) {
		coutField(field, 1, 0, 1, 1, 1, 2);
		return true;
	}
	if (field[0][1] == player && field[1][1] == player && field[2][1] == player) {
		coutField(field, 0, 1, 1, 1, 2, 1);
		return true;
	}
	return false;
}

bool isDraw(char field[3][3]) {
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (field[j][i] == ' ')
				return false;
	return true;
}

int main()
{
	srand(time(0));
	const char FILE_PATH[] = "numbers.txt";
	/*
	FILE* file;
	char message[80];
	cout << "Enter message: ";
	cin >> message;
	fopen_s(&file, "file.txt", "wb");
	fwrite(message, sizeof(char) * strlen(message), 1, file);
	fwrite("\n", 1, 1, file);

	fclose(file);
	*/


	FILE* file;
	fopen_s(&file, FILE_PATH, "wb");
	int numb[] = { 1, 2, 5, 123, 10 };
	fwrite(&numb, sizeof(numb), 1, file);
	fclose(file);


	fopen_s(&file, FILE_PATH, "rb");
	int number;

	while (fread(&number, sizeof(int), 1, file))
	{
		cout << number << " ";
	}

	fclose(file);

	return 0;
}
