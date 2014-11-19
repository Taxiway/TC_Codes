// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero is playing a game on a directed graph.
The graph has N nodes, numbered 0 through N-1.
Each node of the graph has two associated probabilities: winprob[i] and loseprob[i].

At the beginning of the game, Hero takes a token and places it onto the node start.
The game then proceeds in turns.
Each turn consists of the following steps:

Let x be the node currently occupied by the token.
Hero picks a node y. The node y must either be the current node (i.e., y=x), or there must be an edge from x to y.
Hero moves the token from x to y.
One of three outcomes is chosen at random: With probability winprob[y] percent the game ends and Hero wins. With probability loseprob[y] percent the game ends and Hero loses. In all other cases (i.e., with probability 100-winprob[y]-loseprob[y] percent) the game continues.


You are given a vector <string> graph that describes the graph.
More precisely, for each valid i and j, graph[i][j] is '1' if there is an edge from i to j, and it is '0' otherwise.
Note that for all i, graph[i][i] is '1' to indicate that it is always allowed to stay in a node.
You are also given the vector <int>s winprob and loseprob, and the int start.
Assuming that Hero plays the game optimally, return a real number between 0 and 1, inclusive: the probability that he wins the game.

DEFINITION
Class:GraphWalkWithProbabilities
Method:findprob
Parameters:vector <string>, vector <int>, vector <int>, int
Returns:double
Method signature:double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start)


NOTES
-Your return value must have an absolute or a relative error less than 1e-9.
-Note that the input probabilities (winprob, loseprob) are given in percents but the return value is not.
-The constraints guarantee that with probability 1 the game will end.


CONSTRAINTS
-Number of elemets in graph is equal to number of nodes N.
-N will be between 1 and 50, inclusive.
-Each element of graph will contain exactly N characters.
-Each character in graph will be either '0' or '1'.
-graph[i][i] will be equal to '1' for all i between 0 and N-1, inclusive.
-winprob and loseprob will contain exactly N elements.
-Each element of winprob and loseprob will be between 0 and 100, inclusive.
-For each i, the sum of winprob[i] and loseprob[i] will be at least 1.
-start will be between 0 and N-1, inclusive.


EXAMPLES

0)
{"1"}
{1}
{1}
0

Returns: 0.5

In each turn, Hero has to stay in the only node. 
After each turn, he wins the game with probability 1% and loses the game with probability 1%.
By the symmetry of the situation, his overall probability of winning the game has to be 50%, hence the correct return value is 0.5.

Note that as the number of turns increases, the probability that the game is still going on decreases towards zero.
Specifically, the probability that the game still runs after k turns is 0.98^k.
Therefore, the probability of Hero playing the game forever without winning or losing it is 0.

1)
{"11","11"}
{60,40}
{40,60}
0

Returns: 0.6

At the first turn Hero can choose to stay at node 0 or to move token to node 1.
After he made choice game will end at the end of turn. First node has better probability of winning, so optimal play is to stay at node 0 and win with probability of 60 percents.

2)
{"11","11"}
{2,3}
{3,4}
0

Returns: 0.4285714285714286

Here optimal play is to move to node 1 at first turn and stay there until end of game, in this way answer is 3/7.

3)
{"110","011","001"}
{2,1,10}
{20,20,10}
0

Returns: 0.405

Nodes number 0 and 1 have too weak probability of winning, so Hero moves to node number 1 at first turn, to node 2 at second turn, and waits for end.

4)
{"111","111","011"}
{100,1,1}
{0,50,50}
2

Returns: 0.5



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
class GraphWalkWithProbabilities {
public:
    double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start) {
        double res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string graphARRAY[] = {"1"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {1};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {1};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(0, theObject.findprob(graph, winprob, looseprob, 0),0.5);
    }
    {
        string graphARRAY[] = {"11","11"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {60,40};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {40,60};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(1, theObject.findprob(graph, winprob, looseprob, 0),0.6);
    }
    {
        string graphARRAY[] = {"11","11"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {2,3};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {3,4};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(2, theObject.findprob(graph, winprob, looseprob, 0),0.4285714285714286);
    }
    {
        string graphARRAY[] = {"110","011","001"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {2,1,10};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {20,20,10};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(3, theObject.findprob(graph, winprob, looseprob, 0),0.405);
    }
    {
        string graphARRAY[] = {"111","111","011"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {100,1,1};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {0,50,50};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(4, theObject.findprob(graph, winprob, looseprob, 2),0.5);
    }
	return 0;
}
// END CUT HERE
