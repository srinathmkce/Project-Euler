#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void generatePrimes(vector<bool> &primes,vector<int> &output, double n);
int main()
{
	vector<bool> sieve;
	vector<int> comp;
	vector<int> primes;
	double n = 100;
	generatePrimes(sieve ,primes,n);

	for(int i=2; i<n; i++)
	{
		// if it prime set false
		if(primes[i] == true)
			continue;

		if(i % 2 == 0)
			continue;

		comp.push_back(i);

	}

	for(int i=0; i<comp.size(); i++)
		cout << comp[i] << endl;

	return 0;
}


void generatePrimes(vector<bool> &primes, vector<int> &output, double n)
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

        for(int i=2; i<=n; i++)
        {
                if(primes[i] == true)
                {
                        output.push_back(i);
                }
        }

        cout << "Exiting Generate Primes" << endl;
}

