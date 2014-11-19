// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Elly and Kris play the following game. In the beginning Kristina thinks of a number between 1 and 1,000,000,000, inclusive. After that Elly starts trying to guess it. In each round she says a number and Kristina says what is the absolute difference between the number she has thought of, and the number Elly guessed. Now Elly wonders if the guesses she has already made are sufficient to uniquely determine Kristina's number.

You are given a vector <int> guesses and a vector <int> answers of the same length. For each valid i, in round i of the game (0-based index) Elly guessed the number guesses[i] and Kristina answered answers[i]. If Kristina's number can be uniquely determined, return that number. If there are multiple possibilities that are consistent with the current set of guesses and answers, return -1. If it can be shown that at some point Kristina has lied (some of her answers were inconsistent), return -2.

DEFINITION
Class:EllysNumberGuessing
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getNumber(vector <int> guesses, vector <int> answers)


CONSTRAINTS
-guesses and answers will each contain between 1 and 50 elements, inclusive.
-guesses and answers will contain the same number of elements.
-Each element of guesses will be between 1 and 1,000,000,000, inclusive.
-Each element of answers will be between 1 and 999,999,999, inclusive.


EXAMPLES

0)
{600, 594}
{6, 12}

Returns: 606

Apparently Kristina has thought of the number of this SRM.

1)
{100, 50, 34, 40}
{58, 8, 8, 2}

Returns: 42

It is not guaranteed that Elly has used a perfect strategy so far.

2)
{500000, 600000, 700000}
{120013, 220013, 79987}

Returns: -2

The answers here are inconsistent. After the second guess we can conclude that the answer is below 500000. But the third one indicates that it is above 500000. Thus, Kristina is a liar and you should return -2.

3)
{500000000}
{133742666}

Returns: -1

There are multiple possibilities here, thus you should return -1.

4)
{76938260, 523164588, 14196746, 296286419, 535893832,
 41243148, 364561227, 270003278, 472017422, 367932361,
 395758413, 301278456, 186276934, 316343129, 336557549,
 52536121, 98343562, 356769915, 89249181, 335191879}
{466274085, 20047757, 529015599, 246925926, 7318513,
 501969197, 178651118, 273209067, 71194923, 175279984,
 147453932, 241933889, 356935411, 226869216, 206654796,
 490676224, 444868783, 186442430, 453963164, 208020466}

Returns: 543212345



5)
{42}
{42}

Returns: 84

Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.

6)
{999900000}
{100001}

Returns: 999799999

Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.

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

bool isok(int num, vector<int> g, vector<int> a)
{
    if (num < 1 || num > 1000000000) return false;
    for (int i = 0; i < sz(g); ++i) {
        if (abs(num - g[i]) != a[i]) return false;
    }
    return true;
}

class EllysNumberGuessing {
public:
    int getNumber(vector <int> guesses, vector <int> answers) {
        set <int> ans = set<int>();
        for (int i = 0; i < sz(guesses); ++i) {
            if (isok(guesses[i] - answers[i], guesses, answers)) {
                ans.insert(guesses[i] - answers[i]);
            }
            if (isok(guesses[i] + answers[i], guesses, answers)) {
                ans.insert(guesses[i] + answers[i]);
            }
        }
        if (ans.size() == 1) {
            return *ans.begin();
        }
        else if (ans.size() > 1) {
            return -1;
        }
        else {
            return -2;
        }
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int guessesARRAY[] = {600, 594};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {6, 12};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(0, theObject.getNumber(guesses, answers),606);
    }
    {
        int guessesARRAY[] = {100, 50, 34, 40};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {58, 8, 8, 2};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(1, theObject.getNumber(guesses, answers),42);
    }
    {
        int guessesARRAY[] = {500000, 600000, 700000};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {120013, 220013, 79987};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(2, theObject.getNumber(guesses, answers),-2);
    }
    {
        int guessesARRAY[] = {500000000};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {133742666};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(3, theObject.getNumber(guesses, answers),-1);
    }
    {
        int guessesARRAY[] = {76938260, 523164588, 14196746, 296286419, 535893832,
            41243148, 364561227, 270003278, 472017422, 367932361,
            395758413, 301278456, 186276934, 316343129, 336557549,
            52536121, 98343562, 356769915, 89249181, 335191879};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {466274085, 20047757, 529015599, 246925926, 7318513,
            501969197, 178651118, 273209067, 71194923, 175279984,
            147453932, 241933889, 356935411, 226869216, 206654796,
            490676224, 444868783, 186442430, 453963164, 208020466};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(4, theObject.getNumber(guesses, answers),543212345);
    }
    {
        int guessesARRAY[] = {42};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {42};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(5, theObject.getNumber(guesses, answers),84);
    }
    {
        int guessesARRAY[] = {999900000};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {100001};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(6, theObject.getNumber(guesses, answers),999799999);
    }
	return 0;
}
// END CUT HERE
