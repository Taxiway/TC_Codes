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

class SpecialStrings
{
public:
	string findNext(string current);
};

string gao(string s)
{
	int ind = sz(s) - 1;
	while (s[ind] == '1') --ind;
	return s.substr(0, ind) + '1';
}

string SpecialStrings::findNext(string current)
{
	int n = sz(current);
	if (n == 1) {
		if (current == "0") return "1";
		else return "";
	}
	int ind = sz(current) - 1;
	while (current[ind] == '1') --ind;
	if (ind == 0) return "";
	string s = current.substr(0, ind) + "1";
	string ret = "";
	while (sz(ret) + sz(s) < sz(current)) {
		ret += s;
	}
	while (sz(ret) < sz(current)) {
		int diff = sz(current) - sz(ret);
		string ss = ret.substr(0, diff);
		ret += gao(ss);
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
A string S is called special if it satisfies the following two properties:

Each character in S is either '0' or '1'.
Whenever S = UV where both U and V are nonempty strings, U is strictly smaller than V in lexicographic order.




For example, the string S = "00101" is special because we have "0" < "0101", "00" < "101", "001" < "01", and "0010" < "1".



You are given a string current that is guaranteed to be special.
Let N be the length of current.
Consider the lexicographically sorted list of all special strings of length N.
Compute and return the string that comes immediatelly after current in this list.
If current happens to be the last string in the list, return an empty string instead.


DEFINITION
Class:SpecialStrings
Method:findNext
Parameters:string
Returns:string
Method signature:string findNext(string current)


NOTES
-Given two different strings U and V, the string U precedes the string V in lexicographic order if one of two conditions is satisfied: Either U is a proper prefix of V, or there is an integer x such that U and V have the same first x characters, and the x+1th character in U is smaller than the x+1th character in V.


CONSTRAINTS
-current will contain between 1 and 50 characters, inclusive.
-current will be a special string.


EXAMPLES

0)
"01"

Returns: ""

"01" is the only special string of length 2.

1)
"00101"

Returns: "00111"

The special strings of length 5 are "00001", "00011", "00101", "00111", "01011", "01111".

2)
"0010111"

Returns: "0011011"



3)
"000010001001011"

Returns: "000010001001101"



4)
"01101111011110111"

Returns: "01101111011111111"



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
        SpecialStrings theObject;
        eq(0, theObject.findNext("01"),"");
    }
    {
        SpecialStrings theObject;
        eq(1, theObject.findNext("00101"),"00111");
    }
    {
        SpecialStrings theObject;
        eq(2, theObject.findNext("0010111"),"0011011");
    }
    {
        SpecialStrings theObject;
        eq(3, theObject.findNext("000010001001011"),"000010001001101");
    }
    {
        SpecialStrings theObject;
        eq(4, theObject.findNext("01101111011110111"),"01101111011111111");
    }
}
// END CUT HERE
