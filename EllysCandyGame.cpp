// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Elly and Kris play the following game. In the beginning there are several boxes aligned in a row. The boxes may or may not contain candy. As a matter of fact, the girls know exactly how many candies each of them contains. This information is given to you in the vector <int> sweets.
Starting with Elly, the girls make moves in alternating order. A single move looks as follows: the player whose turn it is chooses one of the non-empty boxes and takes all the sweets from it. After that the amount of candy in the neighboring boxes is doubled. For example, suppose that there were five boxes with {20, 50, 70, 0, 30} sweets, respectively. If the girl whose turn it was chose box 0, then in the next turn the number of sweets in the boxes would be {0, 100, 70, 0, 30}. If she chose box 1, then it would be {40, 0, 140, 0, 30}. If she chose box 2, it would be {20, 100, 0, 0, 30}. If she chose box 4, it would be {20, 50, 70, 0, 0}. Note that the girl cannot choose box 3, because it is empty.
The game ends when all boxes are empty. The winner of the game is the girl who has more candies at the end of the game.

Return the name of the girl that will win the game if both girls play optimally, or "Draw" if they end up with the same number of candies.

DEFINITION
Class:EllysCandyGame
Method:getWinner
Parameters:vector <int>
Returns:string
Method signature:string getWinner(vector <int> sweets)


NOTES
-Playing optimally means that if there is a move, which guarantees that the girl whose turn it is will win no matter what the other girl does, she will play it. If there is no such move, but there is one, which would guarantee a draw, she will use it instead.
-The game always ends after a finite number of moves, because the number of empty boxes increases in each step.


CONSTRAINTS
-sweets will contain between 1 and 10 elements, inclusive.
-Each element of sweets will be between 0 and 1000, inclusive.


EXAMPLES

0)
{20, 50, 70, 0, 30}

Returns: "Kris"

If Elly takes the 20, then Kris can take the 30, leaving Elly the choice between 100 and 70. Elly should take the 100, but then Kris will take 140 and win.
If Elly takes the 30, then Kris can take the 20, leaving Elly the same choice.
If Elly takes the 50, then Kris can take the 140, leaving Elly the choice between a 40 and a 30.
If Elly takes the 70, then Kris can take the 100, leaving Elly the same choice.
In any case, Kris will take more than Elly and win.


1)
{42, 13, 7}

Returns: "Elly"

Here Elly can take the 42 in her first move and win, no matter whether Kris chooses the 26 or 7.


2)
{10, 20}

Returns: "Draw"

Elly cannot win, but she can force a draw by taking the 20 (and leaving 20 to her opponent).


3)
{3, 1, 7, 11, 1, 1}

Returns: "Kris"



4)
{41, 449, 328, 474, 150, 501, 467, 329, 536, 440}

Returns: "Kris"



5)
{177, 131, 142, 171, 411, 391, 17, 222, 100, 298}

Returns: "Elly"



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

vector<int> s;
map<int, int> mp;

void decompress(int state, vector<int> &v)
{
    v.clear();
    for (int i = 0; i < sz(s); ++i) {
        v.push_back(state & 3);
        state >>= 2;
    }
    reverse(v.begin(), v.end());
}

int compress(vector<int> &v)
{
    int state = 0;
    for (int i = 0 ; i < sz(v); ++i) {
        state <<= 2;
        state += v[i];
    }
    return state;
}

int t(int i)
{
    return i == 3 ? 4 : i;
}

int getdp(int state)
{
    map<int, int>::iterator mi = mp.find(state);
    if (mi != mp.end()) {
        return mi->second;
    }
    vector<int> st;
    decompress(state, st);
    int best = -100000000;
    for (int i = 0; i < sz(st); ++i) {
        if (st[i] != 0) {
            vector<int> newst = st;
            newst[i] = 0;
            int now = s[i] * t(st[i]);
            if (i && st[i - 1] != 0) {
                ++newst[i - 1];
            }
            if (i + 1 < sz(st) && st[i + 1] != 0) {
                ++newst[i + 1];
            }
            int lose = getdp(compress(newst));
            best = max(best, now - lose);
        }
    }
    if (best == -100000000) {
        best = 0;
    }
    return mp[state] = best;
}

class EllysCandyGame {
public:
    string getWinner(vector <int> sweets) {
        s = sweets;
        mp.clear();
        int state = 0;
        for (int i = 0; i < sz(sweets); ++i) {
            state <<= 2;
            if (sweets[i] != 0) state += 1;
        }
        int res = getdp(state);
        if (res < 0) {
            return "Kris";
        } else if (res == 0) {
            return "Draw";
        } else {
            return "Elly";
        }
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int sweetsARRAY[] = {20, 50, 70, 0, 30};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(0, theObject.getWinner(sweets),"Kris");
    }
    {
        int sweetsARRAY[] = {42, 13, 7};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(1, theObject.getWinner(sweets),"Elly");
    }
    {
        int sweetsARRAY[] = {10, 20};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(2, theObject.getWinner(sweets),"Draw");
    }
    {
        int sweetsARRAY[] = {3, 1, 7, 11, 1, 1};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(3, theObject.getWinner(sweets),"Kris");
    }
    {
        int sweetsARRAY[] = {41, 449, 328, 474, 150, 501, 467, 329, 536, 440};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(4, theObject.getWinner(sweets),"Kris");
    }
    {
        int sweetsARRAY[] = {177, 131, 142, 171, 411, 391, 17, 222, 100, 298};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(5, theObject.getWinner(sweets),"Elly");
    }
	return 0;
}
// END CUT HERE
