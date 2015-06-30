#include <iostream>
using namespace std;


int main()
{

	int a = 0;
	int b = 1;
	int c = 0;
	int sum = 0;
	while(1)
	{
		c = a + b;
		a = b;
		b = c;
		if(c < 4000000)
		{
			if( c % 2 == 0 )
			{
				sum = sum + c;
				cout << c << endl;
			}
		}
		else
			break;

	}

	cout << sum;

	return 0;
}


