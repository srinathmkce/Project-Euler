#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <set>
#include <map>

using namespace std;

void generatePrimes(vector<int > &primes, int  n, int minimum);
bool binarySearch(vector<int > &primes, int  key, int  min, int  max);
void selectRepNum(vector<int> &primes);
void convertToString(vector<int> primes, vector<string> &sprim);
void findRepeatedPosition(string prime, vector<string> &repPos);
void checkForN(vector<string> &rep,int n);
int main()
{

	int minimum = 1000;
	int maximum = 100000000;
	for(int g=10000; g<=maximum; g=g*10)
	{
		cout << "Minimum is " << minimum << endl;
		vector<int > primes;
		vector<string> sprim;
		map<string, vector<string> > bucket;
		map<string, vector<string> > ::iterator mit;

		int  n = 10000000;
		//generatePrimes(primes,1000000);
		primes.clear();

		cout << "Generating Primes till " << g << endl;
		generatePrimes(primes,g,minimum );
		cout << "Total Primes " << primes.size() << endl;
		cout << "Selecting repeated Numbers" << endl;
		selectRepNum(primes);
		cout << "Repeated Primes " << primes.size() << endl;
		cout << "Converting to string" << endl;
		convertToString(primes,sprim);
		cout << "Find repeated Digits " << endl;
		vector<string> repPos;
		for(int i=0; i<sprim.size();i++)
		{
			if(i % 10000 == 0)
				cout << "After " << i << endl;
			repPos.clear();
			findRepeatedPosition(sprim[i], repPos);
			checkForN(repPos,3);
			for(int j=0; j<repPos.size(); j++)
			{
				// key not exists . insert new 
				if(bucket.find(repPos[j]) == bucket.end())
				{
					vector<string> temp;
					temp.push_back(sprim[i]);
					bucket.insert(pair<string, vector<string> > (repPos[j],temp));

				}
				else
				{
					// key is present
					mit = bucket.find(repPos[j]);
					vector<string> temp;
					temp = mit->second;
					temp.push_back(sprim[i]);
					bucket[repPos[j]] = temp;


				}

			}
		}

		cout << "Total bucket " << bucket.size() << endl;
		for(mit = bucket.begin(); mit != bucket.end(); mit++)
			cout << "Key " << mit->first << " has " << mit->second.size() << " Numbers " << endl;


		for(mit = bucket.begin(); mit != bucket.end(); mit++)
		{
			cout << "Processing bucket with size " << mit->first <<  " " << mit->second.size() <<  endl;
			vector<string> temp;
			map<string, int > occur;
			map<string, int > keyValOccur;
			map<string, int > ::iterator kvi;
			multimap<string, string> posStNum;
			multimap<string, string> posStNum1;
			multimap<string, string >::iterator psit ;
			map<string, string> ansmap;
			map<string, int > ::iterator oit;
			map<string, string>::iterator sit ;
			string key = mit->first;
			temp = mit->second;

			if(temp.size() != 0)
			{
				// for each number in the bucket 
				for(int  i =0; i<temp.size(); i++)
				{
					// strip down the repeated positions
					string tempNum = temp[i];
					string saveNum = tempNum;
					for(int j=key.length()-1; j>=0; j--)
					{
						int pos = key[j] - '0';
						tempNum.erase(tempNum.begin()+pos, tempNum.begin()+pos+1);
					}

					// inserting with position
					//cout << "inserting " <<  key << "  " <<  tempNum << "  " << saveNum << endl;
					posStNum.insert(pair<string,string> (key,tempNum));
					posStNum1.insert(pair<string,string> (key+":"+tempNum,saveNum));

					
					


					/*
					ansmap.insert(pair<string,string>(saveNum,tempNum));
					// if striped number is not present - then insert it
					if(occur.find(tempNum) == occur.end())
					{
						occur.insert(pair<string,int > (tempNum,1));

					}
					else
					{
						// if already present
						oit = occur.find(tempNum);
						int  vval = oit->second;
						vval = vval + 1;
						//if(tempNum == "563" )
						//cout << "Updating vval to " << vval << endl;
						occur[tempNum] = vval;

					}
					*/

				}  // for each number in bucket

				for(psit = posStNum.begin(); psit != posStNum.end(); psit++)
				{

					// find the occurence of each key value pair
					string x = psit->first;
					string y = psit->second;
					string z = x + ":" + y;
					if(keyValOccur.find(z) == keyValOccur.end())
					{
						// key not found
						keyValOccur.insert(pair<string,int>(z,1));


					}
					else
					{
						// key found
						kvi = keyValOccur.find(z);
						int kval = kvi->second;
						kval = kval+1;
						keyValOccur[z] = kval;


					}


				}

				bool isFound = false;	
				string mkey;
				for(kvi = keyValOccur.begin(); kvi != keyValOccur.end(); kvi++)
				{
					if(kvi->second == 8)
					{
						cout << "Answer Found" << endl;
						isFound = true;
						mkey = kvi->first;
						break;
					}

				}

				if(isFound)
				{
					for(psit = posStNum1.begin(); psit != posStNum1.end(); psit++)
					{
						if(psit->first == mkey)
						{
							cout << "Numbers are " << psit->second << endl;
						}
					}

						
					
				}




			/*
				// new code to check multimap size
				string mkey;
				for(psit = posStNum.begin(); psit != posStNum.end(); psit++)
				{
					if(posStNum.count(psit->first) == 8)
					{
					isFound = true;
					mkey = psit->first;
					cout << "Answer Found here with key ["<< psit->first <<"]: and value [" << psit->second <<"]" << endl;
					}

				}
				
				if(isFound)
				{
					for(psit = posStNum1.begin(); psit != posStNum1.end(); psit++)
					{
						if(psit->first == mkey)
						{
							cout << "Numbers are " << psit->second << endl;
						}
					}
				}
			
			*/
				/*
				string ans = "";
				for(oit=occur.begin(); oit!= occur.end(); oit++)
				{
					//if(oit->first == "563")

					if(oit->second == 8)
					{
						ans = oit->first;
						break;	

					}
				}

				for(sit=ansmap.begin(); sit != ansmap.end(); sit++)
				{
					if(sit->second == ans)
						cout << "Answer is " << sit->first <<  "  " << endl ;


				}

				*/

			} // if vector size not zero

		} // end of map iteration

	minimum = minimum * 10;
	cout << endl;
	}// end of digit for loop



	return 0;
}

