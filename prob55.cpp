#include <iostream>
#include <vector>
#include <stack>

using namespace std;
bool isPalindrome(vector<int> &nums);

int main()
{

	int answer = 0;
	for(int temp=1; temp<10000; temp++)
	{
		cout << "Running for n " << temp << endl;
		int n = temp;
		vector<int> nums;
		vector<int> rev;
		vector<int> sum;

		while(n > 0)
		{
			nums.push_back(n%10);
			n = n/10;
		}

		reverse(nums.begin(),nums.end());

		int end = 49;
		int count = 0;

		while(count != end)
		{

			stack<int> snum;
			int i,j;
			// reversing the number and storing it in another vector
			rev.clear();
			for(i=nums.size()-1; i>=0; i--)
				rev.push_back(nums[i]);

			int carry = 0;
			// now we need to add 2 numbers 
			for(i=nums.size()-1; i>=0; i--)
			{

				int sum = nums[i] + rev[i] + carry;
				int digit;
				if(sum > 9)
				{
					digit = sum - 10;
					carry = 1;
				}
				else
				{
					digit = sum;
					carry = 0;
				}
				snum.push(digit);

			}

			if(carry > 0)
				snum.push(carry);

			nums.clear();
			while(!snum.empty())
			{

				nums.push_back(snum.top());
				snum.pop();

			}

			// check if nums is palindrome
			if(isPalindrome(nums))
			{
				answer++;
				break;
			}


			count++;
		}

	}

	cout << "Answer is " << answer << endl;

	return 0;
}


bool isPalindrome(vector<int> &nums)
{

	int i =0;
	int j = nums.size()-1;
	int size = nums.size();

	for(;i<=size/2;i++,j--)
	{
		if(nums[i] != nums[j])
			return false;

	}
	return true;

}
