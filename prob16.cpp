#include <iostream>
#include <sstream>

#include <string>

using namespace std;

void multiply(string &num);

int main()
{
	string snum = "1";
	int quo = 0;
	int rem = 0;
	int inp;
	//cin>>inp;

	//cout << "Entering the program" << endl;
	// for each power
	for(int i=1 ; i<=1000;i++)
	{
		multiply(snum);
	}
	//cout << "Num is " << snum << endl;
	int sum = 0;
	for(int i=0; i<snum.length(); i++)
	{

		int d = snum[i] - '0';
		sum = sum + d;

	}

	cout << sum << endl;
	return 0;
}


void multiply(string &num)
{
	//cout << "Entering multiply " << endl;
	if(num.length() == 1)
	{

		int digit = num[num.length()-1] - '0';
		digit *= 2;
		stringstream ss;
		ss << digit;
		num = ss.str();
		//cout << "Returning " << num << endl;
		return;
	}

	//cout << endl;
	int rem = 0;
	string temp = "";
	for(int j=num.length()-1 ; j >=0 ; j--)
	{
		//cout << "Rem Before : " << rem << endl; 
		int digit = num[j] - '0';
		//cout << "Digit : " << digit << endl; 
		int mul = digit * 2 + rem;
		//cout << "Mul : " << mul << endl; 
		if(mul >= 10)
			rem = mul / 10;
		else
			rem = 0;
		//cout << "Rem After : " << rem << endl; 
		stringstream ss;
		if(j == 0)
		ss << mul;
		else
		ss << (mul % 10);
		string sn = ss.str();
		temp = sn + temp ;
		//cout << "Num : " << temp << endl; 
		//cout << endl;
	}
	num = temp;


}

