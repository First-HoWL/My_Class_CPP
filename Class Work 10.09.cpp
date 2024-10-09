
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


bool is_can_move(char maze[10][21], int size, int x, int y) {
	if (x < 0 || x >= size)
		return false;
	if (maze[y][x] != '.' && maze[y][x] != 'e')
		return false;
	return true;
}

bool pass_maze(char maze[10][21], int size, int x, int y) {
	if (maze[y][x] == 'e')
		return true;

	maze[y][x] = '1';
	if (is_can_move(maze, size, x, y + 1) && pass_maze(maze, size, x, y + 1))
		return true;

	if (is_can_move(maze, size, x + 1, y) && pass_maze(maze, size, x + 1, y))
		return true;

	if (is_can_move(maze, size, x, y - 1) && pass_maze(maze, size, x, y - 1))
		return true;

	if (is_can_move(maze, size, x - 1, y) && pass_maze(maze, size, x - 1, y))
		return true;

	maze[y][x] = 'X';
	return false;
}

int main()
{
	srand(time(0));
	const int y = 10, x = 20;
	char field2[y][x + 1] = {
		{"####################"},
		{"........#......#...#"},
		{"###.....#..###.#.#.#"},
		{"#.......#..#...#.#.#"},
		{"##.........#.#.#.#.#"},
		{"#......#####.###.#.#"},
		{"#.######.......#.#.#"},
		{"#..#...#.#####.#.#.#"},
		{"##...#...#...#...#.e"},
		{"####################"}
	};

	cout_masiv(field2);
	int starting_pointX = 0, starting_pointY = 0;
	cout << endl;
	cout << "start point(Y, X): ";
	cin >> starting_pointY >> starting_pointX;
	cout << endl;
	bool result = pass_maze(field2, x, starting_pointX, starting_pointY);
	cout_masiv(field2);
	cout << endl;
	if (result){
		SetColor(2, 0);
		cout << "good" << endl;
		SetColor(7, 0);
	}
	else {
		SetColor(4, 0);
		cout << "not good" << endl;
		SetColor(7, 0);
	}
	return 0;
}
