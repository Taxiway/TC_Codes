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

class TwoLLogo
{
public:
	long long countWays(vector <string> grid);
};

int ver[32][32];
int hor[32][32];

long long gao(int a, int b)
{
    return (a - 1) * (b - 1);
}

long long gao(int r1, int c1, int r2, int c2)
{
    if (r1 == r2) {
        // same row
        if (c1 + hor[r1][c1] > c2) {
            // connect
            return gao(ver[c1][r1], c2 - c1) * gao(ver[c2][r2], hor[r2][c2]);
        } else {
            return gao(ver[c1][r1], hor[r1][c1]) * gao(ver[c2][r2], hor[r2][c2]);
        }
    } else if (c1 == c2) {
        // same col
        if (r2 - ver[c2][r2] < r1) {
            // connect
            return gao(ver[c1][r1], hor[r1][c1]) * gao(r2 - r1, hor[r2][c2]);
        } else {
            return gao(ver[c1][r1], hor[r1][c1]) * gao(ver[c2][r2], hor[r2][c2]);
        }
    } else if (c2 < c1) {
        // ..1
        // ...
        // .2.
        // no trouble
        return gao(ver[c1][r1], hor[r1][c1]) * gao(ver[c2][r2], hor[r2][c2]);
    } else {
        // 1..
        // ...
        // .2.
        if (c1 + hor[r1][c1] > c2 && r2 - ver[c2][r2] < r1) {
            // trouble
            long long sum = 0;
            
            // both limit
            sum += gao(ver[c1][r1], c2 - c1) * gao(r2 - r1, hor[r2][c2]);
            // 1 over
            sum += gao(ver[c1][r1], hor[r1][c2] + 1) * gao(r2 - r1, hor[r2][c2]);
            // 2 over
            sum += gao(ver[c1][r1], c2 - c1) * gao(ver[c2][r1] + 1, hor[r2][c2]);
            return sum;
        } else {
            return gao(ver[c1][r1], hor[r1][c1]) * gao(ver[c2][r2], hor[r2][c2]);
        }
    }
}

long long TwoLLogo::countWays(vector <string> grid)
{
    int n = sz(grid), m = sz(grid[0]);
    for (int col = 0; col < m; ++col) {
        int s = 0;
        for (int row = 0; row < n; ++row) {
            if (grid[row][col] == '.') {
                ver[col][row] = s + 1;
            } else {
                ver[col][row] = 0;
            }
            s = ver[col][row];
        }
    }
    for (int row = 0; row < n; ++row) {
        int s = 0;
        for (int col = m - 1; col >= 0; --col) {
            if (grid[row][col] == '.') {
                hor[row][col] = s + 1;
            } else {
                hor[row][col] = 0;
            }
            s = hor[row][col];
        }
    }
    long long ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                for (int ni = i; ni < n; ++ni) {
                    for (int nj = 0; nj < m; ++nj) {
                        if (ni == i && nj <= j) continue;
                        if (grid[ni][nj] == '.') {
                            ret += gao(i, j, ni, nj);
                        }
                    }
                }
            }
        }
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Please note that this problem has a non-standard time limit: 3 seconds.

A yet unknown "LL Company" wants to design a logo. After a long discussion, company designers decided that the logo should consist of two letters L drawn in some way.

To start with something, designers drew N rows of M points each, one under another, so that these points form a rectangular grid. They also painted each point either white or black. Here is an example of what they could get for N = 4 and M = 5:



Designers agreed to draw each letter L as a union of a horizontal and a vertical line segment intersecting at their left and bottom ends, respectively. The segments must have positive lengths, and their endpoints must be white grid points. All grid points that lie on the segments must be white as well. For example, here are two valid placements of a letter:

 


Note that neither the letters nor the grid can be rotated.

The final requirement is that the two letters should be disjoint. That is, no white point should lie on two segments belonging to different letters.

You are given the grid with N rows and M columns, encoded as a vector <string> grid with N elements, each containing M characters. Each character is either '.' or '#', meaning that the corresponding point is either white or black, respectively.

