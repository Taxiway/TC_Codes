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

class ColorfulCoinsEasy
{
public:
	string isPossible(vector <int> values);
};

string ColorfulCoinsEasy::isPossible(vector <int> values)
{
    vector<int> v;
    for (int i = 1; i < sz(values); ++i) {
        v.push_back(values[i] / values[i - 1]);
    }
    sort(all(v));
    for (int i = 0; i < sz(v); ++i) {
        if (v[i] <= i + 1) return "Impossible";
    }
    return "Possible";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// The currency system in Colorland consists of various types of coins. The coin denominations follow these simple rules:


The denominations are distinct positive integers.
There is a coin type with denomination 1.
For each pair of different coin types, the denomination of one coin type divides the denomination of the other one.


You are given a int[] values containing all the available denominations in ascending order.

Coins of different denominations look exactly the same except that they have different colors. Each coin in Colorland has exactly one color. The coin colors follow these even simpler rules:


All coins of the same type are of the same color.
No two coins of different types are of the same color.


You know all coin denominations used in Colorland, but you don't know their colors. You don't even know the set of colors used on the coins.

For each denomination, you'd like to know the color of coins of this denomination. To accomplish this, you've got a credit card with an infinite amount of money. You can perform a single query to an ATM which can also provide you with an infinite amount of money. The query is described by a positive integer X, which means that you want to receive exactly X units of money from the ATM. The ATM will provide you with the requested amount. You also know that the requested amount will be paid using the smallest possible number of coins. (Note that this rule always uniquely determines the set of coins chosen to make the payment.)

Return "Possible" (quotes for clarity) if it's possible to determine the color of coins of each denomination, and return "Impossible" otherwise.


DEFINITION
Class:ColorfulCoinsEasy
Method:isPossible
Parameters:vector <int>
Returns:string
Method signature:string isPossible(vector <int> values)


CONSTRAINTS
-values will contain between 1 and 15 elements, inclusive.
-Each element of values will be between 1 and 20000, inclusive.
-values will be sorted in strictly ascending order. Note that this also implies that all the elements of values will be distinct.
-For each pair of different elements in values, the smaller one will be a divisor of the larger one.
-values[0] will be 1.


EXAMPLES

0)
{1}

Returns: "Possible"

For any positive X, you'll get exactly X coins of denomination 1, so you'll easily learn their color.

1)
{1, 3}

Returns: "Possible"

X = 5 is one possible solution. As the ATM gives the smallest number of coins, it will give one coin of denomination 3 and two coins of denomination 1. That means, for example, that if you get one red coin and two blue coins, you'll understand that coins of denomination 3 are red, and coins of denomination 1 are blue.

2)
{1, 2, 4}

Returns: "Impossible"

It can be proven that for any X, you'll get at most one coin of denomination 1, and at most one coin of denomination 2. If you get no coins of some denomination, clearly you won't be able to determine their color. However, if you get one coin from each of denominations 1 and 2, you won't be able to find out which of the two colors represents which denomination.

3)
{1, 5, 15, 90}

Returns: "Possible"

X = 504 is one possible solution. You'll get five coins of denomination 90, three coins of denomination 15, one coin of denomination 5 and four coins of denomination 1.

4)
{1, 4, 20, 60, 180, 1440, 5760}

Returns: "Impossible"



5)
{1, 7, 21, 105, 630, 3150, 18900}

Returns: "Possible"

X = 137969 is the smallest possible solution.

6)
{1, 10, 30, 300, 900, 9000, 18000}

Returns: "Impossible"



7)
{1, 2, 10, 40, 200, 1000, 4000, 20000}

Returns: "Impossible"



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
        int valuesARRAY[] = {1};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(0, theObject.isPossible(values),"Possible");
    }
    {
        int valuesARRAY[] = {1, 3};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(1, theObject.isPossible(values),"Possible");
    }
    {
        int valuesARRAY[] = {1, 2, 4};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(2, theObject.isPossible(values),"Impossible");
    }
    {
        int valuesARRAY[] = {1, 5, 15, 90};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(3, theObject.isPossible(values),"Possible");
    }
    {
        int valuesARRAY[] = {1, 4, 20, 60, 180, 1440, 5760};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(4, theObject.isPossible(values),"Impossible");
    }
    {
        int valuesARRAY[] = {1, 7, 21, 105, 630, 3150, 18900};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(5, theObject.isPossible(values),"Possible");
    }
    {
        int valuesARRAY[] = {1, 10, 30, 300, 900, 9000, 18000};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(6, theObject.isPossible(values),"Impossible");
    }
    {
        int valuesARRAY[] = {1, 2, 10, 40, 200, 1000, 4000, 20000};
        vector <int> values( valuesARRAY, valuesARRAY+ARRSIZE(valuesARRAY) );
        ColorfulCoinsEasy theObject;
        eq(7, theObject.isPossible(values),"Impossible");
    }
}
// END CUT HERE
