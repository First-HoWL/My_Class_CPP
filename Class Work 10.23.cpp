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

int riznica(date a, date b) {
	int d_days = ((((b.y * 12) + b.m) * 30) + b.d) - ((((a.y * 12) + a.m) * 30) + a.d);
	return d_days;
}

void cout_list_dates(date dates_lists[], int len) {
	for (int i = 0; i < len; i++) {
		dates_lists[i].print_date();
		cout << endl;
	}
	cout << endl;
}

void bubble_date(date array[], int len) {
	bool is_changed = true;
	int a;
	for (int n = 0; n < len - 1; n++)
	{
		is_changed = false;
		for (int i = 0; i < len - n - 1; i++) {
			if (array[i].days() > array[i + 1].days()) {
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


int main()
{
	srand(time(0));
	
	date dates_lists[5] = { 
		{23, 10, 2024}, 
		{10, 02, 1932}, 
		{03, 12, 2002}, 
		{11, 9, 2001},
		{07, 02, 2007}
	};

	cout_list_dates(dates_lists, 5);
	bubble_date(dates_lists, 5);
	cout_list_dates(dates_lists, 5);

	return 0;
}
