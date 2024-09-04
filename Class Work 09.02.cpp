#include <iostream>
using namespace std;

int main()
{

	int a, b, c;
	cout << "Viber:\n";
	cin >> a;

	cout << "Telegram:\n";
	cin >> b;

	cout << "Viber and Telegram:\n";
	cin >> c;

	int d = (a + b + c * 2);

	
	double e = (a / d) * 100.;
	double f = ((b + c) / d) * 100.;

	cout << e << "% Viber " << f << "% Telegram";


	/* 2 project
	* 
	int a, b, c, d;

	cout << "Type sec:\n";
	cin >> a;

	b = (a / 3600);
	c = ((a - (3600 * b)) / 60);
	d = (a - (3600 * b) - c * 60);

	cout << b << " hours, " << c << " minutes, " << d << " secconds.\n";

	*/
	/* 1 project

	int a, b;

	cout << "Type days:\n";
	cin >> a;
	b = a / 7;
	cout << a / 7 << " full weeks, or " << b << " weeks and " << a - (b * 7) << " days\n";

	*/

	/*
	bool ta = true;
	while (ta)
	{
		cout << "Type cimbol:\n";
		cin >> c;

		if (c = '+' or '-' or '*' or '/') {
			ta = false;
		}
		else {
			ta = true;
		}
	}

	if (c = '+')
	{
		cout << "a + b = " << a + b << endl;
	}
		
	else if (c = '-')
	{
		cout << "a - b = " << a - b << endl;
	}

	else if (c = '*')
	{
		cout << "a * b = " << a * b << endl;
	}

	else if (c = '/')
	{
		cout << "a / b = " << a / b << endl;
	}
	*/

	return 0;
}
