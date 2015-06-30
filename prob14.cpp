#include <iostream>
#include <map>

using namespace std;

int counter = 0;
unsigned long long countSeq(unsigned long long value);
int main()
{
	unsigned long long max = 0;
	for(unsigned long long i = 2; i<= 1000000; i++)
	{
		cout << i << "  " << countSeq(i) << endl;
		if(counter > max)
			max = counter;
		counter = 0;	
	}
	cout << max << endl;
	return 0;
}

unsigned long long countSeq(unsigned long long value)
{
	counter++;
	if(value == 1)
		return counter;
	else
	{
		if(value % 2 == 0)
			return countSeq(value/2);
		else
			return countSeq(value * 3 + 1);
	}


}
