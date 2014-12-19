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

class InvariantSets
{
public:
	long long countSets(vector <int> f);
};

long long dp[64];

long long cal(vector<int> &f, int root)
{
    long long ret = 1;
    for (int i = 0; i < sz(f); ++i) {
        if (f[i] == root) {
            ret *= (1 + cal(f, i));
        }
    }
    return dp[root] = ret;
}

long long gao(vector<int> &f, int root)
{
    set<int> st;
    vector<int> v;
    int now = root;
    while (!st.count(now)) {
        v.push_back(now);
        st.insert(now);
        now = f[now];
    }
    for (int i = 0; v[i] != now; ++i) {
        st.erase(st.find(v[i]));
    }
    long long ret = 1;
    for (int i = 0; i < sz(f); ++i) {
        if (!st.count(i) && st.count(f[i])) {
            ret *= (1 + cal(f, i));
        }
    }
    for (set<int>::iterator si = st.begin(); si != st.end(); ++si) {
        dp[*si] = ret;
    }
    return ret;
}

long long InvariantSets::countSets(vector <int> f)
{
    memset(dp, -1, sizeof(dp));
    long long ret = 1;
    for (int i = 0; i < sz(f); ++i) {
        if (dp[i] == -1) {
            ret *= (1 + gao(f, i));
        }
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Janusz is a young physicist.
Recently he has been studying a dynamic system.
There are n elements in the system.
We will label them 0 through n-1.
The set of all elements will be denoted E.

Janusz models the changes in his system using a function that operates on elements of E.
You are given this function as a vector <int> f with n elements, each between 0 and n-1, inclusive.
The vector <int> f describes Janusz's function as follows:
For each valid i, if the function is given the input i, its output will be f[i].

For Janusz, invariant subsets of E have a special significance.
A subset S of the set E is called invariant (with respect to f) if it has the following property: for any x in S, f[x] is also in S.
For example, the entire set E is invariant (for any f).
The empty set is always invariant as well.

Given is the vector <int> f.
Compute and return the number of invariant subsets of E (including E itself and the empty set).

DEFINITION
Class:InvariantSets
Method:countSets
Parameters:vector <int>
Returns:long long
Method signature:long long countSets(vector <int> f)


NOTES
-You may assume that the return value will fit into integer type long long.


CONSTRAINTS
-f will have between 1 and 50 elements, inclusive.
-Each element of f will be between 0 and n-1, inclusive, where n is the number of elements of f.


EXAMPLES

0)
{1,0,0,0}

Returns: 5

The invariant sets are: {}, {0,1}, {0,1,2}, {0,1,3}, {0,1,2,3}.

1)
{1,2,0}

Returns: 2

There are only 2 invariants sets: {} and {0,1,2}.

2)
{0,0,1,2}

Returns: 5

The invariant sets are: {}, {0}, {0,1}, {0,1,2}, {0,1,2,3}.

3)
{0,1,2,3,4,5}

Returns: 64

Every set is invariant when f(x)=x for all x.

4)
{12, 10, 0, 4, 0, 6, 3, 8, 9, 14, 1, 5, 6, 12, 5}

Returns: 90



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
        int fARRAY[] = {1,0,0,0};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        InvariantSets theObject;
        eq(0, theObject.countSets(f),5LL);
    }
    {
        int fARRAY[] = {1,2,0};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        InvariantSets theObject;
        eq(1, theObject.countSets(f),2LL);
    }
    {
        int fARRAY[] = {0,0,1,2};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        InvariantSets theObject;
        eq(2, theObject.countSets(f),5LL);
    }
    {
        int fARRAY[] = {0,1,2,3,4,5};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        InvariantSets theObject;
        eq(3, theObject.countSets(f),64LL);
    }
    {
        int fARRAY[] = {12, 10, 0, 4, 0, 6, 3, 8, 9, 14, 1, 5, 6, 12, 5};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        InvariantSets theObject;
        eq(4, theObject.countSets(f),90LL);
    }
}
// END CUT HERE
