// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
It's winter time! Time to play some games.




Four reindeers are playing the following game.
The first three of them choose three non-empty strings: A, B, and C. (The strings are not necessarily distinct.)
Then, the fourth one (and it happens to be the youngest one) finds a string S that satisfies the following conditions:



S is a subsequence of A. (I.e., either S equals A, or S can be obtained from A by removing some of its characters.)


S is a subsequence of B.


C is a (contiguous) substring of S.


There is no string longer than S that satisfies the previous three conditions.





You are given three vector <string>s allA, allB and allC.
Concatenate all elements of allA, allB and allC to obtain strings A, B and C, respectively.
Return the length of the string S.
If there is no such string, return 0.


DEFINITION
Class:WinterAndReindeers
Method:getNumber
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)


CONSTRAINTS
-allA, allB and allC will each contain between 1 and 50 elements, inclusive.
-Each element of allA, allB and allC will contain between 1 and 50 characters, inclusive.
-Each element of allA, allB and allC will consist only of uppercase English letters ('A'-'Z').


EXAMPLES

0)
{"X"}
{"X", "Y"}
{"X"}

Returns: 1

In this case, A = "X", B = "XY", C = "X". The longest possible string that satisfies conditions from the statement is "X". Thus, the answer is 1.

1)
{"ABCXD"}
{"BCDEF"}
{"CD"}

Returns: 3

The longest possible string in this case is "BCD".

2)
{"WE", "LOVE"}
{"WORKING", "FOR", "SANTA"}
{"JK"}

Returns: 0

No string satisfies all criteria in this case. Thus, the answer is 0.

3)
{"ABCDE"}
{"CDEAB"}
{"B"}

Returns: 2



4)
{"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}
{"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}
{"AXBADXBBAB", "CDD"}

Returns: 23



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
class WinterAndReindeers {
public:
    int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string allAARRAY[] = {"X"};
        vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
        string allBARRAY[] = {"X", "Y"};
        vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
        string allCARRAY[] = {"X"};
        vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
        WinterAndReindeers theObject;
        eq(0, theObject.getNumber(allA, allB, allC),1);
    }
    {
        string allAARRAY[] = {"ABCXD"};
        vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
        string allBARRAY[] = {"BCDEF"};
        vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
        string allCARRAY[] = {"CD"};
        vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
        WinterAndReindeers theObject;
        eq(1, theObject.getNumber(allA, allB, allC),3);
    }
    {
        string allAARRAY[] = {"WE", "LOVE"};
        vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
        string allBARRAY[] = {"WORKING", "FOR", "SANTA"};
        vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
        string allCARRAY[] = {"JK"};
        vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
        WinterAndReindeers theObject;
        eq(2, theObject.getNumber(allA, allB, allC),0);
    }
    {
        string allAARRAY[] = {"ABCDE"};
        vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
        string allBARRAY[] = {"CDEAB"};
        vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
        string allCARRAY[] = {"B"};
        vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
        WinterAndReindeers theObject;
        eq(3, theObject.getNumber(allA, allB, allC),2);
    }
    {
        string allAARRAY[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"};
        vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
        string allBARRAY[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"};
        vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
        string allCARRAY[] = {"AXBADXBBAB", "CDD"};
        vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
        WinterAndReindeers theObject;
        eq(4, theObject.getNumber(allA, allB, allC),23);
    }
	return 0;
}
// END CUT HERE
