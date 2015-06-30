#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <vector>

using namespace std;
void generatePrimes(vector<bool> &primes, vector<unsigned long long> &output, double n);
unsigned long long findNextDigit(vector<bool> bp, vector<unsigned long long> primes,  int startingDigit, vector<unsigned long long> store);

int main()
{

	vector<unsigned long long> store;
	vector<bool> bp;
	vector<unsigned long long> primes;

	generatePrimes(bp, primes,  1000000);
	cout << "Total Size " << bp.size() << endl;
	bool exitProgram = false;


	// number is not necessarily be 3 . hence iterating over the list.

	for(unsigned long long i=0; i<primes.size(); i++)
	{
			int answer = 0;
			int startingDigit = primes[i];
			store.clear();
			store.push_back(startingDigit);
			cout << "Starting Digit is " << startingDigit << endl;
			unsigned long long nextDigit = 0;
			while(1)
			{

				nextDigit = findNextDigit(bp, primes, startingDigit, store);
				cout << "Next Digit is " << nextDigit << endl;
				store.push_back(nextDigit);
				if(nextDigit == 0)
				{
					break;
				}
				else
				{
					answer++;
					startingDigit = nextDigit;
					if(answer == 3)
					{

						exitProgram = true;
						break;
					}

				}
			}
			cout <<  endl;
			if(exitProgram)
				break;
		}


	cout << "Answer : " <<  endl;
	cout << " ********************************************** " <<  endl;
	for(int i=0; i<store.size(); i++)
		cout << store[i] << endl;
	cout << " ********************************************** " <<  endl;





	return 0;
}

unsigned long long findNextDigit(vector<bool> bp, vector<unsigned long long> primes,  int startingDigit, vector<unsigned long long> store)
{

	for(unsigned long long i=0; i<primes.size(); i++)
	{
		if(primes[i] <= startingDigit)
		continue;

		cout << "Number : " << primes[i] << endl;
		unsigned long long pNum =  1;
		unsigned long long sNum =  primes[i];
		unsigned long long temp =  0;
		temp = startingDigit;
		int nod = 0;
		while(temp > 0)
		{
			nod++;
			temp /= 10;

		}
		temp = primes[i];

		while(temp > 0)
		{
			temp /= 10;
			pNum *= 10;
		}

		while(nod > 0)
		{
			sNum *= 10;
			nod--;
		}

		sNum += startingDigit;
		pNum *= startingDigit;
		pNum += primes[i];

		if(pNum < bp.size() && sNum < bp.size())
		{

			if(bp[pNum] == true && bp[sNum] == true)
			{
				cout << "starting Digit " << startingDigit << " Num : " << primes[i] << " pNum " << pNum << " sNum " << sNum << endl;
				cout << "Found : " << primes[i] << endl;
				cout << "Store size is : " << store.size() << endl;
				cout << endl;
				return primes[i];
			}
			else
			{
				continue;
			}
		}

	}


	return 0;

}

void generatePrimes(vector<bool> &primes, vector<unsigned long long> &output ,  double n)
{
        cout << "Generating Primes  " <<  endl;
        for(unsigned long long i=0; i<=n; i++)
                primes.push_back(true);

        for(unsigned long long i=2; i<=sqrt(n); i++)
        {
                if(primes[i] == true)
                {
                        unsigned long long count = 0;
                        for(unsigned long long j=i*i ; j<=n; j= i*i + count*i)
                        {
                                primes[j] = false;
                                count++;
                        }
                }
        }

        for(unsigned long long i=2; i<=n; i++)
        {
                if(primes[i] == true)
                {
                        output.push_back(i);
                }
        }

        cout << "Exiting Generate Primes" << endl;
}



