#include <iostream>
#include <time.h>
using namespace std;

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int main()
{
	/*
	int a;
	cout << "Your age:\n";
	cin >> a;
	int a, b;
	srand(time(NULL));
	a = randint(0, 200);
	cout << a << "\n";
	cout << "Vgadai chislo:\n";
	cin >> b;
	while (true)
	{
	if (a <= 0 || a >= 120) {
		cout << "lie\n";
		cout << "Your age:\n";
		cin >> a;
	}
	else if (a < 3) {
		cout << "ti nemovlya"; break;
	}
	else if (a < 10) {
		cout << "ti ditina"; break;
	}
	else if (a < 18) {
		cout << "ti ne soverchenoletnii"; break;
	}
	else if (a < 60) {
		cout << "ti soverchenoletnii"; break;
	}
	else if (a < 120) {
		cout << "ti starik"; break;
	}
	
	cout << "\n";
	}
	*/
	int a;
	cout << "Your year:\n";
	cin >> a;

	if (a % 400 == 0) {
		cout << "visocosnii";
	}
	else if (a % 100 == 0) {
		cout << "ne visocosnii";
	}
	else if (a % 4 == 0) {
		cout << "visocosnii";
	}
	else {
		cout << "ne visocosnii";
		if (a == b) {
			cout << "you win! Number is: " << a;
			break;
		}
		else
		{
			cout << "Nevirno,";
			if (a > b) {
				cout << "zagadone chislo bilche";
			}
			else if (a < b) {
				cout << "zagadone chislo menche";
			}
			cout << "\n";
			cin >> b;
		}
	}

	return 0;
