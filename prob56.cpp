#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int num = 99 ;
	int time = 99 ;
	int max = 0;

	for(int num = 2; num <100; num++)
	{
		cout << "Num is " << num << endl;
		for(int time = 2; time < 100; time++)
		{

			int temp;
			int digit;
			temp = num;


			vector<int> product;
			vector<int> answer;

			while(temp > 0)
			{
				digit = temp % 10;
				temp = temp / 10;
				product.push_back(digit);
			}

			int mul = 0;
			for(int i=1; i<time ; i++)
			{
				//cout << "Running " << i << " time" << endl;
				answer.clear();
				int carry = 0;

				for(int j=0; j<product.size(); j++)
				{

					digit = product[j];
					//cout << "Digit is " << digit << endl;
					//cout << "num is " << num << endl;
					mul = num * digit + carry;
					//cout << "mul is " << mul << endl;
					carry = mul / 10;
					//cout << "carry is " << carry << endl;
					answer.push_back(mul % 10);


				}

				while(carry > 0)
				{
					answer.push_back(carry % 10);
					carry /= 10;
				}

				//cout << "Answer contains " << endl;
				//for(int j=0; j<answer.size(); j++)
				//cout << answer[j] << "  ";
				//cout << endl;

				product.clear();
				product = answer;
				//cout << endl;

			}
			int sum = 0;

			for(int j=0; j<answer.size(); j++)
				sum += answer[j];
			if(sum > max)
				max = sum;

		}

	}
	cout << "Answer is " << max << endl;


	return 0;
}
