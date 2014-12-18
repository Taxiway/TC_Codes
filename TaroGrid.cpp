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

class TaroGrid
{
public:
	int getNumber(vector <string> grid);
};

int TaroGrid::getNumber(vector <string> grid)
{
    int ret = 0;
    for (int i = 0; i < sz(grid[0]); ++i) {
        int ct = 0;
        char last = 'a';
        for (int j = 0; j < sz(grid); ++j) {
            if (grid[j][i] == last) ++ct;
            else ct = 1;
            last = grid[j][i];
            ret = max(ret, ct);
        }
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Cat Taro has a square grid with N rows and N columns.
Each cell of the grid is painted either black or white.
You are given a vector <string> grid which represents the current state of the grid.
Each element of grid represents one row of the grid.
In grid, the character 'W' represents a white cell, and the character 'B' represents a black cell. 




Taro wants to choose a set of consecutive cells that are in the same column and are painted in the same color.
Return the largest number of cells he can choose.


DEFINITION
Class:TaroGrid
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> grid)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-grid will contain exactly N elements.
-Each element of grid will contain exactly N characters.
-Each character in grid will be 'W' or 'B'.


EXAMPLES

0)
{"W"}

Returns: 1



1)
{"WB",
 "BW"}

Returns: 1



2)
{"BWW",
 "BBB",
 "BWB"}

Returns: 3

He can choose the entire leftmost column (i.e., character 0 of each element of grid).

3)
{"BWBW",
 "BBWB",
 "WWWB",
 "BWWW"}

Returns: 3



4)
{"BWB",
 "BBW",
 "BWB"}

Returns: 3



5)
{"BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB",
 "BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB"}

Returns: 2

Note that the chosen cells must be consecutive.

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
        string gridARRAY[] = {"W"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TaroGrid theObject;
        eq(0, theObject.getNumber(grid),1);
    }
    {
        string gridARRAY[] = {"WB",
            "BW"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TaroGrid theObject;
        eq(1, theObject.getNumber(grid),1);
    }
    {
        string gridARRAY[] = {"BWW",
            "BBB",
            "BWB"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TaroGrid theObject;
        eq(2, theObject.getNumber(grid),3);
    }
    {
        string gridARRAY[] = {"BWBW",
            "BBWB",
            "WWWB",
            "BWWW"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TaroGrid theObject;
        eq(3, theObject.getNumber(grid),3);
    }
    {
        string gridARRAY[] = {"BWB",
            "BBW",
            "BWB"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TaroGrid theObject;
        eq(4, theObject.getNumber(grid),3);
    }
    {
        string gridARRAY[] = {"BBWWBBWW",
            "BBWWBBWW",
            "WWBBWWBB",
            "WWBBWWBB",
            "BBWWBBWW",
            "BBWWBBWW",
            "WWBBWWBB",
            "WWBBWWBB"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TaroGrid theObject;
        eq(5, theObject.getNumber(grid),2);
    }
}
// END CUT HERE
