#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;

void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
}

void cout_masiv(char array[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << array[i];
	}
	cout << endl;
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


bool is_can_move(char maze[], int size, int x) {
	if (x < 0 || x >= size)
		return false;
	if (maze[x] != '.' && maze[x] != 'e')
		return false;
	return true;
}

bool pass_maze(char maze[], int size, int x, int y) {
	if (maze[x] == 'e')
		return true;

	maze[x] = '0';
	if (is_can_move(maze, size, x - 1) && pass_maze(maze, size, x - 1))
		return true;

	if (is_can_move(maze, size, x + 1) && pass_maze(maze, size, x + 1))
		return true;
	maze[x] = ',';
	return false;
}

int main()
{
	srand(time(0));
	char field[11] = ".......e..";
	char field2[5][11] = { {"##########"}, {".........#"}, {"#........#"}, {"#........e"}, {"##########"} };
	cout_masiv(field2[0], 11);
	cout_masiv(field2[1], 11);
	cout_masiv(field2[2], 11);
	cout_masiv(field2[3], 11);
	cout_masiv(field2[4], 11);
	cout << field << endl;
	int starting_point = 0;
	cout << "start point: ";
	cin >> starting_point;

	bool result = pass_maze(field, 10, starting_point);
	cout << field << endl;
	if (result)
		cout << "good" << endl;
	else
		cout << "not good" << endl;

	return 0;
}
