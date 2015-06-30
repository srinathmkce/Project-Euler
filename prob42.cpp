#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

void computeSequence(int min, int max, vector<int> &seq);
bool binarySearch(int min, int max, int key, vector<int> seq);
int main()
{
	vector<int> seq;
	int ans = 0;
	vector<string> words;
	computeSequence(1,10000,seq);
	map<char,int> scores;
	map<char,int>::iterator it ;
	int counter = 1;
	for(char ch='A'; ch <= 'Z' ; ch++)
	{
		scores.insert(pair<char,int>(ch,counter));
		counter++;
	}

	fstream myfile("p042_words.txt");
	string line;
	getline(myfile,line);

		string temp = "";
		bool flag = false;

	for(int i=0 ;i<line.length(); i++)
	{
		if(line[i] == '\"' || line[i] == ',')
		{
			flag = true;
		}
		else
		{
			temp += line[i];
			flag = false;
		}

		if(temp != "" && flag)
		{
			//words.push_back(temp); // pushing into vector
			int score = 0;
			for(int i=0; i<temp.length(); i++)
			{
				it = scores.find(temp[i]);
				score = score + it->second;		
			}

			if((binarySearch(0,seq.size()-1,score,seq)))
			{
				cout << temp << "  " << score << endl;
				ans++;
			}
			

			temp = "";
			flag = false;
		}

	}

	cout << "Answer is " << ans << endl;

	return 0;
}


bool binarySearch(int min, int max, int key, vector<int> seq)
{

	while(max >= min)
	{

		int mid = (min + max) / 2;
		if(seq[mid] == key)
		{
			return true;
		}

		else if(seq[mid] < key)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}

	}

	return false;

}

void computeSequence(int min, int max, vector<int> &seq)
{

	while(min < max)
	{

		int num = (min * (min + 1)) / 2;
		seq.push_back(num);
		min++;

	}

}
