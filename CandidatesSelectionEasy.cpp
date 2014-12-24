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

class CandidatesSelectionEasy
{
public:
	vector <int> sort(vector <string> score, int x);
};

vector<string> s;
int xx;

bool cmp(const int &a, const int &b)
{
    if (s[a][xx] != s[b][xx]) {
        return s[a][xx] < s[b][xx];
    } else {
        return a < b;
    }
}

vector <int> CandidatesSelectionEasy::sort(vector <string> score, int x)
{
    s = score;
    xx = x;
    vector<int> v;
    for (int i = 0; i < sz(score); ++i) {
        v.push_back(i);
    }
    ::sort(all(v), cmp);
    return v;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Fox Ciel wants to hire a new maid.
There are n candidates for the position.
There are m different skills a maid should have, such as cooking, cleaning, or discreetness.
Ciel numbered the candidates 0 through n-1 and the skills 0 through m-1.



Ciel evaluated the level each candidate has in each of the skills.
You are given this information encoded in a vector <string> score with n elements, each consisting of m characters.
For each i and j, the character score[i][j] represents the level candidate i has in skill j.
Said character will always be between 'A' and 'Z', inclusive, where 'A' means the best possible and 'Z' the worst possible candidate.



You are also given an int x.
Ciel thinks that skill x is the most important skill a maid should have.



Return a vector <int> with n elements: the numbers of all candidates, ordered according to their level in skill x from the best to the worst.
Candidates who have the same level in skill x should be ordered by their number in ascending order.

DEFINITION
Class:CandidatesSelectionEasy
Method:sort
Parameters:vector <string>, int
Returns:vector <int>
Method signature:vector <int> sort(vector <string> score, int x)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-m will be between 1 and 50, inclusive.
-score will contain exactly n elements.
-Each element of score will contain exactly m characters.
-Each character in each element of score will be an uppercase English letter ('A'-'Z').
-x will be between 0 and m-1, inclusive.


EXAMPLES

0)
{"ACB", "BAC", "CBA"}
1

Returns: {1, 2, 0 }

The output should be {1, 2, 0}, because the level of candidate 1 in skill 1 is 'A', the level of candidate 2 in this skill is 'B', and the level of candidate 0 is 'C'.

1)
{"A", "C", "B", "C", "A"}
0

Returns: {0, 4, 2, 1, 3 }

Note that when 2 candidates have same level, they will remain in the original order.

2)
{"LAX","BUR","ONT","LGB","SAN","SNA","SFO","OAK","SJC"}
2

Returns: {5, 3, 8, 7, 4, 6, 1, 2, 0 }



3)
{"BBCBABAC","BCBACABA","CCCBAACB","CACABABB","AABBBBCC"}
6

Returns: {0, 1, 3, 2, 4 }



4)
{"XXYWZWWYXZ","YZZZYWYZYW","ZYZZWZYYWW","ZWZWZWZXYW","ZYXWZXWYXY","YXXXZWXWXW","XWWYZWXYXY","XYYXYWYXWY","ZZYXZYZXYY","WXZXWYZWYY"}
3

Returns: {0, 3, 4, 5, 7, 8, 9, 6, 1, 2 }



5)
{"X"}
0

Returns: {0 }

Note that we may have only one candidate as well as only 1 skill.

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
        string scoreARRAY[] = {"ACB", "BAC", "CBA"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int retrunValueARRAY[] = {1, 2, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandidatesSelectionEasy theObject;
        eq(0, theObject.sort(score, 1),retrunValue);
    }
    {
        string scoreARRAY[] = {"A", "C", "B", "C", "A"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int retrunValueARRAY[] = {0, 4, 2, 1, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandidatesSelectionEasy theObject;
        eq(1, theObject.sort(score, 0),retrunValue);
    }
    {
        string scoreARRAY[] = {"LAX","BUR","ONT","LGB","SAN","SNA","SFO","OAK","SJC"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int retrunValueARRAY[] = {5, 3, 8, 7, 4, 6, 1, 2, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandidatesSelectionEasy theObject;
        eq(2, theObject.sort(score, 2),retrunValue);
    }
    {
        string scoreARRAY[] = {"BBCBABAC","BCBACABA","CCCBAACB","CACABABB","AABBBBCC"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int retrunValueARRAY[] = {0, 1, 3, 2, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandidatesSelectionEasy theObject;
        eq(3, theObject.sort(score, 6),retrunValue);
    }
    {
        string scoreARRAY[] = {"XXYWZWWYXZ","YZZZYWYZYW","ZYZZWZYYWW","ZWZWZWZXYW","ZYXWZXWYXY","YXXXZWXWXW","XWWYZWXYXY","XYYXYWYXWY","ZZYXZYZXYY","WXZXWYZWYY"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int retrunValueARRAY[] = {0, 3, 4, 5, 7, 8, 9, 6, 1, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandidatesSelectionEasy theObject;
        eq(4, theObject.sort(score, 3),retrunValue);
    }
    {
        string scoreARRAY[] = {"X"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int retrunValueARRAY[] = {0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CandidatesSelectionEasy theObject;
        eq(5, theObject.sort(score, 0),retrunValue);
    }
}
// END CUT HERE
