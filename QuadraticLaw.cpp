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

class QuadraticLaw
{
public:
	long long getTime(long long d);
};

long long QuadraticLaw::getTime(long long d)
{
	long long x = sqrt(double(d));
	while (x * x <= d) ++x;
	long long down = 0, up = x;
	while (down + 1 < up) {
		long long mid = (down + up) >> 1;
		if (mid + mid * mid <= d) {
			down = mid;
		} else {
			up = mid;
		}
	}
	return down;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
"N®ßmec's quadratic law: how many minutes the teacher was late to the lesson, that many minutes squared he'll end the lesson earlier."



In other words, if the teacher is t minutes late (for some non-negative integer t), he should end the lesson t2 minutes early. Of course, this means the teacher can't be too late, because a lesson can't end before even starting. It is, however, possible for the teacher to arrive and end the lesson immediately (in fact, he then only arrives to tell the students that the lesson's cancelled).



You're given a long long d. The lesson was supposed to take d minutes. Compute and return the largest non-negative integer t such that the teacher can be t minutes late.


DEFINITION
Class:QuadraticLaw
Method:getTime
Parameters:long long
Returns:long long
Method signature:long long getTime(long long d)


CONSTRAINTS
-d will be between 1 and 1,000,000,000,000,000,000, inclusive.


EXAMPLES

0)
1

Returns: 0

The lesson was supposed to take 1 minute. The teacher can only be 0 minutes late, in which case he ends the lesson 0 minutes early (i.e. he arrives and ends the lecture on time).

1)
2

Returns: 1

It's possible for the teacher to be 1 minute late and end the lecture 1 minute early (so there's no lecture at all).

2)
5

Returns: 1



3)
6

Returns: 2



4)
7

Returns: 2



5)
1482

Returns: 38



6)
1000000000000000000

Returns: 999999999



7)
31958809614643170

Returns: 178770270



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
        QuadraticLaw theObject;
        eq(0, theObject.getTime(1L),0L);
    }
    {
        QuadraticLaw theObject;
        eq(1, theObject.getTime(2L),1L);
    }
    {
        QuadraticLaw theObject;
        eq(2, theObject.getTime(5L),1L);
    }
    {
        QuadraticLaw theObject;
        eq(3, theObject.getTime(6L),2L);
    }
    {
        QuadraticLaw theObject;
        eq(4, theObject.getTime(7L),2L);
    }
    {
        QuadraticLaw theObject;
        eq(5, theObject.getTime(1482L),38L);
    }
    {
        QuadraticLaw theObject;
        eq(6, theObject.getTime(1000000000000000000L),999999999L);
    }
    {
        QuadraticLaw theObject;
        eq(7, theObject.getTime(31958809614643170L),178770270L);
    }
}
// END CUT HERE
