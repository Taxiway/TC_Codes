// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alien Fred wants to destroy the Earth, but he forgot the password that activates the planet destroyer.




You are given a string S.
Fred remembers that the correct password can be obtained from S by erasing exactly one character.




Return the number of different passwords Fred needs to try.


DEFINITION
Class:AlienAndPassword
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"A"

Returns: 1

In this case, the only password Fred needs to try is an empty string.

1)
"ABA"

Returns: 3

The following three passwords are possible in this case: "BA", "AA", "AB".

2)
"AABACCCCABAA"

Returns: 7



3)
"AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ"

Returns: 26



4)
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"

Returns: 1

Regardless of which character we erase, we will always obtain the same string. Thus there is only one possible password: the string that consists of 49 'Z's.

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
class AlienAndPassword {
public:
    int getNumber(string S) {
        int res;
        set<string> st;
        for (int i = 0; i < sz(S); ++i) {
            string ss = S.substr(0, i) + S.substr(i + 1, sz(S) - i  - 1);
            st.insert(ss);
        }
        res = st.size();
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        AlienAndPassword theObject;
        eq(0, theObject.getNumber("A"),1);
    }
    {
        AlienAndPassword theObject;
        eq(1, theObject.getNumber("ABA"),3);
    }
    {
        AlienAndPassword theObject;
        eq(2, theObject.getNumber("AABACCCCABAA"),7);
    }
    {
        AlienAndPassword theObject;
        eq(3, theObject.getNumber("AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ"),26);
    }
    {
        AlienAndPassword theObject;
        eq(4, theObject.getNumber("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"),1);
    }
	return 0;
}
// END CUT HERE
