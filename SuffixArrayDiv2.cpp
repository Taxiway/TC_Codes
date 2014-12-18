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

class SuffixArrayDiv2
{
public:
	string smallerOne(string s);
};

string SuffixArrayDiv2::smallerOne(string s)
{
    string ss = s;
    vector<string> v;
    for (int i = 0; i < sz(s); ++i) {
        v.push_back(s.substr(i));
    }
    sort(all(v));
    vector<int> num;
    map<int, int> mp;
    for (int i = 0; i < sz(v); ++i) {
        num.push_back(sz(s) - sz(v[i]));
        mp[num[i]] = i;
    }
    mp[sz(v)] = -1;
    s[num[0]] = 'a';
    for (int i = 1; i < sz(s); ++i) {
        int current = num[i];
        int last = num[i - 1];
        if (mp[current + 1] < mp[last + 1]) {
            s[current] = s[last] + 1;
        } else {
            s[current] = s[last];
        }
    }
    cout << s << endl;
    if (strcmp(s.c_str(), ss.c_str()) < 0) {
        return "Exists";
    } else {
        return "Does not exist";
    }
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Suffix number i of a string S is the suffix that starts with the character S[i].
For example, for S="abcde" suffix 0 is "abcde" and suffix 3 is "de". 


The suffix array of a string S is defined as the permutation of suffix numbers that corresponds to their lexicographic order.
For example, suppose that S="abca".
If we order all suffixes of S lexicographically, we get the following: "a" < "abca" < "bca" < "ca".
The corresponding suffix numbers are 3, 0, 1, and 2, in this order.
Thus, for this string S the suffix array would be {3, 0, 1, 2}.
Note that the length of a suffix array is the same as the length of the original string.


In this problem, we will only consider strings of lowercase English letters ('a'-'z').
You are given a string s.
We are interested in a string t that is lexicographically smaller than s but has exactly the same suffix array.
Return "Exists" if at least one such string t exists, and "Does not exist" otherwise.

DEFINITION
Class:SuffixArrayDiv2
Method:smallerOne
Parameters:string
Returns:string
Method signature:string smallerOne(string s)


NOTES
-Given two different strings A and B of the same length, A is lexicographically smaller than B if we have A[i] < B[i] for the smallest i such that A[i] and B[i] differ.


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-Each element in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"abca"

Returns: "Exists"

For example, "aaqa" < "abca" but their suffix arrays are the same.

1)
"bbbb"

Returns: "Exists"

Obviously, one of the strings smaller than "bbbb" with the same suffix array is "aaaa".

2)
"aaaa"

Returns: "Does not exist"

The string "aaaa" is already the lexicographically smallest 4-letter string.

3)
"examplesareveryweakthinktwicebeforesubmit"

Returns: "Exists"



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
        SuffixArrayDiv2 theObject;
        eq(0, theObject.smallerOne("abca"),"Exists");
    }
    {
        SuffixArrayDiv2 theObject;
        eq(1, theObject.smallerOne("bbbb"),"Exists");
    }
    {
        SuffixArrayDiv2 theObject;
        eq(2, theObject.smallerOne("aaaa"),"Does not exist");
    }
    {
        SuffixArrayDiv2 theObject;
        eq(3, theObject.smallerOne("examplesareveryweakthinktwicebeforesubmit"),"Exists");
    }
}
// END CUT HERE
