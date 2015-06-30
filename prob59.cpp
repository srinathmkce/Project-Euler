#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int main()
{

	//char a = 'a';
	//int a_ascii = int(a);
	/*
	for(char i= 97 ; i<= 122 ; i++)
	{
		for(char j= 97 ; j<= 122 ; j++)
		{
			for(char k= 97 ; k<= 122 ; k++)
			{

				char mul_i = 79;
				char out_i = i ^ mul_i;

				char mul_j = 59;
				char out_j = j ^ mul_j;

				char mul_k = 12;
				char out_k = k ^ mul_k;

				char mul_m = 2;
				char out_m = i ^ mul_m;

				char mul_n = 79;
				char out_n = j ^ mul_n;

				cout << "key [" << i << j << k << "]" << "   " <<  out_i << out_j << out_k << out_m << out_n << endl;

			}
		}
	}

	*/


	fstream file("resource_prob59.txt", ios::in);

	string line;
	while(getline(file,line))
	{
	}

//	cout << line << endl;
vector<char> fin;

		string num = "";
	for(int i=0; i<line.length(); i++)
	{

		if(line[i] == ',')
		{
			int inum = atoi(num.c_str());
			char cnum = inum;
			fin.push_back(cnum);
			num = "";
		}
		else
		{
			num += line[i];
		}
	}

	num = "73";
		int inum = atoi(num.c_str());
			char cnum = inum;
			fin.push_back(cnum);


	int count = 0;
	long answer = 0;
	for(int i=0; i<fin.size(); i++)
	{
		char a =  int(fin[i]) ;
		char o;
		if(count == 0)
			o = a ^ 'g';

		if(count == 1)
			o = a ^ 'o';

		if(count == 2)
			o = a ^ 'd';

		cout << o  << "  " << int(o) << endl;
		//cout << o ;
		answer += int(o);

		count++;
		if(count == 3)
			count = 0;
	}
	cout << "Answer is " << answer << endl;
	return 0;
}
