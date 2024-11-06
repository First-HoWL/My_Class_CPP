#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip> 
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

void GoToXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, coord);
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
	while (true){
		int vibor;
		FILE* file;
		cout << "1. new file, 2. append numb, 3. reading numb, 4. sum 0. Exit" << endl << " >> ";
		cin >> vibor;
		system("cls");
		if (vibor == 0)
			break;
	
		if (vibor == 1) {
			fopen_s(&file, FILE_PATH, "wb");
			fclose(file);
		}
		else if (vibor == 2) {
			int a;
			
			fopen_s(&file, FILE_PATH, "ab");
			cout << "numb: ";
			cin >> a;
			fwrite(&a, sizeof(a), 1, file);
			fclose(file);
		}
		else if (vibor == 3) {
			int a;
			fopen_s(&file, FILE_PATH, "rb");
			while (fread(&a, sizeof(int), 1, file))
			{
				cout << a << " ";
			}
			cout << endl;
			fclose(file);
		}
		else if (vibor == 4) {
			int a, sum = 0;
			fopen_s(&file, FILE_PATH, "rb");
			while (fread(&a, sizeof(int), 1, file))
			{
				sum += a;
			}
			cout << sum << endl;
			fclose(file);
		}

	}
	

	return 0;
}
