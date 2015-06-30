#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

void populateCards(string p_cards, vector<string> &p_cards);
string tieBreaker(vector<string> p1_cards, vector<string> p2_cards, int rank);
void findRank(vector<string> p_cards, int &rank);
bool isRoyalFlush(vector<string> p_cards);
bool isSameSuit(vector<string> p_cards);
bool isStraightFlush(vector<string> p_cards);
int getCardValue(char c);
void sortCards(vector<string> p_cards, vector<string> & sorted_p_cards);
void sortCardsByA(vector<string> p_cards, vector<string> & sorted_p_cards);
void findOccurence(vector<string> p_cards, map<char,int> &occur);
bool isFourOfAKind(vector<string> p_cards, map<char,int> occur);
bool isFullHouse(vector<string> p_cards, map<char,int> occur);
bool isFlush(vector<string> p_cards);
bool isStraight(vector<string> p_cards);
bool isThreeOfAKind(vector<string> p_cards, map<char,int> occur);
bool isTwoPairs(vector<string> p_cards, map<char,int> occur);
bool isOnePair(vector<string> p_cards, map<char,int> occur);

int main()
{

	//read the input file

	fstream myfile("poker.txt");
	//fstream myfile("test.txt");
	string line;
	while(getline(myfile,line))
	{
		int rank1;
		int rank2;
		string s1_cards = line.substr(0,14);
		string s2_cards = line.substr(15,28);

		// find player 1 cards
		vector<string> p1_cards;
		populateCards(s1_cards,p1_cards);

		// calculate the rank

		findRank(p1_cards,rank1);
		cout << "P1: " << s1_cards << " ==> " << rank1 << "       " ;


		// find player 2 cards
		vector<string> p2_cards;
		populateCards(s2_cards,p2_cards);


		// calculate the rank
		findRank(p2_cards,rank2);
		cout << "P2: " << s2_cards << " ==> " << rank2 ;

		// Now, we have 3 possibilities

		// rp1 > rp2 ==> player 1 wins

		if(rank1 > rank2)
		cout << " ************ Player 1 Wins ************* " << endl;
		
		// rp1 < rp2 ==> player 2 wins
		if(rank1 < rank2)
		cout << " ************ Player 2 Wins ************* " << endl;

		// rp1 == rp2 ==> determin who wins
		string winner = "";
		if(rank1 == rank2)
		{
			winner = tieBreaker(p1_cards,p2_cards,rank1);	
			if(winner == "p1")
			cout << " ************ Player 1 Wins ************* " << endl;
			if(winner == "p2")
			cout << " ************ Player 2 Wins ************* " << endl;
			if(winner == "TBD" || winner == " ")
			cout << " ************ To Be Determined ************* " << endl;

		}
		cout << endl;

	}

	return 0;
}

