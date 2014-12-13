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

class SortishDiv2
{
public:
	int ways(int sortedness, vector <int> seq);
};

int check(vector<int> &v, int s)
{
	int ret = 0;
	for (int i = 0; i < sz(v); ++i) {
		for (int j = i + 1; j < sz(v); ++j) {
			if (v[i] < v[j]) ++ret;
		}
	}
	return ret == s;
}

int SortishDiv2::ways(int sortedness, vector <int> seq)
{
	int n = sz(seq);
	set<int> st;
	for (int i = 0; i < n; ++i) {
		st.insert(i + 1);
	}
	int zero = 0;
	for (int i = 0; i < n; ++i) {
		if (seq[i] == 0) ++zero;
		else st.erase(st.find(seq[i]));
	}
	vector<int> v;
	for (set<int>::iterator si = st.begin(); si != st.end(); ++si) {
		v.push_back(*si);
	}
	int ret = 0;
	if (zero == 0) {
		ret += check(seq, sortedness);
	} else {
		do {
			vector<int> vv = seq;
			for (int i = 0, j = 0; i < n; ++i) {
				if (vv[i] == 0) vv[i] = v[j++];
			}
			ret += check(vv, sortedness);
		}
		while (next_permutation(v.begin(), v.end()));
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Everyone likes some sequences more than others.
Every person has their own function which tells them how good a sequence is.
For example, for some people this function could simply be the count of negative numbers in the sequence.

Jezalb's most favorite sequences are ones that are sorted in increasing order.
When he sees a sequence S, he immediately calculates the number of pairs of indexes i < j such that S[i] < S[j].
He calls this number the "sortedness" of S.

This morning Jezalb entered a classroom and saw a permutation of 1 through N on the blackboard.
He quickly calculated its sortedness.
He then left the classroom and forgot the permutation.
He only remembered the sortedness he computed.
You are given this value in a int sortedness. 

Later that day Jezalb reentered the classroom and saw a sequence on the blackboard.
The sequence was a permutation of 1 through N, but with some elements erased.
You are given this sequence as a vector <int> seq with N elements.
Some of the elements in seq may be 0, which indicates an erased number.

Jezalb thinks that the sequence seq may have been obtained by erasing some elements of the sequence he saw during his first visit to the classroom.
He would like to restore the erased elements.

You are given the int sortedness and the vector <int> seq.
Return the number of ways in which he can fill in the missing elements into seq in such a way that the sortedness of the obtained permutation will be exactly sortedness.

DEFINITION
Class:SortishDiv2
Method:ways
Parameters:int, vector <int>
Returns:int
Method signature:int ways(int sortedness, vector <int> seq)


CONSTRAINTS
-sortedness will be between 0 and 1,000,000,000, inclusive. 
-seq will contain between 1 and 100 elements, inclusive. 
-Elements in seq will be between 0 and number of elements in seq, inclusive. 
-Positive elements in seq will be distinct. 
-Number of elements equal to 0 in seq will be between 0 and 5, inclusive.


EXAMPLES

0)
5
{4, 0, 0, 2, 0}

Returns: 2

There are six ways to fill in the missing elements. Out of those six permutations, only two have sortedness 5: {4, 1, 5, 2, 3} and {4, 3, 1, 2, 5}.

1)
4
{0, 0, 0, 0}

Returns: 5

All 5 possible ways are: {1, 3, 4, 2}, {1, 4, 2, 3}, {2, 1, 4, 3}, {2, 3, 1, 4}, {3, 1, 2, 4}.

2)
2
{1, 3, 2}

Returns: 1

There are no gaps and sortedness is indeed equal to 2.

3)
2
{1, 2, 0, 5, 0, 0}

Returns: 0

Regardless of how he fills in the gaps, the sortedness of the resulting permutation will always be greater than 2.

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
        int seqARRAY[] = {4, 0, 0, 2, 0};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        SortishDiv2 theObject;
        eq(0, theObject.ways(5, seq),2);
    }
    {
        int seqARRAY[] = {0, 0, 0, 0};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        SortishDiv2 theObject;
        eq(1, theObject.ways(4, seq),5);
    }
    {
        int seqARRAY[] = {1, 3, 2};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        SortishDiv2 theObject;
        eq(2, theObject.ways(2, seq),1);
    }
    {
        int seqARRAY[] = {1, 2, 0, 5, 0, 0};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        SortishDiv2 theObject;
        eq(3, theObject.ways(2, seq),0);
    }
}
// END CUT HERE
