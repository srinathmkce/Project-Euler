#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{

	vector<int> vec;
	stack<int> digitStack;
	// initializing the vector by number 1 
	vec.clear();
	vec.push_back(1);


	// Finding Factorial till number 100
	for(int num=1; num<=100; num++)
	{
		cout << "Factorial of " << num << " : ";
		int max_size_vector = vec.size()-1;	
		
		int carry = 0;
		// iterating vector in reverse
		for(int i=max_size_vector ; i>=0 ; i--)
		{
			// getting the digit from vector
			int digit = vec[i];

			// multiply the digit with corresponding factorial number
			digit = digit * num + carry;

			// find the carry and end digit
			int d_t_i = digit % 10;

			// find the carry 
			carry = digit/10;

			digitStack.push(d_t_i);
			
		}
		// inserting the first digit if present 
			while(carry > 0)
			{
				digitStack.push(carry%10);
				carry  /= 10;

			}


		vec.clear();
		int sum = 0;
		// printing the stack
		while(!digitStack.empty())
		{
			//cout << digitStack.top() << " ";	
			// taking out the digit from stack and inserting into vector
			int sd = digitStack.top();
			sum += sd;
			digitStack.pop();
			vec.push_back(sd);
		}
		cout << sum << endl;
		sum = 0;
		cout << endl;
		

		
	}

	return 0;
}
