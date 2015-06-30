#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
 void generatePrimes(vector<int> &output, int n);
int main()
{

	vector<int> primes;
	generatePrimes(primes,1000000);
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

