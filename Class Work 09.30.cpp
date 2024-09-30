#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

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

int main()
{
	srand(time(0));
	int size = 0;


	cout << "Enter array size: ";
	cin >> size;
	
	int* array = new int[size];
	
	for (int i = 0; i < size; i++)
		array[i] = randint(-50, 50);

	cout_masiv(array, size);
	delete[] array;
	return 0;
}
