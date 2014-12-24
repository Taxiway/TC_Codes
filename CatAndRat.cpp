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

class CatAndRat
{
public:
	double getTime(int R, int T, int Vrat, int Vcat);
};

double CatAndRat::getTime(int R, int T, int Vrat, int Vcat)
{
    double PI= acos(-1.0);
    double half = R * PI;
    double d = Vrat * T;
    if (d >= half) d = half;
    if (Vcat <= Vrat) return -1;
    else return d / (Vcat - Vrat);
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// We have a circular tube.
At one point the tube has an entrance.

At time 0, a rat enters the tube via the entrance.
The rat can move inside the tube in both directions (clockwise and counterclockwise).
The rat can change direction in an instant.
Its maximum speed is Vrat.

At time T, the cat will enter the tube via the same entrance.
The cat can also move in both directions and change its direction instantly.
Its maximum speed is Vcat.

For the purpose of this problem, you should imagine the tube as a circle with radius R, and the rat and the cat as points on said circle.

The cat is trying to catch the rat as quickly as possible.
The rat is trying not to be caught, and if that is impossible, to be caught as late as possible.
At any time (starting at time 0) the cat and the rat know each other's position.
Already at time 0 the rat knows the time T.
Assume that both the cat and the rat behave optimally.

You are given the ints R, T, Vrat, and Vcat.
If the cat will catch the rat successfully, return how much time it'll take the cat to catch the rat.
Otherwise, return -1.0.

DEFINITION
Class:CatAndRat
Method:getTime
Parameters:int, int, int, int
Returns:double
Method signature:double getTime(int R, int T, int Vrat, int Vcat)


NOTES
-The cat and rat cannot leave the tube.
-Your return value must have a relative or absolute error less than 1e-9.


CONSTRAINTS
-R, T, Vrat, and Vcat will each be between 1 and 1000, inclusive.


EXAMPLES

0)
10
1
1
1

Returns: -1.0

The rat can survive. During the first unit of time it has to run away from the entrance. Then, once the cat enters the tube, the rat can always run in the same direction and with the same speed as the cat.

1)
10
1
1
2

Returns: 1.0

The cat is now faster than the rat.
The best strategy for the rat is to enter the tube and to start running in either direction at its maximum speed.
The cat will then enter the tube, run in the same direction as the rat, and catch it in exactly 1 unit of time.

2)
10
1
2
1

Returns: -1.0

The rat is now faster than the cat. It can survive, for example by using the strategy described in Example 0.

3)
1000
1000
1
1000

Returns: 1.001001001001001



4)
1
1000
1
2

Returns: 3.141592653589793



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
        CatAndRat theObject;
        eq(0, theObject.getTime(10, 1, 1, 1),-1.0);
    }
    {
        CatAndRat theObject;
        eq(1, theObject.getTime(10, 1, 1, 2),1.0);
    }
    {
        CatAndRat theObject;
        eq(2, theObject.getTime(10, 1, 2, 1),-1.0);
    }
    {
        CatAndRat theObject;
        eq(3, theObject.getTime(1000, 1000, 1, 1000),1.001001001001001);
    }
    {
        CatAndRat theObject;
        eq(4, theObject.getTime(1, 1000, 1, 2),3.141592653589793);
    }
}
// END CUT HERE
