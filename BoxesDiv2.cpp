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

class BoxesDiv2
{
public:
	int findSize(vector <int> candyCounts);
};

int gao(int i)
{
    int ret = 1;
    while (ret < i) {
        ret <<= 1;
    }
    return ret;
}

int BoxesDiv2::findSize(vector <int> candyCounts)
{
    vector<int> v;
    for (int i = 0; i < sz(candyCounts); ++i) {
        v.push_back(gao(candyCounts[i]));
    }
    while (v.size() > 1) {
        sort(all(v));
        int a = v[0], b = v[1];
        v.erase(v.begin());
        v.erase(v.begin());
        v.push_back(b << 1);
    }
    return v[0];
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Today is Fox Ciel's birthday.
You want to give her a box of candies as a present.

You have candies of several different types.
You are given a vector <int> candyCounts.
Each element of candyCounts is the number of candies of one particular type.

For each non-negative integer i, you have an unlimited supply of boxes with volume 2^i.
That is, you have boxes with volume 1, 2, 4, 8, and so on.

You are going to pack the candies into boxes.
Each type of candies has to be packed into a single box, and you have to use different boxes for different types of candy.
The volume of a box must be greater than or equal to the number of candies it contains.

Once you have each type of candies in a box, you want to pack those boxes into larger boxes, until only one box remains.
You can only pack two boxes at a time.
That is, you can take any two boxes you currently have, get a new box, and put the two old boxes into the new box.
This is possible if and only if the volume of the new box is greater than or equal to the sum of volumes of the two old boxes.
You always get to choose which two boxes you want to pack together, and how large the new box should be.

To summarize:

First, you will pack all the candies into boxes.
Then, you will pack all those boxes into larger boxes, until you are left with a single box that contains everything.


Compute and return the smallest possible volume of the box obtained at the end of packing.


DEFINITION
Class:BoxesDiv2
Method:findSize
Parameters:vector <int>
Returns:int
Method signature:int findSize(vector <int> candyCounts)


NOTES
-You may assume that the return value always fits into a signed 32-bit integer variable.


CONSTRAINTS
-candyCounts will contain between 1 and 100 elements, inclusive.
-Each element of candyCounts will be between 1 and 1000, inclusive.


EXAMPLES

0)
{8,8}

Returns: 16

First, you pack each type of candies into a box with volume 8. Then, you pack the two boxes into a single box with volume 16.

1)
{5,6}

Returns: 16

Even though you have fewer candies than in Example 0, you still have to use boxes with volume 8 (or more) to store them.

2)
{1,7}

Returns: 16

Now you could pack the 1 candy into a smaller box, but it will not help: you still have to use a box with volume 16 to store the two boxes with candies.

3)
{1,1,13,1,1}

Returns: 32



4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}

Returns: 1024



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
        int candyCountsARRAY[] = {8,8};
        vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
        BoxesDiv2 theObject;
        eq(0, theObject.findSize(candyCounts),16);
    }
    {
        int candyCountsARRAY[] = {5,6};
        vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
        BoxesDiv2 theObject;
        eq(1, theObject.findSize(candyCounts),16);
    }
    {
        int candyCountsARRAY[] = {1,7};
        vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
        BoxesDiv2 theObject;
        eq(2, theObject.findSize(candyCounts),16);
    }
    {
        int candyCountsARRAY[] = {1,1,13,1,1};
        vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
        BoxesDiv2 theObject;
        eq(3, theObject.findSize(candyCounts),32);
    }
    {
        int candyCountsARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
        vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
        BoxesDiv2 theObject;
        eq(4, theObject.findSize(candyCounts),1024);
    }
}
// END CUT HERE
