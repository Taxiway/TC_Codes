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

class SlimeXSlimonadeTycoon
{
public:
	int sell(vector <int> morning, vector <int> customers, int stale_limit);
};

int SlimeXSlimonadeTycoon::sell(vector <int> morning, vector <int> customers, int stale_limit)
{
    queue<int> q;
    int total = 0;
    for (int i = 0; i < sz(morning); ++i) {
        if (q.size() >= stale_limit) q.pop();
        q.push(morning[i]);
        int need = customers[i];
        while (!q.empty()) {
            if (q.front() >= need) {
                q.front() -= need;
                total += need;
                break;
            } else {
                total += q.front();
                need -= q.front();
                q.pop();
            }
        }
    }
    return total;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You are playing a game called Slime Tycoon.
You will be selling Slimonades in this game, and your goal is to sell as many as you can.

The game will consist of N game days, numbered 0 through N-1 in order.
You are given two vector <int>s morning and customers with N elements each, and an int stale_limit.
These represent constraints on how many Slimonades you can produce and sell, as explained below.

In each game day, three things happen, in the following order:

Early in the morning of day i: All Slimonades that were produced stale_limit days ago (i.e., on day i-stale_limit) go stale. You cannot sell stale Slimonades, you must throw them away immediately.
During day i: You can produce at most morning[i] new Slimonades. (Formally, you choose an integer X between 0 and morning[i], inclusive, and produce X Slimonades.)
In the evening of day i: You can sell at most customers[i] Slimonades. (That is, if you have at most customers[i] Slimonades, you sell all of them. Otherwise, you sell exactly customers[i] Slimonades. In that case, you get to choose which Slimonades you sell and which ones you keep for later days.)


What is the maximum total number of Slimonades that you can sell during these N days?

DEFINITION
Class:SlimeXSlimonadeTycoon
Method:sell
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int sell(vector <int> morning, vector <int> customers, int stale_limit)


CONSTRAINTS
-morning will contain between 2 and 50 elements, inclusive.
-Each element of morning will be between 0 and 10000, inclusive.
-customers will contain the same number of elements as morning.
-Each element of customers will be between 0 and 10000, inclusive.
-stale_limit will be between 1 and N, inclusive.


EXAMPLES

0)
{5, 1, 1}
{1, 2, 3}
2

Returns: 5

Here's one optimal solution.

Day 0: We produce 4 Slimonades, then sell 1 of them.
Day 1: We produce 1 Slimonade (so now we have 4). In the evening, we sell two of the Slimonades that were made yesterday.
Day 2: We still have one Slimonade that was made on day 0. It goes stale and we throw it away. We produce one more Slimonade. In the evening, we sell 2 Slimonades (the one made yesterday and the one made today).


1)
{10, 20, 30}
{30, 20, 10}
1

Returns: 40

As stale_limit=1, each evening we can only sell Slimonades made during that day. Hence, we can sell at most 10 Slimonades on day 0, 20 on day 1, and 10 on day 2.

2)
{1, 2, 3, 4, 5}
{5, 5, 5, 5, 5}
5

Returns: 15



3)
{10000, 0, 0, 0, 0, 0, 0}
{1, 2, 4, 8, 16, 32, 64}
4

Returns: 15



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
        int morningARRAY[] = {5, 1, 1};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {1, 2, 3};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(0, theObject.sell(morning, customers, 2),5);
    }
    {
        int morningARRAY[] = {10, 20, 30};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {30, 20, 10};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(1, theObject.sell(morning, customers, 1),40);
    }
    {
        int morningARRAY[] = {1, 2, 3, 4, 5};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {5, 5, 5, 5, 5};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(2, theObject.sell(morning, customers, 5),15);
    }
    {
        int morningARRAY[] = {10000, 0, 0, 0, 0, 0, 0};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {1, 2, 4, 8, 16, 32, 64};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(3, theObject.sell(morning, customers, 4),15);
    }
}
// END CUT HERE
