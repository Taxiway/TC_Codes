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

class PotentialGeometricSequence
{
public:
	int numberOfSubsequences(vector <int> d);
};

int check(vector<int> v)
{
	for (int i = 2; i < sz(v); ++i) {
		if (v[i] - v[i - 1] != v[i - 1] - v[i - 2]) return 0;
	}
	return 1;
}

int PotentialGeometricSequence::numberOfSubsequences(vector <int> d)
{
	int ret = 0;
	for (int i = 0; i < sz(d); ++i) {
		for (int j = i; j < sz(d); ++j) {
			vector<int> v;
			for (int k = i; k <= j; ++k) v.push_back(d[k]);
			ret += check(v);
		}
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
We have a sequence of N positive integers: a[0] through a[N-1].
You do not know these integers.
All you know is the number of trailing zeros in their binary representations.
You are given a vector <int> d with N elements.
For each i, d[i] is the number of trailing zeros in the binary representation of a[i].



For example, suppose that a[0]=40.
In binary, 40 is 101000 which ends in three zeros.
Therefore, d[0] will be 3.



You like geometric sequences.
(See the Notes section for a definition of a geometric sequence.)
You would like to count all non-empty contiguous subsequences of the sequence a[0], a[1], ..., a[N-1] that can be geometric sequences (given the information you have in d).



More precisely:
For each pair (i,j) such that 0 <= i <= j <= N-1, we ask the following question: "Given the values d[i] through d[j], is it possible that the values a[i] through a[j] form a geometric sequence?"



For example, suppose that d = {0,1,2,3,2}.
For i=0 and j=3 the answer is positive: it is possible that the values a[0] through a[3] are {1,2,4,8} which is a geometric sequence.
For i=1 and j=4 the answer is negative: there is no geometric sequence with these numbers of trailing zeros in binary.



Compute and return the number of contiguous subsequences of a[0], a[1], ..., a[N-1] that can be geometric sequences.


DEFINITION
Class:PotentialGeometricSequence
Method:numberOfSubsequences
Parameters:vector <int>
Returns:int
Method signature:int numberOfSubsequences(vector <int> d)


NOTES
-A geometric sequence is any sequence g[0], g[1], ..., g[k-1] such that there is a real number q (the quotient) with the property that for each valid i, g[i+1] = g[i]*q. For example, {1,2,4,8} is a geometric sequence with q=2, {7,7,7} is a geometric sequence with q=1, and {18,6,2} is a geometric sequence with q=1/3.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-d will contain exactly N elements.
-Each element of d will be between 0 and 100, inclusive.


EXAMPLES

0)
{0,1,2}

Returns: 6

One possibility is that a[0]=3, a[1]=6, and a[2]=12. In this case, all contiguous subsequences of this sequence are geometric.

1)
{1,2,4}

Returns: 5

All one-element and two-element subsequences are geometric. The entire sequence cannot be geometric.

2)
{3,2,1,0}

Returns: 10



3)
{1,2,4,8,16}

Returns: 9



4)
{1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}

Returns: 37



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
        int dARRAY[] = {0,1,2};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialGeometricSequence theObject;
        eq(0, theObject.numberOfSubsequences(d),6);
    }
    {
        int dARRAY[] = {1,2,4};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialGeometricSequence theObject;
        eq(1, theObject.numberOfSubsequences(d),5);
    }
    {
        int dARRAY[] = {3,2,1,0};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialGeometricSequence theObject;
        eq(2, theObject.numberOfSubsequences(d),10);
    }
    {
        int dARRAY[] = {1,2,4,8,16};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialGeometricSequence theObject;
        eq(3, theObject.numberOfSubsequences(d),9);
    }
    {
        int dARRAY[] = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialGeometricSequence theObject;
        eq(4, theObject.numberOfSubsequences(d),37);
    }
}
// END CUT HERE
