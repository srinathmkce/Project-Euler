#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
double a , b, c;
int k;
int max =0;
int ans = 0;
for(int p=2; p<=1000; p++)
{
	k = 0;
	double limit = p/2;
	for(a=1; a<limit; a++)
	{
		for(b=1; b<limit; b++)
		{
			for(c=1; c<limit; c++)
			{
				if(a+b+c == p && a+b > c && pow(a,2) + pow(b,2) == pow(c,2))
				{
					//cout << a << "  " << b << "  " << c << endl;
					k++;

				}

			}
		}

	}
	if( k > max)
	{
		max = k;

		ans = p;
	}

}
cout << "answer is " << ans << " ways is " << max << endl;

return 0;
}


