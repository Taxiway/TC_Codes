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

class MountainRanges
{
public:
	int countPeaks(vector <int> heights);
};

int MountainRanges::countPeaks(vector <int> heights)
{
	if (sz(heights) == 1) return 1;
	int ret = 0;
	for (int i = 1; i + 1 < sz(heights); ++i) {
		if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) ++ret;
	}
	if (heights[0] > heights[1]) ++ret;
	if (heights[sz(heights) - 1] > heights[sz(heights) - 2]) ++ret;
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Tom is in charge of a tourist agency.
He has a lovely picture of the local mountain range.
He would like to sell it to the tourists but first he needs to know how many peaks are visible in the picture.



The mountain range in the picture can be seen as a sequence of heights.
You are given these heights as a vector <int> height.
An element of height is called a peak if its value is strictly greater than each of the values of adjacent elements.
Compute and return the number of peaks in the given mountain range.



DEFINITION
Class:MountainRanges
Method:countPeaks
Parameters:vector <int>
Returns:int
Method signature:int countPeaks(vector <int> heights)


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive.
-Each element of heights will be between 1 and 100, inclusive.


EXAMPLES

0)
{5, 6, 2, 4}

Returns: 2

Element 1 (0-based index) is a peak.
Its height is 6, which is strictly greater than each of its neighbors' heights (5 and 2). 
Element 3 is also a peak since its height is 4 and that is strictly greater than its neighbor's height (which is 2).

1)
{1, 1, 1, 1, 1, 1, 1}

Returns: 0

This is a very flat mountain with no peaks.

2)
{2, 1}

Returns: 1

Element 0 is a peak.

3)
{2,5,3,7,2,8,1,3,1}

Returns: 4

The peaks here are the elements with 0-based indices 1, 3, 5, and 7. Their heights are 5, 7, 8, and 3, respectively.

4)
{1}

Returns: 1

Element 0 is a peak. Even though it has no neighbors, the condition from the problem statement is still satisfied.

5)
{1,2,3,4,4,3,2,1}

Returns: 0

According to our definition there is no peak in this mountain range.

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
        int heightsARRAY[] = {5, 6, 2, 4};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        MountainRanges theObject;
        eq(0, theObject.countPeaks(heights),2);
    }
    {
        int heightsARRAY[] = {1, 1, 1, 1, 1, 1, 1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        MountainRanges theObject;
        eq(1, theObject.countPeaks(heights),0);
    }
    {
        int heightsARRAY[] = {2, 1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        MountainRanges theObject;
        eq(2, theObject.countPeaks(heights),1);
    }
    {
        int heightsARRAY[] = {2,5,3,7,2,8,1,3,1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        MountainRanges theObject;
        eq(3, theObject.countPeaks(heights),4);
    }
    {
        int heightsARRAY[] = {1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        MountainRanges theObject;
        eq(4, theObject.countPeaks(heights),1);
    }
    {
        int heightsARRAY[] = {1,2,3,4,4,3,2,1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        MountainRanges theObject;
        eq(5, theObject.countPeaks(heights),0);
    }
}
// END CUT HERE
