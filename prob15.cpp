#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned long long rows;
	cout << "Enter the number of rows ";

	//cin >> rows;
	rows = 6;
	cout << endl;

	for(unsigned long long i=0; i<rows; i++)
	{
		unsigned long long val = 1;
		for(unsigned long long j=1; j<(rows-i) ; j++)
		{
			cout << "  ";
		}
		for(unsigned long long k=0; k<=i; k++)
		{
			cout << "    " << val;
			val = val * (i-k) / (k + 1);
		}
		cout <<  endl;
	}
	cout << endl;
	return 0;
}



