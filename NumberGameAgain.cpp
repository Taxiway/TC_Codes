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

class NumberGameAgain
{
public:
	long long solve(int k, vector<long long> table);
};

long long p(int k, int d)
{
	long long ret = 1;
	for (int i = 0; i < (k - d); ++i) {
		ret <<= 1;
	}
	return ret - 1;
}

int getd(long long num)
{
	int ret = 0;
	while (num != 1) {
		num >>= 1;
		++ret;
	}
	return ret;
}

bool isroot(long long root, long long num)
{
	while (num > root) {
		num >>= 1;
	}
	return num == root;
}

long long NumberGameAgain::solve(int k, vector<long long> table)
{
	vector<int> ds;
	for (int i = 0; i < sz(table); ++i) {
		bool isok = true;
		for (int j = 0; j < sz(table); ++j) {
			if (j == i) continue;
			if (isroot(table[j], table[i])) {
				isok = false;
				break;
			}
		}
		if (isok) {
			ds.push_back(getd(table[i]));
		}
	}
	long long all = 1LL << k;
	all -= 2;
	for (int i = 0; i < sz(ds); ++i) {
		all -= p(k, ds[i]);
	}
	return all;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
In this problem, you are going to play a simple number game.
The rules of the game are as follows:

You have a single variable called x. Initially, x is set to 1.
In each step, you can change the value of x either to 2x or to 2x+1.
You are given a list of forbidden values. If at any moment your x is on the list, you lose the game.
You are also given a target value y. If at any moment your x is equal to y, you win the game. (Note that the previous item applies sooner: if y is forbidden, you lose the game when you reach it.)
If at any moment winning the game becomes impossible, you lose the game.




For example, assume that the forbidden values are 4 and 7, and the goal is 12.
You can win the game as follows: change x from 1 to 2*1+1=3, then from 3 to 2*3=6, and then from 6 to 2*6=12.



You are given a vector<long long> table.
The elements of table are the forbidden values.



You are also given a int k.
Consider all possible goals y between 2 and (2^k)-1, inclusive.
For how many of these goals is it possible to win the game?
Compute and return the answer to that question.


DEFINITION
Class:NumberGameAgain
Method:solve
Parameters:int, vector<long long>
Returns:long long
Method signature:long long solve(int k, vector<long long> table)


CONSTRAINTS
-k will be between 2 and 40, inclusive.
-The number of elements in table will be between 0 and 20, inclusive.
-all numbers in table will be between 2 and 2^k - 1, inclusive.
-all numbers in table will be distinct.


EXAMPLES

0)
3
{2,4,6}

Returns: 2

There are three forbidden values: 2, 4, and 6.
As k=3, we are considering y between 2 and (2^3)-1 = 7.
This is how the game would end for each of these y's:

For y=2 we cannot win the game because 2 is forbidden.
For y=3 we can win the game: we change x from 1 to 3.
For y=4 we cannot win the game because 4 is forbidden.
For y=5 we cannot win the game. We would need to change x from 1 to 2 and then from 2 to 5, but we cannot do that because 2 is forbidden.
For y=6 we cannot win the game because 6 is forbidden.
For y=7 we can win the game: we change x from 1 to 3, and then from 3 to 7.

Thus, within the specified range there are two values of y for which we can win the game.


1)
5
{2,3}

Returns: 0

In this case, we will always reach a forbidden value after the very first step of the game. Therefore, there is no y for which we can win the game.

2)
5
{}

Returns: 30

With no forbidden values we can win this game for any y between 2 and 31, inclusive.

3)
40
{2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}

Returns: 549755748288



4)
40
{}

Returns: 1099511627774



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
        long long tableARRAY[] = {2LL,4LL,6LL};
        vector<long long> table( tableARRAY, tableARRAY+ARRSIZE(tableARRAY) );
        NumberGameAgain theObject;
        eq(0, theObject.solve(3, table),2LL);
    }
    {
        long long tableARRAY[] = {2LL,3LL};
        vector<long long> table( tableARRAY, tableARRAY+ARRSIZE(tableARRAY) );
        NumberGameAgain theObject;
        eq(1, theObject.solve(5, table),0LL);
    }
    {
        NumberGameAgain theObject;
        eq(2, theObject.solve(5, vector<long long>()),30LL);
    }
    {
        long long tableARRAY[] = {2LL,4LL,8LL,16LL,32141531LL,2324577LL,1099511627775LL,2222222222LL,33333333333LL,4444444444LL,2135LL};
        vector<long long> table( tableARRAY, tableARRAY+ARRSIZE(tableARRAY) );
        NumberGameAgain theObject;
        eq(3, theObject.solve(40, table),549755748288LL);
    }
    {
        NumberGameAgain theObject;
        eq(4, theObject.solve(40, vector<long long>()),1099511627774LL);
    }
}
// END CUT HERE
