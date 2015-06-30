#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

	map<int,string> alpha;
	map<int,string>::iterator it;
string calcName(int);
string calcTwoDigit(int num);
string calcnTen(int num);
int main()
{

	alpha.insert(pair<int,string>(0,""));
	alpha.insert(pair<int,string>(1,"one"));
	alpha.insert(pair<int,string>(2,"two"));
	alpha.insert(pair<int,string>(3,"three"));
	alpha.insert(pair<int,string>(4,"four"));
	alpha.insert(pair<int,string>(5,"five"));
	alpha.insert(pair<int,string>(6,"six"));
	alpha.insert(pair<int,string>(7,"seven"));
	alpha.insert(pair<int,string>(8,"eight"));
	alpha.insert(pair<int,string>(9,"nine"));
	alpha.insert(pair<int,string>(10,"ten"));
	alpha.insert(pair<int,string>(11,"eleven"));
	alpha.insert(pair<int,string>(12,"twelve"));
	alpha.insert(pair<int,string>(13,"thirteen"));
	alpha.insert(pair<int,string>(14,"fourteen"));
	alpha.insert(pair<int,string>(15,"fifteen"));
	alpha.insert(pair<int,string>(16,"sixteen"));
	alpha.insert(pair<int,string>(17,"seventeen"));
	alpha.insert(pair<int,string>(18,"eighteen"));
	alpha.insert(pair<int,string>(19,"nineteen"));
	alpha.insert(pair<int,string>(20,"twenty"));
	alpha.insert(pair<int,string>(30,"thirty"));
	alpha.insert(pair<int,string>(40,"forty"));
	alpha.insert(pair<int,string>(50,"fifty"));
	alpha.insert(pair<int,string>(60,"sixty"));
	alpha.insert(pair<int,string>(70,"seventy"));
	alpha.insert(pair<int,string>(80,"eighty"));
	alpha.insert(pair<int,string>(90,"ninety"));
	alpha.insert(pair<int,string>(100,"hundred"));
	alpha.insert(pair<int,string>(1000,"thousand"));

	string output = "";

	for(int num = 1 ; num <= 20; num ++)
	{
		it = alpha.find(num);
		output += it->second;
		cout << num << "->" << it->second << endl;
	}
	string sn = "";
	for(int num = 21 ; num <= 999; num++)
	{
		if(num < 100)
		{
			output += calcTwoDigit(num);		
			cout << num << "->" << calcTwoDigit(num) << endl;
			continue;
		}
		else if((num / 10) % 10 == 1)
		{
			//if(num % 10 == 0)
			output +=  calcnTen(num);
				cout << num << "->" << calcnTen(num) << endl;
				continue;
			
		}
		else if(num > 100 && (num % 10 == 1 && (num / 10) % 10 == 1 ))
		{
			if(num % 10 == 0)
			{
					output +=  calcnTen(num);
				cout << num << "->" << calcnTen(num) << endl;
				continue;
			}

			cout << num << "->        " << endl;
			continue;
		}
		else
		{
			cout << num << "->" << calcName(num) << endl;
			output += calcName(num);
			//output +="\n";
		}
	}
	output += "onethousand";
	//cout << output << endl;
	cout << output.length() << endl;

	/*
	   string output = calcName(223);
	   cout << output << endl;
	 */	
	return 0;
}
string calcnTen(int num)
{
string out = "";
int hDigit = num / 100;
it = alpha.find(hDigit);
out += it->second + "hundredand";
num = num - hDigit*100;
it = alpha.find(num);
out += it->second;

return out;

}

string calcTwoDigit(int num)
{
	if(num % 10 == 0)
	{
		it = alpha.find(num);
		return it->second;
	}
	string out = "";
	int unitDigit = num % 10;
	int tensDigit = num - unitDigit;
	it = alpha.find(tensDigit);
	out += it->second;
	it = alpha.find(unitDigit);
	out += it->second;
	return out;
}

string calcName(int num)
{
	string result = "";
	string temp = "";

	if(num % 100 == 0)
	{
		num = num / 100;
		it = alpha.find(num);
		return it->second + "hundred";
	}

	int unitDigit = num % 10;
	int tensDigit = num % 100;
	stringstream ss;
	ss << num;
	string snum;
	snum = ss.str();

	string keyword = "";
	if(snum.length() == 3 && snum[1] == 0 && snum[2] == 0)
		keyword = "hundred";
		else
		keyword = "hundredand";
	for(int j=0 ; j<snum.length() ; j++)
	{
		int a = snum[j] - '0';
		if(a != 1 & j == 1)
			a = a * 10;
		it = alpha.find(a);
		temp = temp + it->second + keyword ;
		keyword = "";
	}

	return temp;
}


