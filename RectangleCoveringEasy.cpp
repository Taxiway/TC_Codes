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

class RectangleCoveringEasy
{
public:
	int solve(int holeH, int holeW, int boardH, int boardW);
};

int RectangleCoveringEasy::solve(int holeH, int holeW, int boardH, int boardW)
{
    if (holeH <= boardH && holeW <= boardW) {
        if (holeH == boardH && holeW == boardW) return -1;
        return 1;
    }
    if (holeH <= boardW && holeW <= boardH) {
        if (holeH == boardW && holeW == boardH) return -1;
        return 1;
    }
    return -1;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
There is a rectangular hole in the ground.
You are given the dimensions of this rectangle: ints holeH and holeW.



You have a rectangular board.
You are given its dimensions: ints boardH and boardW.
You would like to use the board to cover the hole.



There are some rules you must follow when covering the hole:

You may rotate the board, but you must place it so that the sides of the board are parallel to the sides of the hole.
The board must cover the entire hole.
All corners of the board must be strictly outside the hole. (That is, they are not allowed to lie on the boundary of the hole.)




If you can cover the hole using the board you have, return 1. Otherwise, return -1.


DEFINITION
Class:RectangleCoveringEasy
Method:solve
Parameters:int, int, int, int
Returns:int
Method signature:int solve(int holeH, int holeW, int boardH, int boardW)


CONSTRAINTS
-holeW, holeH, boardW, and boardH will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
1
1
1

Returns: -1

The vertices of the board must not be on the boundary of the hole.

1)
3
5
4
6

Returns: 1

One possibility is to place the board so that it extends over the hole by 0.5 on each side.

2)
10
20
25
15

Returns: 1

Here we have to rotate the board by 90 degrees.

3)
3
10
3
12

Returns: 1



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
        RectangleCoveringEasy theObject;
        eq(0, theObject.solve(1, 1, 1, 1),-1);
    }
    {
        RectangleCoveringEasy theObject;
        eq(1, theObject.solve(3, 5, 4, 6),1);
    }
    {
        RectangleCoveringEasy theObject;
        eq(2, theObject.solve(10, 20, 25, 15),1);
    }
    {
        RectangleCoveringEasy theObject;
        eq(3, theObject.solve(3, 10, 3, 12),1);
    }
}
// END CUT HERE