// tie breaker , find out the win based on the rank
string tieBreaker(vector<string> p1_cards, vector<string> p2_cards, int rank)
{

	// Royal Flush will not have a tie breaker
	if(rank == 9)
		return "TBD";

	// Straight Flush  - Sort the cards. Check in descending order . 
	// Straight - consecutive numbers

	if(rank == 8 || rank == 4)
	{
		vector<string> sorted_p1_cards;
		vector<string> sorted_p2_cards;
		sortCards(p1_cards, sorted_p1_cards);
		sortCards(p2_cards, sorted_p2_cards);

		for(int i=sorted_p1_cards.size()-1; i>=0; i--)
		{
			int p1Val = getCardValue(sorted_p1_cards[i][0]);
			int p2Val = getCardValue(sorted_p2_cards[i][0]);
			if(p1Val > p2Val)
				return "p1";
			if(p1Val < p2Val)
				return "p2";
		}


	}

	map<char,int> occur1;
	findOccurence(p1_cards,occur1);

	map<char,int> occur2;
	findOccurence(p2_cards,occur2);

	map<char,int>::iterator it;

	// Four of a kind - check which value is greater in the repetition 
	if(rank == 7)
	{

		int r1 , r2;
		int t1 , t2;
		for(it = occur1.begin(); it!= occur1.end(); it++)
		{
			if(it->second == 4)
			{
				r1 = getCardValue(it->first);
				break;
			}

		}

		for(it = occur2.begin(); it!= occur2.end(); it++)
		{
			if(it->second == 4)
			{
				r2 = getCardValue(it->first);
				break;
			}
		}

		if(r1 == 1)
		r1 = 14;
		if(r2 == 1)
		r2 = 14;

		if(r1 > r2)
			return "p1";

		if(r2 < r2)
			return "p2";

	}

	// full house or three of a kind
	if(rank == 6 || rank == 3)
	{

		int r1 , r2;
		int t1 , t2;
		for(it = occur1.begin(); it!= occur1.end(); it++)
		{
			if(it->second == 3)
			{
				r1 = getCardValue(it->first);
				break;
			}

		}

		for(it = occur2.begin(); it!= occur2.end(); it++)
		{
			if(it->second == 3)
			{
				r2 = getCardValue(it->first);
				break;
			}
		}

		if(r1 == 1)
			r1 = 14;
		if(r2 == 1)
			r2 = 14;

		if(r1 > r2)
			return "p1";

		if(r2 < r2)
			return "p2";



	}

// Flush, compare card with rank
// Hight cards
	if(rank == 5 || rank == 0)
	{

		vector<string> sorted_p1_cards;
		vector<string> sorted_p2_cards;
		sortCardsByA(p1_cards, sorted_p1_cards);
		sortCardsByA(p2_cards, sorted_p2_cards);

		for(int i=sorted_p1_cards.size()-1; i>=0; i--)
		{
			int p1Val = getCardValue(sorted_p1_cards[i][0]);
			int p2Val = getCardValue(sorted_p2_cards[i][0]);
			if(p1Val == 1)
			p1Val = 14;
			if(p2Val == 1)
			p2Val = 14;

			if(p1Val > p2Val)
				return "p1";
			if(p1Val < p2Val)
				return "p2";
		}



	}


	// Two pairs - here we have 3 cases
	// First we need to sort card by A
	// find the repeated card 
	
	if(rank == 2)
	{
		vector<string> sorted_p1_cards;
		vector<string> sorted_p2_cards;
		sortCardsByA(p1_cards, sorted_p1_cards);
		sortCardsByA(p2_cards, sorted_p2_cards);


		for(int i=0; i<sorted_p1_cards.size(); i++)
		{
			int p1Val = getCardValue(sorted_p1_cards[i][0]);
			int p2Val = getCardValue(sorted_p2_cards[i][0]);

			if(p1Val == 1)
			p1Val = 14;

			if(p2Val == 1)
			p2Val = 14;

			if(p1Val > p2Val)
				return "p1";
			if(p1Val < p2Val)
				return "p2";
		}



	}

 	// One Pair - Here we have 2 cases
	// check high card in one pair 
	// even one pair may tie. Check the other cards 
	if(rank == 1)
	{
		int r1 , r2;
		char t1, t2;
		for(it = occur1.begin(); it!= occur1.end(); it++)
		{
			if(it->second == 2)
			{
				r1 = getCardValue(it->first);
				t1 = it->first;
				break;
			}

		}

		for(it = occur2.begin(); it!= occur2.end(); it++)
		{
			if(it->second == 2)
			{
				r2 = getCardValue(it->first);
				t2 = it->first;
				break;
			}
		}

		if(r1 == 1)
			r1 = 14;
		if(r2 == 1)
			r2 = 14;

		if(r1 > r2)
			return "p1";

		if(r1 < r2)
			return "p2";

		// Special Case : Even one pair can be a tie. In this casse check for remaining cards
		vector<string> r1_cards;
		vector<string> r2_cards;
		for(int i=0; i<p1_cards.size(); i++)
		{
			if(p1_cards[i][0] != t1)
			{
				r1_cards.push_back(p1_cards[i]);

			}
		}

		for(int i=0; i<p2_cards.size(); i++)
		{
			if(p2_cards[i][0] != t1)
			{
				r2_cards.push_back(p2_cards[i]);

			}
		}

		// Now we have remaining cards in the hand . Sort it by A and find out

		vector<string> sorted_p1_cards;
		vector<string> sorted_p2_cards;
		sortCardsByA(r1_cards, sorted_p1_cards);
		sortCardsByA(r2_cards, sorted_p2_cards);

		for(int i=sorted_p1_cards.size()-1; i>=0; i--)
		{
			int p1Val = getCardValue(sorted_p1_cards[i][0]);
			int p2Val = getCardValue(sorted_p2_cards[i][0]);
			if(p1Val == 1)
				p1Val = 14;
			if(p2Val == 1)
				p2Val = 14;

			if(p1Val > p2Val)
				return "p1";
			if(p1Val < p2Val)
				return "p2";
		}




	}


	return " ";
}


