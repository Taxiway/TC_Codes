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

class ChooseTheBestOne
{
public:
	int countNumber(int N);
};

int ChooseTheBestOne::countNumber(int N)
{
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        v.push_back(i + 1);
    }
    int ind = 0, base = 1;
    while (v.size() > 1) {
        int n = v.size();
        int dis = (((base * base) % n) * base) % n;
        int next = (ind + dis + n - 1) % n;
        ind = next;
        v.erase(v.begin() + next);
        ++base;
        if (ind == v.size()) ind = 0;
    }
    return v[0];
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Shiny wants to give an award to one of the employees in her company.
However, all her employees are doing perfect work, so it's hard to pick the one that gets the award.
Therefore Shiny organized a game they will play to determine the winner.

At the beginning of the game, all N employees form a circle.
Then, they receive t-shirts with numbers 1 through N in clockwise order along the circle.
These numbers are never used in the game, we will just use them to identify the winner.

The game is played in turns.
The turns are numbered starting from 1.
In each turn, Shiny starts by standing in front of some employee (as specified below) and saying "one".
Then she moves clockwise along the circle to the next employee and says "two".
And so on, until the number she says reaches the threshold for that particular turn.
The threshold for turn number t is t^3.
(That is, the threshold is 1 for turn 1, 8 for turn 2, 27 for turn 3, and so on.)

At the end of each turn, the employee currently standing in front of Shiny (i.e., the one that received the number t^3) is eliminated.
In the very first round Shiny starts in front of the employee with the number 1 on their t-shirt.
In each of the following rounds, Shiny starts in front of the next employee clockwise from the one who just got eliminated.

When there is only one employee left in the game, the game ends and the employee wins the award.

You are given the int N.
Return the t-shirt number of the employee who gets the award.


DEFINITION
Class:ChooseTheBestOne
Method:countNumber
Parameters:int
Returns:int
Method signature:int countNumber(int N)


CONSTRAINTS
-N will between 1 and 5000, inclusive.


EXAMPLES

0)
3

Returns: 2

In the first round, Shiny stands in front of employee 1, says "one" and eliminates him.
In the second round, Shiny starts in front of employee 2. She says "one" to employee 2, "two" to
employee 3, "three" to employee 2 again, ..., and "eight" to employee 3. Thus, employee 3 
gets eliminated and employee 2 wins the award.


1)
6

Returns: 6



2)
10

Returns: 8



3)
1234

Returns: 341



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
        ChooseTheBestOne theObject;
        eq(0, theObject.countNumber(3),2);
    }
    {
        ChooseTheBestOne theObject;
        eq(1, theObject.countNumber(6),6);
    }
    {
        ChooseTheBestOne theObject;
        eq(2, theObject.countNumber(10),8);
    }
    {
        ChooseTheBestOne theObject;
        eq(3, theObject.countNumber(1234),341);
    }
}
// END CUT HERE
