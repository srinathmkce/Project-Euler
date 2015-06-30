#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	fstream myfile("a");
	
	vector<string> words;
	// read the line
	string line;
	while(getline(myfile, line))
	{
		words.push_back(line);
	}
cout << "After reading file" << endl;
/*	
	vector<string> words;
	words.push_back("102");
	words.push_back("210");
	words.push_back("012");
*/
	map<char,vector<string> > bucket;
	map<char,vector<string> > ::iterator it;
	bucket.clear();
	vector<string> tempVec;

	// initializing map with null vector and empty for variable length string
	for(char i='0'; i<='9'; i++)
	{
		bucket[i] = tempVec;
	}
	

	/*cout << "init" << endl;
	  for(int k=0; k<words.size(); k++)
	  cout << words[k] << "  ";
	  cout << endl;*/

	// finding the maximum character
	int max = 10;
	/*
	for(int i=0; i<words.size(); i++)
	{
		max = (max > words[i].length())?max:words[i].length();
	}
	*/

	// loop from max char till first char 
	for(int i=max-1; i>=0; i--)
	{
		cout << "iteration " << i << endl;
		//cout << "Running for Phase " << i << endl;
		// loop through the entire vector
		for(int j=0; j<words.size(); j++)
		{
			string word = words[j];

			// index exists .. Hence check the char
			char temp_char;
			temp_char = word[i];

			// insert into map with temp_char, word
			bucket[temp_char].push_back(word);	
			//cout << "Pushing " << word << " into bucket " << temp_char << endl;



		}
		// end of this loop, all the words are inserted into corresponding buckets
		// clear the input vector -- because we are going to change the order
		words.clear();

		// iterate through the keys and write the order into input vector
		for(it=bucket.begin(); it!=bucket.end(); it++)
		{
			tempVec = it->second;
			for(int k=0; k<tempVec.size(); k++)
				words.push_back(tempVec[k]);

			tempVec.clear();

		}

		/*cout << "After bucket insertion words are  " << endl;
		  for(int k=0; k<words.size(); k++)
		  //cout << words[k] << "  ";
		  //cout << endl;
		
		*/


		// now we have the correct order of the phase .. hence clear the bucket
		tempVec.clear();
		for(it=bucket.begin(); it!=bucket.end(); it++)
		{
			it->second.clear();
		}

		//cout << endl;


	}
	for(int k=0; k<words.size(); k++)
		cout << words[k] << endl;


	return 0;
}

