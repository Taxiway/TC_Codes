// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// One day, Fox Ciel looked at the words "tokyo" and "kyoto" and noticed an unusual property:
We can split "tokyo" into "to"+"kyo", and then swap those two parts to obtain "kyo"+"to" = "kyoto".


Formally, let S and T be two different strings.
We call the pair (S,T) interesting if there are two non-empty strings A and B such that S = A+B and T = B+A.
For example, according to this definition, if S="tokyo" and T="kyoto", then the pair (S,T) is interesting, because we can find A="to" and B="kyo".


You are given a vector <string> words.
Return the number of interesting pairs we can find among the elements of words.
Only count each pair once.
E.g., ("tokyo","kyoto") and ("kyoto","tokyo") is the same interesting pair.

DEFINITION
Class:FoxAndWord
Method:howManyPairs
Parameters:vector <string>
Returns:int
Method signature:int howManyPairs(vector <string> words)


CONSTRAINTS
-words will contain between 2 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-Each character in each element of words will be a lowercase letter ('a'-'z').
-All the elements in words will be pairwise distinct.


EXAMPLES

0)
{"tokyo", "kyoto"}

Returns: 1

As mentioned in the problem statement, ("tokyo", "kyoto") is an interesting pair.

1)
{"aaaaa", "bbbbb"}

Returns: 0

("aaaaa", "bbbbb") is not an interesting pair.

2)
{"ababab","bababa","aaabbb"}

Returns: 1

There is one interesting pair: ("ababab","bababa").
Note that for this interesting pair there is more than one way to choose the strings A and B.

3)
{"eel", "ele", "lee"}

Returns: 3



4)
{"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"}

Returns: 6



5)
{"top","coder"}

Returns: 0

Different elements of words may have different lengths.


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

bool isok(string s1, string s2)
{
    for (int i = 0; i < sz(s1); ++i) {
        string s = s1.substr(0, i);
        string t = s1.substr(i, sz(s1) - i);
        if (t + s == s2) return true;
    }
    return false;
}

class FoxAndWord {
public:
    int howManyPairs(vector <string> words) {
        int res = 0;
        for (int i = 0; i + 1 < sz(words); ++i) {
            for (int j = i + 1; j < sz(words); ++j) {
                if (isok(words[i], words[j])) ++res;
            }
        }
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string wordsARRAY[] = {"tokyo", "kyoto"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        FoxAndWord theObject;
        eq(0, theObject.howManyPairs(words),1);
    }
    {
        string wordsARRAY[] = {"aaaaa", "bbbbb"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        FoxAndWord theObject;
        eq(1, theObject.howManyPairs(words),0);
    }
    {
        string wordsARRAY[] = {"ababab","bababa","aaabbb"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        FoxAndWord theObject;
        eq(2, theObject.howManyPairs(words),1);
    }
    {
        string wordsARRAY[] = {"eel", "ele", "lee"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        FoxAndWord theObject;
        eq(3, theObject.howManyPairs(words),3);
    }
    {
        string wordsARRAY[] = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        FoxAndWord theObject;
        eq(4, theObject.howManyPairs(words),6);
    }
    {
        string wordsARRAY[] = {"top","coder"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        FoxAndWord theObject;
        eq(5, theObject.howManyPairs(words),0);
    }
	return 0;
}
// END CUT HERE
