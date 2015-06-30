#include <iostream>

using namespace std;

bool isPrime(int n);

int main()
{
	int n = 2;
	int count = 0;
	while(count != 10001)
	{
		if(isPrime(n))
		{
			count = count + 1;
		}
		n = n + 1;
	}

	cout << n-1 << endl;

	return 0;
}

bool isPrime(int n)
{
	for(int i=2; i<=n/2 ; i++)
	{
		if(n%i == 0)
		{
			return false;
		}
	}
	return true;
}
