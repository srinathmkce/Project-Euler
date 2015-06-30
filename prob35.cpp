#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void generatePrimes(vector<int> &output, int n);
bool binarySearch(vector<int> &primes, int key, int min, int max);
int main()
{
	vector<int> primes;
	vector<int> check;
	check.push_back(2);
	generatePrimes(primes, 1000000);

	for(int num = 3; num < 1000000; num++)
	{
		stringstream ss;
		ss << num;
		string sn = ss.str();

		if(sn.find("0") == -1 && sn.find("2") == -1 && sn.find("4") == -1 && sn.find("6") == -1 && sn.find("8") == -1 )
		{
			if(binarySearch(primes,num,0,primes.size()-1))
				check.push_back(num);
		}

	}

	for(int i= 0; i<check.size() ; i++)
	{

		int num = check[i];
		int temp = num;

		int output = 0;
		int count = 1;
		bool is_prime = true;
		while(output != num)
		{
			output = 0;

			while(temp > 0)
			{

				int digit = temp % 10;
				if(temp > 9)
					output = output  + digit * pow(10,count);
				else
					output = output + digit;

				count++;
				temp = temp / 10;

			}
			count = 1;
			temp = output;


			bool ret_val = binarySearch(primes,output,0,primes.size()-1);
			if(!ret_val)
			{
				is_prime = false;
				break;	
			}


		}

		if(is_prime == true)
			cout << num << endl;


	}
	return 0;
}



void generatePrimes(vector<int> &output, int n)
{
        //cout << "Generating Primes" << endl;
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

        //cout << "Exiting Generate Primes" << endl;
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

