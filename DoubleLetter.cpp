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

class DoubleLetter
{
public:
	string ableToSolve(string S);
};

string gao(string s)
{
    for (int i = 1; i < sz(s); ++i) {
        if (s[i] == s[i - 1]) {
            return s.substr(0, i - 1) + s.substr(i + 1);
        }
    }
    return s;
}

string DoubleLetter::ableToSolve(string S)
{
    string s = S;
    while (1) {
        string ss = gao(s);
        if (ss == "") return "Possible";
        if (ss == s) break;
        s = ss;
    }
    return "Impossible";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You are given a string S.
You can modify this string by repeating the following process:

Find the leftmost occurrence of two consecutive letters in S that are the same.
If you found a pair of identical letters in the first step, delete those two letters from S.


For example, if S="aabccb", you can proceed as follows:

Find and erase "aa", producing the string "bccb".
Find and erase "cc", producing the string "bb".
Find and erase "bb", producing the empty string.


For S="axxyybac" you can do at most two steps, erasing "xx" first and "yy" next. Once you obtain the string "abac", you are done. Note that you cannot erase the two "a"s because they are not consecutive.

You want to change S into an empty string by repeating the operation described above.
Return "Possible" if you can do that, and "Impossible" otherwise.

DEFINITION
Class:DoubleLetter
Method:ableToSolve
Parameters:string
Returns:string
Method signature:string ableToSolve(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters.
-Each character in S will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"aabccb"

Returns: "Possible"



1)
"aabccbb"

Returns: "Impossible"

The process will terminate with a single 'b'.

2)
"abcddcba"

Returns: "Possible"

"abcddcba" -> "abccba" -> "abba" -> "aa" -> "".

3)
"abab"

Returns: "Impossible"

No two successive letters are the same, so we can't do any operation.

4)
"aaaaaaaaaa"

Returns: "Possible"



5)
"aababbabbaba"

Returns: "Impossible"



6)
"zzxzxxzxxzzx"

Returns: "Possible"



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
        DoubleLetter theObject;
        eq(0, theObject.ableToSolve("aabccb"),"Possible");
    }
    {
        DoubleLetter theObject;
        eq(1, theObject.ableToSolve("aabccbb"),"Impossible");
    }
    {
        DoubleLetter theObject;
        eq(2, theObject.ableToSolve("abcddcba"),"Possible");
    }
    {
        DoubleLetter theObject;
        eq(3, theObject.ableToSolve("abab"),"Impossible");
    }
    {
        DoubleLetter theObject;
        eq(4, theObject.ableToSolve("aaaaaaaaaa"),"Possible");
    }
    {
        DoubleLetter theObject;
        eq(5, theObject.ableToSolve("aababbabbaba"),"Impossible");
    }
    {
        DoubleLetter theObject;
        eq(6, theObject.ableToSolve("zzxzxxzxxzzx"),"Possible");
    }
}
// END CUT HERE
