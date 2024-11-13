#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip> 
using namespace std;
#define FILE_PATH "num.txt"
const int year = 2024;

struct Car{
	char brand[20];
	char model[10];
	char nomer[10];
	int rik_vipusky;
	int probig;
	double dvigun;

	void cout_car() {
		cout << setw(20) << brand << " | " << setw(10) << model << " | " << setw(10) << nomer << " | " << setw(6) << rik_vipusky << " | ";
		cout << setw(10) << probig << " | " << setw(5) << dvigun << " | " << setw(10) << avg() << "km/y" << endl;
	}

	int years() {
		return (year - rik_vipusky);
	}

	double avg() {
		return (probig / years());
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

Car cin_car(){
	Car car;
	cout << "Brand: ";
	cin >> car.brand;
	cout << "Model: ";
	cin >> car.model;
	cout << "Nomer: ";
	cin >> car.nomer;
	cout << "rik_vipusky: ";
	cin >> car.rik_vipusky;
	cout << "probig: ";
	cin >> car.probig;
	cout << "dvigun: ";
	cin >> car.dvigun;
	return car;
}

void cout_car_from_file() {
	FILE* file;
	fopen_s(&file, FILE_PATH, "rb");
	cout << "Cars in file: " << endl;
	Car car;
	int i = 1;
	while (fread(&car, sizeof(Car), 1, file)) {
		car.cout_car();
	}
	fclose(file);
}

Car get_car_by_index(int index) {
	FILE* file;
	Car car;
	if (fopen_s(&file, FILE_PATH, "rb")) {
		cout << "NOT Correct!!!!" << endl;
		return car;
	}
	fseek(file, sizeof(Car) * index, SEEK_SET);
	fread(&car, sizeof(Car), 1, file);
	fclose(file);
	return car;
}

void set_car_by_index(int index, Car car) {
	FILE* file;
	if (fopen_s(&file, FILE_PATH, "r+b")) {
		cout << "NOT Correct!!!!" << endl;
		return;
	}
	fseek(file, sizeof(Car) * index, SEEK_SET);
	fwrite(&car, sizeof(Car), 1, file);
	fclose(file);
}

double avg_probig_rik() {
	FILE* file;
	fopen_s(&file, FILE_PATH, "rb");
	Car car;
	int i = 0, sum = 0, avg_car = 0, avg_cars;
	while (fread(&car, sizeof(Car), 1, file)) {
		sum += car.avg();
		i++;
	}
	avg_cars = sum / i;
	fclose(file);
	return avg_cars;
}

int main()
{
	srand(time(0));
	Car mycar;
	FILE* file;
	

	while (true) {
		int vibor;
		cout << "1. new car, 2. reading car, 3. edit car, 4. avg km/year 0. Exit" << endl << " >> ";
		cin >> vibor;
		system("cls");
		if (vibor == 0)
			break;

		if (vibor == 1) {
			if (errno_t err_n = fopen_s(&file, FILE_PATH, "ab")) {
				cout << "NOT Correct!!!!" << endl;
				return err_n;
			}

			mycar = cin_car();

			fwrite(&mycar, sizeof(Car), 1, file);
			fclose(file);
		}
		else if (vibor == 2) {
			cout_car_from_file();
		}
		else if (vibor == 3) {
			cout_car_from_file();
			cout << "Car that you want to change: ";
			int s_index;
			cin >> s_index;
			s_index--;
			mycar = get_car_by_index(s_index);
			
			set_car_by_index(s_index, cin_car());
			system("cls");
			cout << "Correct!" << endl;
		}
		else if (vibor == 4) {
			cout << "avg: " << avg_probig_rik() << "km/year" << endl;
		}
	}

	return 0;
}
