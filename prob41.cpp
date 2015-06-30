#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int findLargestIndexK(vector<int> perm);
int findLargestIndexL(int k, vector<int> perm);
void reverseSequence(int start, int end, vector<int> &perm);
bool binarySearch(vector<int> &primes, int key, int min, int max);
void generatePrimes(vector<int> &output, int n);
void swap(int &k, int &l);
int main()
{

	vector<int> perm;
	perm.push_back(1);
	perm.push_back(2);
	perm.push_back(3);
	perm.push_back(4);
	perm.push_back(5);
	perm.push_back(6);
	perm.push_back(7);
	vector<int> primes;
	vector<int> check;
	generatePrimes(primes, 9999999);

	while(1)
	{
		// step 1 , find largest index
		int k = findLargestIndexK(perm);
		stack<int> st;
		if(k == -1)
			break;
		int l = findLargestIndexL(k,perm);
		swap(perm[k],perm[l]);
		reverseSequence(k+1,perm.size()-1,perm);
		for(int i=0; i<perm.size(); i++)
			st.push(perm[i]);

		int output =0;
		while(!st.empty())
		{
		int digit = st.top();
		st.pop();
		output = output * 10 + digit;
		}
		check.push_back(output);
	}

	int max = 0;
	for(int i=0; i<check.size(); i++)
	{
		if(binarySearch(primes,check[i],0,primes.size()-1))
		{
			if(max < check[i])
			max = check[i];

		}
		
	}

	cout << max << endl;
	return 0;
}

void generatePrimes(vector<int> &output, int n)
{
        cout << "Generating Primes" << endl;
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




void reverseSequence(int start, int end, vector<int> &perm)
{
for(int i=start,j=end; i<j; i++,j--)
{
swap(perm[i],perm[j]);
}

}

int findLargestIndexK(vector<int> perm)
{

	for(int i=perm.size()-1; i>0; i--)
	{
		if(perm[i] > perm[i-1])
		{
			return i-1;
		}

	}

	return -1;
}

int findLargestIndexL(int k, vector<int> perm)
{
	for(int i=perm.size()-1; i>k; i--)
	{
		if(perm[i] > perm[k])
		{
			return i;
		}
	}

	return -1;

}


void swap(int &k, int &l)
{
int temp;
temp = k;
k = l;
l = temp;

}
