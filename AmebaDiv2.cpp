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

class AmebaDiv2
{
public:
	int simulate(vector <int> X, int A);
};

int AmebaDiv2::simulate(vector <int> X, int A)
{
    for (int i = 0; i < sz(X); ++i) if (X[i] == A) A += A;
    return A;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Monte-Carlo is an amoeba. Amoebas can feed on gel: whenever an amoeba encounters a piece of gel that is exactly as big as the amoeba, the amoeba will consume the gel and thus double its size.

Initially, the size of Monte-Carlo was A. During its lifetime, Monte-Carlo encountered several gels and consumed the ones it could.

You are given a vector <int> X and the int A. The elements of X are the sizes of gels Monte-Carlo encountered, in chronological order. Compute and return the final size of Monte-Carlo.

DEFINITION
Class:AmebaDiv2
Method:simulate
Parameters:vector <int>, int
Returns:int
Method signature:int simulate(vector <int> X, int A)


CONSTRAINTS
-X will contain between 1 and 200 integers, inclusive.
-Each element of X will be between 1 and 1,000,000,000, inclusive.
-A will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2,1,3,1,2}
1

Returns: 4


Gel #0 is bigger than Monte-Carlo, nothing happens.
Monte-Carlo consumes gel #1. Its size is now 1+1 = 2.
Gel #2 is bigger than Monte-Carlo, nothing happens.
Gel #3 is smaller than Monte-Carlo, nothing happens.
Monte-Carlo consumes gel #4. Its size is now 2+2 = 4.


1)
{1,4,9,16,25,36,49}
10

Returns: 10

The size of Monte-Carlo doesn't change.

2)
{1,2,4,8,16,32,64,128,256,1024,2048}
1

Returns: 512



3)
{817,832,817,832,126,817,63,63,126,817,832,287,823,817,574}
63

Returns: 252



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
        int XARRAY[] = {2,1,3,1,2};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(0, theObject.simulate(X, 1),4);
    }
    {
        int XARRAY[] = {1,4,9,16,25,36,49};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(1, theObject.simulate(X, 10),10);
    }
    {
        int XARRAY[] = {1,2,4,8,16,32,64,128,256,1024,2048};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(2, theObject.simulate(X, 1),512);
    }
    {
        int XARRAY[] = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(3, theObject.simulate(X, 63),252);
    }
}
// END CUT HERE
