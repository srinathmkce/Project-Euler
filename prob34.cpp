#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{

	map<int, int> fact;
	vector<int> answer;

	fact[0] = 1;

	for(int i=1; i<10; i++)
	{
		int val = i * fact[i-1];
		fact[i] = val;
	}

	for(int i=1; i<10; i++)
	cout << fact[i] <<endl;

	int num = 3;
	while(1)
	{
		break;
		cout << num << endl;
		if(num == 10000000)
		break;
		
		int temp = num;
		int sum = 0;
		while(temp > 0)
		{
			sum = sum + fact[temp%10];
			temp = temp/10;
		}
		if(num == sum)
			answer.push_back(num);	
		num++;

	}

	cout << "Answer is " << endl;
	for(int i=0; i<answer.size(); i++)
	cout << answer[i] << endl;


	return 0;
}
