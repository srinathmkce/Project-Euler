#include <iostream>
#include <vector>
#include <set>

using namespace std;
void generatePrimes(vector<bool> &primes, vector<int> &output, double n);

int main()
{
		vector<bool> input;
		vector<int> primes; 
		generatePrimes(input, primes, 300000);

	vector<bool> ans;

	for(int num=2; num<300000; num++)
	ans.push_back(false);
	for(int num=2; num<300000; num++)
	{
		int temp = num;
		set<int> factors; 
		set<int> ::iterator it; 

		if(num % 100000 == 0)
		cout << num << endl;

		int i = 0;
		while(i<primes.size())
		{

			if(temp == 1 || temp == 0)
				break;
			if(temp % primes[i] == 0)	
			{
				factors.insert(primes[i]);
				temp = temp / primes[i];
				i = -1;


			}

			i++;

		}


		if(factors.size() == 4)
		{
			/*
			if(num > 253890 && num < 253900)
			{
				cout << "Num " << num << endl;
				for(it=factors.begin(); it!= factors.end(); it++)
				{
					cout << *it << "  ";	
				}
				cout << endl;
			}
			*/
			ans[num] = true;					
		}
		factors.clear();
	}

	for(int i=2; i<ans.size()-4; i++)
	{
		if(ans[i] == true && ans[i+1] == true && ans[i+2] == true && ans[i+3] == true)
		cout << "Answer is " << i << endl;

	}


	for(int i=253894; i<253900; i++)
	cout << ans[i] << endl;

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

