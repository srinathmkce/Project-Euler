#include <iostream>
using namespace std;

bool isPrime(unsigned long long n );

int main()
{
	unsigned long long num = 600851475143;
	unsigned long long max = 0;
	for(unsigned long long i = 2 ; i <= num ; i++)
	{
		if(num % i == 0)
		{
			if( i > max)
			{
				max = i;
				cout<<"i = "<<i<<endl;
				num = num / i;
				i = 2;

			}
			
		}

	}
	cout << max << endl;
	return 0;
}


bool isPrime(unsigned long long n)
{
	bool primeNum = true;
	for(int i = n/2; i>1; i--)
	{
		if(n % i == 0)
		{
			return false;
		}

	}

	return true;
}
