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

class MyVeryLongCake
{
public:
	int cut(int n);
};

int MyVeryLongCake::cut(int n)
{
    int nn = n;
    vector<int> v;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) v.push_back(n);
    int s = sz(v);
    int ret = 0;
    for (int i = 1; i < (1 << s); ++i) {
        int d = 1, m = -1;
        for (int j = 0; j < s; ++j) {
            if (i & (1 << j)) {
                d *= v[j];
                m *= -1;
            }
        }
        ret += m * (nn / d - 1);
    }
    return ret + 1;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You have a long thin cake. For simplicity, we can consider the cake to be one-dimensional. The length of the cake is n. 

You are expecting some friends. You are going to cut the cake into multiple pieces before the friends arrive.

When the friends arrive, you will divide the cake among them, using the following procedure: starting at the beginning of the cake, you will first give some consecutive pieces to your first friend, then some consecutive pieces to your second friend, and so on.

Of course, you want to be fair. That is, each of your friends should receive the same total amount of cake. (The number of pieces may be different for different friends, but the sum of their lengths must be the same.)

As we stated above, you want to cut the cake before your friends arrive. However, you don't know how many friends will actually come. You only know that their count will be a divisor of n smaller than n.

You are given the int n. You want to cut the cake in such a way that for each valid number of friends it will be possible to give each of them the same amount of cake when using the above procedure. Return the smallest possible number of pieces after you cut the cake.

DEFINITION
Class:MyVeryLongCake
Method:cut
Parameters:int
Returns:int
Method signature:int cut(int n)


CONSTRAINTS
-n will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
6

Returns: 4

The best possible solution is to cut the cake into 4 pieces. Let's call the pieces A, B, C, and D, in order. Their lengths will be 2, 1, 1, and 2.

As n=6, there will be 1, 2, or 3 friends. If there is just one friend, she gets all four pieces. If there are two friends, the first gets A+B and the second gets C+D. If there are three friends, the first gets A, the second gets B+C, and the third gets D.

Note that the order of parts matters. For example, dividing the cake into parts of length 2, 1, 2, and 1 is not a valid solution.

1)
3

Returns: 1

In this case, the only possible number of friends that will come to your house is 1. Hence, you don't even need to cut the cake, simply leave it in one piece.

2)
15

Returns: 7

You are expecting 1, 3, or 5 friends.

3)
1000000000

Returns: 600000000



4)
577007436

Returns: 384671628



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
        MyVeryLongCake theObject;
        eq(0, theObject.cut(6),4);
    }
    {
        MyVeryLongCake theObject;
        eq(1, theObject.cut(3),1);
    }
    {
        MyVeryLongCake theObject;
        eq(2, theObject.cut(15),7);
    }
    {
        MyVeryLongCake theObject;
        eq(3, theObject.cut(1000000000),600000000);
    }
    {
        MyVeryLongCake theObject;
        eq(4, theObject.cut(577007436),384671628);
    }
}
// END CUT HERE
