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

class LongLongTripDiv2
{
public:
	string isAble(long long D, int T, int B);
};

string LongLongTripDiv2::isAble(long long D, int T, int B)
{
	if (D < T) return "Impossible";
    if (D == T) return "Possible";
    long long t = T, b = B;
    if (t * b < D) return "Impossible";
    long long down = 0, up = t;
    while (down + 1 < up) {
        long long mid = (down + up) >> 1;
        if (mid * b + (t - mid) >= D) {
            up = mid;
        } else {
            down = mid;
        }
    }
    return up * b + (t - up) == D ? "Possible" : "Impossible";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Limit is a flea. He can do two types of jumps: small jumps that have length 1 millimeter, and big jumps that have length B millimeters.

Limit is going to make exactly T jumps, all of them in the same direction. He would like to travel exactly D millimeters in those jumps. Is this possible?

You are given a long long D, and ints T and B. Return "Possible" (quotes for clarity) if there is a combination of T jumps forward that has a total length of exactly D millimeters. Otherwise, return "Impossible".

DEFINITION
Class:LongLongTripDiv2
Method:isAble
Parameters:long long, int, int
Returns:string
Method signature:string isAble(long long D, int T, int B)


CONSTRAINTS
-D will be between 1 and 10^18, inclusive.
-T will be between 1 and 1,000,000,000, inclusive.
-B will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
10
6
3

Returns: "Possible"

Limit must make 6 jumps that have a total length of 10 millimeters. This is possible: two of the jumps must be long and the other four must be short.

1)
10
5
3

Returns: "Impossible"



2)
50
100
2

Returns: "Impossible"



3)
120
10
11

Returns: "Impossible"



4)
10
10
9999

Returns: "Possible"



5)
1000
100
10

Returns: "Possible"



6)
1000010000100001
1100011
1000000000

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
        LongLongTripDiv2 theObject;
        eq(0, theObject.isAble(10L, 6, 3),"Possible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(1, theObject.isAble(10L, 5, 3),"Impossible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(2, theObject.isAble(50L, 100, 2),"Impossible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(3, theObject.isAble(120L, 10, 11),"Impossible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(4, theObject.isAble(10L, 10, 9999),"Possible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(5, theObject.isAble(1000L, 100, 10),"Possible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(6, theObject.isAble(1000010000100001L, 1100011, 1000000000),"Possible");
    }
}
// END CUT HERE
