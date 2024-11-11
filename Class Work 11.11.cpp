#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip> 
using namespace std;
#define FILE_PATH "num.txt"

struct Student {
	char name[15];
	char group[10];
	int grades[5];

	float AVG(){
		float sum = 0;
		for (int i = 0; i < 5; i++) {
			sum += grades[i];
		}
		return (sum / 5);
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

Student who_is_student() {
	Student student;
	cout << "Type student Name: ";
	cin >> student.name;
	cout << "Type student Group: ";
	cin >> student.group;

	for (int i = 1; i < 6; i++) {
		cout << "Type " << i << "-s grade: ";
		cin >> student.grades[i - 1];
	}
	return student;
}

void cout_students_from_file() {
	FILE* file;
	fopen_s(&file, FILE_PATH, "rb");
	cout << "Students in file: " << endl;
	Student student;
	int i = 1;
	while (fread(&student, sizeof(Student), 1, file)) {
		cout << setw(4) << i++ << ". | " << setw(15) << student.name << " | " << setw(10) << student.group << endl;
	}
	fclose(file);
}

void cout_students_from_file_with_grades() {
	FILE* file;
	fopen_s(&file, FILE_PATH, "rb");
	cout << "Students with grades in file: " << endl;
	Student student;
	int i = 1;
	while (fread(&student, sizeof(Student), 1, file)) {
		cout << setw(4) << i++ << ". | " << setw(15) << student.name << " | " << setw(10) << student.group << " | ";
		for (int i = 0; i < 5; i++) {
			cout << student.grades[i] << ", ";
		}
		cout << "\b\b \t|   avg: " << student.AVG() << endl;
	}
	fclose(file);
}

Student get_student_by_index(int index) {
	FILE* file;
	Student student;
	if (fopen_s(&file, FILE_PATH, "rb")) {
		cout << "NOT Correct!!!!" << endl;
		return student;
	}
	fseek(file, sizeof(Student) * index, SEEK_SET);
	fread(&student, sizeof(Student), 1, file);
	fclose(file);
	return student;
}

void set_student_by_index(int index, Student student) {
	FILE* file;
	if (fopen_s(&file, FILE_PATH, "r+b")) {
		cout << "NOT Correct!!!!" << endl;
		return;
	}
	fseek(file, sizeof(Student) * index, SEEK_SET);
	fwrite(&student, sizeof(Student), 1, file);
	fclose(file);
}

int main()
{
	srand(time(0));
	Student student;
	FILE* file;
	
	while (true) {
		int vibor;
		cout << "1. new student, 2. reading student, 3. reading student and grades, 4. change grades,  0. Exit" << endl << " >> ";
		cin >> vibor;
		system("cls");
		if (vibor == 0)
			break;

		if (vibor == 1) {
			if (errno_t err_n = fopen_s(&file, FILE_PATH, "ab")) {
				cout << "NOT Correct!!!!" << endl;
				return err_n;
			}

			student = who_is_student();

			fwrite(&student, sizeof(Student), 1, file);
			fclose(file);
		}
		else if (vibor == 2) {
			cout_students_from_file();
		}
		else if (vibor == 3) {
			cout_students_from_file_with_grades();
		}
		else if (vibor == 4) {
			cout_students_from_file_with_grades();
			cout << "Student that you want to change: ";
			int s_index;
			cin >> s_index;
			s_index--;
			student = get_student_by_index(s_index);
			cout << "Student Name: " << student.name << endl;
			cout << "Type new grades: " << endl;
			for (int i = 0; i < 5; i++) {
				cout << "type " << i + 1 << "-s grade: ";
				cin >> student.grades[i];
			}
			set_student_by_index(s_index, student);
			system("cls");
			cout << "Correct!" << endl;
		}


	}



	return 0;
}
