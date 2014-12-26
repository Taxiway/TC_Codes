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

class MergeStrings
{
public:
	string getmin(string S, string A, string B);
};

bool match(char ch, char c)
{
    return c == '?' || c == ch;
}

string MergeStrings::getmin(string S, string A, string B)
{
    bool isok[64][64];
    string best[64][64];
    memset(isok, false, sizeof(isok));
    isok[sz(A)][sz(B)] = true;
    for (int l = sz(S) - 1; l >= 0; --l) {
        for (int la = 0; la <= sz(A); ++la) {
            int lb = l - la;
            if (lb < 0 || lb > sz(B)) continue;
            string b = "Z";
            ++b[0];
            if (la != sz(A) && match(A[la], S[l]) && isok[la + 1][lb]) {
                isok[la][lb] = true;
                b = min(b, A[la] + best[la + 1][lb]);
            }
            if (lb != sz(B) && match(B[lb], S[l]) && isok[la][lb + 1]) {
                isok[la][lb] = true;
                b = min(b, B[lb] + best[la][lb + 1]);
            }
            if (isok[la][lb]) best[la][lb] = b;
        }
    }
    return best[0][0];
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Guts is a slow loris who likes to play with strings.

String C is obtained by shuffling strings A and B if we can create C by repeatedly taking either the first character of A or the first character of B. Formally, string C is obtained by shuffling strings A and B if length(C) = length(A) + length(B) and there are sequences of integers X and Y such that:

length(X) = length(A) and length(Y) = length(B).
For each valid i, X[i] < X[i+1].
For each valid i, Y[i] < Y[i+1].
For each valid i and j, X[i] != Y[j].
For each valid i, C[X[i]] = A[i].
For each valid i, C[Y[i]] = B[i].


You are given strings S, A, and B. Strings A and B contain only letters, string S can also contain multiple copies of the '?' (question mark) character. The '?' is a wildcard that represents any single letter. Guts wants to shuffle strings A and B in such a way that the resulting string matches S.

Replace each '?' with a letter in such a way that the resulting string S can be obtained by shuffling A and B. Return the resulting string S. If there are multiple solutions, return the lexicographically smallest one. If there is no solution, return an empty string instead.

DEFINITION
Class:MergeStrings
Method:getmin
Parameters:string, string, string
Returns:string
Method signature:string getmin(string S, string A, string B)


NOTES
-Given two distinct strings X and Y such that length(X)=length(Y), the lexicographically smaller one is the one that has a character with a smaller ASCII value on the first position on which they differ.


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-The number of characters in S will be same as the total number of characters of A and B.
-Each character in S will be an uppercase letter ('A'-'Z') or '?'.
-Each character in A and B will be an uppercase letter ('A'-'Z').


EXAMPLES

0)
"??CC??"
"ABC"
"BCC"

Returns: "ABCCBC"

Out of all strings that can be obtained by shuffling "ABC" and "BCC", only two match "??CC??": the strings "ABCCBC" and "BACCBC". The string "ABCCBC" is the lexicographically smaller of the two.

1)
"WHAT?"
"THE"
"WA"

Returns: ""

None of the strings obtained by shuffling "THE" and "WA" matches "WHAT?".

2)
"PARROT"
"PARROT"
""

Returns: "PARROT"

One of A and B may sometimes be empty.

3)
"???????????"
"AZZAA"
"AZAZZA"

Returns: "AAZAZZAAZZA"



4)
"????K??????????????D???K???K????????K?????K???????"
"KKKKKDKKKDKKDDKDDDKDKK"
"KDKDDKKKDDKDDKKKDKDKKDDDDDDD"

Returns: "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"



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
        MergeStrings theObject;
        eq(0, theObject.getmin("??CC??", "ABC", "BCC"),"ABCCBC");
    }
    {
        MergeStrings theObject;
        eq(1, theObject.getmin("WHAT?", "THE", "WA"),"");
    }
    {
        MergeStrings theObject;
        eq(2, theObject.getmin("PARROT", "PARROT", ""),"PARROT");
    }
    {
        MergeStrings theObject;
        eq(3, theObject.getmin("???????????", "AZZAA", "AZAZZA"),"AAZAZZAAZZA");
    }
    {
        MergeStrings theObject;
        eq(4, theObject.getmin("????K??????????????D???K???K????????K?????K???????", "KKKKKDKKKDKKDDKDDDKDKK", "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"),"KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK");
    }
}
// END CUT HERE