// populate Cards
void populateCards(string s_cards, vector<string> &p_cards)
{

	for(int i=0; i<s_cards.length(); i+=3)
	{
		//cout << s_cards.substr(i,2) << endl;
		p_cards.push_back(s_cards.substr(i,2));
	}

}

// find the rank of the cards
void findRank(vector<string> p_cards, int &rank)
{

	// map to hold the ranking from low to high
	map<int,string> ranking;
	ranking.insert(pair<int,string> (0,"High Card"));
	ranking.insert(pair<int,string> (1,"One Pair"));
	ranking.insert(pair<int,string> (2,"Two Pairs"));
	ranking.insert(pair<int,string> (3,"Three of a Kind"));
	ranking.insert(pair<int,string> (4,"Straight"));
	ranking.insert(pair<int,string> (5,"Flush"));
	ranking.insert(pair<int,string> (6,"Full House"));
	ranking.insert(pair<int,string> (7,"Four of a Kind"));
	ranking.insert(pair<int,string> (8,"Straight Flush"));
	ranking.insert(pair<int,string> (9,"Royal Flush"));
/*
	// Player 1 cards
	vector<string> p_cards;
	p_cards.push_back("TC");
	p_cards.push_back("TC");
	p_cards.push_back("KC");
	p_cards.push_back("3D");
	p_cards.push_back("2C");

*/
	if(isRoyalFlush(p_cards))
	{
		rank = 9;
		//cout << "Royal Flush" << endl;
		return;
	}

	if(isStraightFlush(p_cards))
	{
		rank = 8;
		//cout << "Straight Flush" << endl;
		return;
	}

	map<char,int> occur;
	findOccurence(p_cards,occur);

	if(isFourOfAKind(p_cards, occur))	
	{
		rank = 7;
		//cout << "Four of a Kind" << endl;
		return;
	}

	if(isFullHouse(p_cards,occur))
	{
		if(p_cards[0] == "9D")
		cout << "Card is 9 D";
		rank = 6;
		cout << "Full House" << endl;
		return;
	}

	if(isFlush(p_cards))
	{
		rank = 5;
		//cout << "Flush" << endl;
		return;
	}

	if(isStraight(p_cards))
	{
		rank = 4;
		//cout << "Straight" << endl;
		return;
	}

	if(isThreeOfAKind(p_cards, occur))
	{
		rank = 3;
		//cout << "Three of a Kind" << endl;
		return;
	}

	if(isTwoPairs(p_cards,occur))
	{
		rank = 2;
		//cout << "Two Pairs" << endl;
		return;
	}

	if(isOnePair(p_cards,occur))
	{
		rank = 1;
		//cout << "One Pair" << endl;
		return;
	}

	rank = 0;

}

// One Pair - only one pair exists
bool isOnePair(vector<string> p_cards, map<char,int> occur)
{

	map<char,int>::iterator it;
	int count = 0;

	for(it = occur.begin(); it!= occur.end(); it++)
	{
		if(it->second == 2)
			count++;
	}

	if(count == 1)
		return true;
	else
		return false;

}


