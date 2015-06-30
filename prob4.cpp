#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool isPalindrome(int num );
int recurse(int num );
int sum = 0;
double cnt = 0;
int main()
{
	int start = 999;
	int end = 999; 
	int max = 0;
	int temp = 0;
	string maxString = "";




#ifdef PALINDROME
	for(int i = 999 ; i >= 100 ; i--)
	{
		for(int j = 999 ; j >= 100 ; j--)
		{
			sum = 0;
			cnt = 0;
			int prod = i*j;
			//cout << prod << "   " << recurse(prod) << endl;
			if((prod == recurse(prod)) && prod > max)
			{
				max = prod;
			}

		}

	}
	cout << "Max is " << max << endl;
#else
			//if(isPalindrome(998001))
			recurse(1234);
#endif

	
			//string prodStr = "";
			//string revStr = "";
			//stringstream out;
			//out << prod;
			//prodStr = out.str();
			//for(int i = prodStr.length() ; i>=0 ; i--)
			//{
			//	revStr = revStr + prodStr[i];
			//}
			//revStr.erase(0,1);

			//if(prodStr == revStr)
			//{
			//	temp = atoi(prodStr);
			//}
	//	}
	//}

	
	return 0;
}

//bool isPalindrome(int num)
//{
//	int a=0;
//	int b=0;
//	int revnum=0;
//	double cnt = 0;
//	b = num;
//	while(b)
//	{
//		a = b % 10;
//		b = b/10;
//		revnum = revnum + a*pow(10,cnt);
//		cnt++;
//	}
//	if(num == revnum)
//		return true;
//	else
//		return false;
//}

int recurse(int number)
{
	int rem = 0;
	if(number > 0)
	{
		rem = number % 10;
		number = number /10;
		recurse(number);
		sum += rem * pow(10,cnt);
		cnt++;
		//cout << " sum is " << sum << endl;
	}
	return sum;
}
