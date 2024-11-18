#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip> 
#include <fstream>
using namespace std;
#define FILE_PATH "num.txt"

void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
}

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int main()
{
	srand(time(0));
	fstream file;
	/*
	file.open(FILE_PATH, ios::app);
	file << "Hello world!\n";
	file.close();
	*/

	while (true) {
		cout << "1. New file 2. Cout file 3. Add something to the file 0. Exit \n >> ";
		int vibor;
		cin >> vibor;
		system("cls");
		if (vibor == 0)
			break;
		else if (vibor == 1) {
			file.open(FILE_PATH, ios::out);
			file.close();
		}
		else if (vibor == 2) {
			file.open(FILE_PATH, ios::in);
			while (file) {
				string text;
				getline(file, text);
				cout << text << endl;
			}
			file.close();
		}
		else if (vibor == 3) {
			string text;
			file.open(FILE_PATH, ios::app);
			cout << " >> ";
			cin >> text;
			file << text << endl;
			file.close();
		}
	}

	

	return 0;
}
