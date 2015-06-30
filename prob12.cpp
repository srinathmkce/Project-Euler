#include <iostream>
#include <vector>
#include "myLib.h"
#include <map>
#include <set>

using namespace std;

bool is500Divisors(unsigned long long number);
void sieve(int min, unsigned long long max, vector<bool> &result);
	vector<unsigned long long> resultVec;
	map<unsigned long long,long> pFacs;
	map<unsigned long long ,long>::iterator it;

	unsigned long long minLimit = 2;

int main()
{

	int i = 1;
	unsigned long long sum = 0;
	while(1)
	{
		sum = sum + i ;
		//cout << "Number is " << sum << endl;
		//cout << sum << endl;
		if(is500Divisors(sum))
		{
			cout << "Answer : " << sum <<  endl;
			break;
		}
		i++;
	}
	

	return 0;
}

bool is500Divisors(unsigned long long number)
{
	myLib obj;
	unsigned long long maxLimit = number/2;
	int temp=1;

//cout<<minLimit<<"Min   "<<maxLimit<<"Max"<<endl;
	for(int i=minLimit ; i <= maxLimit ; i++)
	{
		if(obj.isPrime(i))
		{
			temp = i;
			//pFacs.insert(pair<unsigned long long,long>(i,0));
			resultVec.push_back(i);
		}

	}

	minLimit = temp+1;

	int counter = 1;
	for(int i = 0;i< resultVec.size() ; i++)	
	{
		//unsigned long long primeNumber = it->first;
		unsigned long long primeNumber = resultVec[i];
		int count = 0;
		while(number % primeNumber == 0)
		{
			number = number / primeNumber;
			count++ ;
		}

		//it->second = count;
		counter = (count + 1) * counter;

	}

	//cout << "counter is " << counter << endl;
/*
	int counter = 1;
	for(it = pFacs.begin();it != pFacs.end();++it)	
	{
		cout << "first and second " << it->first << "  " << it->second <<  endl;
		if(it->second != 0)
			counter = (counter * (it->second+1));
	}
	cout << endl;

*/
	//if(counter == 6)
	if(counter > 500)
		return true;
	else
		return false;


}
