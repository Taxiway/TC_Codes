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

class TaroCoins
{
public:
	long long getNumber(long long N);
};

long long TaroCoins::getNumber(long long N)
{
    int arr[100];
    int n = 0;
    while (N) {
        arr[n++] = N % 2;
        N >>= 1;
    }
    long long dp[100][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i]) {
            dp[i + 1][0] = dp[i][0] + dp[i][1];
            dp[i + 1][1] = dp[i][1];
        } else {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][0] + dp[i][1];
        }
    }
    return dp[n][0];
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Cat Taro likes coins. For any non-negative integer K, he has exactly two coins of value 2^K (i.e., two to the power of K).




You are given a long long N.
Return the number of different ways Taro can represent the value N with coins that he has.
(Two representations are considered different if there is a value that occurs a different number of times in the representations.)


DEFINITION
Class:TaroCoins
Method:getNumber
Parameters:long long
Returns:long long
Method signature:long long getNumber(long long N)


NOTES
-The answer will always fit in a signed 64-bit integer.


CONSTRAINTS
-N will be between 1 and 1,000,000,000,000,000,000 (10^18), inclusive.


EXAMPLES

0)
1

Returns: 1

The only possible way to represent N in this case is to use one coin of value 1.

1)
6

Returns: 3

The following three representations are possible in this case: {1, 1, 2, 2}, {1, 1, 4} and {2, 4}

2)
47

Returns: 2



3)
256

Returns: 9



4)
8489289

Returns: 6853



5)
1000000000

Returns: 73411



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
        TaroCoins theObject;
        eq(0, theObject.getNumber(1LL),1LL);
    }
    {
        TaroCoins theObject;
        eq(1, theObject.getNumber(6LL),3LL);
    }
    {
        TaroCoins theObject;
        eq(2, theObject.getNumber(47LL),2LL);
    }
    {
        TaroCoins theObject;
        eq(3, theObject.getNumber(256LL),9LL);
    }
    {
        TaroCoins theObject;
        eq(4, theObject.getNumber(8489289LL),6853LL);
    }
    {
        TaroCoins theObject;
        eq(5, theObject.getNumber(1000000000LL),73411LL);
    }
}
// END CUT HERE
