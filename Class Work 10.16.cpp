#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Point {
	double x, y;
};

struct date {
	int y, m, d;
};

void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
}

void cout_masiv(char array[10][21]) {
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << endl;
	}
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

bool is_can_move(char maze[10][21], int size, int x, int y) {
	if (x < 0 || x >= size)
		return false;
	if (maze[y][x] != '.' && maze[y][x] != 'e')
		return false;
	return true;
}

bool pass_maze(char maze[10][21], int size, int x, int y) {
	if (maze[y][x] == 'e')
		return true;

	maze[y][x] = '1';
	if (is_can_move(maze, size, x, y + 1) && pass_maze(maze, size, x, y + 1))
		return true;

	if (is_can_move(maze, size, x + 1, y) && pass_maze(maze, size, x + 1, y))
		return true;

	if (is_can_move(maze, size, x, y - 1) && pass_maze(maze, size, x, y - 1))
		return true;

	if (is_can_move(maze, size, x - 1, y) && pass_maze(maze, size, x - 1, y))
		return true;

	maze[y][x] = 'X';
	return false;
}

double distance(Point a, Point b) {
	return pow(pow(b.x - a.x, 2) + pow(b.y - a.y, 2), 0.5);
}

double distance(double x1, double y1, double x2, double y2) {
	return pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
}

void pryamokyt(Point TL, Point BR) {
	for (int i = TL.x; i < BR.x; i++) {
		GoToXY(i, TL.y);
		cout << "#";
	}
	for (int i = TL.y; i < TL.y + BR.y / 2; i++) {
		GoToXY(TL.x, i);
		cout << "#";
	}
	for (int i = TL.x; i < BR.x; i++) {
		GoToXY(i, TL.y + BR.y / 2);
		cout << "#";
	}
	for (int i = TL.y; i < TL.y + BR.y / 2; i++) {
		GoToXY(BR.x - 1, i);
		cout << "#";
	}


	GoToXY(0, (TL.y + (BR.y) / 2) + 1);
}

int perimetr(Point a, Point b) {
	double dlin = pow(pow(b.x - a.x, 2), 0.5);
	double h = pow(pow(b.y - a.y, 2), 0.5);
	return (h + dlin) * 2;
}

int plosha(Point a, Point b) {
	double dlin = pow(pow(b.x - a.x, 2) + pow(a.y - a.y, 2), 0.5);
	double h = pow(pow(a.x - a.x, 2) + pow(b.y - a.y, 2), 0.5);
	return dlin * h;
}

bool is_date_correct(date a) {
	if (a.m > 12) {
		return false;
	}
	else if (a.d > 28){
		if (a.d > 31 && a.m == 1)
			return false;
		if (a.d > 28 && a.m == 2) {
			if (a.d > 29)
				return false;
			if (a.y % 400 == 0 && a.d == 29)
				return true;
			else if (a.y % 100 != 0)
				return false;
			else if (a.y % 4 == 0 && a.d == 29)
				return true;
			}
		if (a.d > 31 && a.m == 3)
			return false;
		if (a.d > 30 && a.m == 4)
			return false;
		if (a.d > 31 && a.m == 5)
			return false;
		if (a.d > 30 && a.m == 6)
			return false;
		if (a.d > 31 && a.m == 7)
			return false;
		if (a.d > 31 && a.m == 8)
			return false;
		if (a.d > 30 && a.m == 9)
			return false;
		if (a.d > 31 && a.m == 10)
			return false;
		if (a.d > 30 && a.m == 11)
			return false;
		if (a.d > 31 && a.m == 12)
			return false;
		}
	return true;
}

int riznica(date a, date b) {
	int d_days = ((((b.y * 12) + b.m) * 30) + b.d) - ((((a.y * 12) + a.m) * 30) + a.d);
	return d_days;
}

int main()
{
	srand(time(0));
	
	date data = { 2000, 2, 30 }, a, b;
	cout << "First year mounth day";
	cin >> a.y >> a.m >> a.d;
	if (is_date_correct(a) == false)
		cout << "Not Correct";
	cout << "Seccond year mounth day";
	cin >> b.y >> b.m >> b.d;
	if (is_date_correct(b) == false)
		cout << "Not Correct";
	cout << riznica(a, b) << "days" << endl;


	cout << "is date correct?" << endl;
	cout << data.y << "." << data.m << "." << data.d << endl;
	if (is_date_correct(data))
		cout << "YES!!!";
	else
		cout << "No";


	/*
	Point TL = { 1, 1 }, BR = { 10, 10 };
	pryamokyt(TL, BR);
	cout << endl;
	cout << "x1: " << TL.x << " y1: " << TL.y << endl;
	cout << "x2: " << BR.x << " y2: " << BR.y << endl;
	cout << "Perimetr: " << perimetr(TL, BR) << endl;
	cout << "Plosha: " << plosha(TL, BR) << endl;
	cout << "Diagonal: " << distance(TL, BR) << endl;
	*/

	return 0;
}
