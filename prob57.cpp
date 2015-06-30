#include <iostream>
#include <queue>

using namespace std;

void addTwoNum(queue<int> num, queue<int> den, queue<int> &sum);
int main()
{
	int counter = 1;
	int answer = 0;

	// vector for num, den, temp
	queue<int> num;
	queue<int> den;
	queue<int> temp;
	queue<int> tempDen;
	queue<int> ptest;



	// init num
	num.push(3);

	// init den 
	den.push(2);

	while(counter != 1000)
	{

		//cout << endl;
		int n_digit = 0;
		int d_digit = 0;
		// adding numerator and denomintor
		int carry = 0;
		tempDen = den;
		while(!num.empty())
		{
			int a = num.front();
			num.pop();
			int b = 0;
			if(!den.empty())
			{
				b = den.front();
				den.pop();
			}

			int s = a + b + carry;
			temp.push(s%10);
			carry = s / 10;

		}

		if(den.size() == 0 && carry > 0)
		temp.push(carry);

		while(!den.empty())
		{
			temp.push((den.front() + carry) % 10);
			carry = (den.front() + carry) / 10;
			den.pop();

		}

		
		d_digit = temp.size();

		// printing temp
		//cout << "printing temp " << endl;
		ptest = temp;
		while(!ptest.empty())
		{
			//cout << ptest.front() << endl;
			ptest.pop();

		}

		den = temp;

		// adding temp and tempDen and forming new numerator

		carry = 0;
		while(!temp.empty())
		{
			int a = temp.front();
			temp.pop();
			int b = 0;
			if(!tempDen.empty())
			{
				b = tempDen.front();
				tempDen.pop();
			}

			int s = a + b + carry;
			num.push(s%10);
			carry = s / 10;

		}
		if(tempDen.size() == 0 && carry > 0)
		num.push(carry);


		while(!tempDen.empty())
		{
			num.push((tempDen.front() + carry ) % 10);
			carry = (tempDen.front() + carry) / 10;
			tempDen.pop();

		}

		// printing num 
		//cout << "printing num " << endl;
		ptest = num ;
		while(!ptest.empty())
		{
			//cout << ptest.front() << endl;
			ptest.pop();

		}

		n_digit = num.size();

		if(n_digit > d_digit)
			answer++;
			
		
		//cout << "After all operations " << endl;
		//cout << "num size " << num.size() << endl;
		//cout << "den size " << den.size() << endl;
		//cout << "temp size " << temp.size() << endl;
		//cout << "tempDen size " << tempDen.size() << endl;

		counter++;
	}

	cout << "Answer is " << answer << endl;



	return 0;
}
