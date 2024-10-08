#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
}

void bubble_sort(int array[], const int len) {
	bool is_changed = true;
	int a;
	for (int n = 0; n < len - 1; n++)
	{
		is_changed = false;
		for (int i = 0; i < len - n - 1; i++) {
			if (array[i] < array[i + 1]) {
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

void cout_masiv(int array[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "\b\b.";
}

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int summa(int array[], int len) {
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += array[i];
	}
	return sum;
}

int kilkist_parnih(int array[], int len) {
	int kilkist = 0;
	for (int i = 0; i < len; i++) {
		if (array[i] % 2 == 0) {
			kilkist++;
		}
	}
	return kilkist;
}

int min_array(int array[], int len) {
	int min = array[0];
	for (int i = 0; i < len; i++) {
		if (min > array[i]) {
			min = array[i];
		}
	}
	return min;
}

int max_array(int array[], int len) {
	int max = array[0];
	for (int i = 0; i < len; i++) {
		if (max < array[i]) {
			max = array[i];
		}
	}
	return max;
}

void delete1(int array[], int& size) {
	for (int i = 0; i < size; i++){
		if (array[i] < 0){ // for homework (array[i] % 2 != 0)
			swap(array[i], array[size - 1]);
			size--;
			i--;
		}
	}
}

void delete2(int array[], int& size) {
	for (int i = 0; i < size; i++) {
		if (array[i] < 0) {
			for (int j = i; j < size - 1; j++)
				array[j] = array[j - 1];
		}
		size--;
		i--;
	}
}


int main()
{
	srand(time(0));
	const int len = 10;
	int size = len;
	int array[len];
	for (int i = 0; i < len; i++) {
		array[i] = randint(-50, 50);
	}

	cout_masiv(array, size);
	cout << "\nsumma: " << summa(array, size) << endl;

	cout << "min: " << min_array(array, size) << endl;
	cout << "max: " << max_array(array, size) << endl;
	cout << "parnih: " << kilkist_parnih(array, size) << endl;

	delete1(array, size);
	cout_masiv(array, size);

	return 0;
}
