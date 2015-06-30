#include <iostream>
#include <vector>
using namespace std;

bool isAbundant(int num);
int main()
{
	vector <int> abun;
	vector <int> sumabun;
	vector <int> output;
	// iterating thro all 28123 numbers

		
	for(int i=1; i<28124; i++)
	{
		output.push_back(i);	
		// pass no. to find divisors
		if(isAbundant(i))
		abun.push_back(i);

	}

	// iterate thro each and every number till the end of vector and sum two 
	// 1 2 3 4 5 
	// 1+2, 1+3, 1+4 , 1+5 
	for(int i=0; i<abun.size(); i++)
	{

		for(int j=i; j<abun.size(); j++)
		{
			int sum = abun[i] + abun[j]; 
			sumabun.push_back(sum); // sum of all possible numbers
			output.erase(remove(output.begin(), output.end(),sum), output.end());
		}
	}

	unsigned long long so = 0;
	for(int i=0; i<output.size(); i++)
		so = so+ output[i];


	cout << so << endl;
		
		


	return 0;
}



// function to find the divisors and add it
bool isAbundant(int num)
{
	int sum = 0;
	for(int i=1; i<=num/2; i++)
	{
		if(num % i == 0) // i is the divisor
		{
			sum = sum + i; // sum all divisors
		}

	}
	return (sum>num)?true:false;
}