void checkForN(vector<string> &rep, int n)
{

	vector<string> copyRep;
	copyRep = rep;
	if(n == 3)
	{

		for(int i=0; i<rep.size(); i++)
		{
			string num = rep[i];

			if(num.length() > 3)
			{

				for(int i=0; i<num.length()-2; i++)
				{
					string x = "";
					x = num[i];
					string temp = x;

					for(int j=i+1; j<num.length(); j++)
					{
						x += num[j];
						for(int k=j+1; k<num.length(); k++)
						{
							string newString = "";
							newString += x;
							newString += num[k];
							//cout << newString << endl;
							copyRep.push_back(newString);
						}
						x = temp;
					}

				}

			}


		}

	}

	for(int i=0; i<copyRep.size(); i++)
	{
		bool notExist = true;
		for(int j=0; j<rep.size(); j++)
		{
			if(rep[j] == copyRep[i])
			{
				notExist = false;
				break;
			}

		}
		if(notExist)
			rep.push_back(copyRep[i]);
	}


}


void findRepeatedPosition(string prime, vector<string> &repPos)
{

	map<int, string> temp;
	map<int, string> ::iterator it;

	// all empty
	for(int i=0; i<10; i++)
	{
		temp.insert(pair<int,string>(i,""));
	}

	// 12341

	for(int i=0; i<prime.length(); i++)
	{
		int digit = prime[i] -'0';


		it = temp.find(digit);
		string s = it->second;

		stringstream ss;
		ss << i;
		s += ss.str();
		temp[digit] = s;

	}

	for(it=temp.begin(); it!= temp.end(); ++it)
	{
		if(it->second.length() > 2)
			repPos.push_back(it->second);
	}


}

void convertToString(vector<int> primes, vector<string> &sprim)
{
	cout << "Entering converToString" << endl;

	stringstream ss;

	for(int i=0; i<primes.size(); i++)
	{
		ss << primes[i];
		sprim.push_back(ss.str());
		ss.str("");

	}

	cout << "Exiting converToString" << endl;

}


void selectRepNum(vector<int> &primes)
{
	cout << "Entering selectRepNum " << endl;
	vector<int> temp;
	temp = primes;

	primes.clear();

	for(int i=0; i<temp.size(); i++)
	{
		set<int> dig;
		int num = temp[i];
		while(num > 0)
		{
			int digit = num % 10;
			num = num / 10;

			if(dig.find(digit) == dig.end())
			{
				// digit not found
				dig.insert(digit);

			}
			else
			{
				primes.push_back(temp[i]);
				break;

			}

		}

	}



	cout << "Exiting selectRepNum " << endl;
}



void generatePrimes(vector<int > &output, int  m, int minimum)
{
	double n = double(m);
	vector<bool> primes;
	for(int  i=2; i<=n; i++)
		primes.push_back(true);

	for(int  i=2; i<=sqrt(n); i++)
	{
		if(primes[i] == true)
		{
			int  count = 0;
			for(int  j=i*i ; j<=n; j= i*i + count*i)
			{
				primes[j] = false;
				count++;
			}
		}
	}

	for(int  i=minimum; i<=n; i++)
	{
		if(primes[i] == true)
		{
			output.push_back(i);
		}
	}
	
}

bool binarySearch(vector<int > &primes, int  key, int  min, int  max)
{
	
	while(max >= min)
	{

		int  mid = (min + max)/2;
		if(primes[mid] == key)
		{
			return true;
		}
		else if(primes[mid] < key)
		{
			min = mid + 1;
		}
		else
		{
			max = mid -1 ;

		}

	}
		return false;



}
