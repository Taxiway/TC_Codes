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

class AliceGameEasy
{
public:
	long long findMinimumValue(long long x, long long y);
};

bool check(long long x, long long s)
{
	return (x * (x + 1)) / 2 == s;
}

long long calu(long long x, long long r)
{
	long long ret = 0;
	while (r && x) {
		if (x >= r) {
			x -= r;
			++ret;
		}
		--r;
	}
	return ret;
}

long long AliceGameEasy::findMinimumValue(long long x, long long y)
{
	long long sum = x + y;
	long long r = (long long)sqrt(double(sum * 2));
	if (check(r, sum)) {
		return calu(x, r);
	}
	if (check(r - 1, sum)) {
		return calu(x, r - 1);
	}
	if (check(r + 1, sum)) {
		return calu(x, r + 1);
	}
	return -1;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Alice and Kirito just played a game.
The game consisted of a finite (possibly empty) sequence of turns.
You do not know the exact number of turns.
The turns were numbered starting from 1.
In each turn, exactly one of our two players won.
The winner of turn i scored i points.



You are given two long longs x and y.
Find out whether it is possible that at the end of the game Alice had exactly x points and Kirito had exactly y points.
If it is possible, return the smallest number of turns Alice could have won.
If the given final result is not possible, return -1 instead.


DEFINITION
Class:AliceGameEasy
Method:findMinimumValue
Parameters:long long, long long
Returns:long long
Method signature:long long findMinimumValue(long long x, long long y)


CONSTRAINTS
-x and y will be between 0 and 1,000,000,000,000(10^12), inclusive.


EXAMPLES

0)
7
14

Returns: 2

This final result is possible.
One possibility is that Alice won turns 1, 2, and 4 (for 1+2+4 = 7 points) and Kirito won turns 3, 5, and 6 (for 3+5+6 = 14 points).
However, there are also some other possibilities in which Alice only won two of the six turns, so the correct answer is 2.

1)
10
0

Returns: 4

There must have been four turns and Alice must have won all four of them.

2)
932599670050
67400241741

Returns: 1047062

Watch out for integer overflow.

3)
7
13

Returns: -1



4)
0
0

Returns: 0



5)
100000
400500

Returns: 106



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
        AliceGameEasy theObject;
        eq(0, theObject.findMinimumValue(7LL, 14LL),2LL);
    }
    {
        AliceGameEasy theObject;
        eq(1, theObject.findMinimumValue(10LL, 0LL),4LL);
    }
    {
        AliceGameEasy theObject;
        eq(2, theObject.findMinimumValue(932599670050LL, 67400241741LL),1047062LL);
    }
    {
        AliceGameEasy theObject;
        eq(3, theObject.findMinimumValue(7LL, 13LL),-1LL);
    }
    {
        AliceGameEasy theObject;
        eq(4, theObject.findMinimumValue(0LL, 0LL),0LL);
    }
    {
        AliceGameEasy theObject;
        eq(5, theObject.findMinimumValue(100000LL, 400500LL),106LL);
    }
}
// END CUT HERE
