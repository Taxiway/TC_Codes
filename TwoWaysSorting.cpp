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

class TwoWaysSorting
{
public:
	string sortingMethod(vector <string> stringList);
};

string TwoWaysSorting::sortingMethod(vector <string> stringList)
{
    vector<string> ss = stringList;
    sort(all(ss));
    bool alp = (ss == stringList);
    bool len = true;
    for (int i = 1; i < sz(stringList); ++i) {
        if (stringList[i].size() < stringList[i - 1].size()) len = false;
    }
    if (alp) {
        if (len) return "both";
        else return "lexicographically";
    } else {
        if (len) return "lengths";
        else return "none";
    }
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
	Sasha has a vector <string> stringList. No two elements of stringList have the same length.



	So far, Sasha has learned two ways of sorting strings:


	
		He can sort strings lexicographically. For example, "car" < "carriage" < "cats" < "doggies". (See Notes for a definition of the lexicographic order.)
	
	
		He can also sort strings according to their lengths in ascending order. For example, "car" < "cats" < "doggies" < "carriage".
	


	Sasha now wonders whether stringList is sorted in either of these two ways. Return "lexicographically" (quotes for clarity) if stringList is sorted lexicographically but not according to the string lengths. Return "lengths" if stringList is sorted according to the string lengths but not lexicographically. Return "both" if it is sorted in both ways. Otherwise, return "none".



DEFINITION
Class:TwoWaysSorting
Method:sortingMethod
Parameters:vector <string>
Returns:string
Method signature:string sortingMethod(vector <string> stringList)


NOTES
-String A is lexicographically smaller than string B if A contains a character with a smaller ASCII value in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.


CONSTRAINTS
-stringList will contain between 1 and 50 elements, inclusive.
-Each element of stringList will contain between 1 and 50 characters, inclusive.
-Each character of each element of stringList will be a lowercase English letter ('a'-'z').
-Every two elements of stringList will have different lengths.


EXAMPLES

0)
{"a", "aa", "bbb"}

Returns: "both"

These strings are sorted both lexicographically and according to their lengths.

1)
{"c", "bb", "aaa"}

Returns: "lengths"

The lengths of these strings are in ascending order. However, they are not sorted lexicographically as, for instance, "aaa" is lexicographically smaller than "c".

2)
{"etdfgfh", "aio"}

Returns: "none"

Here the first string is longer than the second one, so they are not sorted according to length. (Note that we require the lengths to be in ascending order.) Similarly, they are not sorted lexicographically: "aio" should come before "etdfgfh".

3)
{"aaa", "z"}

Returns: "lexicographically"

The input strings are sorted lexicographically only.

4)
{"z"}

Returns: "both"



5)
{"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}

Returns: "lexicographically"



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
        string stringListARRAY[] = {"a", "aa", "bbb"};
        vector <string> stringList( stringListARRAY, stringListARRAY+ARRSIZE(stringListARRAY) );
        TwoWaysSorting theObject;
        eq(0, theObject.sortingMethod(stringList),"both");
    }
    {
        string stringListARRAY[] = {"c", "bb", "aaa"};
        vector <string> stringList( stringListARRAY, stringListARRAY+ARRSIZE(stringListARRAY) );
        TwoWaysSorting theObject;
        eq(1, theObject.sortingMethod(stringList),"lengths");
    }
    {
        string stringListARRAY[] = {"etdfgfh", "aio"};
        vector <string> stringList( stringListARRAY, stringListARRAY+ARRSIZE(stringListARRAY) );
        TwoWaysSorting theObject;
        eq(2, theObject.sortingMethod(stringList),"none");
    }
    {
        string stringListARRAY[] = {"aaa", "z"};
        vector <string> stringList( stringListARRAY, stringListARRAY+ARRSIZE(stringListARRAY) );
        TwoWaysSorting theObject;
        eq(3, theObject.sortingMethod(stringList),"lexicographically");
    }
    {
        string stringListARRAY[] = {"z"};
        vector <string> stringList( stringListARRAY, stringListARRAY+ARRSIZE(stringListARRAY) );
        TwoWaysSorting theObject;
        eq(4, theObject.sortingMethod(stringList),"both");
    }
    {
        string stringListARRAY[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"};
        vector <string> stringList( stringListARRAY, stringListARRAY+ARRSIZE(stringListARRAY) );
        TwoWaysSorting theObject;
        eq(5, theObject.sortingMethod(stringList),"lexicographically");
    }
}
// END CUT HERE
