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

class FixedDiceGameDiv2
{
public:
	double getExpectation(int a, int b);
};

double winpct(int now, int most)
{
    if (now > most) {
        return 1.0;
    } else {
        return (now - 1) * 1.0 / most;
    }
}

double FixedDiceGameDiv2::getExpectation(int a, int b)
{
    double sum = 0;
    for (int i = 2; i <= a; ++i) {
        double pct = winpct(i, b);
        sum += pct;
    }
    double expct = 0;
    for (int i = 2; i <= a; ++i) {
        double pct = winpct(i, b);
        expct += pct * i / sum;
    }
    return expct;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Alice and Bob are playing a game.
Alice has an a-sided die.
Bob has a b-sided die.
(The faces of an n-sided die have numbers 1 through n written on them.)



The game is simple:
Each player rolls their die, and the player who rolls a strictly larger number wins.
(It is possible that neither player wins.)



You are given the ints a and b.
The players already rolled their dice.
You do not know what numbers they rolled, but you know that Alice won the game.
Compute and return the expected value of the number Alice rolled.



DEFINITION
Class:FixedDiceGameDiv2
Method:getExpectation
Parameters:int, int
Returns:double
Method signature:double getExpectation(int a, int b)


NOTES
-Your return value must have absolute or relative error smaller than 1e-9.
-The expected value can be seen as the average of many experiments. In our case, suppose that you folow a lot of games, and each time Alice wins, you write down her score. As you watch more and more games, the average of all numbers you have written down will converge to the expected value you should return. 


CONSTRAINTS
-a and b will each be between 2 and 1000, inclusive.


EXAMPLES

0)
2
2

Returns: 2.0

Alice can only win if she rolls a 2 and Bob rolls a 1. Thus, if we know Alice wins, we know she rolled a 2.

1)
4
2

Returns: 3.2



2)
3
3

Returns: 2.6666666666666665



3)
11
13

Returns: 7.999999999999999



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
        FixedDiceGameDiv2 theObject;
        eq(0, theObject.getExpectation(2, 2),2.0);
    }
    {
        FixedDiceGameDiv2 theObject;
        eq(1, theObject.getExpectation(4, 2),3.2);
    }
    {
        FixedDiceGameDiv2 theObject;
        eq(2, theObject.getExpectation(3, 3),2.6666666666666665);
    }
    {
        FixedDiceGameDiv2 theObject;
        eq(3, theObject.getExpectation(11, 13),7.999999999999999);
    }
}
// END CUT HERE
