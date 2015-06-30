#include <iostream>
#include <vector>

using namespace std;

int main()
{
int product = 1;

for(int x=10; x<100; x++)
{
for(int y=10; y<100; y++)
{
	if(x < y && x != y)
	{
	int d1 = x/10;
	int d2 = x%10;

	int d3 = y/10;
	int d4 = y%10;
	
	if(d2 == d3 && (x * d4 == y * d1))
	{
	cout << x<<"/"<<y<<endl;
	product = product * y;

	}
	}
}

}
cout << "Answer is " << product << endl;
return 0;
}
