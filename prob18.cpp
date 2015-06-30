#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;
int splitLines(string fline, char delim, vector<string>& valVec);

int main()
{
	vector<vector<int> > rowMap;	
	vector<int> lastLine;	
	vector<int> beforeLine;	
	rowMap.clear();
	//fstream myfile("triangle.txt");
	fstream myfile("sup_prob_18.txt");
	char d = ' ';
	string line;
	vector <string> input;
	int num;
	// read the file and store the values in vector
	while(getline(myfile,line)){
		stringstream ss(line);
		vector<int> valVec;
		valVec.clear();
		while (ss >> num)
		{
			valVec.push_back(num);
		}
		rowMap.push_back(valVec);
	}


	for(int i= rowMap.size()-2; i>=0; i--)
	{
		beforeLine = rowMap[i];
		lastLine = rowMap[i+1];
		for(int j=0 ; j<beforeLine.size(); j++)
		{
			int s =  beforeLine[j];
			int x =  lastLine[j];
			int y = lastLine[j+1];
			int u;
			//cout << "s is " << s << endl;
			//cout << "x is " << x << endl;
			//cout << "y is " << y << endl;
			if( (s+x) > (s+y))
			{
				u = s+x;
			}
			else
			{
				u = s+y;
			}
			cout << "u is " << u << endl;
			(rowMap[i])[j] = u;
			cout << endl;

		}
	}

	return 0;
}

