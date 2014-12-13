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

class NarrowPassage2Easy
{
public:
	int count(vector <int> size, int maxSizeSum);
};

int NarrowPassage2Easy::count(vector <int> size, int maxSizeSum)
{
	set<vector<int> > st;
	vector<int> v;
	int n = sz(size);
	for (int i = 0; i < n; ++i) {
		v.push_back(i);
	}
	st.insert(v);
	queue<vector<int> > q;
	q.push(v);
	while (!q.empty()) {
		vector<int> order = q.front();
		q.pop();
		for (int i = 0; i < n - 1; ++i) {
			int i1 = order[i], i2 = order[i + 1];
			if (size[i1] + size[i2] <= maxSizeSum) {
				vector<int> next = order;
				next[i] = order[i + 1];
				next[i + 1] = order[i];
				if (!st.count(next)) {
					st.insert(next);
					q.push(next);
				}
			}
		}
	}
	return st.size();
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// There is a narrow passage.
Inside the passage there are some wolves.
You are given a vector <int> size that contains the sizes of those wolves, from left to right.



The passage is so narrow that some pairs of wolves cannot pass by each other.
More precisely, two adjacent wolves may swap places if and only if the sum of their sizes is maxSizeSum or less.
Assuming that no wolves leave the passage, what is the number of different permutations of wolves in the passage?
Note that two wolves are considered different even if they have the same size.



Compute and return the number of permutations of wolves that can be obtained from their initial order by swapping a pair of wolves zero or more times.

DEFINITION
Class:NarrowPassage2Easy
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> size, int maxSizeSum)


CONSTRAINTS
-size will contain between 1 and 6 elements, inclusive.
-Each element in size will be between 1 and 1,000, inclusive.
-maxSizeSum will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1, 2, 3}
3

Returns: 2

From {1, 2, 3}, you can swap 1 and 2 to get {2, 1, 3}. But you can't get other permutations.

1)
{1, 2, 3}
1000

Returns: 6

Here you can swap any two adjacent wolves. Thus, all 3! = 6 permutations are possible.

2)
{1, 2, 3}
4

Returns: 3

You can get {1, 2, 3}, {2, 1, 3} and {2, 3, 1}.

3)
{1,1,1,1,1,1}
2

Returns: 720

All of these wolves are different, even though their sizes are the same. Thus, there are 6! different permutations possible.

4)
{2,4,6,1,3,5}
8

Returns: 60



5)
{1000}
1000

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
        int sizeARRAY[] = {1, 2, 3};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2Easy theObject;
        eq(0, theObject.count(size, 3),2);
    }
    {
        int sizeARRAY[] = {1, 2, 3};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2Easy theObject;
        eq(1, theObject.count(size, 1000),6);
    }
    {
        int sizeARRAY[] = {1, 2, 3};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2Easy theObject;
        eq(2, theObject.count(size, 4),3);
    }
    {
        int sizeARRAY[] = {1,1,1,1,1,1};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2Easy theObject;
        eq(3, theObject.count(size, 2),720);
    }
    {
        int sizeARRAY[] = {2,4,6,1,3,5};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2Easy theObject;
        eq(4, theObject.count(size, 8),60);
    }
    {
        int sizeARRAY[] = {1000};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2Easy theObject;
        eq(5, theObject.count(size, 1000),1);
    }
}
// END CUT HERE
