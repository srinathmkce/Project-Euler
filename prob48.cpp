#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;
void calcSelfPowers(int n ,int max ,vector<int> &dig);
void calcSum(vector<int> digits, vector<int> &sum);


// say , we have to calculate 17^17
// first we need to push 17 into the vector num
// now , we need to iterate max -1 times .i.e 16 times
// first time, we derive 17 as 7 and 1
// First take 7 and multiply it with num vector from last to first and store it in temp vector
// Take 1 and multiply it with num and store it in another temp vector
// add two vectors and store the result in temp ans vector
// this gives you 17 power 17 .. and we need to add it to the main ans vector to get the result

int main()
{
	vector<int> digits;
	vector<int> sum;
	

	for(int num = 1000 ; num > 0; num--)
	{
	cout << num << endl;
		calcSelfPowers(num,num,digits);
		calcSum(digits, sum);
		digits.clear();

	}

	cout << "Total size is " << sum.size() << endl;
	int count = 0;
	for(int i= sum.size()-1; i>=0; i--)
	{
	count++;
	cout << sum[i] << "  " ;
	if(count == 10)
	break;
	}
	
	return 0;
}


void calcSum(vector<int> digits, vector<int> &sum)
{

	vector<int> temp;
	int dsize = digits.size();
	int ssize = sum.size();
	vector<int> ::reverse_iterator rit;
	vector<int> ::reverse_iterator rit1;

	if(ssize == 0)
	{
		sum = digits;
		return;
	}
	else
	{
		stack<int> ssum;
		for(int i=0; i<sum.size();i++)
		ssum.push(sum[i]);

		stack<int> sdig;
		for(int i=0; i<digits.size();i++)
		sdig.push(digits[i]);


		int carry = 0;
		while(!ssum.empty())
		{
			if(!sdig.empty())
			{

				int add = ssum.top() + sdig.top() + carry;
				carry = add / 10;
				temp.push_back(add%10);
				ssum.pop();
				sdig.pop();
			}
			else
			{
				int add = ssum.top() + carry;
				carry = add / 10;
				temp.push_back(add % 10);
				ssum.pop();
			}

		}

		while(carry > 0)
		{
		temp.push_back(carry % 10);
		carry = carry / 10;
		}
	
		reverse(temp.begin(), temp.end());
		sum.clear();
		sum = temp;



	}


}


void calcSelfPowers(int n ,int max ,vector<int> &temp1)
{

	// push the number n into the temp2 vector
	vector<int> temp2;
	
	// convert the number n to string
	string sn;
	stringstream ss;
	ss << n;
	sn = ss.str();

	for(int i=0; i<sn.length();i++)
	temp1.push_back(sn[i]-'0');

	// run the loop max-1 times
	for(int l=0; l<max-1;l++)
	{
		int carry = 0;
		// each time, multiply the number n with vector

		for(int i=temp1.size()-1; i>=0; i--)
		{
		int ans = temp1[i] * n + carry;
		carry = ans / 10;
		int digit = ans % 10;
		temp2.push_back(digit);

		}

		while(carry > 0)
		{
			temp2.push_back(carry % 10);
			carry = carry/10;
		}


		// copy temp2 to temp1
		temp1.clear();
		int k;
		reverse(temp2.begin(),temp2.end());
		temp1 = temp2;
		temp2.clear();

	}

/*
	for(int i=0; i<temp1.size(); i++)
	cout << temp1[i] << "  " ;
	cout << endl;
	*/


}




