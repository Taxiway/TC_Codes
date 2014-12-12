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

class BuyingTshirts
{
public:
	int meet(int T, vector <int> Q, vector <int> P);
};

int BuyingTshirts::meet(int T, vector <int> Q, vector <int> P)
{
	int n = sz(Q);
	int ret = 0;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; ++i) {
		s1 += Q[i];
		s2 += P[i];
		if (s1 >= T && s2 >= T) ++ret;
		s1 %= T;
		s2 %= T;
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// A local store is selling T-shirts with the face of Fox Ciel printed on them.
Each such T-shirt costs T pesos.
Quimey and Pablo love those T-shirts.
They each buy a new T-shirt whenever they have the money to do so.

Currently, Quimey and Pablo have no money at all.
During the following N days they are going to earn some money and they will use it to buy the T-shirts.
The days are numbered from 0 (today) to N-1 (the day N-1 days in the future).

For each valid i, Q[i] and P[i] are the amounts in pesos Quimey and Pablo will earn on day i.
(Note that each of those amounts is at most T. 
Therefore, Quimey and Pablo will be able to buy at most one T-shirt each day.)

For example, suppose that a T-shirt costs T=10 pesos.
If Q={2,3,5,10}, the following will happen to Quimey:

On day 0, he earns 2 pesos. He now has 2 pesos.
On day 1, he earns 3 pesos. He now has 5 pesos.
On day 2, he earns 5 pesos. He now has 10 pesos, which is enough to buy a T-shirt. He goes to the store and buys one. Afterwards, he has 0 pesos left.
On day 3, he earns 10 pesos. He then goes to buy a second T-shirt. Afterwards, he again has 0 pesos left.

If P={10,8,6,4}, Pablo would buy one T-shirt on day 0, and then another T-shirt on day 2. After buying the T-shirt on day 2 he would have 4 pesos left. After day 3 he would then have a total of 8 pesos, which is still not enough for a T-shirt.
Note that in this example Quimey and Pablo would go to the store together on day 2.

You are given the int T: the price of a single T-shirt.
You are also given the vector <int>s Q and P with N elements each: the amounts Quimey and Pablo earn each day.
Compute and return the number of days on which Quimey and Pablo both go to the store

DEFINITION
Class:BuyingTshirts
Method:meet
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int meet(int T, vector <int> Q, vector <int> P)


NOTES
-If you need the number N in your solution, you can determine it as the number of elements in Q.


CONSTRAINTS
-T will be between 1 and 100.
-Q will contain between 1 and 100 elements.
-Q and P will contain the same number of elements.
-Each element of Q will be between 1 and T.
-Each element of P will be between 1 and T.


EXAMPLES

0)
5
{1,2,3,4,5}
{5,4,3,2,1}

Returns: 2

Quimey will buy his T-shirts on days 2, 3, and 4.
Pablo will buy his on days 0, 2, and 4.
They will go to the store together twice: first on day 2 and then on day 4.

1)
10
{10,10,10}
{10,10,10}

Returns: 3



2)
2
{1,2,1,2,1,2,1,2}
{1,1,1,1,2,2,2,2}

Returns: 5

They will both go to the store on the following days: 1, 3, 5, 6, and 7.

3)
100
{1,2,3}
{4,5,6}

Returns: 0

In this test case they do not buy any T-shirts at all.

4)
10
{10,1,10,1}
{1,10,1,10}

Returns: 0



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
        int QARRAY[] = {1,2,3,4,5};
        vector <int> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        int PARRAY[] = {5,4,3,2,1};
        vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        BuyingTshirts theObject;
        eq(0, theObject.meet(5, Q, P),2);
    }
    {
        int QARRAY[] = {10,10,10};
        vector <int> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        int PARRAY[] = {10,10,10};
        vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        BuyingTshirts theObject;
        eq(1, theObject.meet(10, Q, P),3);
    }
    {
        int QARRAY[] = {1,2,1,2,1,2,1,2};
        vector <int> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        int PARRAY[] = {1,1,1,1,2,2,2,2};
        vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        BuyingTshirts theObject;
        eq(2, theObject.meet(2, Q, P),5);
    }
    {
        int QARRAY[] = {1,2,3};
        vector <int> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        int PARRAY[] = {4,5,6};
        vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        BuyingTshirts theObject;
        eq(3, theObject.meet(100, Q, P),0);
    }
    {
        int QARRAY[] = {10,1,10,1};
        vector <int> Q( QARRAY, QARRAY+ARRSIZE(QARRAY) );
        int PARRAY[] = {1,10,1,10};
        vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
        BuyingTshirts theObject;
        eq(4, theObject.meet(10, Q, P),0);
    }
}
// END CUT HERE
