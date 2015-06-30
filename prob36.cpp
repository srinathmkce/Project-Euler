#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

bool palindromeBase10(unsigned long long num);
bool palindromeBase2(unsigned long long num);
int main()
{
	unsigned long long sum = 0;
	for(unsigned long long num=1; num<1000000; num++)
	{
		if(palindromeBase10(num))
		{
			if(palindromeBase2(num))
			{
				sum = sum + num;
				cout << num << endl;
			}


		}
	}
	cout << "Answer is " << sum << endl;

	return 0;
}

bool palindromeBase10(unsigned long long num)
{

	unsigned long long temp = num;
	unsigned long long output = 0;
	unsigned long long count = 0;
	while(temp > 0)
	{
		unsigned long long digit = temp % 10;
		temp = temp / 10;
		output = output * 10 + digit;
		count++;
	}

	if(output == num)
		return true;

	else
		return false;


}

bool palindromeBase2(unsigned long long num)
{
	stack<unsigned long long> val;
	queue<unsigned long long> rev;
	unsigned long long temp = num;
	string pal = "";
	while(temp > 0)
	{
		unsigned long long digit = temp % 2;
		temp = temp / 2;
		val.push(digit);
		rev.push(digit);
	}

	while(!val.empty())
	{
		unsigned long long x = val.top();
		val.pop();
		stringstream ss;
		ss << x;
		string s = ss.str();
		pal = pal + s;
	}
	string revString;

	for(int i=pal.length()-1; i>=0; i--)
	{
		if(revString.empty()  && pal[i] == '0')
		{
		continue;
		}
		
		revString = revString + pal[i];
	}
	if(pal == revString)
	{
		return true;
	}
	else
	{
		return false;
	}

	/*
	unsigned long long stackNum = 0;
	while(!val.empty())
	{
		unsigned long long x = val.top();
		val.pop();
		if(stackNum == 0 && x == 0)
			continue;

		stackNum = stackNum * 10 + x;

	}

	unsigned long long queueNum = 0;
	while(!rev.empty())
	{
		unsigned long long y = rev.front();
		rev.pop();
		if(queueNum == 0 && y == 0)
			continue;

		queueNum = queueNum * 10 + y;
	}


	if(stackNum == queueNum)
	{
		cout << stackNum ;
		return true;
	}
	else
		return false;

	*/

}
