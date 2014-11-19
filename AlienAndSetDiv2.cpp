// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alien Fred wants to destroy the Earth.
But before he does that, he wants to solve the following problem.




He has the set {1, 2, 3, ..., 2N}.
He wants to split this set into two new sets A and B.
The following conditions must all be satisfied:

Each element of the original set must belong to exactly one of the sets A and B.
The two new sets must have the same size. (I.e., each of them must contain exactly N numbers.)
For each i from 1 to N, inclusive: 
    Let A[i] be the i-th smallest element of A, and let B[i] be the i-th smallest element of B.
    The difference |A[i] - B[i]| must be less than or equal to K.





You are given the two ints N and K.
Let X be the total number of ways in which Fred can choose the sets A and B.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:AlienAndSetDiv2
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int N, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-K will be between 1 and 10, inclusive.


EXAMPLES

0)
2
1

Returns: 4

The initial set is {1, 2, 3, 4}.
The following 6 pairs of subsets are possible in this case:


A={1, 2} and B={3, 4}


A={1, 3} and B={2, 4}


A={1, 4} and B={2, 3}


A={2, 3} and B={1, 4}


A={2, 4} and B={1, 3}


A={3, 4} and B={1, 2}


The first option and the last option are both invalid.
One of the reasons is that in both cases the difference between the smallest element in A and the smallest element in B is too large (3-1 = 2, which is more than 1).
The other 4 options are valid.


Note that order of the two sets matters: the option A={1,3} and B={2,4} differs from the option A={2,4} and B={1,3}.

1)
3
1

Returns: 8



2)
4
2

Returns: 44



3)
10
10

Returns: 184756



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

int ct = 0;
int d = 1;

void rec(vector<int> &a, vector<int> &b, int now, int n)
{
    if (now > n * 2) {
        ++ct;
        return;
    }
    if (sz(a) == n) {
        if (abs(now - a[sz(b)]) <= d) {
            b.push_back(now);
            rec(a, b, now + 1, n);
            b.pop_back();
        }
    } else if (sz(b) == n) {
        if (abs(now - b[sz(a)]) <= d) {
            a.push_back(now);
            rec(a, b, now + 1, n);
            a.pop_back();
        }
    } else {
        if (sz(a) > sz(b)) {
            a.push_back(now);
            rec(a, b, now + 1, n);
            a.pop_back();
            
            if (abs(now - a[sz(b)]) <= d) {
                b.push_back(now);
                rec(a, b, now + 1, n);
                b.pop_back();
            }
        } else if (sz(a) < sz(b)) {
            b.push_back(now);
            rec(a, b, now + 1, n);
            b.pop_back();
            
            if (abs(now - b[sz(a)]) <= d) {
                a.push_back(now);
                rec(a, b, now + 1, n);
                a.pop_back();
            }
        } else {
            a.push_back(now);
            rec(a, b, now + 1, n);
            a.pop_back();
            b.push_back(now);
            rec(a, b, now + 1, n);
            b.pop_back();
        }
    }
}

int gao(int n)
{
    ct = 0;
    vector<int> a, b;
    rec(a, b, 1, n);
    return ct;
}

class AlienAndSetDiv2 {
public:
    int getNumber(int N, int K) {
        for (int n = 1; n <= 10; ++n) {
            cout << gao(n) << endl;
        }
        return 0;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        AlienAndSetDiv2 theObject;
        eq(0, theObject.getNumber(2, 1),4);
    }
    {
        AlienAndSetDiv2 theObject;
        eq(1, theObject.getNumber(3, 1),8);
    }
    {
        AlienAndSetDiv2 theObject;
        eq(2, theObject.getNumber(4, 2),44);
    }
    {
        AlienAndSetDiv2 theObject;
        eq(3, theObject.getNumber(10, 10),184756);
    }
	return 0;
}
// END CUT HERE
