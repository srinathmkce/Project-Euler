#include <iostream>
#include <vector>
#include <map>

using namespace std;
int populateVector(int d);
int repeatLength(vector<int> result);
int checkValueExists(int v, vector<int> output);
int main()
{
int sum = 0;
int r;
for(int den=2; den<1000; den++)
{
	int answer = 0;
	answer =  populateVector(den);
	cout << "den " << den << "answer " << answer << endl;
	if(sum < answer)
	{
		sum = answer;
		r = den;
	}

}
cout << "Result is " <<  r << endl;
return 0;
}

int populateVector(int d)
{
	vector<int> result;
	int quo = 0;
	int rem = 0;
	int num = 1;
	int counter = 0;
	while(1)
	{
		if(result.size() == 10000)
			break;
		// check if digit is lesser, if so increase num by *10
		while(num < d)
		{
			num *= 10;
			if(counter > 0)
			{
				if(result.size() == 10000)
					break;
				result.push_back(0);
				if(result.size() == 10000)
					break;
			}
			counter = counter + 1;

		}
		counter = 0;
		if(result.size() == 10000)
			break;

		// find quo and remainder	
		quo = num/d;
		rem = num % d;
		if( rem == 0)
		{
			return 0;
		}
		

		result.push_back(quo);
		num = rem;
	}

	/*
	for(int i=0; i<result.size(); i++)
		cout << result[i] << "  " ;
		cout << endl;
	*/

	return repeatLength(result);
}

int repeatLength(vector<int> result)
{
	vector<int> tempVec;
	vector<int> toPush;
	int answer = 0;
	bool flag = false;
	bool repeat = true;
	int first = 0;
	int last = -1;
	int j;
	tempVec.clear();


	for(int i=0; i<result.size()-1; i++)
	{
		answer = 0;
		flag = false;
		int value = result[i];
		//cout << "value is " << value << endl;
		// check if value exists 
		int index  = 0;
		index = checkValueExists(value, tempVec);


		//cout << "index is " << index << endl;
		// index is the place where the value is there
		if(index != -1 )
		{
			int j,k;
			// value exists ..
			int t_size = tempVec.size();
			int t_end = t_size - index;
			//cout << "t_size is " << t_size << endl;
			//cout << "t_end is " << t_end << endl;


			for(j=index, k=i ; j<t_size , k<i+t_end; j++,k++)
			{
				//cout << "j = " << j << "  " << "k = " << k << "  " << "t_size = " << t_size << " i+t_end = " << i + t_end << endl;
				//cout << "tempvec[j] = " << tempVec[j] << "  " << "result[k] = " << result[k] << endl;

				if(tempVec[j] != result[k])
				{
					// value is not matching
					flag = true;
					break;
				}
				else
				{

					answer = answer + 1;
				}
			} 

			if(flag == false)
			{
				return answer;
			}
			else
			{

				tempVec.push_back(value);
				/*
				for(int i=0; i<tempVec.size(); i++)
					cout << tempVec[i] << "  " ;
				cout << endl;
				*/

			}
		}
		else
		{
			// value not exists
			tempVec.push_back(value);
			/*
			for(int i=0; i<tempVec.size(); i++)
			cout << tempVec[i] << "  " ;
			cout << endl;
			*/
		}

	}


}


int checkValueExists(int v, vector<int> output)
{
	for(int i=0; i<output.size(); i++)
	{
		if(v == output[i])
			return i;
	}
	return -1;
}


