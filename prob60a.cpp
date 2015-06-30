#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <vector>

using namespace std;
void generatePrimes(vector<bool> &primes, vector<unsigned long long> &output, double n);

int main()
{

	vector<int> nums;
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(109);
//nums.push_back(673);

	int nod = 0;
	int answer = 0;


	vector<bool> bp;
	vector<unsigned long long> primes;

	generatePrimes(bp, primes,  10000000);
	cout << "Total Size " << bp.size() << endl;


/*
	for(unsigned long long i=0; i<primes.size(); i++)
	{

		if(i % 100000 == 0 )
		cout << i << endl;
		unsigned long long num = primes[i];
		answer = 0;

		for(unsigned long long j=0; j<nums.size(); j++)
		{
			unsigned long long pNum =  1;
			unsigned long long sNum =  num;
			unsigned long long temp =  0;

			temp = nums[j];
			nod = 0;
			while(temp > 0)
			{
				nod++;
				temp /= 10;

			}


			temp = num;
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

			sNum += nums[j];
			pNum *= nums[j];
			pNum += num;


			if(pNum < bp.size() && sNum < bp.size())
			{

				if(bp[pNum] == true && bp[sNum] == true)
				{
					answer++;			
				}
				else
				{
					break;

				}
			}


			/*
			   cout << "Number is " << primes[i] << endl;
			   cout << "digit is " << nums[j] << endl;
			   cout << "pnum is " << pNum << endl;
			   cout << "snum is " << sNum << endl;

			   cout << endl;

			 */


		}

		//cout << endl;
		if(answer == 3)
		{
			cout << "Num is " << num << endl;
			break;

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



