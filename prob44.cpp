#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(int min, int max, int key, vector<int> pent);
int main()
{
	vector<int> pent;
	int minimized_diff = 1000000;

	int num = 3;
	while(true)
	{
		if(num == 100000)
			break;
		pent.push_back((num * ( (3 * num) -1)) / 2);
		num++;
	}

	cout << pent.size() << endl << endl;
	for(int i=0; i<pent.size(); i++)
	{
		cout << "i is" << i << endl;
		for(int j=i+1; j<pent.size(); j++)
		{
			int sum = pent[i] + pent[j];
			int diff = pent[i] - pent[j];
			if(binarySearch(0,pent.size()-1,sum,pent) && binarySearch(0,pent.size()-1,diff,pent))
			{
				cout << "i is " << i << endl;
				cout << "j is " << j << endl;
				cout << "pent[i] " << pent[i] << endl;
				cout << "pent[j] " << pent[j] << endl;
				if(diff < minimized_diff)
				{
					minimized_diff = diff;
				}
			}


		}

	}

	cout << "Amswer is " << minimized_diff << endl;

	return 0;
}


bool binarySearch(int min, int max, int key, vector<int> pent)
{

	while(max >= min)
	{

		int mid = (min + max) / 2;
		if(pent[mid] == key)
		{
			return true;
		}

		else if(pent[mid] < key)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}

	}

	return false;

}



