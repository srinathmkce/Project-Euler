#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>

using namespace std;
void generatePrimes(vector<bool> &primes, vector<int> &output, double n);
bool binarySearch(vector<int> &primes, int key, int min, int max);
int main()
{
	vector<bool> input;
	vector<int> primes;
	vector<string> sprim;
	map<int,string> sorted;
	map<string,vector<int> > sortedMap;
	map<string,vector<int> >:: iterator it;
	generatePrimes(input, primes,10000);
	primes.clear();
	for(int i=1000; i<10000; i++)
	{
		if(input[i] == true)
			primes.push_back(i);

	}

	// converting all prime numbers to string
	for(int i=0; i<primes.size(); i++)
	{
		stringstream ss;
		ss << primes[i];
		string snum = ss.str();
		sprim.push_back(snum);

	}

	vector<bool> bucket;
		for(int m=0; m<10; m++)
			bucket.push_back(false);

	for(int i=0; i<primes.size(); i++)
	{
		for(int m=0; m<10; m++)
			bucket[m] = false;


		int num = primes[i];
		int temp = num;
		while(temp >0)
		{
			int digit = temp % 10;
			bucket[digit] = true;
			temp = temp / 10;

		}

		string primeNum = "";
		for(int k=0; k<bucket.size(); k++)
		{
			if(bucket[k] == true)
			{
				string n;
				stringstream ss;
				ss <<k;
				n = ss.str();

				primeNum += n;
			}

		}
		//cout << num << "  " << primeNum << endl;
		sorted[num] = primeNum;

		if(sortedMap.find(primeNum) == sortedMap.end())
		{
		vector<int> t;
		t.push_back(num);
		sortedMap[primeNum] = t;

		}
		else
		{
		sortedMap.find(primeNum)->second.push_back(num);

		}



	}

bool ans = false;
	for(it=sortedMap.begin(); it!=sortedMap.end(); ++it)
	{
		vector<int> temp;
		temp = it->second;

		for(int i=0; i<temp.size(); i++)
		{
			for(int j=i+1; j<temp.size();j++)
			{
				int fir = temp[i];
				int sec= temp[j];
				int diff = sec - fir;
				int newNum = sec + diff;
				if(binarySearch(temp,newNum,j+1,temp.size()-1))
				{
					cout << "Answer is " << fir << " "  << sec << " " << newNum << endl;
				}


			}

		}


	}


	return 0;
}

void generatePrimes(vector<bool> &primes, vector<int> &output, double n)
{
        cout << "Generating Primes" << endl;
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


