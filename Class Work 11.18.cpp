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
	file.open(FILE_PATH, ios::in);
	while (file) {
		string text;
		//file >> text;
		getline(file, text);
		cout << text << endl;
	}
	file.close();

	return 0;
}
