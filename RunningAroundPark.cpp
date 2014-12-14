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

class RunningAroundPark
{
public:
	int numberOfLap(int N, vector <int> d);
};

int RunningAroundPark::numberOfLap(int N, vector <int> d)
{
	int ret = 1;
	for (int i = 1; i < sz(d); ++i) {
		if (d[i] <= d[i - 1]) ++ret;
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Alice went jogging around the park yesterday.
There is a circular track around the park, and Alice's house is right next to the track.
Alice ran in the clockwise direction.
She both started and ended her run at her house.
In other words, she completed some positive number of full laps.



There are N trees along the track.
The trees are numbered 1 through N in the order in which Alice encounters them when running a single lap.
You are given the int N.



Alice remembers some trees she saw during her run.
She remembers them in the order in which she encountered them.
You are given this information as a vector <int> d.



For example, d={6,6,1} has the following meaning:

Alice started running.
After some time she encountered the tree number 6.
After some more time she encountered the tree number 6.
Even later she encountered the tree number 1.




Compute and return the smallest possible number of laps Alice completed.


DEFINITION
Class:RunningAroundPark
Method:numberOfLap
Parameters:int, vector <int>
Returns:int
Method signature:int numberOfLap(int N, vector <int> d)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-d will contain between 1 and 50 elements.
-Each element of d will be between 1 and N, inclusive.


EXAMPLES

0)
3
{1,2,3}

Returns: 1

It is possible that Alice ran just a single lap and remembered all the trees she saw.

1)
24
{6,6}

Returns: 2

Alice ran past the tree number 6 at least twice, so there must have been at least two laps.

2)
3
{3,2,1}

Returns: 3



3)
50
{1,3,5,7,9,2,4,6,8,10}

Returns: 2



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
        int dARRAY[] = {1,2,3};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(0, theObject.numberOfLap(3, d),1);
    }
    {
        int dARRAY[] = {6,6};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(1, theObject.numberOfLap(24, d),2);
    }
    {
        int dARRAY[] = {3,2,1};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(2, theObject.numberOfLap(3, d),3);
    }
    {
        int dARRAY[] = {1,3,5,7,9,2,4,6,8,10};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(3, theObject.numberOfLap(50, d),2);
    }
}
// END CUT HERE
