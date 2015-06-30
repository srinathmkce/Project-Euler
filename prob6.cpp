#include<iostream>
#include<cmath>


using namespace std;

int main()
{
unsigned long sq1 = 0;
unsigned long sq2 = 0;
unsigned long out = 0;

sq1 = pow(((100.00*(100.00+1))/2),2);
sq2 = ((100*(100+1)*(200+1))/6);
out = sq1 - sq2;
cout << out ;
return 0;

}
