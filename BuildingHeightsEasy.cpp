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

class BuildingHeightsEasy
{
public:
	int minimum(int M, vector <int> heights);
};

int BuildingHeightsEasy::minimum(int M, vector <int> heights)
{
    sort(all(heights));
    int best = 0x7FFFFFFF;
    for (int i = sz(heights) - 1; i >= M - 1; --i) {
        int ret = 0;
        for (int k = i - M + 1; k <= i; ++k) {
            ret += heights[i] - heights[k];
        }
        best = min(best, ret);
    }
    return best;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Byteland is a city with many skyscrapers, so it's a perfect venue for BASE jumping. Danilo is an enthusiastic BASE jumper. He plans to come to Byteland and to jump off some of its buildings.

Danilo wants to make M jumps in Byteland. However, he has some rules. First, he never jumps off the same building twice. Second, all buildings he selects for his jumps must have the same number of floors. (This is for safety reasons: It is hard to get the timing right if each jump starts at a different height.)

Philipe is the mayor of Byteland. He welcomes Danilo's visit as he would like to use it as a publicity stunt. However, Philipe knows that Danilo will only come to Byteland if there are at least M buildings that each have the same number of floors. To ensure that, the mayor is willing to build additional floors on some of the skyscrapers in Byteland.

You are given the int M and a vector <int> heights. Each element of heights is the number of floors in one of Byteland's skyscrapers. Compute and return the smallest number of additional floors the mayor has to build so that there will be at least M buildings with the same number of floors.

DEFINITION
Class:BuildingHeightsEasy
Method:minimum
Parameters:int, vector <int>
Returns:int
Method signature:int minimum(int M, vector <int> heights)


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive.
-M will be between 1 and the number of elements in heights, inclusive.
-Each element in heights will be between 1 and 50, inclusive.


EXAMPLES

0)
2
{1, 2, 1, 4, 3}

Returns: 0

Note that we already have two buildings that have the same number of floors. Hence, no additional floors need to be built.

1)
3
{1, 3, 5, 2, 1}

Returns: 2

We want to have at least three buildings with the same number of floors. The best way to reach this goal is to build one floor on building #0 and one floor on building #4 (0-based indices). After these changes, buildings #0, #3, and #4 will have two floors each.

2)
1
{43, 19, 15}

Returns: 0



3)
3
{19, 23, 9, 12}

Returns: 15



4)
12
{25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4}

Returns: 47



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
        int heightsARRAY[] = {1, 2, 1, 4, 3};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(0, theObject.minimum(2, heights),0);
    }
    {
        int heightsARRAY[] = {1, 3, 5, 2, 1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(1, theObject.minimum(3, heights),2);
    }
    {
        int heightsARRAY[] = {43, 19, 15};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(2, theObject.minimum(1, heights),0);
    }
    {
        int heightsARRAY[] = {19, 23, 9, 12};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(3, theObject.minimum(3, heights),15);
    }
    {
        int heightsARRAY[] = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(4, theObject.minimum(12, heights),47);
    }
}
// END CUT HERE
