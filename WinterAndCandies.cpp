// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
It's winter time!
You have some candies arranged in a row and now you want to choose some of them and give them to your friend.




You are given a vector <int> type.
Each candy has a type, which is some positive integer.
For each i, type[i] represents the type of i-th candy.
You want to choose some non-empty subset of candies with the following property:
if the number of candies you choose is K, their types must be precisely all the numbers from 1 to K, inclusive.
Return the number of different ways to do that.
(Two ways are considered different if there exists some candy that is chosen in only one of them.)


DEFINITION
Class:WinterAndCandies
Method:getNumber
Parameters:vector <int>
Returns:int
Method signature:int getNumber(vector <int> type)


NOTES
-The answer will always fit in a signed 32-bit integer.


CONSTRAINTS
-type will contain between 1 and 50 elements, inclusive.
-Each element of type will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 3, 2}

Returns: 3

There are 7 possible non-empty subsets in this case:


(1)


(3)


(2)


(1, 3)


(1, 2)


(3, 2)


(1, 3, 2)


Out of them, only first, fifth and seventh are valid. Thus, the answer is 3.

1)
{1, 1, 2}

Returns: 4

Note that the chosen subset can never contain two elements with the same type.

2)
{1, 3, 2, 5, 7, 4, 5, 4}

Returns: 9



3)
{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}

Returns: 62



4)
{2}

Returns: 0



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
class WinterAndCandies {
public:
    int getNumber(vector <int> type) {
        int ct[60];
        memset(ct, 0, sizeof(ct));
        for (int i = 0; i < sz(type); ++i) {
            ct[type[i]]++;
        }
        int res = 0;
        int rem = 1;
        for (int i = 1; ; ++i) {
            if (ct[i] == 0) {
                break;
            }
            rem *= ct[i];
            res += rem;
        }
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int typeARRAY[] = {1, 3, 2};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(0, theObject.getNumber(type),3);
    }
    {
        int typeARRAY[] = {1, 1, 2};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(1, theObject.getNumber(type),4);
    }
    {
        int typeARRAY[] = {1, 3, 2, 5, 7, 4, 5, 4};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(2, theObject.getNumber(type),9);
    }
    {
        int typeARRAY[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(3, theObject.getNumber(type),62);
    }
    {
        int typeARRAY[] = {2};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(4, theObject.getNumber(type),0);
    }
	return 0;
}
// END CUT HERE
