// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Snake Snuke has N rectangles cut out of paper.
The rectangles are labeled 0 through N-1.
You are given vector <int>s X and Y with N elements each.
For each i, the sides of rectangle i have lengths X[i] and Y[i].

Snake Snuke will choose some of his rectangles and place them onto a table, one rectangle at a time, in any order he likes.
Each rectangle (except for the first one) must overlap the immediately previous one, so at the end Snuke will have a pile of rectangles.
Snuke may rotate the rectangles, but once placed, the sides of each rectangle must be parallel to the sides of the table.
(I.e., he may only swap the width and height of some rectangles he places.)
After placing all the rectangles, Snuke computes the area that is covered by all N rectangles.
(Formally, the area of their intersection.)

You are also given an int limit.
The area computed by Snuke must be greater than or equal to limit.

Return the largest positive R such that Snuke can select some R of his rectangles and place them in such a way that the area of their intersection is at least limit. If there is no such R, return -1 instead.


DEFINITION
Class:PilingRectsDiv2
Method:getmax
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int getmax(vector <int> X, vector <int> Y, int limit)


CONSTRAINTS
-X and Y will contain between 1 and 50 elements, inclusive.
-X and Y will contain the same number of elements.
-Each element of X and Y will be between 1 and 200, inclusive.
-limit will be between 1 and 40000, inclusive.


EXAMPLES

0)
{1,2,3,1}
{3,2,4,4}
3

Returns: 3

He can choose rectangles 0, 2, and 3. These three rectangles can then be placed in such a way that both rectangle 2 and rectangle 3 cover rectangle 0 completely. For this placement, the area of their intersection will be exactly 3.

1)
{4,7}
{7,4}
25

Returns: 2

Note that he can rotate rectangles.

2)
{10}
{10}
9999

Returns: -1

There is no possible choice.

3)
{10}
{3}
30

Returns: 1



4)
{3,6,5,8,2,9,14}
{14,6,13,8,15,6,3}
27

Returns: 4



5)
{121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149}
{199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146}
5345

Returns: 24



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
class PilingRectsDiv2 {
public:
    int getmax(vector <int> X, vector <int> Y, int limit) {
        int res = -1;
        int n = sz(X);
        for (int i = 0; i < n; ++i) {
            if (X[i] > Y[i]) swap(X[i], Y[i]);
        }
        for (int i = 1; i <= limit; ++i) {
            int j = limit / i;
            if (limit % i != 0) ++j;
            int ct = 0;
            for (int ii = 0; ii < n; ++ii) {
                if (X[ii] >= i && Y[ii] >= j) ++ct;
            }
            if (ct != 0) res = max(res, ct);
        }
        return res;
    }
    
};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int XARRAY[] = {1,2,3,1};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {3,2,4,4};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        PilingRectsDiv2 theObject;
        eq(0, theObject.getmax(X, Y, 3),3);
    }
    {
        int XARRAY[] = {4,7};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {7,4};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        PilingRectsDiv2 theObject;
        eq(1, theObject.getmax(X, Y, 25),2);
    }
    {
        int XARRAY[] = {10};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {10};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        PilingRectsDiv2 theObject;
        eq(2, theObject.getmax(X, Y, 9999),-1);
    }
    {
        int XARRAY[] = {10};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {3};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        PilingRectsDiv2 theObject;
        eq(3, theObject.getmax(X, Y, 30),1);
    }
    {
        int XARRAY[] = {3,6,5,8,2,9,14};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {14,6,13,8,15,6,3};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        PilingRectsDiv2 theObject;
        eq(4, theObject.getmax(X, Y, 27),4);
    }
    {
        int XARRAY[] = {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        PilingRectsDiv2 theObject;
        eq(5, theObject.getmax(X, Y, 5345),24);
    }
	return 0;
}
// END CUT HERE
