// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel has a robot.
The robot is located on an infinite plane.
At the beginning, the robot starts at the coordinates (0, 0).
The robot can then make several steps.
The steps are numbered starting from 0.

In each step, Ciel must choose one of two directions for the robot: right (x coordinate increases) or up (y coordinate increases).
In step k, the robot will move 3^k units in the chosen direction.
It is not allowed to skip a step.

You are given ints x and y.
Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps.
Otherwise, return "Impossible".

DEFINITION
Class:PowerOfThreeEasy
Method:ableToGet
Parameters:int, int
Returns:string
Method signature:string ableToGet(int x, int y)


CONSTRAINTS
-x will be between 0 and 1,000,000,000, inclusive.
-y will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
3

Returns: "Possible"

In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).

1)
1
1

Returns: "Impossible"



2)
3
0

Returns: "Impossible"



3)
1
9

Returns: "Impossible"

Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.

4)
3
10

Returns: "Possible"



5)
1093
2187

Returns: "Possible"



6)
0
0

Returns: "Possible"



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

set<int> split(int n)
{
    set<int> st;
    int i = 0;
    while (n) {
        if (n % 3 == 1) {
            st.insert(i);
        } else if (n % 3 == 2) {
            st.insert(-1);
        }
        ++i;
        n /= 3;
    }
    return st;
}

class PowerOfThreeEasy {
public:
    string ableToGet(int x, int y) {
        set<int> s1 = split(x);
        set<int> s2 = split(y);
        int n = sz(s1) + sz(s2);
        for (int i = 0; i < n; ++i) {
            if (s1.count(i) || s2.count(i)) {
                continue;
            } else {
                return "Impossible";
            }
        }
        return "Possible";
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        PowerOfThreeEasy theObject;
        eq(0, theObject.ableToGet(1, 3),"Possible");
    }
    {
        PowerOfThreeEasy theObject;
        eq(1, theObject.ableToGet(1, 1),"Impossible");
    }
    {
        PowerOfThreeEasy theObject;
        eq(2, theObject.ableToGet(3, 0),"Impossible");
    }
    {
        PowerOfThreeEasy theObject;
        eq(3, theObject.ableToGet(1, 9),"Impossible");
    }
    {
        PowerOfThreeEasy theObject;
        eq(4, theObject.ableToGet(3, 10),"Possible");
    }
    {
        PowerOfThreeEasy theObject;
        eq(5, theObject.ableToGet(1093, 2187),"Possible");
    }
    {
        PowerOfThreeEasy theObject;
        eq(6, theObject.ableToGet(0, 0),"Possible");
    }
	return 0;
}
// END CUT HERE
