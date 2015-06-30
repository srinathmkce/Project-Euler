#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void generatePrimes(vector<int> &primes, int n);
bool binarySearch(vector<int> &primes, int key, int min, int max);
int main()
{

	vector<int> primes;
	int n = 2000000;
	//generatePrimes(primes,1000000);
	primes.clear();
	generatePrimes(primes,n);
	for(int i=0; i<primes.size(); i++)
	{
	cout << primes[i] << endl;
	}
	
	if(binarySearch(primes,3,0,primes.size()-1))
	  {
	  cout << "Key found" << endl;
	  }
	  else
	  cout << "Key not found" << endl;



	return 0;
}

void generatePrimes(vector<int> &output, int n)
{
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
