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

class NumbersChallenge
{
public:
	int MinNumber(vector <int> S);
};

int NumbersChallenge::MinNumber(vector <int> S)
{
    int n = sz(S);
    vector<int> s;
    for (int i = 1; i < (1 << n); ++i) {
        int ss = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                ss += S[j];
            }
        }
        s.push_back(ss);
    }
    sort(all(s));
    int now = 1;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == now) {
            ++now;
        } else if (s[i] > now) {
            return now;
        }
    }
    return now;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Your friend Lucas gave you a sequence S of positive integers.

For a while, you two played a simple game with S:
Lucas would pick a number, and you had to select some elements of S such that the sum of all numbers you selected is the number chosen by Lucas.
For example, if S={2,1,2,7} and Lucas chose the number 11, you would answer that 2+2+7 = 11.

Lucas now wants to trick you by choosing a number X such that there will be no valid answer.
For example, if S={2,1,2,7}, it is not possible to select elements of S that sum up to 6.

You are given the vector <int> S.
Find the smallest positive integer X that cannot be obtained as the sum of some (possibly all) elements of S.

DEFINITION
Class:NumbersChallenge
Method:MinNumber
Parameters:vector <int>
Returns:int
Method signature:int MinNumber(vector <int> S)


CONSTRAINTS
-S will contain between 1 and 20 elements, inclusive.
-Each element of S will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{5, 1, 2}

Returns: 4

These are all the positive integers that can be obtained: 1, 2, 3, 5, 6, 7, and 8.
(We can obtain 3 as 1+2, 6 as 1+5, 7 as 2+5, and 8 as 1+2+5.)
The smallest positive integer not present in the above list is 4.

1)
{2, 1, 4}

Returns: 8

We can obtain each of the sums from 1 to 7, inclusive. The smallest impossible sum is 8.

2)
{2, 1, 2, 7}

Returns: 6

The example given in the problem statement.

3)
{94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}

Returns: 1092



4)
{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}

Returns: 56523



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
        int SARRAY[] = {5, 1, 2};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
        eq(0, theObject.MinNumber(S),4);
    }
    {
        int SARRAY[] = {2, 1, 4};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
        eq(1, theObject.MinNumber(S),8);
    }
    {
        int SARRAY[] = {2, 1, 2, 7};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
        eq(2, theObject.MinNumber(S),6);
    }
    {
        int SARRAY[] = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
        eq(3, theObject.MinNumber(S),1092);
    }
    {
        int SARRAY[] = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
        eq(4, theObject.MinNumber(S),56523);
    }
}
// END CUT HERE
