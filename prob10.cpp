#include <iostream>
#include "myLib.h"

using namespace std;

int main()
{
	myLib obj;
	unsigned long long sum;
	for(unsigned long long i=2; i<2000000; i++)
	{
		if(obj.isPrime(i))
		{
			//cout << i << endl;
			sum += i;
		}
	}

	cout << sum << endl;
}
