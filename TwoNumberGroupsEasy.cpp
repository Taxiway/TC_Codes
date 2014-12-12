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

class TwoNumberGroupsEasy
{
public:
	int solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB);
};

int getres(vector <int> &A, vector <int> &numA, vector <int> &B, vector <int> &numB)
{
	map<int, int> mp;
	for (int i = 0; i < sz(A); ++i) {
		mp[A[i]] += numA[i];
	}
	for (int i = 0; i < sz(B); ++i) {
		mp[B[i]] -= numB[i];
	}
	int ret = 0;
	for (map<int, int>::iterator mi = mp.begin(); mi != mp.end(); ++mi) {
		if (mi->second > 0) {
			ret += mi->second;
		} else {
			ret -= mi->second;
		}
	}
	return ret;
}

int TwoNumberGroupsEasy::solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB)
{
	vector<int> v = A;
	v.insert(v.end(), B.begin(), B.end());
	int best = getres(A, numA, B, numB);
	vector<int> AA = A, BB = B;
	set<int> cand;
	for (int i = 0; i < sz(v); ++i) {
		for (int j = i + 1; j < sz(v); ++j) {
			int diff = v[i] - v[j];
			if (diff < 0) diff = -diff;
			if (diff <= 1) {
				continue;
			}
			cand.insert(diff);
			for (int i = 2; i * i <= diff; ++i) {
				if (diff % i == 0) {
					cand.insert(i);
					cand.insert(diff / i);
				}
			}
		}
	}
	for (set<int>::iterator si = cand.begin(); si != cand.end(); ++si) {
		for (int i = 0; i < sz(A); ++i) {
			AA[i] = A[i] % (*si);
		}
		for (int i = 0; i < sz(B); ++i) {
			BB[i] = B[i] % (*si);
		}
		best = min(best, getres(AA, numA, BB, numB));
	}
	return best;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
A multiset is the same thing as a set, with the difference that a multiset can contain multiple copies of the same element.
For example, {1,1,1,2,3} is a multiset that contains three 1s, one 2, and one 3.



The distance between two multisets is the smallest total number of elements we need to erase from them in order to make them equal.
For example, the distance between {1,1,2,2,3} and {1,2,2,4} is 3.
Note that we can compute distance as follows:
For each value, we count its occurrences in the first multiset, we count its occurrences in the second multiset, and we write down the difference between those two counts.
The distance is then equal to the sum of all values we wrote down.



If S is a multiset, then (S modulo M) is the multiset of all values (x modulo M) where x belongs to S.
For example, if S = {11,12,13,21,22} and M = 10, then (S modulo M) = {1,2,3,1,2} = {1,1,2,2,3}.



You have two multisets called A and B.
The first multiset is described by the vector <int>s A and numA.
For each valid i, the multiset contains numA[i] copies of the value A[i].
The second multiset is described by the vector <int>s B and numB in the same way.



We are now looking for a positive integer M with the following properties:
M must be greater than 1, and the distance between (A modulo M) and (B modulo M) must be as small as possible.
Compute and return the smallest possible distance.


DEFINITION
Class:TwoNumberGroupsEasy
Method:solve
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB)


CONSTRAINTS
-A and B will each contain between 1 and 10 elements, inclusive.
-All elements of A will be distinct.
-All elements of B will be distinct.
-The number of elements in numA will be the same as the number of elements in A.
-The number of elements in numB will be the same as the number of elements in B.
-All elements of A and B will be between 1 and 1,000,000,000, inclusive.
-All elements of numA and numB will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{1,2,3,4}
{2,1,1,1}
{5,6,7,8}
{1,1,1,2}

Returns: 2

This input describes the multisets A = {1,1,2,3,4} and B = {5,6,7,8,8}.
For M=2, we have (A modulo M) = {0,0,1,1,1} and (B modulo M) = {0,0,0,1,1}.
The distance between these two multisets is 2, and that is the best we can get.

