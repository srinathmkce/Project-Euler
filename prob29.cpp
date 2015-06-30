#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main()
{
double result;
set<double> logVec;
for(double a=2; a<=100; a++)
{
for(double b=2; b<=100; b++)
{
	result = b * log10(a);	
	logVec.insert(result);

	
}
}

cout << logVec.size() << endl;
return 0;
}


