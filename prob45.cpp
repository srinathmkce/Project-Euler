#include <iostream>
#include <vector>

using namespace std;
bool binarySearch(unsigned long long  min, unsigned long long  max, unsigned long long  key, vector<unsigned long long > input);
int main()
{
vector<unsigned long long > tri;
vector<unsigned long long > hex;
vector<unsigned long long > pent;
unsigned long long  lower_bound = 100;
unsigned long long  upper_bound = 100000;
for(unsigned long long  num = 0; num < upper_bound ; num++)
{
tri.push_back(0);
hex.push_back(0);
pent.push_back(0);
}
for(unsigned long long  num = lower_bound ; num < upper_bound ; num++)
{

	unsigned long long  x = (num * (num +1) ) / 2;
	unsigned long long  y = (num * (3 * num - 1) ) / 2;
	unsigned long long  z = (num * (2 * num - 1) );
	tri[num] = x;
	pent[num] = y;
	hex[num] = z;


	// check if x is already there in pent
	if(binarySearch(lower_bound ,num,x,pent))
	{

		if(binarySearch(lower_bound ,num,x,hex))
		{
			cout << "Answer is " << num  << "  " << x << endl;
		}

	}

}

	return 0;
}

bool binarySearch(unsigned long long  min, unsigned long long  max, unsigned long long  key, vector<unsigned long long > input)
{

	while(max >= min)
	{
		unsigned long long  mid = (min + max)/2;

		if(input[mid] == key)
			return true;
		else if(input[mid] < key)
			min = mid + 1;
		else 
			max = mid - 1;


	}

	return false;
}

