// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Note that the memory limit for all tasks in this SRM is 256 MB.


Fox Ciel has a matrix A that consists of N rows by M columns.
Both N and M are even.
Each element of the matrix is either 0 or 1.
The rows of the matrix are numbered 0 through N-1 from top to bottom, the columns are numbered 0 through M-1 from left to right.
The element in row i, column j is denoted A(i, j).
You are given a vector <string> A that describes the matrix A.
The character A[i][j] is '1' if A(i, j)=1 and it is '0' otherwise.



A palindrome is a string that reads the same forwards and backwards.
For example, "1001" and "0111001110" are palindromes while "1101" and "000001" are not.



Some rows and some columns in Ciel's matrix may be palindromes.
For example, in the matrix below both row 0 and column 3 are palindromes.
(Row 0 is the palindrome "0000", column 3 is the palindrome "0110".)


0000
0011
0111
1110



You are also given two ints: rowCount and columnCount.
Ciel wants her matrix A to have at least rowCount rows that are palindromes, and at the same time at least columnCount columns that are palindromes.
If this is currently not the case, she can change A by changing some of the elements (from '0' to '1' or vice versa).
Compute and return the smallest possible number of elements she needs to change in order to reach her goal.



DEFINITION
Class:PalindromeMatrixDiv2
Method:minChange
Parameters:vector <string>, int, int
Returns:int
Method signature:int minChange(vector <string> A, int rowCount, int columnCount)


CONSTRAINTS
-N and M will be between 2 and 8, inclusive.
-N and M will be even.
-A will contain N elements.
-Each element of A will contain M characters.
-Each character of A will be either '0' or '1'.
-rowCount will be between 0 and N.
-columnCount will be between 0 and M.


EXAMPLES

0)
{"0000"
,"1000"
,"1100"
,"1110"}
2
2

Returns: 1

An optimal solution is to change A(3, 0) to 0. Then we will have palindromes in two rows (0 and 3), and in two columns (0 and 3).


1)
{"0000"
,"1000"
,"1100"
,"1110"}
3
2

Returns: 3

This is similar to the previous example, but in this case we must have three row palindromes. 
An optimal solution is to change A(1, 0), A(2, 0) and A(3, 0) to 0.

2)
{"01"
,"10"}
1
1

Returns: 1



3)
{"1110"
,"0001"}
0
0

Returns: 0

Here, we do not have to change A at all.


4)
{"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}
2
2

Returns: 8



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

vector <string> a;
int n, m;
bool done[60][60];

int gaogao(set<pair<int, int> > v)
{
    map<char, int> mp;
    mp['0'] = mp['1'] = 0;
    for (set<pair<int, int> >::iterator si = v.begin(); si != v.end(); ++si) {
        int x = si->first, y = si->second;
        done[x][y] = true;
        mp[a[x][y]]++;
    }
    return min(mp['0'], mp['1']);
}

int gao(int m1, int m2)
{
    memset(done, false, sizeof(done));
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (done[i][j]) continue;
            if ((m1 & (1 << i)) || (m2 & (1 << j))) {
                set<pair<int, int> > v;
                v.insert(make_pair(i, j));
                if (m1 & (1 << i)) {
                    v.insert(make_pair(i, m - j - 1));
                    if (m2 & (1 << (m - j - 1))) {
                        v.insert(make_pair(n - i - 1, m - j - 1));
                        if (m1 & (1 << (n - i - 1))) {
                            v.insert(make_pair(n - i - 1, j));
                        }
                    }
                }
                if (m2 & (1 << j)) {
                    v.insert(make_pair(n - i - 1, j));
                    if (m1 & (1 << (n - i - 1))) {
                        v.insert(make_pair(n - i - 1, m - j - 1));
                        if (m2 & (1 << (m - j - 1))) {
                            v.insert(make_pair(i, m - j - 1));
                        }
                    }
                }
                sum += gaogao(v);
            }
        }
    }
    return sum;
}

class PalindromeMatrixDiv2 {
public:
    int minChange(vector <string> _A, int rowCount, int columnCount) {
        a = _A;
        n = sz(a);
        m = sz(a[0]);
        int res = n * m;
        for (int m1 = 0; m1 < (1 << n); ++m1) {
            int ct1 = 0;
            for (int i = 0; i < n; ++i) {
                if (m1 & (1 << i)) ++ct1;
            }
            if (ct1 < rowCount) continue;
            for (int m2 = 0; m2 < (1 << m); ++m2) {
                int ct2 = 0;
                for (int j = 0; j < m; ++j) {
                    if (m2 & (1 << j)) ++ct2;
                }
                if (ct2 < columnCount) continue;
                res = min(res, gao(m1, m2));
            }
        }
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string AARRAY[] = {"0000"
           ,"1000"
           ,"1100"
           ,"1110"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(0, theObject.minChange(A, 2, 2),1);
    }
    {
        string AARRAY[] = {"0000"
           ,"1000"
           ,"1100"
           ,"1110"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(1, theObject.minChange(A, 3, 2),3);
    }
    {
        string AARRAY[] = {"01"
           ,"10"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(2, theObject.minChange(A, 1, 1),1);
    }
    {
        string AARRAY[] = {"1110"
           ,"0001"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(3, theObject.minChange(A, 0, 0),0);
    }
    {
        string AARRAY[] = {"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(4, theObject.minChange(A, 2, 2),8);
    }
	return 0;
}
// END CUT HERE
