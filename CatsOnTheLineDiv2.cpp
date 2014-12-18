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

class CatsOnTheLineDiv2
{
public:
	string getAnswer(vector <int> position, vector <int> count, int time);
};

string CatsOnTheLineDiv2::getAnswer(vector <int> position, vector <int> count, int time)
{
    vector<pair<int, int> > vp;
    for (int i = 0; i < sz(position); ++i) {
        vp.push_back(make_pair(position[i], count[i]));
    }
    sort(all(vp));
    int limit = -100000;
    for (int i = 0; i < sz(vp); ++i) {
        int p = vp[i].first, n = vp[i].second;
        int left = p - time, right = p + time;
        left = max(left, limit + 1);
        if (right - left + 1 < n) return "Impossible";
        limit = left + n - 1;
    }
    return "Possible";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
There are some cats sitting on a straight line that goes from the left to the right.
You are given two vector <int>s position and count.
For each valid i, there are count[i] cats initially sitting at the point position[i].




During each minute, each cat chooses and performs one of three possible actions: it may stay in its place, move one unit to the left (i.e., from x to x-1), or move one unit to the right (i.e., from x to x+1).
(Note that there are no restrictions. In particular, different cats that are currently at the same point may make different choices.)




You are also given an int time.
The goal is to rearrange the cats in such a way that each point contains at most one cat.
Return "Possible" if it's possible to achive the goal in time minutes, and "Impossible" otherwise (quotes for clarity).


DEFINITION
Class:CatsOnTheLineDiv2
Method:getAnswer
Parameters:vector <int>, vector <int>, int
Returns:string
Method signature:string getAnswer(vector <int> position, vector <int> count, int time)


CONSTRAINTS
-position will contain between 1 and 50 elements, inclusive.
-position and count will contain the same number of elements.
-Each element of position will be between -1000 and 1000, inclusive.
-All elements of position will be distinct.
-Each element of count will be between 1 and 1000, inclusive.
-time will be between 0 and 1000, inclusive.


EXAMPLES

0)
{0}
{7}
3

Returns: "Possible"

There are 7 cats sitting at the origin in this case. There are also 7 different points that cats can reach in 3 minutes, so each cat can occupy a unique point. Thus, the answer is "Possible".

1)
{0}
{8}
2

Returns: "Impossible"

Unlike the first test case, in this case there are 8 cats for 7 available points. Thus, the answer is "Impossible".

2)
{0, 1}
{3, 1}
0

Returns: "Impossible"



3)
{5, 0, 2}
{2, 3, 5}
2

Returns: "Impossible"



4)
{5, 1, -10, 7, 12, 2, 10, 20}
{3, 4, 2, 7, 1, 4, 3, 4}
6

Returns: "Possible"



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
        int positionARRAY[] = {0};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        int countARRAY[] = {7};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        CatsOnTheLineDiv2 theObject;
        eq(0, theObject.getAnswer(position, count, 3),"Possible");
    }
    {
        int positionARRAY[] = {0};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        int countARRAY[] = {8};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        CatsOnTheLineDiv2 theObject;
        eq(1, theObject.getAnswer(position, count, 2),"Impossible");
    }
    {
        int positionARRAY[] = {0, 1};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        int countARRAY[] = {3, 1};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        CatsOnTheLineDiv2 theObject;
        eq(2, theObject.getAnswer(position, count, 0),"Impossible");
    }
    {
        int positionARRAY[] = {5, 0, 2};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        int countARRAY[] = {2, 3, 5};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        CatsOnTheLineDiv2 theObject;
        eq(3, theObject.getAnswer(position, count, 2),"Impossible");
    }
    {
        int positionARRAY[] = {5, 1, -10, 7, 12, 2, 10, 20};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        int countARRAY[] = {3, 4, 2, 7, 1, 4, 3, 4};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        CatsOnTheLineDiv2 theObject;
        eq(4, theObject.getAnswer(position, count, 6),"Possible");
    }
}
// END CUT HERE
