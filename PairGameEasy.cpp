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

class PairGameEasy
{
public:
	string able(int a, int b, int c, int d);
};


string PairGameEasy::able(int a, int b, int c, int d)
{
    while (!(a == c && b == d)) {
        if (c < a || d < b) return "Not able to generate";
        if (c <= d) d -= c;
        else c -= d;
    }
    return "Able to generate";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You have an ordered pair of integers.
You can now make zero or more steps.
In each step, you can change your pair into a new pair of integers by adding one of them to the other.
That is, if your current pair is (x, y), then your next pair will be either (x+y, y), or (x, x+y).



For example, you can start with (1, 2), change it to (3, 2), change that to (3, 5), and then change that again to (3, 8).



You are given four ints: a, b, c, and d.
Return "Able to generate" (quotes for clarity) if it is possible to start with the pair (a, b) and end with the pair (c, d).
Otherwise, return "Not able to generate".

DEFINITION
Class:PairGameEasy
Method:able
Parameters:int, int, int, int
Returns:string
Method signature:string able(int a, int b, int c, int d)


CONSTRAINTS
-a will be between 1 and 1,000, inclusive.
-b will be between 1 and 1,000, inclusive.
-c will be between 1 and 1,000, inclusive.
-d will be between 1 and 1,000, inclusive.


EXAMPLES

0)
1
2
3
5

Returns: "Able to generate"

(1, 2) -> (3, 2) -> (3, 5).

1)
1
2
2
1

Returns: "Not able to generate"

Note that order matters: (1, 2) and (2, 1) are two different pairs.

2)
2
2
2
999

Returns: "Not able to generate"



3)
2
2
2
1000

Returns: "Able to generate"



4)
47
58
384
221

Returns: "Able to generate"



5)
1000
1000
1000
1000

Returns: "Able to generate"



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
        PairGameEasy theObject;
        eq(0, theObject.able(1, 2, 3, 5),"Able to generate");
    }
    {
        PairGameEasy theObject;
        eq(1, theObject.able(1, 2, 2, 1),"Not able to generate");
    }
    {
        PairGameEasy theObject;
        eq(2, theObject.able(2, 2, 2, 999),"Not able to generate");
    }
    {
        PairGameEasy theObject;
        eq(3, theObject.able(2, 2, 2, 1000),"Able to generate");
    }
    {
        PairGameEasy theObject;
        eq(4, theObject.able(47, 58, 384, 221),"Able to generate");
    }
    {
        PairGameEasy theObject;
        eq(5, theObject.able(1000, 1000, 1000, 1000),"Able to generate");
    }
}
// END CUT HERE
