// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
It's winter time!
Time to eat a lot of mandarins with your friends.




You have several bags with mandarins.
You are given an vector <int> bags.
For each i, the i-th element of bags represents the number of mandarins in the i-th bag.
You are also given an int K.
You want to choose exactly K bags and distribute them among you and your friends.
To be as fair as possible, you want to minimize the difference between the chosen bag with most mandarins and the chosen bag with fewest mandarins.
Return the smallest difference that can be achieved.


DEFINITION
Class:WinterAndMandarins
Method:getNumber
Parameters:vector <int>, int
Returns:int
Method signature:int getNumber(vector <int> bags, int K)


CONSTRAINTS
-bags will contain between 2 and 50 elements, inclusive.
-Each element of bags will be between 1 and 1,000,000,000, inclusive.
-K will be between 2 and N, inclusive, where N is the number of elements in bags.


EXAMPLES

0)
{10, 20, 30}
2

Returns: 10

There are three ways to choose two bags in this case: {10, 20}, {20, 30}, and {10, 30}.
Both in the first case and in the second case the difference between the largest and the smallest number of mandarins is 10.
In the third case the difference is 20.
Thus, the smallest possible difference is 10.

1)
{4, 7, 4}
3

Returns: 3



2)
{4, 1, 2, 3}
3

Returns: 2



3)
{5, 4, 6, 1, 9, 4, 2, 7, 5, 6}
4

Returns: 1



4)
{47, 1000000000, 1, 74}
2

Returns: 27



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
class WinterAndMandarins {
public:
    int getNumber(vector <int> bags, int K) {
        sort(all(bags));
        int res = bags[K - 1] - bags[0];
        for (int i = 0; i + K <= sz(bags); ++i) {
            res = min(res, bags[i + K - 1] - bags[i]);
        }
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int bagsARRAY[] = {10, 20, 30};
        vector <int> bags( bagsARRAY, bagsARRAY+ARRSIZE(bagsARRAY) );
        WinterAndMandarins theObject;
        eq(0, theObject.getNumber(bags, 2),10);
    }
    {
        int bagsARRAY[] = {4, 7, 4};
        vector <int> bags( bagsARRAY, bagsARRAY+ARRSIZE(bagsARRAY) );
        WinterAndMandarins theObject;
        eq(1, theObject.getNumber(bags, 3),3);
    }
    {
        int bagsARRAY[] = {4, 1, 2, 3};
        vector <int> bags( bagsARRAY, bagsARRAY+ARRSIZE(bagsARRAY) );
        WinterAndMandarins theObject;
        eq(2, theObject.getNumber(bags, 3),2);
    }
    {
        int bagsARRAY[] = {5, 4, 6, 1, 9, 4, 2, 7, 5, 6};
        vector <int> bags( bagsARRAY, bagsARRAY+ARRSIZE(bagsARRAY) );
        WinterAndMandarins theObject;
        eq(3, theObject.getNumber(bags, 4),1);
    }
    {
        int bagsARRAY[] = {47, 1000000000, 1, 74};
        vector <int> bags( bagsARRAY, bagsARRAY+ARRSIZE(bagsARRAY) );
        WinterAndMandarins theObject;
        eq(4, theObject.getNumber(bags, 2),27);
    }
	return 0;
}
// END CUT HERE
