#include <iostream>
#include <vector>

using namespace std;
void generatePrimes(vector<bool> &primes, vector<int> &output, double n);
bool binarySearch(vector<int> primes, int key, int min, int max);

int main()
{
vector<bool> input;
vector<int> primes;
vector<int> cons;

generatePrimes(input,primes,1000000);


int i = 0;
int sum = 0;
int max = 0;
int length = 0;
while(i<primes.size())
{
	cout << i << endl;
	for(int j=i; j<primes.size(); j++)
	{
		sum = sum + primes[j];
		if(sum > 1000000)
		break;
			cons.push_back(primes[j]);
		if(binarySearch(primes,sum,0,primes.size()-1))
		{

			if(sum > max &&  cons.size() >= length)
			{
				max = sum;
				length = cons.size();
				/*
				cout << "Nums ";
				for(int k=0; k<cons.size(); k++)
				{
				cout << cons[k] << "  ";
				}
				cout<< endl;
				cout << "Max is " << max << "  " << length << endl;
				cout << "Sum is " << sum << endl;
				*/
			}
		}

	}

	sum = 0;
	cons.clear();

	i++;
}
cout << "Max is " << max << " length is " << length << endl;


/*

int sum = 0;
int max = 0;
int counter = 0;
for(int i=0; i<primes.size(); i++)
{
	for(int j=i; j<primes.size(); j++)
	{
		sum = sum + primes[j];
		cons.push_back(primes[j]);
		counter++;
		if(binarySearch(primes,sum,j,primes.size()-1))
		{
			if(sum > max)
			{
				cout << "max is " << max << " counter is " << counter <<  endl;
				for(int k=0; k<cons.size(); k++)
				cout << cons[k] << "  ";
				cout << endl;
				max = sum;
			}
		}
	}
    counter = 0;
	sum = 0;
}
cout << "Answer is " << max;
*/

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


bool binarySearch(vector<int> primes, int key, int min, int max)
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


