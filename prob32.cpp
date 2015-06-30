#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int main()
{

	vector<bool> digitCounter;
	int sum = 0;
	digitCounter.clear();
	int a ,b;
	set<int> ans;
	set<int> ::iterator it;
			for(int i=0; i<10; i++)
			{
				digitCounter.push_back(false);
			}

	for(a=1; a<10000; a++)
	{

		for(b=1; b<10000; b++)
		{
			for(int i=0; i<10; i++)
				digitCounter[i] = false;
			// converting a to string
			stringstream ss;
			ss << a;
			string x = ss.str();


			// converting b to string
			ss.str("");
			ss.clear();
			ss << b;
			string y = ss.str();

			// calculate the product

			int c = a * b;
			ss.str("");
			ss.clear();

			// coverting c to string
			ss << c;
			string z = ss.str();


			// 1. if any of the digit contains 0 then number should be ignored
			string con = x + y + z;	

			if(con.find("0") != -1)
			{
				//cout << "Continue " << endl;	
				continue;
			}


			// 2. length of all 3 numbers together should form 10


			if(con.length() != 9)
			{
				//cout << "Continue " << endl;	
				continue;
			}


			// 3. if a number is repeated, then it should be ignored
			bool repeated = false;
			for(int i=0; i<con.length(); i++)
			{
				int d = con[i] - '0';

				if(digitCounter[d] == true)
				{
					repeated = true;
					break;
				}
				else
				{
					digitCounter[d] = true;
				}
			}
			if((repeated == true))
			{
				//cout <<"continue" << endl;
				continue;
			}
			else
			{
				cout << x  << " " << y << "  " << z << endl;
				ans.insert(c);
				
			}



		}
	}

	for(it=ans.begin(); it!= ans.end(); it++)
	{

		sum = sum + *it;
		cout << *it << endl;
	}
	cout << "Answer is " << sum;

	

	return 0;
}

