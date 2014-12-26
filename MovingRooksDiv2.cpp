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

class MovingRooksDiv2
{
public:
	string move(vector <int> Y1, vector <int> Y2);
};

string MovingRooksDiv2::move(vector <int> Y1, vector <int> Y2)
{
    for (int i = 0; i < sz(Y2); ++i) {
        int need = Y2[i];
        int ind = i;
        while (Y1[ind] != need) ++ind;
        while (ind != i) {
            int m = 1024, mind = -1;
            for (int j = i; j < ind; ++j) {
                if (Y1[j] > need && Y1[j] < m) {
                    m = Y1[j];
                    mind = j;
                }
            }
            if (mind == -1) {
                return "Impossible";
            }
            swap(Y1[mind], Y1[ind]);
            ind = mind;
        }
    }
    return "Possible";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// This problem is about chessboards with rooks.
A rook is a chess piece that moves arbitrarily far, either horizontally or vertically.
Both rows and columns of chessboards in our problem are numbered starting from 0.

An n times n chessboard is called peaceful if it contains exactly n rooks and no two rooks attack each other.
In other words, there cannot be two rooks in the same row or in the same column of the chessboard.
A peaceful chessboard can be described by a vector <int> Y with n elements: for each row r, the rook in row r is in column Y[r].

You are given two vector <int>s Y1 and Y2 with n elements each.
Each of them represents one peaceful chessboard.

You want to change the first chessboard into the second one.
There is only one type of moves you are allowed to make:
On the first chessboard, you can choose two rooks in positions (r1,c1) and (r2,c2) such that r1 < r2 and c1 > c2, and move them to (r1,c2) and (r2,c1).
Note that the new chessboard is peaceful again.

Return "Possible" (quotes for clarity) if it is possible to change the first chessboard into the second one. Otherwise, return "Impossible".

DEFINITION
Class:MovingRooksDiv2
Method:move
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string move(vector <int> Y1, vector <int> Y2)


CONSTRAINTS
-Y1 will contain between 1 and 8 elements, inclusive.
-Y2 will contain the same number of elements as Y1.
-Each element of Y1 will be between 0 and n-1, inclusive, where n is the number of elements of Y1.
-Each element of Y2 will be between 0 and n-1, inclusive, where n is the number of elements of Y2.
-All elements of Y1 will be distinct.
-All elements of Y2 will be distinct.


EXAMPLES

0)
{0}
{0}

Returns: "Possible"

Both boards are already equal, we don't even have to make any moves.

1)
{1,0}
{0,1}

Returns: "Possible"

Initially, the rooks on the first chessboard are on the cells (0,1) and (1,0).
There is one valid move: moving these two rooks to (0,0) and (1,1).
After this move, the first chessboard is identical to the second one.

2)
{0,1}
{1,0}

Returns: "Impossible"

There are no valid moves so there's no way to reach the goal.

3)
{3,1,2,0}
{0,2,1,3}

Returns: "Possible"



4)
{3,1,2,0}
{3,2,0,1}

Returns: "Impossible"



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
        int Y1ARRAY[] = {0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {0};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(0, theObject.move(Y1, Y2),"Possible");
    }
    {
        int Y1ARRAY[] = {1,0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {0,1};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(1, theObject.move(Y1, Y2),"Possible");
    }
    {
        int Y1ARRAY[] = {0,1};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {1,0};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(2, theObject.move(Y1, Y2),"Impossible");
    }
    {
        int Y1ARRAY[] = {3,1,2,0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {0,2,1,3};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(3, theObject.move(Y1, Y2),"Possible");
    }
    {
        int Y1ARRAY[] = {3,1,2,0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {3,2,0,1};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(4, theObject.move(Y1, Y2),"Impossible");
    }
}
// END CUT HERE
