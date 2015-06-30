#include <iostream>

using namespace std;

int main()
{
	double toRaise = 2;
	for(double i=0; i<=1000; i++)
	{
		for(double j=0; j<=1000; j++)
		{
			for(double k=0; k<=1000; k++)
			{
				if(i + j + k == 1000 && i < j  && j < k)
				{
					if( pow(i,toRaise) + pow (j, toRaise) == pow(k,toRaise))
					{
						cout << i << " " << j << "  " << k << endl;
					}
				}

			}
		}
	}
	return 0;
}
