#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
ifstream infile("largeSum.txt");
//ifstream infile("test");
string line;
vector<string> tenDigits;

while(getline(infile,line))
{
	tenDigits.push_back(line);

}

int digit = 49;
//int digit = 2;
int sum = 0;
int rem = 0;
int idigit = 0;
int outputDigit = 0;
while( digit >= 0)
{
	for(int i=0; i<tenDigits.size() ; i++)
	{
		string number = tenDigits[i];
		idigit = number[digit] - '0';
		sum += idigit;
	}
	sum += rem;
	//cout << "Sum is " << sum <<endl;
	rem = sum / 10;
	outputDigit = sum % 10;
	digit --;
	//cout << "Sum is " << sum << endl;
	//cout << "Rem is " << rem << endl;
	cout << "output is "<< outputDigit<< endl;
	sum = 0;
}
cout << "Rem is" << rem << endl;

return 0;
}
