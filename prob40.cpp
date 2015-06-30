#include <iostream>
#include <vector>

#include <sstream>

using namespace std;

int main()
{
string output = " ";
for(int num = 1; num<1000000; num++)
{
cout << num << endl;
stringstream ss;
ss<<num;
output = output + ss.str();
if(output.length() > 1000010)
break;
}

int d1 = output[1] - '0';
int d2 = output[10] - '0';
int d3 = output[100] - '0';
int d4 = output[1000] - '0';
int d5 = output[10000] - '0';
int d6 = output[100000] - '0';
int d7 = output[1000000] - '0';


cout << "Zeroth digit is [" << output[0] << "]" << endl; 
cout << d1 <<" " << d2 << " "<< d3 << "  " << d4 << "  " << d5 << "  "<< d6 << "  " << d7 << endl;

cout << "Answer is " << d1 * d2 * d3 * d4 * d5 * d6 * d7 << endl; 




return 0;
}


