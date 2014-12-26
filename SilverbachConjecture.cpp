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

class SilverbachConjecture
{
public:
	vector <int> solve(int n);
};

bool isok(int n)
{
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}

vector <int> SilverbachConjecture::solve(int n)
{
    vector<int> v;
    for (int i = 4; ; ++i) {
        if (isok(i) && isok(n - i)) {
            v.push_back(i);
            v.push_back(n - i);
            break;
        }
    }
    return v;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// In this problem, some test cases have more than one correct output. We are using a special checker to verify that the output of your program is correct.

A positive integer x is called composite if there are positive integers y > 1 and z > 1 such that x = yz.
In other words, a composite positive integer has a positive integer divisor other than 1 and itself.
For example, 48 is composite because 48 = 4*12.
The smallest few composite integers are 4, 6, 8, 9, and 10.

You are given an int n.
Return a vector <int> with two elements.
Both elements of the returned vector <int> must be positive composite integers, and their sum must be n.

For the given constraints on n at least one such pair always exists.
Note that if there are many such pairs, your solution can return any one of them.

DEFINITION
Class:SilverbachConjecture
Method:solve
Parameters:int
Returns:vector <int>
Method signature:vector <int> solve(int n)


CONSTRAINTS
-n will be between 20 and 2000, inclusive.


EXAMPLES

0)
20

Returns: {8, 12 }

For n=20 there are seven correct answers: {4,16}, {6,14}, {8,12}, {10,10}, {12,8}, {14,6}, and {16,4}. Your program must return one of these seven answers.

1)
30

Returns: {15, 15 }

You may return two identical numbers.

2)
999

Returns: {699, 300 }



3)
45

Returns: {15, 30 }



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
        int retrunValueARRAY[] = {8, 12 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(0, theObject.solve(20),retrunValue);
    }
    {
        int retrunValueARRAY[] = {15, 15 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(1, theObject.solve(30),retrunValue);
    }
    {
        int retrunValueARRAY[] = {699, 300 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(2, theObject.solve(999),retrunValue);
    }
    {
        int retrunValueARRAY[] = {15, 30 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(3, theObject.solve(45),retrunValue);
    }
}
// END CUT HERE
