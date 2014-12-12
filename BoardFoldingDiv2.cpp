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

class BoardFoldingDiv2
{
public:
	int howMany(vector <string> paper);
};

vector<string> trans(vector <string> paper)
{
	vector<string> ret;
	for (int i = 0; i < sz(paper[0]); ++i) {
		string s;
		for (int j = 0; j < sz(paper); ++j) {
			s += paper[j][i];
		}
		ret.push_back(s);
	}
	return ret;
}

int gao(vector<string> paper)
{
	bool dp[50][50];
	memset(dp, false, sizeof(dp));
	int n = sz(paper);
	dp[0][n - 1] = true;
	bool isok[50][50];
	memset(isok, false, sizeof(isok));
	for (int d = 0; d + 1 < n; ++d) {
		int x = d, y = d + 1;
		int r = 1;
		while (x >= 0 && y < n && paper[x] == paper[y]) {
			isok[d][r] = true;
			++r;
			--x;
			++y;
		}
	}
	int ret = 0;
	for (int len = n; len >= 1; --len) {
		for (int i = 0; i + len <= n; ++i) {
			if (dp[i][i + len - 1]) {
				++ret;
				for (int d = i; d < i + len - 1; ++d) {
					int up = d - i + 1;
					int down = i + len - 1 - d;
					if (isok[d][min(up, down)]) {
						if (up <= down) {
							dp[d + 1][i + len - 1] = true;
						}
						if (up >= down) {
							dp[i][d] = true;
						}
					}
				}
			}
		}
	}
	return ret;
}

int BoardFoldingDiv2::howMany(vector <string> paper)
{
	return gao(paper) * gao(trans(paper));
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Little Petya likes puzzles a lot.
Recently he has received one as a gift from his mother.
The puzzle has the form of a rectangular sheet of paper that is divided into N rows by M columns of unit square cells.
Rows are numbered 0 through N-1 from top to bottom, and columns 0 through M-1 from left to right.
Each cell is colored either black or white.
You are given a description of the paper, the exact format is specified at the end of this problem statement.


The goal of the puzzle is to fold the paper.
This has to be done in a sequence of turns.
In each turn, Petya has to fold the paper according to the rules below.
He can end the process after any number of turns (including zero), even if there are still valid ways to fold the paper.


In each turn, Petya must follow these steps:
To start folding, he must choose a line that is parallel to one of the sides of the paper and passes between two rows/columns of cells.
He can then take the smaller part of the paper and fold it on top of the larger part.
(If the line divides the current paper in half, he can fold either half on top of the other.)
There is one additional restriction:
Petya may only perform the fold if all cells of the part that is being folded land on equally-colored cells of the part that remains in place.


For example, consider the following paper (with 0 and 1 representing white and black):

10010101
11110100
00000000
01101110



Here, Petya could choose the vertical line that goes between the two leftmost columns and the rest of the paper.
Note that this is a valid choice: as he makes the fold, the cells from the leftmost two columns will all match their counterparts in the right part of the
paper.
This is how the paper looks like after the fold (with periods representing empty spaces):

..010101
..110100
..000000
..101110



Clearly, even after multiple folds the paper will always look like a subrectangle of the original paper.
Two states of the game are considered the same if that rectangle has the same dimensions and the same offset with respect to the original top left corner of
the paper.
(Note that folding order does not matter. Two different sequences of folding may produce the same final state.)


You are given a description of the original state of the paper as a vector <string> paper. Here N is the number of elements in paper and M is the length of its each element. For each i and j, the character paper[i][j] is either '0' (meaning that the cell (i,j) is white) or '1' (the cell is black).
Compute and return the number of possible final states of the game.

DEFINITION
Class:BoardFoldingDiv2
Method:howMany
Parameters:vector <string>
Returns:int
Method signature:int howMany(vector <string> paper)


CONSTRAINTS
-paper will contain between 1 and 50 elements, inclusive.
-Each element of paper will contain between 1 and 50 elements, inclusive.
-All elements of paper will have the same length.
-paper will contain only characters '0' and '1'.


EXAMPLES

0)
{"10",
 "11"}

Returns: 1

There is no valid way to fold this paper, so there is just one possible outcome.

1)
{"1111111",
 "1111111"}

Returns: 84

We can fold it into any of the 84 possible subrectangles of the original rectangle.

2)
{"0110",
 "1001",
 "1001",
 "0110"}

Returns: 9



3)
{"0",
 "0",
 "0",
 "1",
 "0",
 "0"}

Returns: 6



4)
{"000",
 "010",
 "000"}

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
        string paperARRAY[] = {"10",
            "11"};
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        BoardFoldingDiv2 theObject;
        eq(0, theObject.howMany(paper),1);
    }
    {
        string paperARRAY[] = {"1111111",
            "1111111"};
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        BoardFoldingDiv2 theObject;
        eq(1, theObject.howMany(paper),84);
    }
    {
        string paperARRAY[] = {"0110",
            "1001",
            "1001",
            "0110"};
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        BoardFoldingDiv2 theObject;
        eq(2, theObject.howMany(paper),9);
    }
    {
        string paperARRAY[] = {"0",
            "0",
            "0",
            "1",
            "0",
            "0"};
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        BoardFoldingDiv2 theObject;
        eq(3, theObject.howMany(paper),6);
    }
    {
        string paperARRAY[] = {"000",
            "010",
            "000"};
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        BoardFoldingDiv2 theObject;
        eq(4, theObject.howMany(paper),1);
    }
}
// END CUT HERE
