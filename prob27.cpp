#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
bool isPrime(int n);
void generatePrimes(vector<int> &output, int n);
bool binarySearch(vector<int> &primes, int key, int min, int max);

int main()
{
	int counter = 0;
	int max_counter = 0;
	int prod = 0;
	int n_flag = false;
	int  a_flag = false;
	int b_flag = false;
	vector<int> primes;
	int n_prime = 2000000;
	int temp_a = 0, temp_b = 0;
	generatePrimes(primes,n_prime);
	for(int a=-999; a<1000; a++)
	{
		cout << a << endl;
		if(a%2 == 0)
			a_flag = true;
		else
			a_flag = false;
		for(int b=-999; b<1000; b++)
		{
			if(b%2 == 0)
				b_flag = true;
			else
				b_flag = false;
			for(int n=0; n<1000; n++)
			{
				if(n%2 == 0)
					n_flag = true;
				else
					n_flag = false;


				if(n_flag && a_flag && b_flag)
				{
					counter = 0;
					continue;
				}

				if(n_flag && !a_flag && b_flag)
				{
					counter = 0;
					continue;
				}

				if(!n_flag && !a_flag && b_flag)
				{
					counter = 0;
					continue;
				}

				if(!n_flag && a_flag && !b_flag)
				{
					counter = 0;
					continue;
				}

				//cout << "n is " << n << " a is " << a << " b is " << b << endl;
				int sum;
				sum = n * (n + a) + b;
				if(sum < 0 )
				{
					counter = 0;
					continue;
				}

				if(sum % 2 == 0)
				{

					counter =0;
					continue;
				}

				//if(isPrime(sum))
				if(binarySearch(primes,sum,0,primes.size()-1))
				{
					counter = counter + 1;
					//cout << "counter is " << counter << endl;
				}
				else
				{
					if(counter > max_counter)
					{
						max_counter = counter;
						//cout << "max counter is " << max_counter << endl;
						prod = a * b;
						temp_a = a;
						temp_b = b;
					}
					counter = 0;

				}
			}
		}
	}

	cout << "Max ounter is " << max_counter << endl;
	cout << "Product is " << prod << endl;
	cout << "a is " << temp_a << endl;
	cout << "b is " << temp_b << endl;
	return 0;
}

bool isPrime(int n)
{

	for(int i=2; i<=sqrt(n); i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}


void generatePrimes(vector<int> &output, int n)
{
	cout << "Generating Primes" << endl;
	vector<bool> primes;
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

	for(int i=2; i<=n; i++)
	{
		if(primes[i] == true)
		{
			output.push_back(i);
		}
	}

	cout << "Exiting Generate Primes" << endl;
}

bool binarySearch(vector<int> &primes, int key, int min, int max)
{

	while(max >= min)
	{

		int mid = (min + max)/2;
		if(primes[mid] == key)
		{
			return true;
		}
		else if(primes[mid] < key)
		{
			min = mid + 1;
		}
		else
		{
			max = mid -1 ;

		}

	}
	return false;



}

