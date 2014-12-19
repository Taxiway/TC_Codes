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

class BishopMove
{
public:
	int howManyMoves(int r1, int c1, int r2, int c2);
};

int BishopMove::howManyMoves(int r1, int c1, int r2, int c2)
{
    if (r1 == r2 && c1 == c2) return 0;
    if ((abs(r1 - r2 + c1 - c2) & 1)) return -1;
    int  dx = abs(r1 - r2), dy = abs(c1 - c2);
    return dx == dy ? 1 : 2;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Janusz is learning how to play chess.
He is using the standard chessboard with 8 rows and 8 columns.
Both the rows and the columns are numbered 0 through 7.
Thus, we can describe each cell using its two coordinates: (row, column).

Janusz recently learned about one of the chess pieces: the bishop.
The bishop is a piece that moves diagonally by an arbitrary number of cells.
Formally, if a bishop is currently on the cell (r,c) of an empty chessboard,
the set of all cells reachable in a single move contains the following cells:

All cells of the form (r+k,c+k), where k is a positive integer.
All cells of the form (r+k,c-k), where k is a positive integer.
All cells of the form (r-k,c+k), where k is a positive integer.
All cells of the form (r-k,c-k), where k is a positive integer.

(Of course, the bishop's destination must always be a valid cell on the chessboard.)

Janusz took an empty chessboard and he placed a single bishop onto the cell (r1,c1).
He now wants to move it to the cell (r2,c2) using as few moves as possible.

You are given the ints r1, c1, r2, and c2.
Compute and return the smallest number of moves a bishop needs to get from (r1,c1) to (r2,c2).
If it is impossible for a bishop to reach the target cell, return -1 instead.

DEFINITION
Class:BishopMove
Method:howManyMoves
Parameters:int, int, int, int
Returns:int
Method signature:int howManyMoves(int r1, int c1, int r2, int c2)


CONSTRAINTS
-r1,c1,r2,c2 will be between 0 and 7, inclusive.


EXAMPLES

0)
4
6
7
3

Returns: 1

The bishop can go from (4,6) to (7,3) in a single move.

1)
2
5
2
5

Returns: 0

The bishop is already where it should be, no moves are necessary.

2)
1
3
5
5

Returns: 2

In the first move Janusz can move the bishop to the cell (4,6).
Please note that this is the largest possible return value: whenever there is a solution, there is a solution that uses at most two moves.

3)
4
6
7
4

Returns: -1

If the bishop starts at (4,6), it can never reach (7,4).

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
        BishopMove theObject;
        eq(0, theObject.howManyMoves(4, 6, 7, 3),1);
    }
    {
        BishopMove theObject;
        eq(1, theObject.howManyMoves(2, 5, 2, 5),0);
    }
    {
        BishopMove theObject;
        eq(2, theObject.howManyMoves(1, 3, 5, 5),2);
    }
    {
        BishopMove theObject;
        eq(3, theObject.howManyMoves(4, 6, 7, 4),-1);
    }
}
// END CUT HERE
