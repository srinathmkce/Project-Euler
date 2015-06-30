#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <vector>

using namespace std;
void generatePrimes(vector<bool> &primes, vector<unsigned long long> &output, double n);
bool binarySearch(vector<unsigned long long> &primes, unsigned long long key, unsigned long long min, unsigned long long max);

int main()
{

	vector<bool> bp;
	vector<unsigned long long> primes;
	vector<unsigned long long> primes3;

	generatePrimes(bp, primes,  1000000000);
	//generatePrimes(bp, primes,  1000000);
	unsigned long long size = primes.size();
	cout << "size " << size << endl;

	for(unsigned long long i=0; i<primes.size(); i++)
	{
		if(i % 100000 == 0)
			cout << i << endl;

		unsigned long long pNum =  1;
		unsigned long long sNum =  1;
		sNum = primes[i] * 10 + 3;

		unsigned long long temp = primes[i];

		while(temp > 0)
		{
			temp /= 10;
			pNum *= 10;
		}
		pNum *= 3;
		pNum += primes[i];

		if(sNum < bp.size() && pNum < bp.size())
		{
			if (bp[pNum] == true && bp[sNum] == true )
			{
				primes3.push_back(primes[i]);
			}
		}


		/*
		   stringstream ss;
		   ss << primes[i];

		   string num = "3" + ss.str();
		   string num1 = ss.str() + "3";
		//cout << primes[i] << "   " << num << "  " << num1 << endl;

		if( (atoi(num.c_str()) < primes.size()  || atoi(num1.c_str()) < primes.size() ) && (bp[atoi(num.c_str())] == true) && (bp[atoi(num1.c_str())] == true) )
		primes3.push_back(primes[i]);

		 */

	}

	cout << "prime 3 size " << primes3.size() << endl;

	for(unsigned long long i=0; i<primes3.size(); i++)
		cout << primes3[i] << "  " ;
	cout << endl;

	vector<unsigned long long> primes7;
	for(unsigned long long i=0; i<primes3.size(); i++)
	{
		unsigned long long pNum =  1;
		unsigned long long sNum =  1;
		sNum = primes3[i] * 10 + 7;

		unsigned long long temp = primes3[i];

		while(temp > 0)
		{
			temp /= 10;
			pNum *= 10;
		}
		pNum *= 7;
		pNum += primes3[i];

		//cout << "num : " << primes3[i] << " pNum : " << pNum << " sNum : "<< sNum << endl;

		if(sNum < bp.size() && pNum < bp.size())
		{
			if ( bp[pNum] == true && bp[sNum] == true )
			{
				primes7.push_back(primes3[i]);
			}
		}
	}

	cout << "prime 7 size " << primes7.size() << endl;

	for(unsigned long long i=0; i<primes7.size(); i++)
		cout << primes7[i] << "  " ;
	cout << endl;

	vector<unsigned long long> primes109;
	for(unsigned long long i=0; i<primes7.size(); i++)
	{
		unsigned long long pNum =  1;
		unsigned long long sNum =  1;
		sNum = primes7[i] * 10 + 7;

		unsigned long long temp = primes7[i];

		while(temp > 0)
		{
			temp /= 10;
			pNum *= 10;
		}
		pNum *= 7;
		pNum += primes7[i];
		//cout << "num : " << primes7[i] << " pNum : " << pNum << " sNum : "<< sNum << " value : " << bp[pNum] << bp[sNum] << endl;


		if ( (pNum < primes.size()  || sNum < primes.size() ) && bp[pNum] == true && bp[sNum] == true )
		{
			primes109.push_back(primes7[i]);
		}

	}



	cout << "prime 109 size " << primes109.size() << endl;

	for(unsigned long long i=0; i<primes109.size(); i++)
		cout << primes109[i] << "  " ;
	cout << endl;


	vector<unsigned long long> primes673;
	for(unsigned long long i=0; i<primes109.size(); i++)
	{
		unsigned long long pNum =  1;
		unsigned long long sNum =  1;
		sNum = primes109[i] * 1000 + 109;

		unsigned long long temp = primes109[i];

		while(temp > 0)
		{
			temp /= 10;
			pNum *= 10;
		}
		pNum *= 109;
		pNum += primes109[i];
		/*
		cout << "Number is " << primes109[i] << endl;
		cout << "pNum is " << pNum << endl;
		cout << "sNum is " << sNum << endl;
		*/

		if(sNum < bp.size() && pNum < bp.size())
		{
			if ( bp[pNum] == true && bp[sNum] == true )
			{
				//cout << "value : " << bp[pNum] << bp[sNum] << endl;
				primes673.push_back(primes109[i]);
			}
		}

	}



	cout << "prime 673 size " << primes673.size() << endl;

	for(unsigned long long i=0; i<primes673.size(); i++)
		cout << primes673[i] << "  " ;
	cout << endl;



vector<unsigned long long> primesAns;
	for(unsigned long long i=0; i<primes673.size(); i++)
	{
		unsigned long long pNum =  1;
		unsigned long long sNum =  1;
		sNum = primes673[i] * 1000 + 673;

		unsigned long long temp = primes673[i];

		while(temp > 0)
		{
			temp /= 10;
			pNum *= 10;
		}
		pNum *= 673;
		pNum += primes673[i];
		/*
		cout << "Number is " << primes109[i] << endl;
		cout << "pNum is " << pNum << endl;
		cout << "sNum is " << sNum << endl;
		*/

		if(sNum < bp.size() && pNum < bp.size())
		{
			if ( bp[pNum] == true && bp[sNum] == true )
			{
				//cout << "value : " << bp[pNum] << bp[sNum] << endl;
				primesAns.push_back(primes673[i]);
			}
		}

	}



	cout << "prime Ans size " << primesAns.size() << endl;

	for(unsigned long long i=0; i<primesAns.size(); i++)
		cout << primesAns[i] << "  " ;
	cout << endl;



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



bool binarySearch(vector<unsigned long long> &primes, unsigned long long key, unsigned long long min, unsigned long long max)
{
 
         while(max >= min)
         {
 
                 unsigned long long mid = (min + max)/2;
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

