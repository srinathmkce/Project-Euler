#include <iostream>
#include <vector>
#include <map>

using namespace std;
int populateVector(int d);
int repeatLength(vector<int> result);
int checkValueExists(int v, vector<int> output);
int main()
{

for(int den=14; den<15; den++)
{
cout << endl;
cout << "Answer is : " << populateVector(den) << endl;

}










/*
vector<int> result;
vector<int> temp_vec;
map<int,int> output;

for(int i=1; i<1000; i++)
output[i]=0;

int num = 1;

// iterating thro all denoms

int quo = 0;
int rem = 0;
bool flag = false;
int max = 0;
int counter = 0;
int first = 0;
int last = 1;
bool repeat = true;
int temp_rem = -1;
//for(int den=1; den<1000; den++)
{
	int den = 77;
	cout << "Den is " << den << endl;
	num = 1;
	while(1)
	{

		// resetting flag 
		quo = 0;
		rem = 0;
		flag = false;
		// check if digit is lesser, if so increase num by *10
		while(num < den)
		{
			num *= 10;
			if(counter > 0)
			{
				result.push_back(0);
			}
			counter = counter + 1;

		}
		counter = 0;
		cout << "Number is " << num << endl;		

		// find quo and remainder	
		quo = num/den;
		rem = num % den;
		cout << "Quotient : " <<  quo << endl;
		cout << "Remainder : " <<  rem << endl;


		// after finding the quotient and remainder we have 3 cases
		// 1. it solves to 0. Like 10/2 
		// 2. its recurring to same digit. like 10/3
		// 3. its different like 10/7 

		// case 1  

		if(rem == 0)
		{
			output[den] = 0;
			cout<<"case 1";
			break;
		}


		// case 2 
			//if(quo == result[result.size() - 1])
			if(temp_rem == rem)
			{
				cout << "Case 2 " << endl;
				output[den] = 1;
				break;
			}

		// case 3 : 

		for(int i=0; i<result.size();i++)
		{
			// first check if quotient is already there in the input
			if(quo == result[i])
			{
				flag = true;
				temp_vec.push_back(quo);
				if(repeat)
				{
					first = i;
					last = result.size() ;
					repeat = false;	

				}
				cout << "i is " << i << endl;
				cout << "First is  " << first << endl;
				cout << "last is  " << last << endl;

				if(!repeat && quo == result[first])
				{
					first = first + 1;
					break;
				}
				else
				{
					cout << "Inside else" << endl;

					for(int i=0; i<temp_vec.size(); i++)
						result.push_back(temp_vec[i]);

					first = 0;
					last = 1;
					repeat = true;
					//flag = false;
					cout << "Repeat is set true " << endl;
					temp_vec.clear();
					break;
				}


			}

		}


		if(first == last)
		{
			cout << "first == last .. breaking " << endl;
			output[den] = result.size();
			cout << "Answer for den is " << den << "  " << result.size() << endl;
			break;
		}



		if(flag == true)
		{
			//cout << " Answer : Den " << den << " size " << result.size() << endl;
			   for(int i=0; i<result.size();i++)
			   cout << result[i] << "  ";
			   cout << endl;
			num = rem;
			temp_rem = rem;

		}
		else
		{
			result.push_back(quo);
			   for(int i=0; i<result.size();i++)
			   cout << result[i] << "  ";
			   cout << endl;

			num = rem;
			temp_rem = rem;
		}

		cout << "Number changes to " << num << endl;
		cout << endl << endl;

	}
	result.clear();
	//cout << endl << endl;
}
	



return 0;
*/
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
		if(result.size() == 50)
			break;
		// check if digit is lesser, if so increase num by *10
		while(num < d)
		{
			num *= 10;
			if(counter > 0)
			{
				result.push_back(0);
			}
			counter = counter + 1;

		}
		counter = 0;

		// find quo and remainder	
		quo = num/d;
		rem = num % d;

		result.push_back(quo);
		num = rem;
	}

	for(int i=0; i<result.size(); i++)
		cout << result[i] << "  " ;
		cout << endl;

	return repeatLength(result);
}

int repeatLength(vector<int> result)
{
vector<int> tempVec;
vector<int> toPush;
bool flag = true;
bool repeat = true;
int first = 0;
int last = -1;
int j;


for(int i=0; i<result.size(); i++)
{
int value = result[i];

// check if value exists 
int index = checkValueExists(value, result);

// index is the place where the value is there
if(index > 0 )
{
// value exists .. 

}
else
{
// value not exists
tempVec.push_back(value);
}

}


}


int checkValueExists(int v, vector<int> output)
{
	for(int i=0; i<output.size(); i++)
	{
		if(v == output[i])
			return i
	}
	return -1;
}


