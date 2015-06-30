#include <iostream>
#include <vector>
#include <map>

using namespace std;

int checkNMinusR(int n, int r);
void populateArray(int n , int r, vector<int> &nFact, vector<int> &rFact, vector<int> &nMinusRFact);
void calculate(int n , int r, vector<int> nFact, vector<int> rFact, vector<int> nMinusRFact);

int main()
{
	//int n = 23;
	//int r = 1;
	int count = 0;

	for(int n=5; n<101; n++)
	{
		//cout << "N : " << n << endl;
		map<int,bool> mapping;
		for(int r=1; r<=n; r++)
		{
			//cout << "R : " << r << endl;
			int ret = checkNMinusR(n,r);
			int j;
			int i;
			bool found = false;

			vector<int> num;
			vector<int> den;
			for(i=n, j=1; j<=ret; i--,j++)
			{
				num.push_back(i);
				//if(j != 1)
				den.push_back(j);
			}
			double product = 1;
			// if the value of r is present in the mapping, it means its already computer. No need to compute again. 
			// check if the value is true , if so increment counter
			if(mapping.find(ret) != mapping.end())
			{
				if(mapping.find(ret)->second == true)
					count++;
				continue;

			}

			for(i=0, j=0; i<num.size(), j<den.size(); i++,j++)
			{
				double div = (double)num[i]/(double)den[j];
				//cout << "Num den, div " << num[i] << "  " << den[j] << "  " <<  div << endl;
				product = product * div;
				//cout << "Product is " << product << endl;
				if(product > 1000000)
				{
					//cout << "here" << endl;
					count++;
					found = true;
					break;
				}

			}
			mapping.insert(pair<int,bool>(ret,found));


		}
	}
			cout << "Count is " << count << endl;

	return 0;
}



int checkNMinusR(int n, int r)
{

	if(n-r > r)
		return r;
	else
		return n-r;

}
