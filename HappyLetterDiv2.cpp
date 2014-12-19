// Orz AekdyCoin 福大核武景润后人

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <functional>
#include <cctype>
#include <string>

using namespace std;

#define all(X) (X).begin(), (X).end() 
#define sz(a) int((a).size())

typedef long long ll;

class HappyLetterDiv2
{
public:
	char getHappyLetter(string letters);
};

char HappyLetterDiv2::getHappyLetter(string letters)
{
    map<char, int> mp;
    int best = 0;
    char bestc;
    for (int i = 0; i < sz(letters); ++i) {
        mp[letters[i]]++;
        if (mp[letters[i]] > best) {
            best = mp[letters[i]];
            bestc = letters[i];
        }
    }
    if (best + best > sz(letters)) {
        return bestc;
    } else {
        return '.';
    }
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// The Happy Letter game is played as follows:
At the beginning, several players enter the field.
Each player has a lowercase English letter on their back.
The game is played in turns.
In each turn, you select two players with different letters, and both selected players leave the field.
The game ends once it is impossible to take another turn.

If there are some players left in the field at the end of the game, they must all have the same letter.
That letter is called the winning letter.
If there are no players left in the field at the end of the game, there is no winning letter.

In general, there may be many different ways how to play the game, and these may lead to different outcomes of the game.
However, sometimes we can look at the initial players and determine that each possible sequence of turns leads to the same winning letter.
That winning letter is then called a happy letter.

You are given a string letters.
The characters in letters are the characters carried by the players at the beginning of the game.
Return a string with one character: either the happy letter (if it exists), or a period ('.') if there is no happy letter.


DEFINITION
Class:HappyLetterDiv2
Method:getHappyLetter
Parameters:string
Returns:char
Method signature:char getHappyLetter(string letters)


CONSTRAINTS
-letters will contain between 1 and 50 elements.
-Each element of letters will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"aacaaa"

Returns: 'a'

In the first turn we send away the player with the 'c' and one of the players with an 'a'. All remaining players have an 'a', hence the game ends and 'a' is the winning letter.


1)
"dcdjx"

Returns: '.'

Each of the letters 'c', 'd', 'j', and 'x' can be the winning letter. Thus there is no happy letter.


2)
"bcbbbbba"

Returns: 'b'



3)
"aabc"

Returns: '.'

Here, only 'a' can be the winning letter. However, it is also possible that there is no winning letter at the end of the game. Therefore 'a' is not considered to be the happy letter.


*/

#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
void print(T a) {
	cerr << a;
}

void print(long long a) {
	cerr << a << "LL";
}

void print(string a) {
	cerr << '"' << a << '"';
}

template<typename T>
void print(vector<T> a) {
	cerr << "{";
	for (unsigned i = 0; i != a.size(); i++) {
		if (i != 0) cerr << ", ";
		print(a[i]);
	}
	cerr << "}" << endl;
}

template<typename T>
void eq(int n, T have, T need) {
	if (have == need) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print(need);
		cerr << " received ";
		print(have);
		cerr << "." << endl;
	}
}

template<typename T>
void eq(int n, vector<T> have, vector<T> need) {
	if(have.size() != need.size()) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print(have);
		print(need);
		return;
	}
	for(unsigned i = 0; i < have.size(); i++) {
		if(have[i] != need[i]) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print(have);
			print(need);
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}

void eq(int n, string have, string need) {
	if (have == need) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print(need);
		cerr << " received ";
		print(have);
		cerr << "." << endl;
	}
}

int main() {
    {
        HappyLetterDiv2 theObject;
        eq(0, theObject.getHappyLetter("aacaaa"),'a');
    }
    {
        HappyLetterDiv2 theObject;
        eq(1, theObject.getHappyLetter("dcdjx"),'.');
    }
    {
        HappyLetterDiv2 theObject;
        eq(2, theObject.getHappyLetter("bcbbbbba"),'b');
    }
    {
        HappyLetterDiv2 theObject;
        eq(3, theObject.getHappyLetter("aabc"),'.');
    }
}
// END CUT HERE
