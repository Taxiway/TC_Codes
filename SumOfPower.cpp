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

class SumOfPower
{
public:
	int findSum(vector <int> array);
};

int SumOfPower::findSum(vector <int> array)
{
    int ret = 0;
    for (int i = 0; i < sz(array); ++i) {
        int left = i, right = sz(array) - i - 1;
        ret += array[i] * (left + 1) * (right + 1);
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
You are given a vector <int> array.
At any moment, you may choose a nonempty contiguous subsequence of array.
Whenever you do so, you will gain power equal to the sum of all elements in the chosen subsequence.



You chose each possible contiguous subsequence exactly once, each time gaining some power.
Compute and return the total amount of power you gained.


DEFINITION
Class:SumOfPower
Method:findSum
Parameters:vector <int>
Returns:int
Method signature:int findSum(vector <int> array)


CONSTRAINTS
-array will contain between 1 and 50 elements, inclusive.
-Each element in array will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,2}

Returns: 6

We have the following three contiguous subsequences:

 {1} => 1 
 {2} => 2 
 {1,2} => 3 

Thus, the sum of all possible powers is 1+2+3=6.

1)
{1,1,1}

Returns: 10

A 3-element sequence has 6 possible nonempty contiguous subsequences.
For the sequence {1,1,1} these are the subsequences: {1}, {1}, {1}, {1,1}, {1,1}, and {1,1,1}.
Their sums are 1, 1, 1, 2, 2, and 3.
If you choose each of them once, the total power you'll gain is 1+1+1+2+2+3 = 10.

2)
{3,14,15,92,65}

Returns: 1323



3)
{1,2,3,4,5,6,7,8,9,10}

Returns: 1210



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
        int arrayARRAY[] = {1,2};
        vector <int> array( arrayARRAY, arrayARRAY+ARRSIZE(arrayARRAY) );
        SumOfPower theObject;
        eq(0, theObject.findSum(array),6);
    }
    {
        int arrayARRAY[] = {1,1,1};
        vector <int> array( arrayARRAY, arrayARRAY+ARRSIZE(arrayARRAY) );
        SumOfPower theObject;
        eq(1, theObject.findSum(array),10);
    }
    {
        int arrayARRAY[] = {3,14,15,92,65};
        vector <int> array( arrayARRAY, arrayARRAY+ARRSIZE(arrayARRAY) );
        SumOfPower theObject;
        eq(2, theObject.findSum(array),1323);
    }
    {
        int arrayARRAY[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> array( arrayARRAY, arrayARRAY+ARRSIZE(arrayARRAY) );
        SumOfPower theObject;
        eq(3, theObject.findSum(array),1210);
    }
}
// END CUT HERE
