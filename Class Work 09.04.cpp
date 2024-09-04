#include <iostream>
#include <time.h>
using namespace std;

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int main()
{
	int a, b;
	srand(time(NULL));
	a = randint(0, 200);
	cout << a << "\n";
	cout << "Vgadai chislo:\n";
	cin >> b;
	while (true)
	{
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
}
