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

class LongWordsDiv2
{
public:
	string find(string word);
};

bool isok(string s1, string s2)
{
    set<char> st;
    for (int i = 0; i < sz(s1); ++i) st.insert(s1[i]);
    for (int i = 0; i < sz(s2); ++i) {
        if (st.count(s2[i])) return false;
    }
    return true;
}

string LongWordsDiv2::find(string word)
{
    for (int i = 1; i < sz(word); ++i) {
        if (word[i] == word[i - 1]) return "Dislikes";
    }
    for (int i = 0; i < sz(word); ++i) {
        for (int j = i + 1; j < sz(word); ++j) {
            if (word[i] == word[j]) {
                if (!isok(word.substr(i + 1, j - i - 1), word.substr(j + 1))) return "Dislikes";
            }
        }
    }
    return "Likes";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Fox Ciel likes all the words that have the following properties:

Each letter of the word is an uppercase English letter.
Equal letters are never consecutive.
There is no subsequence of the form xyxy, where x and y are (not necessarily distinct) letters. Note that a subsequence doesn't have to be contiguous.

Examples:

Ciel does not like "ABBA" because there are two consecutive 'B's.
Ciel does not like "THETOPCODER" because it contains the subsequence "TETE".
Ciel does not like "ABACADA" because it contains the subsequence "AAAA". (Note that here x=y='A'.)
Ciel likes "A", "ABA", and also "ABCBA".

Given a string word, return "Likes" (quotes for clarity) if Ciel likes word and "Dislikes" if she does not.


DEFINITION
Class:LongWordsDiv2
Method:find
Parameters:string
Returns:string
Method signature:string find(string word)


CONSTRAINTS
-word will contain between 1 and 100 characters, inclusive.
-Each character of word will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"AAA"

Returns: "Dislikes"



1)
"ABCBA"

Returns: "Likes"



2)
"ABCBAC"

Returns: "Dislikes"



3)
"TOPCODER"

Returns: "Likes"



4)
"VAMOSGIMNASIA"

Returns: "Dislikes"



5)
"SINGLEROUNDMATCH"

Returns: "Likes"



6)
"DALELOBO"

Returns: "Likes"



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
        LongWordsDiv2 theObject;
        eq(0, theObject.find("AAA"),"Dislikes");
    }
    {
        LongWordsDiv2 theObject;
        eq(1, theObject.find("ABCBA"),"Likes");
    }
    {
        LongWordsDiv2 theObject;
        eq(2, theObject.find("ABCBAC"),"Dislikes");
    }
    {
        LongWordsDiv2 theObject;
        eq(3, theObject.find("TOPCODER"),"Likes");
    }
    {
        LongWordsDiv2 theObject;
        eq(4, theObject.find("VAMOSGIMNASIA"),"Dislikes");
    }
    {
        LongWordsDiv2 theObject;
        eq(5, theObject.find("SINGLEROUNDMATCH"),"Likes");
    }
    {
        LongWordsDiv2 theObject;
        eq(6, theObject.find("DALELOBO"),"Likes");
    }
}
// END CUT HERE
