#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

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

int main()
{
	srand(time(0));
	int size1 = 0, size2 = 0, size3 = 0, real_size = 0;


	cout << "Enter TWO arrays size: ";
	cin >> size1 >> size2;
	size3 = size1 + size2;
	int* array1 = new int[size1];
	int* array2 = new int[size2];
	int* array3 = new int[size3];
	bool povtor = false;
	for (int i = 0; i < size1; i++)
		array1[i] = randint(-10, 10);

	for (int i = 0; i < size2; i++)
		array2[i] = randint(-10, 10);
	cout << "first masiv: ";
	cout_masiv(array1, size1);
	cout << endl;
	cout << "second masiv: ";
	cout_masiv(array2, size2);
	cout << endl;
	array3[0] = array1[0];
	for (int j = 1, i = 1; i < size1 + 1; j++, i++) {
		for (int n = 0; n < real_size + 1; n++) {
			if (array1[i] == array3[n]) {
				povtor = true;
			}

		}
		if (povtor == false) {
			array3[j] = array1[i];
			real_size++;
		}
		else {
			j--;
			povtor = false;
		}
	}
	

	for (int j = real_size, i = 0; i < size2; j++, i++) {
		for (int n = 0; n < real_size + 1; n++) {
			if (array2[i] == array3[n]) {
				povtor = true;
			}

		}
		if (povtor == false) {
			array3[j] = array2[i];
			real_size++;
		}
		else {
			j--;
			povtor = false;
		}
	}
	cout << "second chikl: ";
	cout_masiv(array3, real_size);



	delete[] array1;
	delete[] array2;
	delete[] array3;
	return 0;
}