// Two Pairs - Two pairs 
bool isTwoPairs(vector<string> p_cards, map<char,int> occur)
{

	map<char,int>::iterator it;
	int count = 0;

	for(it = occur.begin(); it!= occur.end(); it++)
	{
		if(it->second == 2)
			count++;
	}

	if(count == 2)
		return true;
	else
		return false;

}





// Three Of A Kind - Three cards of a same value

bool isThreeOfAKind(vector<string> p_cards, map<char,int> occur)
{
	map<char,int>::iterator it;

	for(it = occur.begin(); it!= occur.end(); it++)
	{
		if(it->second == 3)
			return true;
	}

	return false;



}


// Straight - consecutive numbers of any suit
bool isStraight(vector<string> p_cards)
{
	vector<string> temp;
	temp = p_cards;
	p_cards.clear();
	sortCards(temp,p_cards);

	int i,j;
	for(i=0, j=i+1; i<4; i++,j++)
	{
		int val1 = getCardValue(p_cards[i][0]);
		int val2 = getCardValue(p_cards[j][0]);

		if(val2-val1 != 1)
			return false;


	}

	return true;


}


// Flush - all of same suit
bool isFlush(vector<string> p_cards)
{

	if(isSameSuit(p_cards))
		return true;
	else
		return false;

}

bool isFullHouse(vector<string> p_cards, map<char,int> occur)
{

	map<char,int>::iterator it;
	bool tok = false;
	bool pair = false;

	for(it = occur.begin(); it!= occur.end(); it++)
	{
		if(it->second == 3)
		{
			tok = true;
			}
		if(it->second == 2)
		{
			pair= true;
			}
	}

	if(tok==true && pair==true)
		return true;
	else
		return false;

}

// Four of a kind - Four cards with same value

bool isFourOfAKind(vector<string> p_cards, map<char,int> occur)
{

	map<char,int>::iterator it;

	for(it = occur.begin(); it!= occur.end(); it++)
	{
		if(it->second == 4)
			return true;
	}

	return false;


}

// find occurence of each card
void findOccurence(vector<string> p_cards, map<char,int> &occur)
{

	map<char,int> ::iterator it;
	occur.insert(pair<char,int>('A',0));
	occur.insert(pair<char,int>('2',0));
	occur.insert(pair<char,int>('3',0));
	occur.insert(pair<char,int>('4',0));
	occur.insert(pair<char,int>('5',0));
	occur.insert(pair<char,int>('6',0));
	occur.insert(pair<char,int>('7',0));
	occur.insert(pair<char,int>('8',0));
	occur.insert(pair<char,int>('9',0));
	occur.insert(pair<char,int>('T',0));
	occur.insert(pair<char,int>('J',0));
	occur.insert(pair<char,int>('Q',0));
	occur.insert(pair<char,int>('K',0));


	for(int i=0; i<p_cards.size(); i++)
	{
		char card = p_cards[i][0];
		it = occur.find(card);
		int val = it->second;
		val = val + 1;
		occur[card] = val;

	}


}

// For royal Flush we know that , all cards should be of the same suit. and it should be having T to A in any order
bool isRoyalFlush(vector<string> p_cards)
{

	map<char,bool> rf;
	map<char,bool>:: iterator it;
	rf.insert(pair<char,bool>('A',false));
	rf.insert(pair<char,bool>('K',false));
	rf.insert(pair<char,bool>('Q',false));
	rf.insert(pair<char,bool>('J',false));
	rf.insert(pair<char,bool>('T',false));
	char suit;
	suit = p_cards[0][1];

	if(!isSameSuit(p_cards))
	return false;

	for(int i=0; i<p_cards.size(); i++)
	{
		string card = p_cards[i];
		char number = card[0];
		// only A to T can exist
		if(rf.find(number) == rf.end())
			return false;
		else
		{
			rf[number] = true;
		}

	}

	for(it=rf.begin(); it!=rf.end(); it++)
	{
		if(it->second == false)
			return false;
	}

	return true;


}


