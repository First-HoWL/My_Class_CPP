#include <iostream>
#include <time.h>
using namespace std;

int randint(int min, int max) {
	return(rand() % (max - min + 1) + min);
}

int main()
{
	int a, b, t = 0, d, e;
	srand(time(NULL));
	d = time(NULL);
	a = randint(0, 200);
	cout << a << "\n";
	cout << "Vgadai chislo:\n";
	cin >> b;
	while (true)
	{
		t++;
		if (b == 0) {
			break;
		}
		if (a == b) {
			cout << "you win!";
			break;
		}
		else
		{
			cout << "Nevirno,";
			if (a - b >= -20 && a - b <= 20) {
				cout << "garacho";
			}
			else if (a - b >= -50 && a - b <= 50) {
				cout << "teplo";
			}
			else if (a - b >= -100 && a - b <= 100) {
				cout << "holodno";
			}
			cout << "\n";
			cin >> b;
		}
	}
	e = time(NULL);
	cout << "Number is: " << a << ";\n" << t << " tries\n" << (e - d) << " seconds";

	return 0;
}
