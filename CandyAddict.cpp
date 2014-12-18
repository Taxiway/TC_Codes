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

class CandyAddict
{
public:
	vector<long long> solve(vector <int> X, vector <int> Y, vector <int> Z);
};

vector<long long> CandyAddict::solve(vector <int> X, vector <int> Y, vector <int> Z)
{
	
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Alice is a candy addict!
She doesn't eat any food except for candy.
More precisely, the only thing she eats on any day is one piece of candy in the evening.



Alice receives an allowance of x dollars every morning.
One piece of candy costs y dollars.
We will follow Alice for z days.
The days will be numbered 1 through z.
At the beginning of day 1, Alice has no money and no candies.



Each day looks as follows:

In the morning, Alice receives her allowance.
At noon, Alice checks whether she has some candies. If she still has some candies, she does nothing. If she has no candies, she uses her money to buy as many candies as she currently can.
In the evening, Alice eats one candy.




For the given x, y, and z, we want to calculate the amount of money Alice has left at the end of day z.
(Alice may also have some candies at the end of day z. We are not interested in those.)



You are given multiple queries (x,y,z) and you have to process all of them.
More precisely, you are given vector <int>s X, Y, and Z, each with Q elements.
For each valid i, you must answer the query with x=X[i], y=Y[i], and z=Z[i].
Return a vector<long long> with Q elements: the answers to the queries, in the same order.


DEFINITION
Class:CandyAddict
Method:solve
Parameters:vector <int>, vector <int>, vector <int>
Returns:vector<long long>
Method signature:vector<long long> solve(vector <int> X, vector <int> Y, vector <int> Z)


CONSTRAINTS
-The number of queries will be between 1 and 100, inclusive.
-X, Y, Z will contain same number of elements.
-Each element of X, Y and Z will be between 1 and 1,000,000,000, inclusive.
-For each valid i, Y[i] <= X[i].


EXAMPLES

0)
{5}
{3}
{3}

Returns: {6 }

There is only one query.
In this query, Alice receives 5 dollars each day, a candy costs 3 dollars, and there are 3 days.
The entire process will look as follows:

Day 1 morning: Alice receives 5 dollars. She now has 5 dollars and 0 candies.
Day 1 noon: Alice has no candies, so she buys one. She now has 2 dollars and 1 candy.
Day 1 evening: Alice eats a candy. She now has 2 dollars and 0 candies.
Day 2 morning: Alice receives 5 dollars. She now has 7 dollars and 0 candies.
Day 2 noon: Alice has no candies, so she buys two. She now has 1 dollar and 2 candies.
Day 2 evening: Alice eats a candy. She now has 1 dollar and 1 candy.
Day 3 morning: Alice receives 5 dollars. She now has 6 dollars and 1 candy.
Day 3 noon: Alice still has some candies, so she does nothing. She still has 6 dollars and 1 candy.
Day 3 evening: Alice eats a candy. She now has 6 dollars and 0 candies.

Hence, at the end of day 3 Alice will have 6 dollars.

1)
{5,5,5,5,5}
{3,3,3,3,3}
{1,2,3,4,5}

Returns: {2, 1, 6, 2, 7 }



2)
{1000000000,1000000000,1000000000,1000000000,1000000000}
{1,2,3,999999998,999999999}
{342568368,560496730,586947396,386937583,609483745}

Returns: {342568367000000000, 60496729000000000, 253614062000000001, 773875166, 609483745 }



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
        int XARRAY[] = {5};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {3};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        int ZARRAY[] = {3};
        vector <int> Z( ZARRAY, ZARRAY+ARRSIZE(ZARRAY) );
        long retrunValueARRAY[] = {6L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandyAddict theObject;
        eq(0, theObject.solve(X, Y, Z),retrunValue);
    }
    {
        int XARRAY[] = {5,5,5,5,5};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {3,3,3,3,3};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        int ZARRAY[] = {1,2,3,4,5};
        vector <int> Z( ZARRAY, ZARRAY+ARRSIZE(ZARRAY) );
        long retrunValueARRAY[] = {2L, 1L, 6L, 2L, 7L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandyAddict theObject;
        eq(1, theObject.solve(X, Y, Z),retrunValue);
    }
    {
        int XARRAY[] = {1000000000,1000000000,1000000000,1000000000,1000000000};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        int YARRAY[] = {1,2,3,999999998,999999999};
        vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
        int ZARRAY[] = {342568368,560496730,586947396,386937583,609483745};
        vector <int> Z( ZARRAY, ZARRAY+ARRSIZE(ZARRAY) );
        long retrunValueARRAY[] = {342568367000000000L, 60496729000000000L, 253614062000000001L, 773875166L, 609483745L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandyAddict theObject;
        eq(2, theObject.solve(X, Y, Z),retrunValue);
    }
}
// END CUT HERE
