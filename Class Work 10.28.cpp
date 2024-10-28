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

struct Train {
	int number;
	string startPoint, endPoint;
	date startDate, endDate;
	int seatsTotal, seatsTaken;
	double price;
	string sitys[7] = { "Dnipro", "Kuiv", "Kharkov", "Lviv", "Ivano-Frankivsk", "Odessa", "Vinnitsa"};
	void print(){
		cout << setw(5) << number << " | " << setw(15) << startPoint << "  -  " << setw(15) << endPoint << "  | ";
		startDate.print_date();
		cout << " - ";
		endDate.print_date();
		cout << " | " << setw(8) << price << "grn  | " << setw(4) << getFreeSeats() << " free sits" << "  | " << seatsTaken * price << " grn. ";
	}

	int getFreeSeats() { return seatsTotal - seatsTaken; }

	
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

void cout_list_dates(date dates_lists[], int len) {
	for (int i = 0; i < len; i++) {
		dates_lists[i].print_date();
		cout << endl;
	}
	cout << endl;
}


void bubble_trains(Train array[], int len) {
	bool is_changed = true;
	int a;
	for (int n = 0; n < len - 1; n++)
	{
		is_changed = false;
		for (int i = 0; i < len - n - 1; i++) {
			if (array[i].startDate.days() > array[i + 1].startDate.days()) {
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

Train getRandomTrain() {
	Train a;
	a.number = randint(10, 200);
	int startIndex = randint(0, 6);
	int endIndex = randint(0, 6);
	while (true) {
		if (endIndex != startIndex)
			break;
		endIndex = randint(0, 6);
	}
	a.startPoint = a.sitys[startIndex];
	a.endPoint = a.sitys[endIndex];

	a.startDate = { randint(1, 30), randint(10, 12), 2024 };
	a.endDate = { randint(a.startDate.d, 30), randint(a.startDate.m, 12), 2024 };
	if (a.startDate.m == a.endDate.m) {
		if (a.startDate.m == 11)
			a.endDate.d = randint(a.startDate.d, 30);
		else
			a.endDate.d = randint(a.startDate.d, 30);
	}
	else {
		if (a.startDate.m == 11)
			a.endDate.d = randint(1, 30);
		else
			a.endDate.d = randint(1, 30);
	}
	a.seatsTotal = randint(100, 400);
	a.seatsTaken = randint(40, a.seatsTotal);
	a.price = randint(20000, 70000) / 100.;
	return a;
}

double costs(Train array[], int len) {
	int a = 0;
	for (int i = 0; i < len; i++) {
		a += array[i].seatsTaken * array[i].price;
	}
	return a;
}

int main()
{
	
	srand(time(0));
	Train trains[10];
	for (int i = 0; i < 10; i++){
		trains[i] = getRandomTrain();
	}

	bubble_trains(trains, 10);

	for (int i = 0; i < 10; i++){
		trains[i].print();
		cout << endl;
	}

	cout << costs(trains, 10) << "grn";


	cout << endl;
	return 0;
}
