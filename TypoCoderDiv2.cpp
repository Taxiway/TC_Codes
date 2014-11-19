// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// TypoCoder is a programming contest like TopCoder.
TypoCoder also has a rating system.
There are two types of coders in TypoCoder: brown coders and ciel coders.
A brown coder is a coder whose rating is greater than or equal to 1200.
A ciel coder is a coder whose rating is less than 1200.

Whenever a new contestant joins TypoCoder, their rating is 500.
Cat Lower joined TypoCoder and then competed in some contests.
You are given a vector <int> rating.
For each i (0-based index), rating[i] is Cat Lower's rating after he competed in (i+1) contests.

Return the number of times Cat Lower changed his color (i.e., changed from being a ciel coder to being a brown coder or back).

DEFINITION
Class:TypoCoderDiv2
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> rating)


CONSTRAINTS
-rating will contain between 1 and 50 elements, inclusive.
-Each element of rating will be between 0 and 4000, inclusive.


EXAMPLES

0)
{1000,1200,1199}

Returns: 2

After the first contest Cat Lower was still a ciel coder. After the second contest his new rating was 1200 which made him a brown coder. (This was the first color change.) After the third contest his new rating was 1199 which made him a ciel coder again. (This was the second color change.)

1)
{1500,2200,900,3000}

Returns: 3

The color changed after the first, the third and the fourth competition.

2)
{600,700,800,900,1000,1100,1199}

Returns: 0

Cat Lower wasn't a brown coder at any time in this case.

3)
{0,4000,0,4000,4000,0,0}

Returns: 4



4)
{575,1090,3271,2496,859,2708,3774,2796,1616,2552,3783,2435,1111,526,562}

Returns: 4



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

bool gao(int rate)
{
    return rate >= 1200;
}

class TypoCoderDiv2 {
public:
    int count(vector <int> rating) {
        rating.insert(rating.begin(), 500);
        int res = 0;
        for (int i = 0; i + 1 < sz(rating); ++i) {
            if (gao(rating[i]) != gao(rating[i + 1])) ++ res;
        }
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int ratingARRAY[] = {1000,1200,1199};
        vector <int> rating( ratingARRAY, ratingARRAY+ARRSIZE(ratingARRAY) );
        TypoCoderDiv2 theObject;
        eq(0, theObject.count(rating),2);
    }
    {
        int ratingARRAY[] = {1500,2200,900,3000};
        vector <int> rating( ratingARRAY, ratingARRAY+ARRSIZE(ratingARRAY) );
        TypoCoderDiv2 theObject;
        eq(1, theObject.count(rating),3);
    }
    {
        int ratingARRAY[] = {600,700,800,900,1000,1100,1199};
        vector <int> rating( ratingARRAY, ratingARRAY+ARRSIZE(ratingARRAY) );
        TypoCoderDiv2 theObject;
        eq(2, theObject.count(rating),0);
    }
    {
        int ratingARRAY[] = {0,4000,0,4000,4000,0,0};
        vector <int> rating( ratingARRAY, ratingARRAY+ARRSIZE(ratingARRAY) );
        TypoCoderDiv2 theObject;
        eq(3, theObject.count(rating),4);
    }
    {
        int ratingARRAY[] = {575,1090,3271,2496,859,2708,3774,2796,1616,2552,3783,2435,1111,526,562};
        vector <int> rating( ratingARRAY, ratingARRAY+ARRSIZE(ratingARRAY) );
        TypoCoderDiv2 theObject;
        eq(4, theObject.count(rating),4);
    }
	return 0;
}
// END CUT HERE
