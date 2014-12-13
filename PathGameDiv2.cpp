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

class PathGameDiv2
{
public:
	int calc(vector <string> board);
};

int PathGameDiv2::calc(vector <string> board)
{
	int ret = 0;
	int last = 0;
	int ct = 0;
	for (int i = 0; i < sz(board[0]); ++i) {
		if (board[0][i] == '.' && board[1][i] == '.') {
			++ct;
		} else if (board[0][i] == '.' && board[1][i] == '#') {
			if (last == 0 || last == 1) {
				ret += ct;
			} else {
				ret += (ct - 1);
			}
			last = 1;
			ct = 0;
		} else if (board[0][i] == '#' && board[1][i] == '.') {
			if (last == 0 || last == 2) {
				ret += ct;
			} else {
				ret += (ct - 1);
			}
			last = 2;
			ct = 0;
		}
	}
	ret += ct;
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Cat Snuke is playing the Path Game.

The Path Game is played on a rectangular grid of square cells.
The grid has 2 rows and some positive number of columns.
Each cell is either black or white.

A left-to-right path in the grid is a sequence of white cells such that the first cell in the sequence is in the leftmost column, the last cell in the sequence is in the rightmost column, and each pair of consecutive cells shares a common side.

The initial coloring of the grid is such that there is at least one left-to-right path.
You are given this initial coloring as a vector <string> board with two elements.
For each i and j, board[i][j] is either '#' (representing a black cell) or '.' (representing a white cell).

Snuke may color some of the white cells black.
After he does so, there must still be at least one left-to-right path left on the board.
The goal of the game is to color as many cells black as possible.
Compute and return the largest number of cells Snuke can color black.
(Note that the cells that are already black do not count.)

DEFINITION
Class:PathGameDiv2
Method:calc
Parameters:vector <string>
Returns:int
Method signature:int calc(vector <string> board)


CONSTRAINTS
-board will contain 2 elements.
-Each element in board will contain between 1 and 50 characters, inclusive.
-All elements in board will have the same length.
-Each character in board will be '#' or '.'.
-The grid described by board will contain a left-to-right path.


EXAMPLES

0)
{"#...."
,"...#."}

Returns: 2

Snuke can color at most two white cells black.
One possible final state of the board looks as follows:

#....
..###


1)
{"#"
,"."}

Returns: 0

Snuke can't color any cells.

2)
{"."
,"."}

Returns: 1



3)
{"....#.##.....#..........."
,"..#......#.......#..#...."}

Returns: 13



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
        string boardARRAY[] = {"#...."
           ,"...#."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        PathGameDiv2 theObject;
        eq(0, theObject.calc(board),2);
    }
    {
        string boardARRAY[] = {"#"
           ,"."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        PathGameDiv2 theObject;
        eq(1, theObject.calc(board),0);
    }
    {
        string boardARRAY[] = {"."
           ,"."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        PathGameDiv2 theObject;
        eq(2, theObject.calc(board),1);
    }
    {
        string boardARRAY[] = {"....#.##.....#..........."
           ,"..#......#.......#..#...."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        PathGameDiv2 theObject;
        eq(3, theObject.calc(board),13);
    }
}
// END CUT HERE
