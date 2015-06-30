#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int findLargestIndexK(vector<int> perm);
int findLargestIndexL(int k, vector<int> perm);
void reverseSequence(int start, int end, vector<int> &perm);
void swap(int &k, int &l);


int main()
{
	vector<string> check;
	vector<string> answer;
	vector<int> perm;
	perm.push_back(0);
	perm.push_back(1);
	perm.push_back(2);
	perm.push_back(3);
	perm.push_back(4);
	perm.push_back(5);
	perm.push_back(6);
	perm.push_back(7);
	perm.push_back(8);
	perm.push_back(9);

	   cout <<"generating number" << endl;
	   while(1)
	   {
	// step 1 , find largest index
	int k = findLargestIndexK(perm);
	if(k == -1)
	break;
	//cout << "K is " << k << endl;
	int l = findLargestIndexL(k,perm);
	//cout << "l is " << l << endl;
	swap(perm[k],perm[l]);
	reverseSequence(k+1,perm.size()-1,perm);
	string seq = "";
	for(int i=0; i<perm.size(); i++)
	{
	int digit = perm[i];
	stringstream ss;
	ss << digit;

	seq += ss.str();
	}
	check.push_back(seq);
	}

	cout <<"After generating number" << endl;

	for(int i=0; i<check.size(); i++)
	{

	string num = check[i];
	string div2 = num.substr(1,3);



	// condition for num 2
	if( (div2[div2.length()-1] - '0') % 2 != 0)
	{
	continue;
	}

	// condition for num 3
	string div3 = num.substr(2,3);
	int count = 0;
	for(int i=0; i< div3.length() ; i++)
	{
	count = count + (div3[i] - '0');
	}
	if(count % 3 != 0)
	{
	continue;
	}


	// condition for 5

	string div5 = num.substr(3,3);
	if(div5[div5.length()-1] != '0' && div5[div5.length()-1] != '5')
	{
	continue;
	}

	// condition for 7, 11, 13 and 19

	string div7 = num.substr(4,3);
	int id7 = atoi(div7.c_str());

	string div11 = num.substr(5,3);
	int id11 = atoi(div11.c_str());

	string div13 = num.substr(6,3);
	int id13 = atoi(div13.c_str());

	string div17 = num.substr(7,3);
	int id17 = atoi(div17.c_str());

	if(id7 % 7 != 0 || id11 % 11 != 0 || id13 % 13 != 0 || id17 % 17 != 0)
	{
		continue;
	}

	cout << "Answer is " << num << endl;
	answer.push_back(num);

}

cout << "Answer is " << endl;
int carry = 0;
for(int i=9; i>=0; i--)
{
	int output = 0;
	for(int j=0; j<answer.size(); j++)
	{
		string word = answer[j];
		output = output + (word[i] - '0') + carry;

	}
		cout << output % 10;
		carry = output / 10;
}
if(carry > 0)
	cout << carry;
	return 0;

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
