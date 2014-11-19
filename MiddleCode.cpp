// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero is learning a new algorithm to encode a string.
You are given a string s that consists of lowercase letters only.
Your task is to simulate the algorithm described below on this string, so that Hero can see how it works.

The algorithm starts with a given input string s and an empty output string t.
The execution of the algorithm consists of multiple steps.
In each step, s and t are modified as follows:

If the length of s is odd, the middle character of s is added to the end of t, and then deleted from s.
If the length of s is even, the two characters in the middle of s are compared. The smaller one of them (either one in case of a tie) is added to the end of t, and then deleted from s.

If after some step the string s is empty, the algorithm terminates.
The output of the algorithm is the final string t.

Return the string t that will be produced by the above algorithm for the given string s.

DEFINITION
Class:MiddleCode
Method:encode
Parameters:string
Returns:string
Method signature:string encode(string s)


NOTES
-When comparing letters, the smaller one is the one earlier in the alphabet - i.e., the character with the smaller ASCII code.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"word"

Returns: "ordw"


In the first step, 'o' is smaller than 'r', thus 'o' is selected.
After the first step: s="wrd", t="o".
After the second step: s="wd", t="or".
In the third step, 'w' is greater than 'd', thus 'd' is selected.
After the third step: s="w", t="ord".
After the fourth step: s="", t="ordw", and the algorithm terminates.


1)
"aaaaa"

Returns: "aaaaa"



2)
"abacaba"

Returns: "caabbaa"



3)
"shjegr"

Returns: "ejghrs"



4)
"adafaaaadafawafwfasdaa"

Returns: "afawadafawafaafsadadaa"



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

string gao(string s)
{
    if (s == "") return "";
    if (sz(s) % 2 == 1) return gao(s.substr(0, sz(s) / 2) + s.substr(sz(s) / 2 + 1, sz(s) / 2)) + s[sz(s) / 2];
    else if (s[sz(s) / 2 - 1] > s[sz(s) / 2]) return gao(s.substr(0, sz(s) / 2) + s.substr(sz(s) / 2 + 1, sz(s) / 2 - 1)) + s[sz(s) / 2];
    else return gao(s.substr(0, sz(s) / 2 - 1) + s.substr(sz(s) / 2, sz(s) / 2)) + s[sz(s) / 2 - 1];
}

class MiddleCode {
public:
    string encode(string s) {
        string res = gao(s);
        reverse(res.begin(), res.end());
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        MiddleCode theObject;
        eq(0, theObject.encode("word"),"ordw");
    }
    {
        MiddleCode theObject;
        eq(1, theObject.encode("aaaaa"),"aaaaa");
    }
    {
        MiddleCode theObject;
        eq(2, theObject.encode("abacaba"),"caabbaa");
    }
    {
        MiddleCode theObject;
        eq(3, theObject.encode("shjegr"),"ejghrs");
    }
    {
        MiddleCode theObject;
        eq(4, theObject.encode("adafaaaadafawafwfasdaa"),"afawadafawafaafsadadaa");
    }
	return 0;
}
// END CUT HERE
