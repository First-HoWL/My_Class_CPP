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

void cout_masiv(int array[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "\b\b." << endl;
}

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

float seredne_arefmetichne(int array[], int len) {
	float seredne = 0;
	for (int i = 0; i < len; i++) {
		seredne += array[i];
	}
	seredne = seredne / len;
	return seredne;
}

void cout_kubik(int num) {
	if (num == 1) {
		cout << " _______ " << endl;
		cout << "|       |" << endl;
		cout << "|   #   |" << endl;
		cout << "|       |" << endl;
		cout << "|_______|" << endl;
	}
	else if (num == 2) {
		cout << " _______ " << endl;
		cout << "|       |" << endl;
		cout << "| #   # |" << endl;
		cout << "|       |" << endl;
		cout << "|_______|" << endl;
	}
	else if (num == 3) {
		cout << " _______ " << endl;
		cout << "| #     |" << endl;
		cout << "|   #   |" << endl;
		cout << "|     # |" << endl;
		cout << "|_______|" << endl;
	}
	else if (num == 4) {
		cout << " _______ " << endl;
		cout << "| #   # |" << endl;
		cout << "|       |" << endl;
		cout << "| #   # |" << endl;
		cout << "|_______|" << endl;
	}
	else if (num == 5) {
		cout << " _______ " << endl;
		cout << "| #   # |" << endl;
		cout << "|   #   |" << endl;
		cout << "| #   # |" << endl;
		cout << "|_______|" << endl;
	}
	else if (num == 6) {
		cout << " _______ " << endl;
		cout << "| #   # |" << endl;
		cout << "| #   # |" << endl;
		cout << "| #   # |" << endl;
		cout << "|_______|" << endl;
	}
}

void GoToXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, coord);
}

void cout_kubik2(int num, int i) {
	if (num == 1) {
		GoToXY(14, i + 1);
		cout << " _______ " << endl;
		GoToXY(14, i + 2);
		cout << "|       |" << endl;
		GoToXY(14, i + 3);
		cout << "|   #   |" << endl;
		GoToXY(14, i + 4);
		cout << "|       |" << endl;
		GoToXY(14, i + 5);
		cout << "|_______|" << endl;
	}
	else if (num == 2) {
		GoToXY(14, i + 1);
		cout << " _______ " << endl;
		GoToXY(14, i + 2);
		cout << "|       |" << endl;
		GoToXY(14, i + 3);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 4);
		cout << "|       |" << endl;
		GoToXY(14, i + 5);
		cout << "|_______|" << endl;
	}
	else if (num == 3) {
		GoToXY(14, i + 1);
		cout << " _______ " << endl;
		GoToXY(14, i + 2);
		cout << "| #     |" << endl;
		GoToXY(14, i + 3);
		cout << "|   #   |" << endl;
		GoToXY(14, i + 4);
		cout << "|     # |" << endl;
		GoToXY(14, i + 5);
		cout << "|_______|" << endl;
	}
	else if (num == 4) {
		GoToXY(14, i + 1);
		cout << " _______ " << endl;
		GoToXY(14, i + 2);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 3);
		cout << "|       |" << endl;
		GoToXY(14, i + 4);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 5);
		cout << "|_______|" << endl;
	}
	else if (num == 5) {
		GoToXY(14, i + 1);
		cout << " _______ " << endl;
		GoToXY(14, i + 2);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 3);
		cout << "|   #   |" << endl;
		GoToXY(14, i + 4);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 5);
		cout << "|_______|" << endl;
	}
	else if (num == 6) {
		GoToXY(14, i + 1);
		cout << " _______ " << endl;
		GoToXY(14, i + 2);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 3);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 4);
		cout << "| #   # |" << endl;
		GoToXY(14, i + 5);
		cout << "|_______|" << endl;
	}
}

void code(int& player_score, int& bot_score) {
	int player_num, bot_num;
	player_num = randint(1, 6);
	bot_num = randint(1, 6);
	cout << "player: " << endl;
	cout_kubik(player_num);
	player_score += player_num;
	player_num = randint(1, 6);
	cout_kubik2(player_num, 0);
	player_score += player_num;
	cout << "bot: " << endl;
	cout_kubik(bot_num);
	bot_score += bot_num;
	bot_num = randint(1, 6);
	cout_kubik2(bot_num, 6);
	bot_score += bot_num;
}

void delete1(int array[], int& size, bool a) {
	if (a == false) {
		for (int i = 0; i < size; i++) {
			if (array[i] % 2 != 0) {
				swap(array[i], array[size - 1]);
				size--;
				i--;
			}
		}
	}
	else{
		for (int i = 0; i < size; i++) {
			if (array[i] % 2 == 0) {
				swap(array[i], array[size - 1]);
				size--;
				i--;
			}
		}
	}
}

bool is_can_move(char maze[], int size, int x) {
	if (x < 0 || x >= size)
		return false;
	if (maze[x] != '.' && maze[x] != 'e')
		return false;
	return true;
}


bool pass_maze(char maze[], int size, int x) {
	if (maze[x] == 'e')
		return true;

	maze[x] = '<';
	if (is_can_move(maze, size, x - 1) && pass_maze(maze, size, x - 1))
		return true;

	maze[x] = '>';
	if (is_can_move(maze, size, x + 1) && pass_maze(maze, size, x + 1))
		return true;
	maze[x] = ',';
	return false;
}

int main()
{
	srand(time(0));
	char field[11] = ".......e..";

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
