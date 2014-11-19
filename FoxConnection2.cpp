// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are N cities in Treeland.
The cities are numbered 1 through N.
The roads in Treeland have the topology of a tree.
That is, there are exactly N-1 bidirectional roads in Treeland, each connecting a pair of cities, and it is possible to travel between any two cities along the roads.

You are given two vector <int>s A and B that describe the tree.
Each of these vector <int>s has N-1 elements.
For each valid i, there is a road that connects the cities A[i] and B[i].

Currently, k foxes live in a forest in Treeland.
They would like to move into cities.
Each fox must live in a different city.
Therefore, they must select exactly k different cities where they will live.
Additionally, they have an important constraint:
The set of cities inhabited by the foxes must be connected.
That is, for any two different cities i and j that both contain a fox, all the cities on the (only) path between i and j must also contain a fox.

Let X be the number of ways in which we can choose k cities in Treeland in such a way that the constraint is satisfied.
Return the value (X modulo 1,000,000,007).
Two selections are different if and only if there is a city selected in one of them but not in the other.
(Note that we are only selecting a set of cities, we are not assigning individual foxes to the cities.)

DEFINITION
Class:FoxConnection2
Method:ways
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int ways(vector <int> A, vector <int> B, int k)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-A will contain exactly N-1 elements.
-Each element of A will be between 1 and N, inclusive.
-B will contain exactly N-1 elements.
-Each element of B will be between 1 and N, inclusive.
-The graph described by A and B will be a tree.
-k will be between 1 and N, inclusive.


EXAMPLES

0)
{1,2,3}
{2,3,4}
2

Returns: 3

Treeland looks as follows: 1-2-3-4.
There are 3 ways to put 2 foxes: {1,2}, {2,3} or {3,4}.

1)
{1,1,1,1}
{2,3,4,5}
3

Returns: 6

There are 6 ways: {1,2,3}, {1,2,4}, {1,2,5}, {1,3,4}, {1,3,5} and {1,4,5}.

2)
{1,2,3,4}
{2,3,4,5}
3

Returns: 3



3)
{1,2,2,4,4}
{2,3,4,5,6}
3

Returns: 6



4)
{1,2,2,4,4}
{2,3,4,5,6}
5

Returns: 4



5)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40}
20

Returns: 923263934



6)
{2}
{1}
1

Returns: 2



*/
// END CUT HERE

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector> 

using namespace std;

#define sz(a) int((a).size())
#define all(X) (X).begin(), (X).end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll; 

// BEGIN CUT HERE

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

const int MAXN = 64;

int n;
int father[MAXN];
vector<int> childs[MAXN];
bool ved[MAXN];
int dp[MAXN][MAXN];
int k;
int mod = 1000000007;

void getdp(int root)
{
    for (int i = 0; i < childs[root].size(); ++i) {
        int n = childs[root][i];
        getdp(n);
    }

    dp[root][0] = 1;
    int temp[MAXN];
    memset(temp, 0, sizeof(temp));
    temp[0] = 1;
    for (int i = 0; i < childs[root].size(); ++i) {
        int next = childs[root][i];
        for (int need = k; need >= 0; --need) {
            long long sum = 0;
            for (int choose = need; choose >= 0; --choose) {
                sum += (long long)dp[next][choose] * temp[need - choose];
                sum %= mod;
            }
            temp[need] = (int)sum;
        }
    }
    for (int i = 1; i <= k; ++i) {
        dp[root][i] = temp[i - 1];
    }
}

void dfs(int now)
{
    for (int i = 0; i < sz(childs[now]); ++i) {
        int n = childs[now][i];
        if (!ved[n]) {
            father[n] = now;
            ved[n] = true;
            dfs(n);
        }
    }
}

class FoxConnection2 {
public:
    int ways(vector <int> A, vector <int> B, int _k) {
        k = _k;
        n = sz(A) + 1;
        for (int i = 0; i < n; ++i) {
            childs[i].clear();
            father[i] = -1;
        }
        for (int i = 0; i < n - 1; ++i) {
            int a = A[i] - 1, b = B[i] - 1;
            childs[a].push_back(b);
            childs[b].push_back(a);
        }
        memset(ved, false, sizeof(ved));
        ved[0] = true;
        dfs(0);
        for (int i = 1; i < n; ++i) {
            childs[i].erase(find(childs[i].begin(), childs[i].end(), father[i]));
        }
        memset(dp, 0, sizeof(dp));
        getdp(0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += dp[i][k];
            if (sum >= mod) sum -= mod;
        }
        return sum;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int AARRAY[] = {1,2,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,3,4};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        FoxConnection2 theObject;
        eq(0, theObject.ways(A, B, 2),3);
    }
    {
        int AARRAY[] = {1,1,1,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,3,4,5};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        FoxConnection2 theObject;
        eq(1, theObject.ways(A, B, 3),6);
    }
    {
        int AARRAY[] = {1,2,3,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,3,4,5};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        FoxConnection2 theObject;
        eq(2, theObject.ways(A, B, 3),3);
    }
    {
        int AARRAY[] = {1,2,2,4,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,3,4,5,6};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        FoxConnection2 theObject;
        eq(3, theObject.ways(A, B, 3),6);
    }
    {
        int AARRAY[] = {1,2,2,4,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,3,4,5,6};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        FoxConnection2 theObject;
        eq(4, theObject.ways(A, B, 5),4);
    }
    {
        int AARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        FoxConnection2 theObject;
        eq(5, theObject.ways(A, B, 20),923263934);
    }
    {
        int AARRAY[] = {2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        FoxConnection2 theObject;
        eq(6, theObject.ways(A, B, 1),2);
    }
	return 0;
}
// END CUT HERE
