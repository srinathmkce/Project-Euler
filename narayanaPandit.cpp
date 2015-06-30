#include <iostream>
#include <vector>

using namespace std;

int findLargestIndexK(vector<int> perm);
int findLargestIndexL(int k, vector<int> perm);
void reverseSequence(int start, int end, vector<int> &perm);
void swap(int &k, int &l);
int main()
{

	vector<int> perm;
	perm.push_back(1);
	perm.push_back(2);
	perm.push_back(3);
	perm.push_back(4);

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
		//cout << "After swapping " << endl;
		/*
		   for(int i=0; i<perm.size(); i++)
		   cout<<perm[i] << "  " ;
		   cout << endl;
		   cout << endl;
		*/
		reverseSequence(k+1,perm.size()-1,perm);
		for(int i=0; i<perm.size(); i++)
			cout<<perm[i] << "  " ;
		cout << endl;
	}
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
