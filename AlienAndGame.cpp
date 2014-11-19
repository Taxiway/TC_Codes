// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alien Fred wants to destroy the Earth.
But before he does that, he wants to play the following game.




He has a rectangular board divided into unit cells.
Each cell is initially painted black or white.
You are given a vector <string> board.
The character board[i][j] represents the cell with coordinates (i, j).
Each of those characters is either 'B' (representing a black cell) or 'W' (representing a white cell).
The game is played in turns.
In each turn Fred can choose any row of the board and repaint all black cells of the row to white, and vice versa.
(Note that he can only select rows, not columns. 
Formally, he can choose an index i and change all characters of board[i].)




Fred wants to have a large white square somewhere on his board.
The sides of Fred's square must be parallel to the sides of the board.
The white square may be a part of a larger white area. 
(I.e., the cells that touch the square may be both black and white.)
Find a sequence of turns that produces the largest possible white square somewhere on the board, and return the area of that square.


DEFINITION
Class:AlienAndGame
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character in each element of board will be either 'B' or 'W'.


EXAMPLES

0)
{"BB",
 "WW"}

Returns: 4

The optimal strategy is to repaint row 0. After this change the entire board will be white, and thus we have a 2*2 white square.

1)
{"W"}

Returns: 1

Sometimes the optimal strategy requires no repainting.

2)
{"WBBB",
 "WBBB",
 "WWWW"}

Returns: 9

We should repaint row 0 and then repaint row 1. 
The resulting board will contain a 3*3 white square (in rows 0-2 and columns 1-3).

3)
{"W",
 "B",
 "W",
 "W",
 "W"}

Returns: 1



4)
{"BWBBWBB",
 "WWBWWBW",
 "BBBBBBW",
 "WBBBBWB",
 "BBWWWWB",
 "WWWWWWW",
 "BBWWBBB"}

Returns: 9



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

int n, m;

bool isok(int i, int j, int s, vector<string> board)
{
    for (int x = i; x < i + s; ++x) {
        for (int y = j + 1; y < j + s; ++y) {
            if (board[x][y] != board[x][y - 1]) return false;
        }
    }
    return true;
}

bool isok(int s, vector<string> board)
{
    for (int i = 0; i + s <= n; ++i) {
        for (int j = 0; j + s <= m; ++j) {
            if (isok(i, j, s, board)) {
                return true;
            }
        }
    }
    return false;
}

class AlienAndGame {
public:
    int getNumber(vector <string> board) {
        n = sz(board);
        m = sz(board[0]);
        int ans = min(n, m);
        while (1) {
            if (isok(ans, board)) return ans * ans;
            --ans;
        }
        return ans;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string boardARRAY[] = {"BB",
            "WW"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(0, theObject.getNumber(board),4);
    }
    {
        string boardARRAY[] = {"W"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(1, theObject.getNumber(board),1);
    }
    {
        string boardARRAY[] = {"WBBB",
            "WBBB",
            "WWWW"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(2, theObject.getNumber(board),9);
    }
    {
        string boardARRAY[] = {"W",
            "B",
            "W",
            "W",
            "W"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(3, theObject.getNumber(board),1);
    }
    {
        string boardARRAY[] = {"BWBBWBB",
            "WWBWWBW",
            "BBBBBBW",
            "WBBBBWB",
            "BBWWWWB",
            "WWWWWWW",
            "BBWWBBB"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(4, theObject.getNumber(board),9);
    }
	return 0;
}
// END CUT HERE
