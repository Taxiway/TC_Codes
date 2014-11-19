// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a vector <int> A with N elements, where N is even.
Note that some elements of A may be negative.
You are also given a int X which is guaranteed to be negative.
You must divide the elements of A into N/2 disjoint pairs.
(That is, each element of A must be in exactly one of those pairs.)
Your goal is to maximize the number of pairs in which the product of the two elements is greater than or equal to X.
Return the largest possible number of such pairs.

DEFINITION
Class:SplitIntoPairs
Method:makepairs
Parameters:vector <int>, int
Returns:int
Method signature:int makepairs(vector <int> A, int X)


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-The number of elements in A will be even.
-Each element in A will be between -1,000,000,000 and 1,000,000,000, inclusive.
-X will be between -1,000,000,000 and -1, inclusive.


EXAMPLES

0)
{2,-1}
-1

Returns: 0

One possible pair has product -2, which is lower than needed.

1)
{1,-1}
-1

Returns: 1

Here product is -1, it's enough.

2)
{-5,-4,2,3}
-1

Returns: 2

If first pair contains numbers -5 and -4, and second contains 2 and 3, both will have positive product.

3)
{5,-7,8,-2,-5,3}
-7

Returns: 3

Acceptable splitting is {5,8}, {-7,-5} and {-2,3}.

4)
{3,4,5,6,6,-6,-4,-10,-1,-9}
-2

Returns: 4



5)
{1000000,1000000}
-5

Returns: 1

Beware overflow.

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

bool isok(vector<int> a, int x)
{
    vector<int> neg, pos;
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] == 0) return true;
        else if (a[i] < 0) neg.push_back(a[i]);
        else pos.push_back(a[i]);
    }
    if (neg.size() % 2 == 0) return true;
    sort(all(neg));
    sort(all(pos));
    long long aa = neg.back();
    long long bb = pos[0];
    return aa * bb >= x;
}

class SplitIntoPairs {
public:
    int makepairs(vector <int> A, int X) {
        int res = sz(A) / 2;
        if (!isok(A, X)) --res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int AARRAY[] = {2,-1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(0, theObject.makepairs(A, -1),0);
    }
    {
        int AARRAY[] = {1,-1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(1, theObject.makepairs(A, -1),1);
    }
    {
        int AARRAY[] = {-5,-4,2,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(2, theObject.makepairs(A, -1),2);
    }
    {
        int AARRAY[] = {5,-7,8,-2,-5,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(3, theObject.makepairs(A, -7),3);
    }
    {
        int AARRAY[] = {3,4,5,6,6,-6,-4,-10,-1,-9};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(4, theObject.makepairs(A, -2),4);
    }
    {
        int AARRAY[] = {1000000,1000000};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(5, theObject.makepairs(A, -5),1);
    }
	return 0;
}
// END CUT HERE
