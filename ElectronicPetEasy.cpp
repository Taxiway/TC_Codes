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

class ElectronicPetEasy
{
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2);
};

string ElectronicPetEasy::isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
{
	set<int> st;
	st.insert(st1);
	for (int i = 1; i < t1; ++i) {
		st1 += p1;
		st.insert(st1);
	}
	if (st.count(st2)) return "Difficult";
	for (int i = 1; i < t2; ++i) {
		st2 += p2;
		if (st.count(st2)) return "Difficult";
	}
	return "Easy";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Kirino has found a game in which she has to feed electronic pets.
There are two pets in the game.
You are given six ints st1,p1,t1,st2,p2,t2.
To win the game, Kirino must satisfy the following rules:

She must feed her first pet for the first time precisely at the time st1.
There must be exactly p1 seconds between any two consecutive feedings of the first pet.
She must feed the first pet exactly t1 times.
She must feed her second pet for the first time precisely at the time st2.
There must be exactly p2 seconds between any two consecutive feedings of the second pet.
She must feed the second pet exactly t2 times.




Feeding the pets is easy if Kirino never needs to feed both pets at the same time.
Return "Easy" (quotes for clarity) if feeding the pets is easy for the given inputs.
Otherwise, return "Difficult".
Note that the return value is case-sensitive.


DEFINITION
Class:ElectronicPetEasy
Method:isDifficult
Parameters:int, int, int, int, int, int
Returns:string
Method signature:string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)


CONSTRAINTS
-st1, p1, t1, st2, p2, and t2 will be between 1 and 1,000, inclusive.


EXAMPLES

0)
3
3
3
5
2
3

Returns: "Difficult"

Kirino must feed her first pet at the times 3, 6, and 9.
She must feed her second pet at the times 5, 7, and 9.
Feeding these two pets is difficult because she needs to feed both of them at the same time (at time 9).

1)
3
3
3
5
2
2

Returns: "Easy"

Kirino must feed her first pet at 3, 6, and 9, and her second pet at 5 and 7.
As all of these times are distinct, feeding these two pets is easy.

2)
1
4
7
1
4
7

Returns: "Difficult"



3)
1
1000
1000
2
1000
1000

Returns: "Easy"



4)
1
1
1
2
2
2

Returns: "Easy"



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
        ElectronicPetEasy theObject;
        eq(0, theObject.isDifficult(3, 3, 3, 5, 2, 3),"Difficult");
    }
    {
        ElectronicPetEasy theObject;
        eq(1, theObject.isDifficult(3, 3, 3, 5, 2, 2),"Easy");
    }
    {
        ElectronicPetEasy theObject;
        eq(2, theObject.isDifficult(1, 4, 7, 1, 4, 7),"Difficult");
    }
    {
        ElectronicPetEasy theObject;
        eq(3, theObject.isDifficult(1, 1000, 1000, 2, 1000, 1000),"Easy");
    }
    {
        ElectronicPetEasy theObject;
        eq(4, theObject.isDifficult(1, 1, 1, 2, 2, 2),"Easy");
    }
}
// END CUT HERE