Return the number of different possible logos with two L's drawn on them according to the requirements. Two logos are considered different if there is a pair of points that is connected by a line segment in exactly one of the logos.


DEFINITION
Class:TwoLLogo
Method:countWays
Parameters:vector <string>
Returns:long long
Method signature:long long countWays(vector <string> grid)


CONSTRAINTS
-grid will contain between 2 and 30 elements, inclusive.
-All elements of grid will contain the same number of characters.
-Each element of grid will contain between 2 and 30 characters, inclusive.
-Each character of grid will be either '.' or '#'.


EXAMPLES

0)
{"....",
 "...."}

Returns: 1





1)
{".##..",
 "...#.",
 ".#.#.",
 "#...#"}

Returns: 3

This is the example from the problem statement. The three possible logos look as follows:

 
 



2)
{"..#.",
 "#.#.",
 "....",
 "..#."}

Returns: 4


 
 
 



3)
{"..",
 ".."}

Returns: 0

Too small for a logo.

4)
{".#.#",
 "....",
 ".#.#",
 "...."}

Returns: 34



5)
{"##############",
 "##############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"}

Returns: 1350

Corners of L's are identified uniquely in this case, but line segment lengths can vary.

6)
{"#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."}

Returns: 2386



7)
{"...#..........................",
 "..............................",
 "..............................",
 "..................#...#.......",
 "..................#...........",
 "..............................",
 "...........#..................",
 "..............................",
 ".....#..#.....................",
 ".......................#......",
 "..................#.....#.....",
 "..............................",
 "..............................",
 "..............................",
 "..............................",
 "..#...........................",
 "..............................",
 "..............................",
 "..............................",
 "#............................#",
 "..............................",
 ".....#.........#............#.",
 "..............................",
 ".........................#....",
 ".#............................",
 ".............#................",
 "..............................",
 "..............................",
 ".......................#......",
 ".............#................"}

Returns: 5020791386



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
        string gridARRAY[] = {"....",
            "...."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(0, theObject.countWays(grid),1LL);
    }
    {
        string gridARRAY[] = {".##..",
            "...#.",
            ".#.#.",
            "#...#"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(1, theObject.countWays(grid),3LL);
    }
    {
        string gridARRAY[] = {"..#.",
            "#.#.",
            "....",
            "..#."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(2, theObject.countWays(grid),4LL);
    }
    {
        string gridARRAY[] = {"..",
            ".."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(3, theObject.countWays(grid),0LL);
    }
    {
        string gridARRAY[] = {".#.#",
            "....",
            ".#.#",
            "...."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(4, theObject.countWays(grid),34LL);
    }
    {
        string gridARRAY[] = {"##############",
            "##############",
            "#.############",
            "#.############",
            "#.############",
            "#.############",
            "#.############",
            "#.############",
            "#.#####.######",
            "#.#####.######",
            "#.#####.######",
            "#....##.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######......#",
            "##############"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(5, theObject.countWays(grid),1350LL);
    }
    {
        string gridARRAY[] = {"#......",
            ".#....#",
            ".#.#...",
            "#....#.",
            ".##..#.",
            ".#.....",
            ".....#.",
            ".#.#...",
            ".#...#.",
            "..##..."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(6, theObject.countWays(grid),2386LL);
    }
    {
        string gridARRAY[] = {"...#..........................",
            "..............................",
            "..............................",
            "..................#...#.......",
            "..................#...........",
            "..............................",
            "...........#..................",
            "..............................",
            ".....#..#.....................",
            ".......................#......",
            "..................#.....#.....",
            "..............................",
            "..............................",
            "..............................",
            "..............................",
            "..#...........................",
            "..............................",
            "..............................",
            "..............................",
            "#............................#",
            "..............................",
            ".....#.........#............#.",
            "..............................",
            ".........................#....",
            ".#............................",
            ".............#................",
            "..............................",
            "..............................",
            ".......................#......",
            ".............#................"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(7, theObject.countWays(grid),5020791386LL);
    }
}
// END CUT HERE
