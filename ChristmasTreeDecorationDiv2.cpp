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

class ChristmasTreeDecorationDiv2
{
public:
	int solve(vector <int> col, vector <int> x, vector <int> y);
};

int ChristmasTreeDecorationDiv2::solve(vector <int> col, vector <int> x, vector <int> y)
{
	int ret = 0;
	for (int i = 0; i < sz(x); ++i) {
		if (col[x[i] - 1] != col[y[i] - 1]) ++ret;
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Christmas is just around the corner, and Alice just decorated her Christmas tree.
There are N stars and N-1 ribbons on the tree.
Each ribbon connects two of the stars in such a way that all stars and ribbons hold together.
(In other words, the stars and ribbons are the vertices and edges of a tree.)



The stars are numbered 1 through N.
Additionally, each star has some color.
You are given the colors of stars as a vector <int> col with N elements.
For each i, col[i] is the color of star i+1.
(Different integers represent different colors.)



You are also given a description of the ribbons: two vector <int>s x and y with N-1 elements each.
For each i, there is a ribbon that connects the stars with numbers x[i] and y[i].



According to Alice, a ribbon that connects two stars with different colors is beautiful, while a ribbon that connects two same-colored stars is not.
Compute and return the number of beautiful ribbons in Alice's tree.


DEFINITION
Class:ChristmasTreeDecorationDiv2
Method:solve
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int solve(vector <int> col, vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-The number of elements in col will be exactly N.
-The number of elements in x will be exactly N - 1.
-The number of elements in y will be the same as the number of elements in x.
-All elements of x and y will be between 1 and N, inclusive.
-For each i, the numbers x[i] and y[i] will be different.
-The graph formed by the N-1 ribbons will be connected.


EXAMPLES

0)
{1,2,3,3}
{1,2,3}
{2,3,4}

Returns: 2

There are two beautiful ribbons: the one that connects stars 1 and 2, and the one that connects stars 2 and 3.
The other ribbon is not beautiful because stars 3 and 4 have the same color.

1)
{1,3,5}
{1,3}
{2,2}

Returns: 2



2)
{1,1,3,3}
{1,3,2}
{2,1,4}

Returns: 2



3)
{5,5,5,5}
{1,2,3}
{2,3,4}

Returns: 0



4)
{9,1,1}
{3,2}
{2,1}

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
        int colARRAY[] = {1,2,3,3};
        vector <int> col( colARRAY, colARRAY+ARRSIZE(colARRAY) );
        int xARRAY[] = {1,2,3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2,3,4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        ChristmasTreeDecorationDiv2 theObject;
        eq(0, theObject.solve(col, x, y),2);
    }
    {
        int colARRAY[] = {1,3,5};
        vector <int> col( colARRAY, colARRAY+ARRSIZE(colARRAY) );
        int xARRAY[] = {1,3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2,2};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        ChristmasTreeDecorationDiv2 theObject;
        eq(1, theObject.solve(col, x, y),2);
    }
    {
        int colARRAY[] = {1,1,3,3};
        vector <int> col( colARRAY, colARRAY+ARRSIZE(colARRAY) );
        int xARRAY[] = {1,3,2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2,1,4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        ChristmasTreeDecorationDiv2 theObject;
        eq(2, theObject.solve(col, x, y),2);
    }
    {
        int colARRAY[] = {5,5,5,5};
        vector <int> col( colARRAY, colARRAY+ARRSIZE(colARRAY) );
        int xARRAY[] = {1,2,3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2,3,4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        ChristmasTreeDecorationDiv2 theObject;
        eq(3, theObject.solve(col, x, y),0);
    }
    {
        int colARRAY[] = {9,1,1};
        vector <int> col( colARRAY, colARRAY+ARRSIZE(colARRAY) );
        int xARRAY[] = {3,2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        ChristmasTreeDecorationDiv2 theObject;
        eq(4, theObject.solve(col, x, y),1);
    }
}
// END CUT HERE
