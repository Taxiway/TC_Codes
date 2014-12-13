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

class GreaterGameDiv2
{
public:
	int calc(vector <int> snuke, vector <int> sothe);
};

int GreaterGameDiv2::calc(vector <int> snuke, vector <int> sothe)
{
	int ret = 0;
	for (int i = 0; i < sz(snuke); ++i) {
		ret += (snuke[i] > sothe[i]);
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Cat Snuke and wolf Sothe are playing the Greater Game.
The game is played with cards.
Each card has a number written on it.
There are 2N cards.
The numbers on the cards are the integers between 1 and 2N, inclusive.

At the beginning of the game, each player gets N of the cards and chooses the order in which he wants to play them.
The game then consists of N turns.
In each turn, both players play one of their cards simultaneously.
The player who revealed the card with the larger number gets a point.

You are given two vector <int>s: snuke and sothe.
The elements of snuke are the numbers on the cards Snuke is going to play, in order.
Similarly, the elements of sothe are the numbers on the cards Sothe is going to play, in order.
Compute and return the number of points Snuke will have at the end of the game.

DEFINITION
Class:GreaterGameDiv2
Method:calc
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int calc(vector <int> snuke, vector <int> sothe)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-snuke and sothe will contain exactly N elements each.
-Each integer in snuke and sothe will be between 1 and 2N, inclusive.
-The integers in snuke and sothe will be distinct.


EXAMPLES

0)
{1,3}
{4,2}

Returns: 1

Snuke loses the first round because 1 is less than 4. Snuke then wins the second round because 3 is greater than 2.

1)
{1,3,5,7,9}
{2,4,6,8,10}

Returns: 0



2)
{2}
{1}

Returns: 1



3)
{3,5,9,16,14,20,15,17,13,2}
{6,18,1,8,7,10,11,19,12,4}

Returns: 6



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
        int snukeARRAY[] = {1,3};
        vector <int> snuke( snukeARRAY, snukeARRAY+ARRSIZE(snukeARRAY) );
        int sotheARRAY[] = {4,2};
        vector <int> sothe( sotheARRAY, sotheARRAY+ARRSIZE(sotheARRAY) );
        GreaterGameDiv2 theObject;
        eq(0, theObject.calc(snuke, sothe),1);
    }
    {
        int snukeARRAY[] = {1,3,5,7,9};
        vector <int> snuke( snukeARRAY, snukeARRAY+ARRSIZE(snukeARRAY) );
        int sotheARRAY[] = {2,4,6,8,10};
        vector <int> sothe( sotheARRAY, sotheARRAY+ARRSIZE(sotheARRAY) );
        GreaterGameDiv2 theObject;
        eq(1, theObject.calc(snuke, sothe),0);
    }
    {
        int snukeARRAY[] = {2};
        vector <int> snuke( snukeARRAY, snukeARRAY+ARRSIZE(snukeARRAY) );
        int sotheARRAY[] = {1};
        vector <int> sothe( sotheARRAY, sotheARRAY+ARRSIZE(sotheARRAY) );
        GreaterGameDiv2 theObject;
        eq(2, theObject.calc(snuke, sothe),1);
    }
    {
        int snukeARRAY[] = {3,5,9,16,14,20,15,17,13,2};
        vector <int> snuke( snukeARRAY, snukeARRAY+ARRSIZE(snukeARRAY) );
        int sotheARRAY[] = {6,18,1,8,7,10,11,19,12,4};
        vector <int> sothe( sotheARRAY, sotheARRAY+ARRSIZE(sotheARRAY) );
        GreaterGameDiv2 theObject;
        eq(3, theObject.calc(snuke, sothe),6);
    }
}
// END CUT HERE
