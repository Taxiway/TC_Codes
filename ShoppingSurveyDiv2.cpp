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

class ShoppingSurveyDiv2
{
public:
	int minValue(int N, vector <int> s);
};

int ShoppingSurveyDiv2::minValue(int N, vector <int> s)
{
	int m = sz(s);
	int sum = 0;
	for (int i = 0; i < m; ++i) {
		sum += s[i];
	}
	for (int i = 0; i <= N; ++i) {
		int none = N - i;
		int most = none * (m - 1);
		int left = sum - i * m;
		if (most >= left) return i;
	}
	return N;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
A store sells M different items, conveniently numbered 0 through M-1.
For a shopping survey you interviewed N customers.
Each customer responded to the survey with a list of items they've bought.
Each customer bought at most one of each item.
It is possible that some customers did not buy anything at all.



After collecting the responses, you've summed up the results and found that s[i] people have bought item i.
Due to an unfortunate accident, you've then lost the actual survey responses.
All you have left are the values s[i] you computed.



You are now supposed to report the number of big shoppers among the survey respondents.
A big shopper is defined as a customer who has bought all M items.
Of course, having lost the detailed responses, you might be unable to determine the actual number of big shoppers.



You are given the int N and the vector <int> s with M elements.
Compute and return the smallest possible number of big shoppers.



DEFINITION
Class:ShoppingSurveyDiv2
Method:minValue
Parameters:int, vector <int>
Returns:int
Method signature:int minValue(int N, vector <int> s)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-s will contain between 1 and 100 elements, inclusive.
-Each element in s will be between 0 and N, inclusive.


EXAMPLES

0)
5
{3, 3}

Returns: 1


There are 5 customers and 2 items in the store.
Each of the items was bought by three of the customers.
Since there are five people and a total of six bought items, we must have at least one big shopper.
And we can easily verify that there could have been exactly one big shopper and four other customers who have bought one item each.

1)
100
{97}

Returns: 97



2)
10
{9, 9, 9, 9, 9}

Returns: 5



3)
7
{1, 2, 3}

Returns: 0



4)
5
{3, 3, 3}

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
        int sARRAY[] = {3, 3};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        ShoppingSurveyDiv2 theObject;
        eq(0, theObject.minValue(5, s),1);
    }
    {
        int sARRAY[] = {97};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        ShoppingSurveyDiv2 theObject;
        eq(1, theObject.minValue(100, s),97);
    }
    {
        int sARRAY[] = {9, 9, 9, 9, 9};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        ShoppingSurveyDiv2 theObject;
        eq(2, theObject.minValue(10, s),5);
    }
    {
        int sARRAY[] = {1, 2, 3};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        ShoppingSurveyDiv2 theObject;
        eq(3, theObject.minValue(7, s),0);
    }
    {
        int sARRAY[] = {3, 3, 3};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        ShoppingSurveyDiv2 theObject;
        eq(4, theObject.minValue(5, s),0);
    }
	{
		int sARRAY[] = {58, 58, 58, 56, 58, 58, 58, 58, 58, 58, 50, 58, 58, 58, 58, 58, 58, 58, 58, 58, 51, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 56, 58, 58, 58, 58, 58, 56, 58, 58, 58, 57, 58, 58, 58, 58, 58, 51, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58};
		vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
		ShoppingSurveyDiv2 theObject;
		eq(5, theObject.minValue(58, s),29);
	}

}
// END CUT HERE
