#include <iostream>

using namespace std;

unsigned long gcd(unsigned long a , unsigned long b);
unsigned long lcm(unsigned long a , unsigned long b);

int main()
{
	unsigned long x = lcm(1,lcm(2,lcm(3,lcm(4,lcm(5,lcm(6,lcm(7,lcm(8,lcm(9,lcm(10,lcm(11,lcm(12,lcm(13,lcm(14,lcm(15,lcm(16,lcm(17,lcm(18,lcm(18,lcm(19,20))))))))))))))))))));
	cout << x;

   return 0;
}



unsigned long lcm (unsigned long a, unsigned long b)
{
return (a*b) / gcd (a,b);
}

unsigned long gcd(unsigned long a, unsigned long b)
{
	//cout << "Entering gcd with " << a << "   " << b << endl;
	if(b == 0)
	{
		//cout<<"a = "<<a<<endl;
		return a;
	}
	else
	    return gcd(b, a % b);
}



