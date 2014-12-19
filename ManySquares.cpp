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

class ManySquares
{
public:
	int howManySquares(vector <int> sticks);
};

int ManySquares::howManySquares(vector <int> sticks)
{
    map<int, int> mp;
    for (int i = 0 ; i < sz(sticks); ++i) mp[sticks[i]]++;
    int ret = 0;
    for (map<int, int>::iterator mi = mp.begin(); mi != mp.end(); ++mi) {
        ret += mi->second / 4;
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You found a box from an old game.
The box contains a lot of sticks and a manual.
Frustrated by the fact the manual was unreadable, you decided to invent your own game with the sticks.
In your game, the goal is to use the sticks to build as many squares as possible.
There are only two rules:

Each stick can only be used in one square.
Each square must consist of exactly 4 sticks. That is, you cannot combine two or more sticks to create one side of the square.


You are given a vector <int> sticks.
The elements of sticks are the lengths of the sticks you have.
Return the maximum number of squares you can make.


DEFINITION
Class:ManySquares
Method:howManySquares
Parameters:vector <int>
Returns:int
Method signature:int howManySquares(vector <int> sticks)


NOTES
-If you can't make any square, return 0.


CONSTRAINTS
-sticks will contain between 1 and 50 elements.
-Each element of sticks will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,1,2,2,1,1,2}

Returns: 1

You can build a square with side 1.


1)
{3, 1, 4, 4, 4, 10, 10, 10, 10}


Returns: 1

You can build a square with side 10. You cannot build a square with side 4. (Note that you are not allowed to use 3+1 instead of a 4.)


2)
{1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3}

Returns: 3



3)
{1,1,1,2,2,2,3,3,3,4,4,4}

Returns: 0

Sometimes you can't make any square.


4)
{1,1,1,2,1,1,1,3,1,1,1}

Returns: 2



5)
{2,2,4,4,8,8}

Returns: 0

You are also not allowed to break the sticks.


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
        int sticksARRAY[] = {1,1,2,2,1,1,2};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(0, theObject.howManySquares(sticks),1);
    }
    {
        int sticksARRAY[] = {3, 1, 4, 4, 4, 10, 10, 10, 10}
           ;
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(1, theObject.howManySquares(sticks),1);
    }
    {
        int sticksARRAY[] = {1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(2, theObject.howManySquares(sticks),3);
    }
    {
        int sticksARRAY[] = {1,1,1,2,2,2,3,3,3,4,4,4};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(3, theObject.howManySquares(sticks),0);
    }
    {
        int sticksARRAY[] = {1,1,1,2,1,1,1,3,1,1,1};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(4, theObject.howManySquares(sticks),2);
    }
    {
        int sticksARRAY[] = {2,2,4,4,8,8};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(5, theObject.howManySquares(sticks),0);
    }
}
// END CUT HERE
