// Orz AekdyCoin 福大核武景润后人

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <functional>
#include <cctype>
#include <string>

using namespace std;

#define all(X) (X).begin(), (X).end() 
#define sz(a) int((a).size())

typedef long long ll;

class CatchTheBeatEasy
{
public:
	string ableToCatchAll(vector <int> x, vector <int> y);
};

string CatchTheBeatEasy::ableToCatchAll(vector <int> x, vector <int> y)
{
    vector<pair<int, int> > v;
    for (int i = 0; i < sz(x); ++i) {
        v.push_back(make_pair(y[i], x[i]));
    }
    sort(all(v));
    int xx = 0, yy = 0;
    for (int i = 0; i < sz(v); ++i) {
        int nx = v[i].second, ny = v[i].first;
        if (ny - yy < abs(nx - xx)) {
            return "Not able to catch";
        }
        xx = nx;
        yy = ny;
    }
    return "Able to catch";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// One of the modes in the game "osu!" is called "catch the beat".
In this mode, you control a character that catches falling fruit.



The game is played in the vertical plane.
For simplicity, we will assume that both your character and all pieces of fruit are points in that plane.



You start the game at the coordinates (0, 0).
Your character can only move along the x-axis.
The maximum speed of your character is 1 unit of distance per second.
For example, you need at least 3 seconds to move from (-2, 0) to (1, 0).



You are given vector <int>s x and y that contain initial coordinates of the fruit you should catch:
for each valid i, there is one piece of fruit that starts at (x[i], y[i]).
All pieces of fruit fall down with constant speed of 1 unit of distance per second.
That is, a fruit currently located at (xf, yf) will move to (xf, yf-t) in t seconds.



You will catch a fruit if the character is located at the same point as the fruit at some moment in time.
Can you catch all the fruit in the game?
Return "Able to catch" (quotes for clarity) if you can, and "Not able to catch" otherwise.

DEFINITION
Class:CatchTheBeatEasy
Method:ableToCatchAll
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string ableToCatchAll(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-The elements in x will be between -1,000 and 1,000, inclusive.
-The elements in y will be between 0 and 1,000, inclusive.


EXAMPLES

0)
{-1, 1, 0}
{1, 3, 4}

Returns: "Able to catch"

In order to catch all three pieces of fruit, you have to follow this schedule (always walking at 1 unit per second):

Walk left for 1 second. When you reach (-1,0), catch the fruit that started at (-1,1).
Walk right for 2 seconds. When you reach (1,0), catch the fruit that started at (1,3).
Walk left for 1 second. When you reach (0,0), catch the fruit that started at (0,4).


1)
{-3}
{2}

Returns: "Not able to catch"

The only piece of fruit cannot be caught.
Even if you start moving left immediately, you will only reach (-2,0) by the time the fruit crosses the y axis.

2)
{-1, 1, 0}
{1, 2, 4}

Returns: "Not able to catch"



3)
{0, -1, 1}
{9, 1, 3}

Returns: "Able to catch"

You can catch the pieces of fruit in any order.
Also note that sometimes you'll want to move slower or wait at some location.
For example, after catching the pieces of fruit that started at (-1,1) and (1,3), you can walk to (0,0) and wait there for the third piece.

4)
{70,-108,52,-70,84,-29,66,-33}
{141,299,402,280,28,363,427,232}

Returns: "Not able to catch"



5)
{-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66}
{320,107,379,72,126,445,318,255,445,62,52,184,247,245,185}

Returns: "Able to catch"



6)
{0,0,0,0}
{0,0,0,0}

Returns: "Able to catch"

Different pieces of fruit may share the same position.
You can catch all the pieces at the same time.

*/

#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
void print(T a) {
	cerr << a;
}

void print(long long a) {
	cerr << a << "LL";
}

void print(string a) {
	cerr << '"' << a << '"';
}

template<typename T>
void print(vector<T> a) {
	cerr << "{";
	for (unsigned i = 0; i != a.size(); i++) {
		if (i != 0) cerr << ", ";
		print(a[i]);
	}
	cerr << "}" << endl;
}

template<typename T>
void eq(int n, T have, T need) {
	if (have == need) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print(need);
		cerr << " received ";
		print(have);
		cerr << "." << endl;
	}
}

template<typename T>
void eq(int n, vector<T> have, vector<T> need) {
	if(have.size() != need.size()) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print(have);
		print(need);
		return;
	}
	for(unsigned i = 0; i < have.size(); i++) {
		if(have[i] != need[i]) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print(have);
			print(need);
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}

void eq(int n, string have, string need) {
	if (have == need) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print(need);
		cerr << " received ";
		print(have);
		cerr << "." << endl;
	}
}

int main() {
    {
        int xARRAY[] = {-1, 1, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 3, 4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(0, theObject.ableToCatchAll(x, y),"Able to catch");
    }
    {
        int xARRAY[] = {-3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(1, theObject.ableToCatchAll(x, y),"Not able to catch");
    }
    {
        int xARRAY[] = {-1, 1, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 2, 4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(2, theObject.ableToCatchAll(x, y),"Not able to catch");
    }
    {
        int xARRAY[] = {0, -1, 1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {9, 1, 3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(3, theObject.ableToCatchAll(x, y),"Able to catch");
    }
    {
        int xARRAY[] = {70,-108,52,-70,84,-29,66,-33};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {141,299,402,280,28,363,427,232};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(4, theObject.ableToCatchAll(x, y),"Not able to catch");
    }
    {
        int xARRAY[] = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(5, theObject.ableToCatchAll(x, y),"Able to catch");
    }
    {
        int xARRAY[] = {0,0,0,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,0,0,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(6, theObject.ableToCatchAll(x, y),"Able to catch");
    }
}
// END CUT HERE
