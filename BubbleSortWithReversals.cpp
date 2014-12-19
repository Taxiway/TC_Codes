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

class BubbleSortWithReversals
{
public:
	int getMinSwaps(vector <int> A, int K);
};

int num[64][64];
int num2[64][64];
int dp[64][64];
int n;

int getrev(vector<int> &v, int f, int t)
{
    int ret = 0;
    for (int i = f; i <= t; ++i) {
        for (int j = i + 1; j <= t; ++j) {
            if (v[i] > v[j]) {
                ++ret;
            }
        }
    }
    return ret;
}

int getrev2(vector<int> &v, int f, int t)
{
    int ret = 0;
    for (int i = f; i <= t; ++i) {
        for (int j = i + 1; j <= t; ++j) {
            if (v[i] < v[j]) {
                ++ret;
            }
        }
    }
    return ret;
}

int getdp(int now, int k)
{
    if (dp[now][k] != -1) {
        return dp[now][k];
    }
    if (now >= n - 1) {
        return dp[now][k] = 0;
    }
    dp[now][k] = getdp(now + 1, k);
    if (k > 0) {
        for (int j = now + 1; j < n; ++j) {
            int cur = num[now][j];
            int then = num2[now][j];
            if (then < cur) {
                dp[now][k] = max(dp[now][k], cur - then + getdp(j + 1, k - 1));
            }
        }
    }
    return dp[now][k];
}

int BubbleSortWithReversals::getMinSwaps(vector <int> A, int K)
{
    n = sz(A);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            num[i][j] = getrev(A, i, j);
            num2[i][j] = getrev2(A, i, j);
        }
    }
    memset(dp, -1, sizeof(dp));
    return num[0][n - 1] - getdp(0, K);
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// The pseudocode shown below is an implementation of BubbleSort.
Note that the array A used in the implementation is 0-based.
That is, elements of A have indices 0 through Length(A)-1, inclusive.


BubbleSort(A):
        Repeat Length(A)-1 times:
               For every i from 0 to Length(A)-2, inclusive:
                      If A[i] > A[i+1] then:
                               Swap A[i] and A[i+1]


We are going to sort the array A using the above algorithm.
However, before we do that, you are allowed to reverse at most K disjoint subarrays of A.

For example, suppose that A={10, 20, 30, 40, 50, 60, 70} and that K=1.
In this case you may, for example, reverse the subarray [2,5] - that is, the elements at (0-based) indices 2 through 5.
This would produce the array {10, 20, 60, 50, 40, 30, 70}.

We are interested in minimizing the number of swaps executed by our BubbleSort.
You are given the vector <int> A and the int K.
Return the smallest possible number of swaps performed by our BubbleSort after you reverse at most K disjoint subarrays of A.


DEFINITION
Class:BubbleSortWithReversals
Method:getMinSwaps
Parameters:vector <int>, int
Returns:int
Method signature:int getMinSwaps(vector <int> A, int K)


CONSTRAINTS
-A will contain between 2 and 50 elements.
-K will be between 1 and 50.
-Each element of A will be between 1 and 1000, inclusive.


EXAMPLES

0)
{6,8,8,7,7}
1

Returns: 0

By reversing the subarray [1,4] we obtain a new array {6,7,7,8,8}. This array is already sorted and we can easily verify that our BubbleSort never swaps anything.


1)
{7,2,2,13,5,5,2}
2

Returns: 3



2)
{12,5,1,10,12,6,6,10,6,8}
2

Returns: 12



3)
{2,3,1}
2

Returns: 1

Note that the subarrays we are reversing must all be disjoint. For example, it is not allowed to reverse first the subarray [0,1] and then the subarray [0,2].


4)
{482,619,619,601,660,660,691,691,77,77,96,77}
9

Returns: 22



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
        int AARRAY[] = {6,8,8,7,7};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        BubbleSortWithReversals theObject;
        eq(0, theObject.getMinSwaps(A, 1),0);
    }
    {
        int AARRAY[] = {7,2,2,13,5,5,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        BubbleSortWithReversals theObject;
        eq(1, theObject.getMinSwaps(A, 2),3);
    }
    {
        int AARRAY[] = {12,5,1,10,12,6,6,10,6,8};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        BubbleSortWithReversals theObject;
        eq(2, theObject.getMinSwaps(A, 2),12);
    }
    {
        int AARRAY[] = {2,3,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        BubbleSortWithReversals theObject;
        eq(3, theObject.getMinSwaps(A, 2),1);
    }
    {
        int AARRAY[] = {482,619,619,601,660,660,691,691,77,77,96,77};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        BubbleSortWithReversals theObject;
        eq(4, theObject.getMinSwaps(A, 9),22);
    }
}
// END CUT HERE
