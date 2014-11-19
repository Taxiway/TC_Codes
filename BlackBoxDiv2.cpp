// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Cat Upper has a rectangular black box.
On the bottom of the box there is a grid that divides the box into identical square cells.
There are no walls between the cells.
The sides of the box are transparent, the top and bottom are opaque (i.e., Upper cannot see through them).
Some of the cells are filled: each of them contains an opaque black block that fills the entire cell.
The remaining cells are empty.

Cat Upper looked into the black box from the front and recorded what he saw:
Whenever a column of the grid was completely empty, he could see through the box and wrote down '.' (a period).
And whenever a column of the grid contained at least one block, Upper could not see through the box and he wrote down 'B'.

Then, he looked into the black box from the left side and again he recorded what he saw:
for each row of the grid he wrote '.' if the row was completely empty and 'B' otherwise.

You are given the recorded information in two strings: front and side.

Return the number of possible arrangements of the opaque blocks within the black box, modulo 1,000,000,007.
Note that you don't know the exact number of blocks in the black box.


DEFINITION
Class:BlackBoxDiv2
Method:count
Parameters:string, string
Returns:int
Method signature:int count(string front, string side)


CONSTRAINTS
-front and side will each contain between 1 and 50 characters, inclusive.
-Each character in front and side will be 'B' or '.'.


EXAMPLES

0)
"BB"
"BB"

Returns: 7

There are seven possible arrangements, as shown in the figure below.




1)
"..."
"....."

Returns: 1

There is no block, thus there is exactly 1 valid arrangement: the one where all cells are empty.

2)
"..."
"BBB"

Returns: 0

There is no possible arrangement. Upper must have made a mistake.

3)
"...BB.B...."
"B.B.B.B.B"

Returns: 16081



4)
"BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB"
".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"

Returns: 771030153



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

int MOD = 1000000007;
int dp[64][64];
int dp2[64][64][64];
long long C[64][64];

int getdp2(int must, int free, int rows)
{
    if (dp2[must][free][rows] != -1) {
        return dp2[must][free][rows];
    }
    if (rows == 0) {
        if (must == 0) dp2[must][free][rows] = 1;
        else dp2[must][free][rows] = 0;
        return dp2[must][free][rows];
    }
    
    dp2[must][free][rows] = 0;
    for (int m = 0; m <= must; ++m) {
        for (int f = 0; f <= free; ++f) {
            if (m + f == 0) continue;
            dp2[must][free][rows] += (((C[must][m] * C[free][f]) % MOD) * getdp2(must - m, free + m, rows - 1)) % MOD;
            if (dp2[must][free][rows] >= MOD) dp2[must][free][rows] -= MOD;
        }
    }
    return dp2[must][free][rows];
}

int getdp(int a, int b)
{
    if (dp[a][b] != -1) {
        return dp[a][b];
    }
    if (a == 0 && b == 0) {
        return dp[a][b] = 1;
    }
    if (a == 0 || b == 0) {
        return dp[a][b] = 0;
    }
    return dp[a][b] = getdp2(a, 0, b);
}

class BlackBoxDiv2 {
public:
    int count(string front, string side) {
        C[0][0] = 1;
        for (int i = 1; i <= 50; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    C[i][j] = 1;
                } else {
                    C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                    if (C[i][j] >= MOD) C[i][j] -= MOD;
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        int a = 0, b = 0;
        for (int i = 0; i < sz(front); ++i) {
            if (front[i] == 'B') ++a;
        }
        for (int i = 0; i < sz(side); ++i) {
            if (side[i] == 'B') ++b;
        }
        return getdp(a, b);
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        BlackBoxDiv2 theObject;
        eq(0, theObject.count("BB", "BB"),7);
    }
    {
        BlackBoxDiv2 theObject;
        eq(1, theObject.count("...", "....."),1);
    }
    {
        BlackBoxDiv2 theObject;
        eq(2, theObject.count("...", "BBB"),0);
    }
    {
        BlackBoxDiv2 theObject;
        eq(3, theObject.count("...BB.B....", "B.B.B.B.B"),16081);
    }
    {
        BlackBoxDiv2 theObject;
        eq(4, theObject.count("BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB", ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"),771030153);
    }
	return 0;
}
// END CUT HERE
