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
	fstream file, file2;
	/*
	file.open(FILE_PATH, ios::app);
	file << "Hello world!\n";
	file.close();
	*/

	while (true) {
		cout << "1. New file 2. Cout file 3. Add smth to the file 4. Find longest string 5. Copy file 6. File long words 7. loking for char 0. Exit \n >> ";
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
		else if (vibor == 4) {
			file.open(FILE_PATH, ios::in);
			string text, correct_text;
			int size = 0;
			while (file) {
				getline(file, text);
				if (text.length() > size){
					size = text.length();
					correct_text = text;
				}
								
			}
			cout << correct_text << endl << size << "characters!" << endl;
			file.close();
		}
		else if (vibor == 5) {
			cout << "name new file: ";
			char FILE_PATH_NEW[30];
			cin >> FILE_PATH_NEW;

			file2.open(FILE_PATH_NEW, ios::out);
			file.open(FILE_PATH, ios::in);
			string text;
			while (file) {
				getline(file, text);
				file2 << text << endl;
			}
			file.close();
			file2.close();
			cout << "correct!" << endl;
		}
		else if (vibor == 6) {
			cout << "name new file: ";
			char FILE_PATH_NEW[30];
			cin >> FILE_PATH_NEW;

			file2.open(FILE_PATH_NEW, ios::out);
			file.open(FILE_PATH, ios::in);
			string text;
			while (file) {
				getline(file, text);
				if (text.length() > 7)
					file2 << text << endl;
			}
			file.close();
			file2.close();
			cout << "correct!" << endl;
		}
		else if (vibor == 7) {
			cout << "character: ";
			char character;
			cin >> character;
			file.open(FILE_PATH, ios::in);
			string text;
			int count = 0;
			while (file) {
				file >> text;
				if (character == text[0])
					count++;
			}
			if (character == text[0])
				count--;
			file.close();
			cout << count << " words!" << endl;
		}
	}

	

	return 0;
}
