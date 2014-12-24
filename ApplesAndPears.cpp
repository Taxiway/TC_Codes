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

class ApplesAndPears
{
public:
	int getArea(vector <string> board, int K);
};

int ee[64][64], aa[64][64], pp[64][64];

bool isoke(int s, int e, int a, int p, int oe, int oa, int op, int k)
{
    int needmove = p + a;
    return (needmove <= k && needmove <= oe);
}

bool isokap(int s, int e, int a, int p, int oe, int oa, int op, int k)
{
    if (e > k) return false;
    if (e > oa) return false;
    k -= e;
    oa -= e;
    oe += e;
    if (p == 0) return true;
    return oe > 0 && oa >= p && 2 * p <= k;
}

int ApplesAndPears::getArea(vector <string> board, int K)
{
    int e = 0, a = 0, p = 0;
    for (int j = 0; j < sz(board[0]); ++j) {
        ee[j][0] = aa[j][0] = pp[j][0] = 0;
        for (int i = 0; i < sz(board); ++i) {
            ee[j][i + 1] = ee[j][i];
            aa[j][i + 1] = aa[j][i];
            pp[j][i + 1] = pp[j][i];
            if (board[i][j] == '.') {
                ++e;
                ++ee[j][i + 1];
            } else if (board[i][j] == 'A') {
                ++a;
                ++aa[j][i + 1];
            } else {
                ++p;
                ++pp[j][i + 1];
            }
        }
    }
    int best = 1;
    for (int r1 = 0; r1 < sz(board); ++r1) {
        for (int r2 = r1; r2 < sz(board); ++r2) {
            for (int c1 = 0; c1 < sz(board[0]); ++c1) {
                int sume = 0, suma = 0, sump = 0;
                for (int c2 = c1; c2 < sz(board[0]); ++c2) {
                    sume += ee[c2][r2 + 1] - ee[c2][r1];
                    suma += aa[c2][r2 + 1] - aa[c2][r1];
                    sump += pp[c2][r2 + 1] - pp[c2][r1];
                    int s = (r2 - r1 + 1) * (c2 - c1 + 1);
                    if (isoke(s, sume, suma, sump, e - sume, a - suma, p - sump, K) ||
                        isokap(s, sume, suma, sump, e - sume, a - suma, p - sump, K) ||
                        isokap(s, sume, sump, suma, e - sume, p - sump, a - suma, K)) {
                        if (s > best) {
                            best = s;
                        }
                    }
                }
            }
        }
    }
    return best;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// A square board is divided into N rows by N columns of unit square cells.
Some cells of the board are empty.
Each of the other cells contains either an apple or a pear.
You are given the current state of the board as a vector <string> board.
In board, the character '.' denotes an empty cell, 'A' denotes an apple, and 'P' denotes a pear.

You are allowed to perform at most K moves.
In each move, you can pick up one fruit (an apple or a pear) and place it onto any empty cell.
(The new cell doesn't have to be adjacent to the old one.)
Note that you cannot remove fruit from the board, you are only allowed to move it onto different cells.

A rectangular section of the board is called uniform if all cells in the rectangle are the same:
that is, either all those cells contain apples, or they all contain pears, or all of them are empty.
After you are done moving the fruit, you want to have a uniform rectangle that is as large as possible somewhere on the board.
Return the largest possible area of such a rectangle.

DEFINITION
Class:ApplesAndPears
Method:getArea
Parameters:vector <string>, int
Returns:int
Method signature:int getArea(vector <string> board, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-board will contain exactly N elements.
-Each element of board will contain exactly N characters.
-Each character in board will be '.', 'A', or 'P'.
-K will be between 0 and 1000, inclusive.


EXAMPLES

0)
{".A",
 "P."}
0

Returns: 1

As K=0, you are not allowed to make any moves.
Currently, the largest uniform rectangle is just a single cell.

1)
{".A",
 "P."}
1

Returns: 2

Move any piece of fruit onto any of the two currently empty cells.
After the move, there will be two adjacent empty cells.
These form a 2x1 uniform rectangle.

2)
{".PP", 
 "PPA", 
 "PAP"}
3

Returns: 6

In three moves, you can create a 3x2 rectangle of cells that contain pears.

3)
{"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}
10

Returns: 21



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
        string boardARRAY[] = {".A",
            "P."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(0, theObject.getArea(board, 0),1);
    }
    {
        string boardARRAY[] = {".A",
            "P."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(1, theObject.getArea(board, 1),2);
    }
    {
        string boardARRAY[] = {".PP", 
            "PPA", 
            "PAP"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(2, theObject.getArea(board, 3),6);
    }
    {
        string boardARRAY[] = {"A.P.PAAPPA",
            "PPP..P.PPP",
            "AAP.A.PAPA",
            "P.PA.AAA.A",
            "...PA.P.PA",
            "P..A.A.P..",
            "PAAP..A.A.",
            "PAAPPA.APA",
            ".P.AP.P.AA",
            "..APAPAA.."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(3, theObject.getArea(board, 10),21);
    }
}
// END CUT HERE