1)
{5,7}
{1,1}
{12,14}
{1,1}

Returns: 0

The optimal solution is obtained for M = 7.

2)
{100}
{2}
{1}
{1}

Returns: 1



3)
{1}
{1}
{1}
{1}

Returns: 0



4)
{5}
{1}
{6}
{1}

Returns: 2



5)
{733815053,566264976,984867861,989991438,407773802,701974785,599158121,713333928,530987873,702824160}
{8941,4607,1967,2401,495,7654,7078,4213,5485,1026}
{878175560,125398919,556001255,570171347,643069772,787443662,166157535,480000834,754757229,101000799}
{242,6538,7921,2658,1595,3049,655,6945,7350,6915}

Returns: 7



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
        int AARRAY[] = {1,2,3,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int numAARRAY[] = {2,1,1,1};
        vector <int> numA( numAARRAY, numAARRAY+ARRSIZE(numAARRAY) );
        int BARRAY[] = {5,6,7,8};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int numBARRAY[] = {1,1,1,2};
        vector <int> numB( numBARRAY, numBARRAY+ARRSIZE(numBARRAY) );
        TwoNumberGroupsEasy theObject;
        eq(0, theObject.solve(A, numA, B, numB),2);
    }
    {
        int AARRAY[] = {5,7};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int numAARRAY[] = {1,1};
        vector <int> numA( numAARRAY, numAARRAY+ARRSIZE(numAARRAY) );
        int BARRAY[] = {12,14};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int numBARRAY[] = {1,1};
        vector <int> numB( numBARRAY, numBARRAY+ARRSIZE(numBARRAY) );
        TwoNumberGroupsEasy theObject;
        eq(1, theObject.solve(A, numA, B, numB),0);
    }
    {
        int AARRAY[] = {100};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int numAARRAY[] = {2};
        vector <int> numA( numAARRAY, numAARRAY+ARRSIZE(numAARRAY) );
        int BARRAY[] = {1};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int numBARRAY[] = {1};
        vector <int> numB( numBARRAY, numBARRAY+ARRSIZE(numBARRAY) );
        TwoNumberGroupsEasy theObject;
        eq(2, theObject.solve(A, numA, B, numB),1);
    }
    {
        int AARRAY[] = {1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int numAARRAY[] = {1};
        vector <int> numA( numAARRAY, numAARRAY+ARRSIZE(numAARRAY) );
        int BARRAY[] = {1};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int numBARRAY[] = {1};
        vector <int> numB( numBARRAY, numBARRAY+ARRSIZE(numBARRAY) );
        TwoNumberGroupsEasy theObject;
        eq(3, theObject.solve(A, numA, B, numB),0);
    }
    {
        int AARRAY[] = {5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int numAARRAY[] = {1};
        vector <int> numA( numAARRAY, numAARRAY+ARRSIZE(numAARRAY) );
        int BARRAY[] = {6};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int numBARRAY[] = {1};
        vector <int> numB( numBARRAY, numBARRAY+ARRSIZE(numBARRAY) );
        TwoNumberGroupsEasy theObject;
        eq(4, theObject.solve(A, numA, B, numB),2);
    }
    {
        int AARRAY[] = {733815053,566264976,984867861,989991438,407773802,701974785,599158121,713333928,530987873,702824160};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int numAARRAY[] = {8941,4607,1967,2401,495,7654,7078,4213,5485,1026};
        vector <int> numA( numAARRAY, numAARRAY+ARRSIZE(numAARRAY) );
        int BARRAY[] = {878175560,125398919,556001255,570171347,643069772,787443662,166157535,480000834,754757229,101000799};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int numBARRAY[] = {242,6538,7921,2658,1595,3049,655,6945,7350,6915};
        vector <int> numB( numBARRAY, numBARRAY+ARRSIZE(numBARRAY) );
        TwoNumberGroupsEasy theObject;
        eq(5, theObject.solve(A, numA, B, numB),7);
    }
}
// END CUT HERE
