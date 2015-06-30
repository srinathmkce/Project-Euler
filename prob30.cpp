#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
map<int, int> powers;
for(int i=0; i<10; i++)
{
	powers[i] = pow(i,5);
}
int num = 2;
int answer = 0;
while(1)
{
	if(num == 10000000)
	break;
	int temp = num;
	int sum = 0;
	while(num > 0)
	{
		int digit = num % 10;
		num = num / 10;
		//cout << digit<< "  " << powers[digit] << endl;
		sum = sum + powers[digit];

	}

	if(sum == temp)
	{
		cout << temp << endl;
		answer = answer + temp;
	}

	num = temp;
	sum = 0;
	num++;
}

cout << "Answer is " << answer << endl;

return 0;
}
