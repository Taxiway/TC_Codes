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

class GoodSubset
{
public:
	int numberOfSubsets(int goodValue, vector <int> d);
};

int MOD = 1000000007;
long long p[110];
long long C[110][110];
map<pair<int, int>, long long> mem;
vector<pair<int, int> > v;

long long dfs(int ind, long long need)
{
	if (ind == v.size()) {
		if (need == 1) return 1;
		else return 0;
	}
	if (mem.count(make_pair(ind, need))) {
		return mem[make_pair(ind, need)];
	}
	long long now = v[ind].first, ct = v[ind].second;
	long long ret = 0;
	long long c = 1;
	for (long long i = 0; i <= ct; ++i) {
		if (need % c == 0) {
			ret += C[ct][i] * dfs(ind + 1, need / c);
			ret %= MOD;
		}
		c *= now;
		if (need % c != 0) break;
	}
	
	return mem[make_pair(ind, need)] = ret % MOD;
}

int GoodSubset::numberOfSubsets(int goodValue, vector <int> d)
{
	mem.clear();
	p[0] = 1;
	for (int i = 1; i <= 100; ++i) {
		p[i] = (p[i - 1] << 1) % MOD;
	}
	C[0][0] = 1;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) C[i][j] = 1;
			else {
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
			}
		}
	}
	map<int, int> mp;
	for (int i = 0; i < sz(d); ++i) {
		mp[d[i]]++;
	}
	v.clear();
	int ones = mp[1];
	if (goodValue == 1) {
		return (p[ones] - 1 + MOD) % MOD;
	}
	mp.erase(mp.find(1));
	for (map<int, int>::iterator mi = mp.begin(); mi != mp.end(); ++mi) {
		if (goodValue % mi->first == 0) {
			v.push_back(make_pair(mi->first, mi->second));
		}
	}
	return (dfs(0, goodValue) * p[ones]) % MOD;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
You have some cards, each containing a positive integer.
You are given a vector <int> d.
Each element of d is one of those integers.
The integers are not necessarily distinct.



You are also given an int goodValue.
You are interested in non-empty subsets of cards with the following property:
The product of integers written on those cards is exactly equal to goodValue.



Let X be the number of subsets with the above property.
Compute and return the value (X modulo 1,000,000,007).


DEFINITION
Class:GoodSubset
Method:numberOfSubsets
Parameters:int, vector <int>
Returns:int
Method signature:int numberOfSubsets(int goodValue, vector <int> d)


CONSTRAINTS
-goodValue will be between 1 and 2,000,000,000, inclusive.
-d will contain between 1 and 100 elements, inclusive.
-Each element of d will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
10
{2,3,4,5}

Returns: 1

There is only one good subset:{2,5}.

1)
6
{2,3,4,5,6}

Returns: 2

There are two good subsets: {2,3} and {6}.

2)
1
{1,1,1}

Returns: 7

All non-empty subsets of this set of cards are good.

3)
12
{1,2,3,4,5,6,7,8,9,10,11,12}

Returns: 6



4)
5
{1,2,3,4}

Returns: 0



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
        int dARRAY[] = {2,3,4,5};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        GoodSubset theObject;
        eq(0, theObject.numberOfSubsets(10, d),1);
    }
    {
        int dARRAY[] = {2,3,4,5,6};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        GoodSubset theObject;
        eq(1, theObject.numberOfSubsets(6, d),2);
    }
    {
        int dARRAY[] = {1,1,1};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        GoodSubset theObject;
        eq(2, theObject.numberOfSubsets(1, d),7);
    }
    {
        int dARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        GoodSubset theObject;
        eq(3, theObject.numberOfSubsets(12, d),6);
    }
    {
        int dARRAY[] = {1,2,3,4};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        GoodSubset theObject;
        eq(4, theObject.numberOfSubsets(5, d),0);
    }
	{
		int dARRAY[] = {65536, 1, 8, 2048, 4096, 4096, 256, 524288, 2, 1024, 4194304, 134217728, 67108864, 2097152, 32, 1024, 1, 512, 524288, 512, 4194304, 4194304, 8192, 16777216, 2, 32, 16384, 32, 16777216, 2048, 524288, 131072, 8192, 64, 524288, 67108864, 2048, 32768, 32, 262144, 2, 16, 4096, 33554432, 1, 1073741824, 268435456, 512, 1048576, 134217728, 262144, 256, 1048576, 4194304, 1073741824, 134217728, 8, 262144, 268435456, 128, 268435456, 1073741824, 512, 268435456, 32, 1048576, 128, 67108864, 4, 64, 64, 8388608, 4194304, 512, 524288, 8192, 2, 128, 16777216, 512, 4194304, 16, 1048576, 32768, 1073741824, 512, 33554432, 16777216, 536870912, 67108864, 268435456, 512, 1073741824, 32, 4, 4194304, 131072, 2048, 1024, 8192};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		GoodSubset theObject;
		eq(5, theObject.numberOfSubsets(1073741824, d),0);
	}
}
// END CUT HERE
