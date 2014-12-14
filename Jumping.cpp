// Orz AekdyCoin ∏£¥Û∫ÀŒ‰æ∞»Û∫Û»À

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

class Jumping
{
public:
	string ableToGet(int x, int y, vector <int> jumpLengths);
};

string Jumping::ableToGet(int x, int y, vector <int> jumpLengths)
{
	sort(all(jumpLengths), greater<int>());
	long long from = jumpLengths[0], to = jumpLengths[0];
	for (int i = 1; i < sz(jumpLengths); ++i) {
		int now = jumpLengths[i];
		if (from <= now && now <= to) {
			to += now;
			from = 0;
		} else {
			from -= now;
			to += now;
		}
	}
	if (from * from > x * x + y * y || to * to < x * x + y * y) {
		return "Not able";
	} else {
		return "Able";
	}
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Frog Suwako lives on a two-dimensional plane.
She likes to jump.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, y).
You are given the ints x and y.



Suwako wants to reach the desired destination in a specific way: using a series of jumps with pre-determined lengths.
You are given these lengths in a vector <int> jumpLenghts.
For example, if jumpLengths = { 2, 5 }, Suwako must make a jump of length exactly 2, followed by a jump of length exactly 5.



Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.
Return "Able" (quotes for clarity) if Suwako is able to reach her desired destination from (0, 0) using the desired sequence of jump lengths.
Otherwise, return "Not able".

DEFINITION
Class:Jumping
Method:ableToGet
Parameters:int, int, vector <int>
Returns:string
Method signature:string ableToGet(int x, int y, vector <int> jumpLengths)


CONSTRAINTS
-x will be between -1,000 and 1,000, inclusive.
-y will be between -1,000 and 1,000, inclusive.
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000, inclusive.


EXAMPLES

0)
5
4
{2, 5}

Returns: "Able"

One possibility is to jump from (0, 0) to (2, 0), and then from (2, 0) to (5, 4).

1)
3
4
{4}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 4 - it is too short.

2)
3
4
{6}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 6 - it is too long.

3)
0
1
{100, 100}

Returns: "Able"

Here, one possible solution looks as follows: Let t = sqrt(100*100 - 0.5*0.5). Suwoko will make her first jump from (0, 0) to (t, 0.5), and her second jump from (t, 0.5) to (0, 1).

4)
300
400
{500}

Returns: "Able"



5)
11
12
{1,2,3,4,5,6,7,8,9,10}

Returns: "Able"



6)
11
12
{1,2,3,4,5,6,7,8,9,100}

Returns: "Not able"



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
        int jumpLengthsARRAY[] = {2, 5};
        vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
        Jumping theObject;
        eq(0, theObject.ableToGet(5, 4, jumpLengths),"Able");
    }
    {
        int jumpLengthsARRAY[] = {4};
        vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
        Jumping theObject;
        eq(1, theObject.ableToGet(3, 4, jumpLengths),"Not able");
    }
    {
        int jumpLengthsARRAY[] = {6};
        vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
        Jumping theObject;
        eq(2, theObject.ableToGet(3, 4, jumpLengths),"Not able");
    }
    {
        int jumpLengthsARRAY[] = {100, 100};
        vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
        Jumping theObject;
        eq(3, theObject.ableToGet(0, 1, jumpLengths),"Able");
    }
    {
        int jumpLengthsARRAY[] = {500};
        vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
        Jumping theObject;
        eq(4, theObject.ableToGet(300, 400, jumpLengths),"Able");
    }
    {
        int jumpLengthsARRAY[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
        Jumping theObject;
        eq(5, theObject.ableToGet(11, 12, jumpLengths),"Able");
    }
    {
        int jumpLengthsARRAY[] = {1,2,3,4,5,6,7,8,9,100};
        vector <int> jumpLengths( jumpLengthsARRAY, jumpLengthsARRAY+ARRSIZE(jumpLengthsARRAY) );
        Jumping theObject;
        eq(6, theObject.ableToGet(11, 12, jumpLengths),"Not able");
    }
}
// END CUT HERE
