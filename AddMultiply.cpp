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

class AddMultiply
{
public:
	vector <int> makeExpression(int y);
};

vector <int> AddMultiply::makeExpression(int y)
{
    vector<int> v;
    for (int i = -1000; i <= 1000; ++i) {
        for (int j = -1000; j <= 1000; ++j) {
            int z = y - i * j;
            if (-1000 <= z && z <= 1000) {
                v.push_back(i);
                v.push_back(j);
                v.push_back(z);
                return v;
            }
        }
    }
    return v;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You are given an int y.
We are looking for any vector <int> x that satisfies the following constraints:

x has exactly three elements
( x[0] * x[1] ) + x[2] = y
Each x[i] must be between -1000 and 1000, inclusive.
No x[i] can be equal to 0 or 1.

Find and return one such x.

If there are multiple valid solutions, you may return any of them.
You may assume that for our constraints on y (specified below) at least one valid x always exists.

DEFINITION
Class:AddMultiply
Method:makeExpression
Parameters:int
Returns:vector <int>
Method signature:vector <int> makeExpression(int y)


CONSTRAINTS
-y will be between 0 and 500, inclusive.


EXAMPLES

0)
6

Returns: {2, 2, 2 }

2*2 + 2 = 6

Note that this is one of many possible solutions. Another solution is:

3*3 + (-3) = 6


1)
11

Returns: {2, 3, 5 }



2)
0

Returns: {7, 10, -70 }

Note that 0 and 1 are not allowed, thus a result like 0 * 0 + 0 would be incorrect.

3)
500

Returns: {-400, -3, -700 }

Some or all of the returned numbers may be negative.

4)
2

Returns: {2, 2, -2 }



5)
5

Returns: {5, 2, -5 }



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
        int retrunValueARRAY[] = {2, 2, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AddMultiply theObject;
        eq(0, theObject.makeExpression(6),retrunValue);
    }
    {
        int retrunValueARRAY[] = {2, 3, 5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AddMultiply theObject;
        eq(1, theObject.makeExpression(11),retrunValue);
    }
    {
        int retrunValueARRAY[] = {7, 10, -70 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AddMultiply theObject;
        eq(2, theObject.makeExpression(0),retrunValue);
    }
    {
        int retrunValueARRAY[] = {-400, -3, -700 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AddMultiply theObject;
        eq(3, theObject.makeExpression(500),retrunValue);
    }
    {
        int retrunValueARRAY[] = {2, 2, -2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AddMultiply theObject;
        eq(4, theObject.makeExpression(2),retrunValue);
    }
    {
        int retrunValueARRAY[] = {5, 2, -5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AddMultiply theObject;
        eq(5, theObject.makeExpression(5),retrunValue);
    }
}
// END CUT HERE
