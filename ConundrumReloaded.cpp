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

class ConundrumReloaded
{
public:
	int minimumLiars(string answers);
};

int gao(string s)
{
    int ret = 0;
    for (int i = 0; i < sz(s); ++i) {
        ret += s[i] == 'L';
    }
    return ret;
}

int getans(string s)
{
    int best = 10000;
    string s2 = "H";
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == s2[i]) {
            s2 += "H";
        } else {
            s2 += "L";
        }
    }
    best = min(best, gao(s2));
    
    s2 = "L";
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == s2[i]) {
            s2 += "H";
        } else {
            s2 += "L";
        }
    }
    best = min(best, gao(s2));
    return best;
}

int getans2(string s)
{
    int best = 10000;
    string s2 = "H";
    for (int i = 0; i + 1 < sz(s); ++i) {
        if (s[i] == s2[i]) {
            s2 += "H";
        } else {
            s2 += "L";
        }
    }
    if ((s2[sz(s) - 1] == s[sz(s) - 1]) == (s2[0] == 'H')) {
        best = min(best, gao(s2));
    }
    
    s2 = "L";
    for (int i = 0; i + 1 < sz(s); ++i) {
        if (s[i] == s2[i]) {
            s2 += "H";
        } else {
            s2 += "L";
        }
    }
    if ((s2[sz(s) - 1] == s[sz(s) - 1]) == (s2[0] == 'H')) {
        best = min(best, gao(s2));
    }
    return best == 10000 ? -1 : best;
}

int ConundrumReloaded::minimumLiars(string answers)
{
    int ind = -1;
    for (int i = 0; i < sz(answers); ++i) {
        if (answers[i] == '?') {
            ind = i;
            break;
        }
    }
    int ret = 0;
    if (ind == -1) {
        return getans2(answers);
    } else {
        string s = answers.substr(ind + 1) + answers.substr(0, ind);
        s += "?";
        string ss = "";
        for (int i = 0; i < sz(s); ++i) {
            if (s[i] == '?') {
                ret += getans(ss);
                ss = "";
            } else {
                ss += s[i];
            }
        }
        return ret;
    }
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Once upon a time, N people sat around a circle. They were numbered 0 through N-1 in counter-clockwise order. Each person was either a honest person or a liar. A honest person always tells the truth, a liar always lies. You asked some of them (possibly all or none) whether the person sitting to the right of them is a liar. You are given their answers in a string answers with N characters. For each i, character i of answers is one of the following:


'L' if person i said that person (i+1) is a liar,
'H' if person i said that person (i+1) is a honest person,
'?' if you didn't ask person i.

(Above, (i+1) is considered modulo N. That is, person N-1 is talking about person 0.)

You are given the string answers. If there is at least one possible combination of honest people and liars that is consistent with answers, return the smallest possible number of liars. Else return -1.

DEFINITION
Class:ConundrumReloaded
Method:minimumLiars
Parameters:string
Returns:int
Method signature:int minimumLiars(string answers)


CONSTRAINTS
-answers will contain between 2 and 50 characters, inclusive.
-Each character in answers will be 'L', 'H' or '?'.


EXAMPLES

0)
"LLH"

Returns: 1

According to the input:

Person 0 says that person 1 is a liar.
Person 1 says that person 2 is a liar.
Person 2 says that person 0 is a honest person.

Clearly, they cannot all be honest, so there is at least one liar. It is possible that person 1 is liar and the other two are honest. Hence, the smallest possible number of liars is one.

(Note that it is also possible that person 1 is honest and the other two are liars.)

1)
"?????"

Returns: 0

Nobody told us anything. It is possible that everybody is honest.

2)
"LHLH?"

Returns: 2

If person #1 and person #2 are liars, then the answers would be "LHLHH". This is consistent with the answers we received.

3)
"??LLLLLL??"

Returns: 3



4)
"LLL"

Returns: -1

Each of the 8 possible combinations of (liar / honest person) will lead to a contradiction.

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
        ConundrumReloaded theObject;
        eq(0, theObject.minimumLiars("LLH"),1);
    }
    {
        ConundrumReloaded theObject;
        eq(1, theObject.minimumLiars("?????"),0);
    }
    {
        ConundrumReloaded theObject;
        eq(2, theObject.minimumLiars("LHLH?"),2);
    }
    {
        ConundrumReloaded theObject;
        eq(3, theObject.minimumLiars("??LLLLLL??"),3);
    }
    {
        ConundrumReloaded theObject;
        eq(4, theObject.minimumLiars("LLL"),-1);
    }
    {
        ConundrumReloaded theObject;
        eq(5, theObject.minimumLiars("L?LL?L"),2);
    }
}
// END CUT HERE
