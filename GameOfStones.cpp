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

class GameOfStones
{
public:
	int count(vector <int> stones);
};

int GameOfStones::count(vector <int> stones)
{
	int sum = 0;
	for (int i = 0; i < sz(stones); ++i) sum += stones[i];
	int n = sz(stones);
	if (sum % n != 0) return -1;
	sum /= n;
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		int diff = abs(stones[i] - sum);
		if (diff % 2 != 0) return -1;
		ret += diff / 2;
	}
	return ret / 2;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Limak has found a large field with some piles of stones.

Limak likes perfection. It would make him happy if every pile had the same number of stones. He is now going to move some stones between the piles to make them all equal.

However, there is a catch.
Limak's perfectionism does not allow him to carry just one stone at a time.
As he has two hands, he must always carry exactly two stones: one in each hand.
Thus, he can only make one type of an action: pick up two stones from one of the piles and carry both of them to some other pile. He is not allowed to remove a pile completely. Therefore, he cannot pick up stones from a pile that currently contains fewer than 3 stones.

You are given a vector <int> stones.
Each element of stones is the initial number of stones in one of the piles.
Compute and return the smallest number of actions Limak has to perform in order to make all piles equal.
If it is impossible to make all piles equal using the allowed type of actions, return -1 instead.

DEFINITION
Class:GameOfStones
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> stones)


CONSTRAINTS
-stones will contain between 1 and 100 elements, inclusive. 
-Each element in stones will be between 1 and 100, inclusive.


EXAMPLES

0)
{7, 15, 9, 5}

Returns: 3

There are four piles of stones.
There are 7 stones in pile number 0, 15 stones in pile number 1, 9 stones in pile number 2, and 5 stones in pile number 3.
One optimal solution looks as follows:
First, Limak will move a pair of stones from pile 1 to pile 0.
Afterwards, Limak will twice move a pair of stones from pile 1 to pile 3.
After these 3 actions, each pile contains exactly 9 stones.

1)
{10, 16}

Returns: -1

It can be proven that Limak can't make these two piles equal.

2)
{2, 8, 4}

Returns: -1



3)
{17}

Returns: 0

Limak doesn't need to perform any actions. There is only one pile and it means that all piles already have the same size.

4)
{10, 15, 20, 12, 1, 20}

Returns: -1



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
        int stonesARRAY[] = {7, 15, 9, 5};
        vector <int> stones( stonesARRAY, stonesARRAY+ARRSIZE(stonesARRAY) );
        GameOfStones theObject;
        eq(0, theObject.count(stones),3);
    }
    {
        int stonesARRAY[] = {10, 16};
        vector <int> stones( stonesARRAY, stonesARRAY+ARRSIZE(stonesARRAY) );
        GameOfStones theObject;
        eq(1, theObject.count(stones),-1);
    }
    {
        int stonesARRAY[] = {2, 8, 4};
        vector <int> stones( stonesARRAY, stonesARRAY+ARRSIZE(stonesARRAY) );
        GameOfStones theObject;
        eq(2, theObject.count(stones),-1);
    }
    {
        int stonesARRAY[] = {17};
        vector <int> stones( stonesARRAY, stonesARRAY+ARRSIZE(stonesARRAY) );
        GameOfStones theObject;
        eq(3, theObject.count(stones),0);
    }
    {
        int stonesARRAY[] = {10, 15, 20, 12, 1, 20};
        vector <int> stones( stonesARRAY, stonesARRAY+ARRSIZE(stonesARRAY) );
        GameOfStones theObject;
        eq(4, theObject.count(stones),-1);
    }
}
// END CUT HERE
