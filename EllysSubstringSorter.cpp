// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Elly has a string S of uppercase letters and a magic device that can modify the string. The strength of the device is an int L.

The device does the following: The user enters a 0-based index i such that 0 <= i <= length(S)-L. The device then takes L letters of S, starting at index i, and puts these letters into alphabetical order.
Formally, the letters that get reordered are the letters S[i], S[i+1], and so on, until and including S[i+L-1].

For example, let S="TOPCODER" and let L=4. If the user chooses i=0, the selected substring will be "TOPC". These letters are rearranged into alphabetical order ("COPT") while the rest of the string remains unchanged ("....ODER"). Thus, the result would be the string "COPTODER". If the user were to choose i=2 instead, the resulting string would be "TOCDOPER". Here, "TO....ER" was left unchanged, and "PCOD" was changed into "CDOP".

Elly's magic device has a flaw: it can only be used once and then it self-destructs. You are given the string S and the int L described above. Return the lexicographically smallest string Elly can create by using the device exactly once.


DEFINITION
Class:EllysSubstringSorter
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string S, int L)


NOTES
-A string S1 is lexicographically smaller than a string S2 if S1 contains a smaller character than S2 at the first index where they differ.


CONSTRAINTS
-L will be between 2 and 50, inclusive.
-S will contain between L and 50 characters, inclusive.
-Each character of S will be an uppercase letter of the English alphabet ('A'-'Z').


EXAMPLES

0)
"TOPCODER"
4

Returns: "COPTODER"

The best we can do here is to sort the first 4 characters of the string.

1)
"ESPRIT"
3

Returns: "EPRSIT"

The best solution is obtained by choosing i=1, i.e., by sorting the letters in the substring "SPR".

2)
"AAAAAAAAA"
2

Returns: "AAAAAAAAA"

Sometimes sorting doesn't do anything.

3)
"ABRACADABRA"
5

Returns: "AAABCRDABRA"



4)
"BAZINGA"
6

Returns: "ABGINZA"



5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
21

Returns: "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD"



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

string gao(string s, int i, int l)
{
    sort(s.begin() + i, s.begin() + i + l);
    return s;
}

class EllysSubstringSorter {
public:
    string getMin(string S, int L) {
        string res = S;
        for (int i = 0; i + L <= S.length(); ++i) {
            string next = gao(S, i, L);
            if (next < res) res = next;
        }
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        EllysSubstringSorter theObject;
        eq(0, theObject.getMin("TOPCODER", 4),"COPTODER");
    }
    {
        EllysSubstringSorter theObject;
        eq(1, theObject.getMin("ESPRIT", 3),"EPRSIT");
    }
    {
        EllysSubstringSorter theObject;
        eq(2, theObject.getMin("AAAAAAAAA", 2),"AAAAAAAAA");
    }
    {
        EllysSubstringSorter theObject;
        eq(3, theObject.getMin("ABRACADABRA", 5),"AAABCRDABRA");
    }
    {
        EllysSubstringSorter theObject;
        eq(4, theObject.getMin("BAZINGA", 6),"ABGINZA");
    }
    {
        EllysSubstringSorter theObject;
        eq(5, theObject.getMin("AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD", 21),"AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD");
    }
	return 0;
}
// END CUT HERE
