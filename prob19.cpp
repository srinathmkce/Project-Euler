#include <iostream>
#include <vector>

using namespace std;

void populateMonth(vector<string> &, vector<int> &, vector<string> &);
int leapYear(int y);
int main()
{
vector<string> month;
vector<int> maxDays;
vector<string> days;
populateMonth(month, maxDays, days);
int d = 1;
int m = 1;
int y= 1901;


int day = 3;
int dmlimit;
int counter = 0;
while(1)
{
	if(d == 1 && m == 1 && y == 2001)
		break;
	//if(d == 10 && m == 1 && y == 1901)
	// if date is 31-Dec-1900 ,, we ve to increment move year and set d to 1 and m to 1 
	if( d == 31 && m == 12 ) // reached max days .. so increment month 
	{
		//cout << d << "-" << m << "-" << y << "    " << days[day-1] << endl;
		m = 1;
		d = 1;
		y = y + 1;
		day = (day % 7) + 1;
		continue;
	}


	dmlimit = maxDays[m-1];
	if(dmlimit == 0)
	{
		// leap year logic ,, return 28 or 29 days
		dmlimit = leapYear(y);
	}

	// if date is 31-Nov-1900 ,, we set date to 1 , increment month by 1 and year remains same

	if(d == dmlimit)
	{
		//cout << d << "-" << m << "-" << y << "    " << days[day-1] << endl;
		d = 1;
		m = m + 1;
		day = (day % 7) + 1;
		continue;
	}


	// ordinary date -- 21-Oct-1990
	if(d == 1 && day == 1)
	{
	counter++;
	cout << d << "-" << m << "-" << y << "    " << days[day-1] << endl;
	}
	d++;
	day = (day % 7) + 1;


}
cout << "Count is " << counter;

return 0;
}

int leapYear(int y)
{
	if(y % 4 == 0 && ((y % 100 == 0 && y % 400 == 0) || (y % 100 != 0 && y % 400 != 0)) )
			return 29;
	else
		return 28;
}

void populateMonth(vector<string> &months, vector<int> &md, vector<string> &wd)
{
	months.push_back("jan");
	months.push_back("feb");
	months.push_back("mar");
	months.push_back("apr");
	months.push_back("may");
	months.push_back("jun");
	months.push_back("jul");
	months.push_back("aug");
	months.push_back("sep");
	months.push_back("oct");
	months.push_back("nov");
	months.push_back("dec");

	md.push_back(31);
	md.push_back(0);
	md.push_back(31);
	md.push_back(30);
	md.push_back(31);
	md.push_back(30);
	md.push_back(31);
	md.push_back(31);
	md.push_back(30);
	md.push_back(31);
	md.push_back(30);
	md.push_back(31);


	wd.push_back("Sunday");
	wd.push_back("Monday");
	wd.push_back("Tuesday");
	wd.push_back("Wednesday");
	wd.push_back("Thursday");
	wd.push_back("Friday");
	wd.push_back("Saturday");

}
