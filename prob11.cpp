#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int matrix[20][20];
	string line;
	ifstream infile("matrix.txt");
	int i = 0, j = 0;

	while(getline(infile,line))
	{
		istringstream iss(line);
		string c;
		int x;
		j = 0;
		while(iss >> c)
		{
			istringstream buffer(c);
			buffer >> x;
			matrix[i][j] = x;
			j++;
		}
		i++;
	}
/*
	for(int i = 0 ; i < 20 ; i++)
	{
		for(int j = 0 ; j < 20 ; j++)
		{
		}

	}
*/
unsigned long rprod = 0,max = 0;
for(j = 0; j < 20 ; j++)
{
	i = 0;
	while(i<17)
	{
		rprod = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j];
		if(rprod > max)
		{
			max = rprod;
			}
		i++;
	}
}

for(i = 0; i < 20 ; i++)
 {
   j = 0;
   while(j<17)
	{
		rprod = matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3];
		if(rprod > max)
		{
			max = rprod;
			}
		j++;
	}
 }

for(i = 0; i < 17 ; i++)
{
	for(j = 0 ; j < 17 ; j++)
	{
		rprod = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
		if(rprod > max)
		{
			max = rprod;
		}

	}
}

for(i = 0 ; i < 17 ; i++)
{
	for(j = 19 ; j > 2 ; j--)
	{
		rprod = matrix[i][j] * matrix[i+1][j-1] * matrix[i+2][j-2] * matrix[i+3][j-3];
		if(rprod > max)
		{
			max = rprod;
		}

	}
}
cout<<max;



	return 0;
}
