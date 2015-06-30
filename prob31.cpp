#include <iostream>


using namespace std;

int main()
{

int k = 0;
for(int onePaise = 0; onePaise <= 200; onePaise++)
for(int twoPaise = 0; twoPaise <= 100; twoPaise++)
for(int fivePaise = 0; fivePaise <= 40; fivePaise++)
for(int tenPaise = 0; tenPaise <= 20; tenPaise++)
for(int twentyPaise= 0; twentyPaise <= 10; twentyPaise++)
for(int fiftyPaise= 0; fiftyPaise <= 4; fiftyPaise++)
for(int rupee = 0; rupee <= 2; rupee++)
if(onePaise + twoPaise*2 + fivePaise*5 + tenPaise*10 + twentyPaise*20 + fiftyPaise*50 + rupee*100 == 200)
k++;

cout << k << endl;


return 0;

}

