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

class Egalitarianism3Easy
{
public:
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len);
};

vector<pair<int, int> > edge[15];
int dis[15][15];

void gao(int root)
{
    bool ved[15];
    memset(ved, false, sizeof(ved));
    queue<pair<int, int> > q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        int now = q.front().first, d = q.front().second;
        q.pop();
        dis[root][now] = d;
        for (int i = 0; i < sz(edge[now]); ++i) {
            int next = edge[now][i].first, nextd = edge[now][i].second;
            if (!ved[next]) {
                ved[next] = true;
                q.push(make_pair(next, d + nextd));
            }
        }
    }
}

int Egalitarianism3Easy::maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
{
    for (int i = 0; i < n; ++i) edge[i].clear();
    for (int i = 0; i < sz(a); ++i) {
        int x = a[i] - 1, y = b[i] - 1;
        edge[x].push_back(make_pair(y, len[i]));
        edge[y].push_back(make_pair(x, len[i]));
    }
    for (int i = 0; i < n; ++i) {
        gao(i);
    }
    int ret = 1;
    for (int i = 1; i < (1 << n); ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) v.push_back(j);
        }
        set<int> st;
        for (int x = 0; x < sz(v); ++x) {
            for (int y = x + 1; y < sz(v); ++y) {
                st.insert(dis[v[x]][v[y]]);
            }
        }
        if (st.size() <= 1) {
            ret = max(ret, sz(v));
        }
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// In Treeland there are n cities, numbered 1 through n.
The cities are linked by n-1 bidirectional roads.
Each road connects a pair of cities.
The roads are built in such a way that each city is reachable from each other city by roads.
(In other words, the topology of the road network is a tree.)


You are given the int n and three vector <int>s that describe the road network: a, b, and len.
For each i between 0 and n-2, inclusive, there is a road of length len[i] that connects the cities a[i] and b[i].


The distance between two cities is the sum of lengths of roads on the sequence of roads that connects them. (Note that this sequence of roads is always unique.)


You want to select k cities in such a way that all pairwise distances between the selected cities are the same.
In other words, there must be a distance d such that the distance between every two selected cities is d.
Return the largest possible value of k for which this is possible.

DEFINITION
Class:Egalitarianism3Easy
Method:maxCities
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)


CONSTRAINTS
-n will be between 1 and 10, inclusive.
-a will contain exactly n-1 elements.
-b will contain exactly n-1 elements.
-len will contain exactly n-1 elements.
-Each element in a will be between 1 and n, inclusive.
-Each element in b will be between 1 and n, inclusive.
-Each element in len will be between 1 and 1,000, inclusive.
-The graph described by a and b will be a tree.


EXAMPLES

0)
4
{1,1,1}
{2,3,4}
{1,1,1}

Returns: 3

There are 4 cities and 3 roads, each of length 1.
The roads connect the following pairs of cities: (1,2), (1,3), and (1,4).
The optimal answer is k=3.
We can select three cities in the required way: we select the cities {2, 3, 4}.
The distance between any two of these cities is 2.

1)
6
{1,2,3,2,3}
{2,3,4,5,6}
{2,1,3,2,3}

Returns: 3

Again, the largest possible k is 3.
There are two ways to select three equidistant cities: {1, 4, 6} and {4, 5, 6}.
(In both cases the common distance is 6.)

2)
10
{1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10}
{1000,1000,1000,1000,1000,1000,1000,1000,1000}

Returns: 9



3)
2
{1}
{2}
{3}

Returns: 2



4)
1
{}
{}
{}

Returns: 1

Note that n can be 1.

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
        int aARRAY[] = {1,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {1,1,1};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(0, theObject.maxCities(4, a, b, len),3);
    }
    {
        int aARRAY[] = {1,2,3,2,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4,5,6};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {2,1,3,2,3};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(1, theObject.maxCities(6, a, b, len),3);
    }
    {
        int aARRAY[] = {1,1,1,1,1,1,1,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4,5,6,7,8,9,10};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(2, theObject.maxCities(10, a, b, len),9);
    }
    {
        int aARRAY[] = {1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        int lenARRAY[] = {3};
        vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
        Egalitarianism3Easy theObject;
        eq(3, theObject.maxCities(2, a, b, len),2);
    }
    {
        Egalitarianism3Easy theObject;
        eq(4, theObject.maxCities(1, vector <int>(), vector <int>(), vector <int>()),1);
    }
}
// END CUT HERE
