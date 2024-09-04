#include <iostream>
using namespace std;

int main()
{
	/*
	int a;
	cout << "Your age:\n";
	cin >> a;
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
	}

	return 0;
}
