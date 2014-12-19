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

class NegativeGraphDiv2
{
public:
	long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges);
};

long long dp[64][1024];
bool isok[64][1024];
vector<pair<int, int> > vp[64];
long long ret;

long long NegativeGraphDiv2::findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges)
{
    memset(isok, false, sizeof(isok));
    for (int i = 0; i < N; ++i) {
        vp[i].clear();
    }
    for (int i = 0; i < sz(s); ++i) {
        int f = s[i] - 1, to = t[i] - 1;
        vp[f].push_back(make_pair(to, weight[i]));
    }
    ret = 1LL << 60;
    dp[0][charges] = 0;
    isok[0][charges] = true;
    for (int c = charges; c >= 0; --c) {
        set<pair<long long, int> > st;
        for (int i = 0; i < N; ++i) {
            if (isok[i][c]) {
                st.insert(make_pair(dp[i][c], i));
            }
        }
        while (!st.empty()) {
            int now = st.begin()->second;
            long long d = st.begin()->first;
            st.erase(st.begin());
            if (now == N - 1) {
                ret = min(ret, d);
            }
            for (int i = 0; i < sz(vp[now]); ++i) {
                int next = vp[now][i].first;
                int len = vp[now][i].second;
                long long nextd = d + len;
                if (!isok[next][c]) {
                    isok[next][c] = true;
                    dp[next][c] = nextd;
                    st.insert(make_pair(dp[next][c], next));
                } else if (dp[next][c] > nextd) {
                    st.erase(st.find(make_pair(dp[next][c], next)));
                    dp[next][c] = nextd;
                    st.insert(make_pair(dp[next][c], next));
                }
                
                if (c) {
                    nextd = d - len;
                    if (!isok[next][c - 1] || dp[next][c - 1] > nextd) {
                        isok[next][c - 1] = true;
                        dp[next][c - 1] = nextd;
                    }
                }
            }
        }
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Nancy has a directed graph with N vertices and E edges.
The vertices are numbered 1 through N.
Each edge of the graph has a positive integer weight.
This graph is described by three vector <int>s with E elements each: s, t, and weight.
For each valid i, the graph contains an edge from s[i] to t[i], and its weight is weight[i].
Note that Nancy's graph may contain multiple edges with the same start and end.
It may also contain self-loops.



Nancy is currently standing in the vertex 1.
She can reach other vertices by moving along the edges.
The cost of using an edge is equal to its weight.
Nancy's goal is to reach the vertex N and to minimize the total cost of doing so.



Nancy has a special power she can use to make her travels cheaper.
Whenever she traverses an edge, she can use that special power to make the weight of that edge temporarily negative.
You are given an int charges: the number of times Nancy can use her special power.
Each use of the special power only works for one traversal of an edge.
Nancy can traverse each edge arbitrarily many times.
Each time she traverses an edge, she may use her special power, if she still has some charges left.



Compute and return the minimal total cost of Nancy's journey.


DEFINITION
Class:NegativeGraphDiv2
Method:findMin
Parameters:int, vector <int>, vector <int>, vector <int>, int
Returns:long long
Method signature:long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-E will be between 1 and 2500, inclusive.
-s, t, weight will each contain exactly E elements.
-s and t will only contain numbers between 1 and N, inclusive.
-There will be a path from node 1 to node N.
-weight will contain numbers between 0 and 100,000, inclusive. 
-charges will be between 0 and 1,000, inclusive.


EXAMPLES

0)
3
{1,1,2,2,3,3}
{2,3,1,3,1,2}
{1,5,1,10,1,1}
1

Returns: -9

The optimal path for Nancy is 1->2->3, and using her single charge on the last edge.

1)
1
{1}
{1}
{100}
1000

Returns: -100000

The graph may contain self-loops. Here, the optimal solution is that Nancy uses the self-loop 1,000 times, each time using her special power to change its cost from 100 to -100.

2)
2
{1,1,2}
{2,2,1}
{6,1,4}
2

Returns: -9

There can be multiple edges between vertices.

3)
2
{1}
{2}
{98765}
100

Returns: -98765

Nancy may not be able to use all her charges.

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
        int sARRAY[] = {1,1,2,2,3,3};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int tARRAY[] = {2,3,1,3,1,2};
        vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
        int weightARRAY[] = {1,5,1,10,1,1};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        NegativeGraphDiv2 theObject;
        eq(0, theObject.findMin(3, s, t, weight, 1),-9LL);
    }
    {
        int sARRAY[] = {1};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int tARRAY[] = {1};
        vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
        int weightARRAY[] = {100};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        NegativeGraphDiv2 theObject;
        eq(1, theObject.findMin(1, s, t, weight, 1000),-100000LL);
    }
    {
        int sARRAY[] = {1,1,2};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int tARRAY[] = {2,2,1};
        vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
        int weightARRAY[] = {6,1,4};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        NegativeGraphDiv2 theObject;
        eq(2, theObject.findMin(2, s, t, weight, 2),-9LL);
    }
    {
        int sARRAY[] = {1};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int tARRAY[] = {2};
        vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
        int weightARRAY[] = {98765};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        NegativeGraphDiv2 theObject;
        eq(3, theObject.findMin(2, s, t, weight, 100),-98765LL);
    }
}
// END CUT HERE
