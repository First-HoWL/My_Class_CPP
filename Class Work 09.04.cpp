#include <iostream>
using namespace std;

int main()
{

	int a;
	cout << "Your age:\n";
	cin >> a;

	if (a <= 0 || a >= 120) {
		cout << "lie";
	}
	else if (a < 3) {
		cout << "ti nemovlya";
	}
	else if (a < 10) {
		cout << "ti ditina";
	}
	else if (a < 18) {
		cout << "ti ne soverchenoletnii";
	}
	else if (a < 60) {
		cout << "ti soverchenoletnii";
	}
	else if (a < 120) {
		cout << "ti starik";
	}
	cout << "\n";
	return 0;
}
