#include <iostream>
#include <set>
using namespace std;
int findSumOfDivisors(int n);
int main()
{
set<int> outValue;
set<int>::iterator it ;
// finding input for all the numbers .

for(int num=1; num<=10000; num++)
{
	int s_o_d = 0;
	// find the sum of divisors
	s_o_d = findSumOfDivisors(num);

	if(num == findSumOfDivisors(s_o_d) && num != s_o_d)
	{
		cout << num << "  " << s_o_d << endl;
		outValue.insert(num);
		outValue.insert(s_o_d);
		
	}


}
cout << "Size of set is " << outValue.size() << endl;
int output = 0;
for(it=outValue.begin(); it!=outValue.end();it++)
output = output + *it;
cout<<"answer is "<< output << endl;


return 0;
}


int findSumOfDivisors(int n)
{
	int sum = 0;
	for(int i=1; i<=n/2; i++)
	{
		if(n%i == 0)
			sum = sum + i;
	}
	return sum;
}
