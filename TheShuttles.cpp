// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Note that the memory limit for all tasks in this SRM is 256 MB.

The company Manao Inc. cares for its employees and tries to provide them with as much comfort as possible. One of the services Manao Inc. provides is transportation of employees from N distant locations to the office. The locations are numbered from 0 to N-1. You are given a vector <int> cnt containing N elements. The i-th (0-based index) element of cnt is the number of employees who live near location i.

The company wants to purchase several shuttles of the same size. These shuttles will then be used for employee transportation. Each of the shuttles will only serve one particular location. Each location will be assigned the smallest number of shuttles sufficient to transport all of the employees living close to it.

The cost of a shuttle consists of the cost baseCost of its frame and some additional cost seatCost per each seat. That is, a shuttle with X seats will cost baseCost + X * seatCost. For its shuttles, Manao Inc. can choose X to be any positive integer. (But remember that all the shuttles must have the same X.) Compute and return the least amount of money the company needs to spend on the shuttles in order to provide transportation for all employees.

DEFINITION
Class:TheShuttles
Method:getLeastCost
Parameters:vector <int>, int, int
Returns:int
Method signature:int getLeastCost(vector <int> cnt, int baseCost, int seatCost)


CONSTRAINTS
-cnt will contain between 1 and 50 elements, inclusive.
-Each element of cnt will be between 1 and 100, inclusive.
-baseCost will be between 1 and 100, inclusive.
-seatCost will be between 1 and 100, inclusive.


EXAMPLES

0)
{9}
30
5

Returns: 75

Manao Inc. provides transportation for its employees from a single location. There are 9 employees living near it. A shuttle with X seats will cost the company 30 + 5X. It is optimal to buy a single shuttle with 9 seats.

1)
{9, 4}
30
5

Returns: 150

Manao Inc. provides transportation from two locations. There are 9 employees living near location 0 and 4 employees living near location 1. It is optimal to buy two shuttles with 9 seats each and send a single shuttle to each location. (Note that the shuttles we buy must all be of the same size. It is not allowed to buy one shuttle with 9 and another with 4 seats.)

2)
{9, 4}
10
5

Returns: 105

This is the same test as the previous example, but baseCost is lower. It is optimal to buy three shuttles with 5 seats each and send two shuttles to location 0 and one shuttle to location 1.

3)
{51, 1, 77, 14, 17, 10, 80}
32
40

Returns: 12096



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
class TheShuttles {
public:
    int getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
        int res = 1000000000;
        int m = *max_element(cnt.begin(), cnt.end());
        for (int i = 1; i <= m; ++i) {
            int sum = 0;
            for (int j = 0; j < sz(cnt); ++j) {
                sum += cnt[j] / i;
                if (cnt[j] % i != 0) ++sum;
            }
            int one = baseCost + seatCost * i;
            sum *= one;
            res = min(res, sum);
        }
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int cntARRAY[] = {9};
        vector <int> cnt( cntARRAY, cntARRAY+ARRSIZE(cntARRAY) );
        TheShuttles theObject;
        eq(0, theObject.getLeastCost(cnt, 30, 5),75);
    }
    {
        int cntARRAY[] = {9, 4};
        vector <int> cnt( cntARRAY, cntARRAY+ARRSIZE(cntARRAY) );
        TheShuttles theObject;
        eq(1, theObject.getLeastCost(cnt, 30, 5),150);
    }
    {
        int cntARRAY[] = {9, 4};
        vector <int> cnt( cntARRAY, cntARRAY+ARRSIZE(cntARRAY) );
        TheShuttles theObject;
        eq(2, theObject.getLeastCost(cnt, 10, 5),105);
    }
    {
        int cntARRAY[] = {51, 1, 77, 14, 17, 10, 80};
        vector <int> cnt( cntARRAY, cntARRAY+ARRSIZE(cntARRAY) );
        TheShuttles theObject;
        eq(3, theObject.getLeastCost(cnt, 32, 40),12096);
    }
	return 0;
}
// END CUT HERE
