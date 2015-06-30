#include <iostream>
#include <queue>


using namespace std;

int main()
{

queue<int> fq;
queue<int> sq;
queue<int> oq;
queue<int> bq;

fq.push(1);
sq.push(1);
	int counter = 2;

while(1)
{
	bq = sq;
	int first_num = 0;
	int second_num = 0;
	int carry = 0;
	// while second queue is not empty 
	while(!sq.empty())
	{
		first_num = 0;
		second_num = 0;
		// get the first number
		first_num = sq.front();
		sq.pop();
		if(!fq.empty())
		{
			// if exists , get the second number
			second_num  = fq.front();
			fq.pop();
		}

		// add numbers

		int result = 0;
		result = first_num + second_num+ carry;
		if(result < 10)
		{
			oq.push(result);
			carry = 0;
		}
		else
		{
			oq.push(result-10);
			carry = 1;
		}

	}
	// enqueue last digit
	if(carry > 0)
		oq.push(carry);

	// update corresponding queues

	fq = bq;
	sq = oq;
	counter++;
	if(oq.size() == 1000)
		break;

	// efficient way of clearing queue
	queue<int> empty;
	swap(oq,empty);

}
cout << counter << endl;

return 0;
}