// assign first suit and check successive suits . if not matches return false else return true;
bool isSameSuit(vector<string> p_cards)
{
	char suit;
	suit = p_cards[0][1];
	bool a = false;

	for(int i=0; i<p_cards.size(); i++)
	{
		if(p_cards[i][1] != suit)
		{
			//return false;
			a = true;
		}
	}
	if(a)
		return false;
	else
		return true;
}

// all same suite and succesive numbers
bool isStraightFlush(vector<string> p_cards)
{

	if(!isSameSuit(p_cards))
	return false;

	vector<string> temp;
	temp = p_cards;
	p_cards.clear();
	sortCards(temp,p_cards);

	int i,j;
	for(i=0, j=i+1; i<4; i++,j++)
	{
		int val1 = getCardValue(p_cards[i][0]);
		int val2 = getCardValue(p_cards[j][0]);

		if(val2-val1 != 1)
		return false;
		

	}

	return true;

}

int getCardValue(char c)
{

	int retval = 0;
	switch(c)
	{
		case 'A' : retval = 1;
				   break;

		case 'T' :  retval = 10;
					break;

		case 'J' :  retval = 11;
					break;

		case 'Q' : retval = 12;
				   break;

		case 'K' : retval = 13;
				   break;

		default : retval = c - '0';
				  break;


	}

	return retval;
}




void sortCards(vector<string> p_cards, vector<string> & sorted_p_cards)
{

	vector<string> numCards;
	vector<string> picCards;

	for(int i=0; i<p_cards.size(); i++)
	{
		int ascii_val = (int)p_cards[i][0] ;
		if(ascii_val < 50 || ascii_val > 57)
			picCards.push_back(p_cards[i]);
		else
			numCards.push_back(p_cards[i]);

	}



	// check for A and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'A')
			sorted_p_cards.push_back(picCards[i]);
	}

	// sort the numbers 

	for(int i=0; i<numCards.size(); i++)
	{
		for(int j=0; j<numCards.size(); j++)
		{
			if(numCards[i][0] < numCards[j][0])
			{

				string temp = numCards[i];
				numCards[i] = numCards[j];
				numCards[j] = temp;


			}
		}

	}

	for(int i=0; i<numCards.size(); i++)
		sorted_p_cards.push_back(numCards[i]);


	// check for Ten and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'T')
			sorted_p_cards.push_back(picCards[i]);
	}

	// check for J and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'J')
			sorted_p_cards.push_back(picCards[i]);
	}

	// check for Q and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'Q')
			sorted_p_cards.push_back(picCards[i]);
	}

	// check for K and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'K')
			sorted_p_cards.push_back(picCards[i]);
	}
}



void sortCardsByA(vector<string> p_cards, vector<string> & sorted_p_cards)
{

	vector<string> numCards;
	vector<string> picCards;

	for(int i=0; i<p_cards.size(); i++)
	{
		int ascii_val = (int)p_cards[i][0] ;
		if(ascii_val < 50 || ascii_val > 57)
			picCards.push_back(p_cards[i]);
		else
			numCards.push_back(p_cards[i]);

	}



	// sort the numbers 

	for(int i=0; i<numCards.size(); i++)
	{
		for(int j=0; j<numCards.size(); j++)
		{
			if(numCards[i][0] < numCards[j][0])
			{

				string temp = numCards[i];
				numCards[i] = numCards[j];
				numCards[j] = temp;


			}
		}

	}

	for(int i=0; i<numCards.size(); i++)
		sorted_p_cards.push_back(numCards[i]);


	// check for Ten and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'T')
			sorted_p_cards.push_back(picCards[i]);
	}

	// check for J and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'J')
			sorted_p_cards.push_back(picCards[i]);
	}

	// check for Q and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'Q')
			sorted_p_cards.push_back(picCards[i]);
	}

	// check for K and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'K')
			sorted_p_cards.push_back(picCards[i]);
	}

	// check for A and insert it

	for(int i=0; i<picCards.size(); i++)
	{
		if(picCards[i][0] == 'A')
			sorted_p_cards.push_back(picCards[i]);
	}


}
