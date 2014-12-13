// Orz AekdyCoin ∏£¥Û∫ÀŒ‰æ∞»Û∫Û»À

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

class IdentifyingWood
{
public:
	string check(string s, string t);
};

string IdentifyingWood::check(string s, string t)
{
	for (int i = 0, j = 0; i < sz(s); ++i) {
		if (s[i] == t[j]) {
			++j;
			if (j == t.size()) {
				return "Yep, it's wood.";
			}
		}
	}
	return "Nope.";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
We call a pair of strings (s, t) "wood" if t is contained in s as a subsequence. (See Notes for a formal definition.)



Given strings s and t, return the string "Yep, it's wood." (quotes for clarity) if the pair (s, t) is wood and "Nope." otherwise.


DEFINITION
Class:IdentifyingWood
Method:check
Parameters:string, string
Returns:string
Method signature:string check(string s, string t)


NOTES
-String t is contained in string s as a subsequence if we can obtain t by removing zero or more (not necessarily consecutive) characters from s.


CONSTRAINTS
-s and t will consist only of lowercase English letters.
-s and t will each be between 1 and 10 characters long, inclusive.


EXAMPLES

0)
"absdefgh"
"asdf"

Returns: "Yep, it's wood."



1)
"oxoxoxox"
"ooxxoo"

Returns: "Nope."



2)
"oxoxoxox"
"xxx"

Returns: "Yep, it's wood."



3)
"qwerty"
"qwerty"

Returns: "Yep, it's wood."



4)
"string"
"longstring"

Returns: "Nope."



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
        IdentifyingWood theObject;
        eq(0, theObject.check("absdefgh", "asdf"),"Yep, it's wood.");
    }
    {
        IdentifyingWood theObject;
        eq(1, theObject.check("oxoxoxox", "ooxxoo"),"Nope.");
    }
    {
        IdentifyingWood theObject;
        eq(2, theObject.check("oxoxoxox", "xxx"),"Yep, it's wood.");
    }
    {
        IdentifyingWood theObject;
        eq(3, theObject.check("qwerty", "qwerty"),"Yep, it's wood.");
    }
    {
        IdentifyingWood theObject;
        eq(4, theObject.check("string", "longstring"),"Nope.");
    }
}
// END CUT HERE
