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

class IncrementingSequence
{
public:
	string canItBeDone(int k, vector <int> A);
};

string IncrementingSequence::canItBeDone(int k, vector <int> A)
{
    vector<int> v[10];
    vector<int> w[10];
    for (int i = 0; i < sz(A); ++i) {
        v[A[i] % k].push_back(A[i]);
        w[(i + 1) % k].push_back(i + 1);
    }
    for (int i = 0; i < k; ++i) {
        sort(all(v[i]));
        sort(all(w[i]));
        if (sz(v[i]) != sz(w[i])) return "IMPOSSIBLE";
        for (int j = 0; j < sz(v[i]); ++j) {
            if (v[i][j] > w[i][j]) return "IMPOSSIBLE";
        }
    }
    return "POSSIBLE";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You have a vector <int> A with N elements.

Your goal is to change it into a vector <int> that contains each number from 1 to N exactly once. The change will consist of zero or more steps. In each step, you may pick an arbitrary element of A and increment its value by k. You may pick the same element multiple times. Note that you are not allowed to decrement the value of any element.

You are given the int k and the vector <int> A.
Return "POSSIBLE" if it is possible to achieve your goal. Return "IMPOSSIBLE" otherwise.

DEFINITION
Class:IncrementingSequence
Method:canItBeDone
Parameters:int, vector <int>
Returns:string
Method signature:string canItBeDone(int k, vector <int> A)


NOTES
-Return value is case-sensitive. For example, you can't return "Possible" or "possible" instead of "POSSIBLE".


CONSTRAINTS
-k will be between 1 and 10, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-Each element of A will be between 1 and 50, inclusive.


EXAMPLES

0)
3
{1,2,4,3}

Returns: "POSSIBLE"

This sequence of length 4 already contains all numbers from 1 to 4 exactly once. Note that their order does not matter.

1)
5
{2,2}

Returns: "IMPOSSIBLE"



2)
1
{1,1,1,1,1,1,1,1}

Returns: "POSSIBLE"

There are many ways to achieve the goal. For example, it is possible to obtain the sequence {1,2,3,4,5,6,7,8}. To do this, just increment the element at each position one by one until it reaches the required value.

3)
2
{5,3,3,2,1}

Returns: "IMPOSSIBLE"

We want to have the values {1,2,3,4,5}, in any order. Currently, we are missing the 4. As k=2, the only way to produce a 4 is by incrementing a 2. But if we increment our only 2, we will have no way of producing another 2.

4)
9
{1,2,3,1,4,5,6,7,9,8}

Returns: "POSSIBLE"



5)
2
{1,1,1,1,1,1,2,2,2,2,2,2}

Returns: "POSSIBLE"



6)
1
{1}

Returns: "POSSIBLE"



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
        int AARRAY[] = {1,2,4,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        IncrementingSequence theObject;
        eq(0, theObject.canItBeDone(3, A),"POSSIBLE");
    }
    {
        int AARRAY[] = {2,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        IncrementingSequence theObject;
        eq(1, theObject.canItBeDone(5, A),"IMPOSSIBLE");
    }
    {
        int AARRAY[] = {1,1,1,1,1,1,1,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        IncrementingSequence theObject;
        eq(2, theObject.canItBeDone(1, A),"POSSIBLE");
    }
    {
        int AARRAY[] = {5,3,3,2,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        IncrementingSequence theObject;
        eq(3, theObject.canItBeDone(2, A),"IMPOSSIBLE");
    }
    {
        int AARRAY[] = {1,2,3,1,4,5,6,7,9,8};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        IncrementingSequence theObject;
        eq(4, theObject.canItBeDone(9, A),"POSSIBLE");
    }
    {
        int AARRAY[] = {1,1,1,1,1,1,2,2,2,2,2,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        IncrementingSequence theObject;
        eq(5, theObject.canItBeDone(2, A),"POSSIBLE");
    }
    {
        int AARRAY[] = {1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        IncrementingSequence theObject;
        eq(6, theObject.canItBeDone(1, A),"POSSIBLE");
    }
}
// END CUT HERE
