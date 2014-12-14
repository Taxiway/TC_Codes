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

class GCDLCMEasy
{
public:
	string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L);
};

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int lcm(int a, int b)
{
	int g = gcd(a, b);
	return a / g * b;
}

string GCDLCMEasy::possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L)
{
	int g[512], l[512];
	for (int i = 0; i < n; ++i) {
		g[i] = 1;
		l[i] = 0;
	}
	for (int i = 0; i < sz(A); ++i) {
		int a = A[i], b = B[i];
		int gg = G[i], ll = L[i];
		g[a] = lcm(g[a], gg);
		g[b] = lcm(g[b], gg);
		l[a] = gcd(l[a], ll);
		l[b] = gcd(l[b], ll);
		if (l[a] % g[a] != 0 || l[b] % g[b] != 0) return "Solution does not exist";
	}
	return "Solution exists";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Your task is to find n positive integers.
We will label them x[0] through x[n-1].



We will give you some information about these integers.
Namely, for some pairs of integers we will tell you both their greatest common divisor (GCD) and their least common multiple (LCM).



You are given the int n and four vector <int>s: A, B, G, and L.
These vector <int>s will all have the same number of elements.
Their meaning is as follows:
For each valid i, the integers x[ A[i] ] and x[ B[i] ] must have the greatest common divisor G[i] and the least common multiple L[i].



Return "Solution exists" (quotes for clarity) if there is at least one way to choose x[0] through x[n-1] so that all requirements are satisfied.
Otherwise, return "Solution does not exist".

DEFINITION
Class:GCDLCMEasy
Method:possible
Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L)


NOTES
-The greatest common divisor (GCD) of two positive integers x and y is the largest positive integer z such that z divides x and at the same time z divides y.
-The least common multiple (LCM) of two positive integers x and y is the smallest positive integer z such that x divides z and at the same time y divides z.
-For example, the GCD of 10 and 15 is 5, and the LCM of 10 and 15 is 30.


CONSTRAINTS
-n will be between 1 and 500, inclusive.
-A will contain between 1 and 500 elements, inclusive.
-A and B will contain the same number of elements.
-A and G will contain the same number of elements.
-A and L will contain the same number of elements.
-Each element in A will be between 0 and n-1, inclusive.
-Each element in B will be between 0 and n-1, inclusive.
-For each i, A[i] and B[i] will be different.
-Each element in G will be between 1 and 10,000, inclusive.
-Each element in L will be between 1 and 10,000, inclusive.


EXAMPLES

0)
4
{0,1,2,3}
{1,2,3,0}
{6,6,6,6}
{12,12,12,12}

Returns: "Solution exists"

We have 4 unknown integers: x[0], x[1], x[2], and x[3].
The given A, B, G, and L encode the following information:

The GCD of x[0] and x[1] must be 6 and their LCM must be 12.
The GCD of x[1] and x[2] must be 6 and their LCM must be 12.
The GCD of x[2] and x[3] must be 6 and their LCM must be 12.
The GCD of x[3] and x[0] must be 6 and their LCM must be 12.

There are two valid solutions.
In one of them, x[0] = x[2] = 6 and x[1] = x[3] = 12.

1)
5
{0,1,2,3,4}
{1,2,3,4,0}
{6,6,6,6,6}
{12,12,12,12,12}

Returns: "Solution does not exist"



2)
2
{0,0}
{1,1}
{123,123}
{456,789}

Returns: "Solution does not exist"

The LCM of x[0] and x[1] cannot be 456 and 789 at the same time.

3)
2
{0}
{1}
{1234}
{5678}

Returns: "Solution does not exist"

The LCM of x[0] and x[1] must always be a multiple of their GCD.

4)
6
{0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4}
{1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5}
{2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7}
{30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105}


Returns: "Solution exists"

There is one solution: {6, 10, 14, 15, 21, 35}.

5)
500
{0}
{1}
{10000}
{10000}

Returns: "Solution exists"



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
        int AARRAY[] = {0,1,2,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,0};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int GARRAY[] = {6,6,6,6};
        vector <int> G( GARRAY, GARRAY+ARRSIZE(GARRAY) );
        int LARRAY[] = {12,12,12,12};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        GCDLCMEasy theObject;
        eq(0, theObject.possible(4, A, B, G, L),"Solution exists");
    }
    {
        int AARRAY[] = {0,1,2,3,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,4,0};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int GARRAY[] = {6,6,6,6,6};
        vector <int> G( GARRAY, GARRAY+ARRSIZE(GARRAY) );
        int LARRAY[] = {12,12,12,12,12};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        GCDLCMEasy theObject;
        eq(1, theObject.possible(5, A, B, G, L),"Solution does not exist");
    }
    {
        int AARRAY[] = {0,0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,1};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int GARRAY[] = {123,123};
        vector <int> G( GARRAY, GARRAY+ARRSIZE(GARRAY) );
        int LARRAY[] = {456,789};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        GCDLCMEasy theObject;
        eq(2, theObject.possible(2, A, B, G, L),"Solution does not exist");
    }
    {
        int AARRAY[] = {0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int GARRAY[] = {1234};
        vector <int> G( GARRAY, GARRAY+ARRSIZE(GARRAY) );
        int LARRAY[] = {5678};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        GCDLCMEasy theObject;
        eq(3, theObject.possible(2, A, B, G, L),"Solution does not exist");
    }
    {
        int AARRAY[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int GARRAY[] = {2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7};
        vector <int> G( GARRAY, GARRAY+ARRSIZE(GARRAY) );
        int LARRAY[] = {30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105}
           ;
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        GCDLCMEasy theObject;
        eq(4, theObject.possible(6, A, B, G, L),"Solution exists");
    }
    {
        int AARRAY[] = {0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int GARRAY[] = {10000};
        vector <int> G( GARRAY, GARRAY+ARRSIZE(GARRAY) );
        int LARRAY[] = {10000};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        GCDLCMEasy theObject;
        eq(5, theObject.possible(500, A, B, G, L),"Solution exists");
    }
}
// END CUT HERE
