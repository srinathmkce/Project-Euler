#include <iostream>

using namespace std;

int main()
{
	int arr[1001][1001];
	int i,j;
	int number = 0;

	int n = 1001;
	// initializing the array
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			arr[i][j] = 0;
		}
	}

	// now we have to find the starting point
	i = n/2;
	j = n/2;
	int a= 0;
	int b = 0;
	int odd = 0;
	int even = 1;
	int counter = 0;

	counter = counter + 1;
	arr[i][j] = counter;

	while(1)
	{

		// step 1 :  Turn right by i, j+1 
		j = j + 1;
		counter = counter + 1;
		arr[i][j] = counter;

		// setp 2 : Turn down by i+(2n+1) ,j
		a = i + (2 * odd) + 1 ;
		odd = odd + 1;
		for(int k=i+1; k<=a;k++)
		{
			counter = counter + 1;
			arr[k][j] = counter;

		}
		i = a;
		a = 0;
		b = 0;

		// step 3 : Turn left by i , j-2

		b = j - (2 * even);
		for(int k=j-1; k>=b; k--)
		{

			counter = counter + 1;
			arr[i][k] = counter;
		}

		j = b;
		a = 0;
		b = 0;

		// step 4 : Turn up by i-1, j
		a = i - (2 * even);
		for(int k=i-1; k>=a; k--)
		{
			counter = counter + 1;
			arr[k][j] = counter;
		}
		i = a;
		a = 0;
		b = 0;	


		// step 5 : Turn right by i, j+2
		b = j + (2 * even);
		for(int k=j+1; k<=b; k++)
		{

			counter = counter + 1;
			arr[i][k] = counter;
		}

		even = even + 1;
		j = b;
		a = 0;
		b = 0;
		
		if(i == 0 && j == n-1)
		{
			break;
		}
	}
/*
	// output matrix is 
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
*/
int answer = 0;
	
	for(i=0,j=0; i<n, j<n; i++, j++)
	{
		answer = answer + arr[i][j];
	}

	cout << endl;
	for(i=n-1, j=0; i>=0, j<n; i--,j++)
	{

		answer = answer + arr[i][j];
	}

	cout << "Answer is " << answer << endl;

	return 0;
}
