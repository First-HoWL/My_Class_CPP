#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip> 
using namespace std;
#define FILE_PATH "rec.txt"

struct records {
	int corrects = 0;
	char name[12];

	void cout_rec() {
		cout << setw(12) << name << " | " << setw(5) << corrects;
	}

	bool is_cor() {
		if (corrects > 0)
			return true;
		return false;
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

void buble_sort_records(records array[], int len) {
	bool is_changed = true;
	int a;
	for (int n = 0; n < len - 1; n++)
	{
		is_changed = false;
		for (int i = 0; i < len - n - 1; i++) {
			if (array[i].corrects < array[i + 1].corrects) {
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

int main() {
	srand(time(0));
	int first, second, vidpovid = 0, correct = 1, lives = 3;
	string answer;
	FILE* file;
	
	while (true) {
		first = randint(10, 100);
		second = randint(10, 100);

		cout << first << " + " << second << " = ";
		cin >> answer;
		system("cls");
		if (answer[0] == 'q') {
			break;
		}
		else {
			vidpovid = stoi(answer);
		}
		
		if (vidpovid == (first + second)) {
			cout << "Corect!!!\n";
			correct++;
			GoToXY(20, 0);
			cout << "Corect: " << correct;
			cout << "\tlives: " << lives;
			GoToXY(0, 1);
		}
		else {
			lives--;
			cout << "Not corect!\n" << first << " + " << second << " = ";
			SetColor(2, 0);
			cout << first + second << endl;
			SetColor(7, 0);
			GoToXY(20, 0);
			cout << "Corect: " << correct;
			cout << "\tlives: " << lives;
			GoToXY(0, 3);
			
		}
		if (lives == 0) {
			SetColor(4, 0);
			cout << "You lose!\n";
			SetColor(7, 0);
			cout << "Corect: " << correct << endl;
			break;
		}
	}



	records rec[5], record;

	
	fopen_s(&file, FILE_PATH, "rb");
	int i = 1;
	while (fread(&record, sizeof(records), 1, file)) {
		rec[i - 1] = record;
		cout << setw(12) << rec[i - 1].name << " | " << setw(5) << rec[i - 1].corrects << endl;
		i++;
	}
	i--;
	fclose(file);
	buble_sort_records(rec, i);
	if (i < 5) {
		cout << "What is your name?\n >> ";
		cin >> rec[i].name;
		rec[i].corrects = correct;
		i++;
	}
	else if (correct > rec[4].corrects) {
		cout << "What is your name?\n >> ";
		cin >> rec[4].name;
		rec[4].corrects = correct;
	}
	buble_sort_records(rec, i);
	fopen_s(&file, FILE_PATH, "wb");
	if (i == 0) 
		i++;
	for (int j = 0; j < i; j++){
		record = rec[j];
		fwrite(&record, sizeof(records), 1, file);
	}
	fclose(file);
	return 0;
}
