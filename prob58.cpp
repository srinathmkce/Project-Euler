#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime( unsigned long long n);
void generatePrimes(vector<bool> &primes, double n);
int main()
{

	// starting from 3 
	 unsigned long long n = 3;
	 unsigned long long num = 0;
	 unsigned long long den = 1;

	 unsigned long long perc = 100;
	 vector<bool> primes;
	 generatePrimes(primes, 1000000000);

	while(perc >= 10 )
	{

		if(n % 1000 == 1)
			cout << "N is " << n << endl;
		// find four corner values
		 unsigned long long topLeft = (n * n) - n + 1;
		 //unsigned long long topRight = (n * n);
		 unsigned long long downLeft = (n * n) - (2 * n) + 2;
		 unsigned long long downRight = (n * n) - (3 * n) + 3;
		 

		if(primes[topLeft])
		num++;
		//if(isPrime(topRight))
		//num++;
		if(primes[downLeft])
		num++;
		if(primes[downRight])
		num++;

		den += 4;
		//cout << "N is " << n << endl;
		perc = (num * 100) / den;
		//cout << "Percentage is " <<  (num * 100) / den << endl ;
		cout << "N:" << n << " num:"<<num<<" den:"<<den << " perc:"<< perc << endl;
		n += 2;




	}
		cout << "N is " << n << endl;
		cout << "Percentage is " <<  perc << endl ;




	return 0;
}


bool isPrime( unsigned long long n)
{
	bool primeNum = true;
	for( unsigned long long i = n/2; i>1; i--)
	{
		if(n % i == 0)
		{
			return false;
		}

	}

	return true;
}




void generatePrimes(vector<bool> &primes, double n)
{
        cout << "Generating Primes  " <<  endl;
        for(int i=2; i<=n; i++)
                primes.push_back(true);

        for(int i=2; i<=sqrt(n); i++)
        {
                if(primes[i] == true)
                {
                        int count = 0;
                        for(int j=i*i ; j<=n; j= i*i + count*i)
                        {
                                primes[j] = false;
                                count++;
                        }
                }
        }
        cout << "Exiting Generate Primes  " <<  endl;

}

