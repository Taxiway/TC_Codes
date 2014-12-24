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

class FibonacciDiv2
{
public:
	int find(int N);
};

int FibonacciDiv2::find(int N)
{
    int a = 1, b = 1;
    while (b <= N) {
        int c = b + a;
        a = b;
        b = c;
    }
    return min(abs(N - a), abs(N - b));
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// The Fibonacci sequence is defined as follows:

F[0] = 0
F[1] = 1
for each i >= 2: F[i] = F[i-1] + F[i-2]

Thus, the Fibonacci sequence starts as follows: 0, 1, 1, 2, 3, 5, 8, 13, ...
The elements of the Fibonacci sequence are called Fibonacci numbers.

You're given an int N.
You want to change N into a Fibonacci number.
This change will consist of zero or more steps.
In each step, you can either increment or decrement the number you currently have.
That is, in each step you can change your current number X either to X+1 or to X-1.

Return the smallest number of steps needed to change N into a Fibonacci number.

DEFINITION
Class:FibonacciDiv2
Method:find
Parameters:int
Returns:int
Method signature:int find(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 0

The number 1 is already a Fibonacci number. No changes are necessary.

1)
13

Returns: 0

The number 13 is also a Fibonacci number.

2)
15

Returns: 2

The best way to change 15 into a Fibonacci number is to decrement it twice in a row (15 -> 14 -> 13).

3)
19

Returns: 2

You can increase it by 2 to get 21.

4)
1000000

Returns: 167960

This is the biggest possible number that you can get as input.

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
        FibonacciDiv2 theObject;
        eq(0, theObject.find(1),0);
    }
    {
        FibonacciDiv2 theObject;
        eq(1, theObject.find(13),0);
    }
    {
        FibonacciDiv2 theObject;
        eq(2, theObject.find(15),2);
    }
    {
        FibonacciDiv2 theObject;
        eq(3, theObject.find(19),2);
    }
    {
        FibonacciDiv2 theObject;
        eq(4, theObject.find(1000000),167960);
    }
}
// END CUT HERE
