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

class Subsets
{
public:
	int findSubset(vector <int> numbers);
};

int ret;

void dfs(vector<pair<int, int> > &v, int ind, int sum, int mul, int ones)
{
    if (ind == sz(v)) return;
    dfs(v, ind + 1, sum, mul, ones);
    for (int i = 0; i < v[ind].second; ++i) {
        sum += v[ind].first;
        mul *= v[ind].first;
        if (sum + ones <= mul) return;
        ret += (sum + ones - mul);
        dfs(v, ind + 1, sum, mul, ones);
    }
}

int Subsets::findSubset(vector <int> numbers)
{
    map<int, int> mp;
    for (int i = 0; i < sz(numbers); ++i) {
        mp[numbers[i]]++;
    }
    int ones = mp[1];
    mp.erase(mp.find(1));
    vector<pair<int, int> > v;
    for (map<int, int>::iterator mi = mp.begin(); mi != mp.end(); ++mi) {
        v.push_back(*mi);
    }
    ret = 0;
    dfs(v, 0, 0, 1, ones);
    if (ones) ret += (ones - 1);
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// You have a bag with some balls.
There is a positive integer written on each of the balls.
Balls with the same integer are identical.

A bag with balls is nice if the sum of numbers on all balls is strictly greater than the product of those numbers.
For example, if the numbers on balls are {1,1,2,3}, the bag is nice because 1+1+2+3 > 1*1*2*3.

You are given a vector <int> numbers.
Each element of numbers is a number written on one of the balls in your bag.
You are going to remove some (possibly none, but not all) balls from the bag.
After you do so, the bag must be nice.

Return the number of different nice bags you can obtain.

DEFINITION
Class:Subsets
Method:findSubset
Parameters:vector <int>
Returns:int
Method signature:int findSubset(vector <int> numbers)


NOTES
-You may assume that the return value always fits into a signed 32-bit integer variable.


CONSTRAINTS
-numbers will contain between 1 and 1000 elements, inclusive.
-Each element of numbers will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,1,1}

Returns: 2

The bag contains three identical balls, each with the number 1.
We can produce a nice bag in two ways:

Keep all three balls. The bag is nice because 1+1+1 > 1*1*1.
Throw away one ball. The bag is nice because 1+1 > 1*1.


1)
{1,1,1,1,2,2,2,2}

Returns: 13

Our bag contains 8 balls: four with a 1 and four with a 2.
All possible nice bags that can be produced by removing some of these balls are listed below, one per row.

1,1
1,1,1
1,1,1,1
1,2
1,1,2
1,1,1,2
1,1,1,1,2
1,2,2
1,1,2,2
1,1,1,2,2
1,1,1,1,2,2
1,1,1,2,2,2
1,1,1,1,2,2,2

2)
{1,2,3,4}

Returns: 3



3)
{1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50}

Returns: 77



4)
{1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2}

Returns: 100



5)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}

Returns: 8050



6)
{5,3}

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
        int numbersARRAY[] = {1,1,1};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        Subsets theObject;
        eq(0, theObject.findSubset(numbers),2);
    }
    {
        int numbersARRAY[] = {1,1,1,1,2,2,2,2};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        Subsets theObject;
        eq(1, theObject.findSubset(numbers),13);
    }
    {
        int numbersARRAY[] = {1,2,3,4};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        Subsets theObject;
        eq(2, theObject.findSubset(numbers),3);
    }
    {
        int numbersARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        Subsets theObject;
        eq(3, theObject.findSubset(numbers),77);
    }
    {
        int numbersARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        Subsets theObject;
        eq(4, theObject.findSubset(numbers),100);
    }
    {
        int numbersARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        Subsets theObject;
        eq(5, theObject.findSubset(numbers),8050);
    }
    {
        int numbersARRAY[] = {5,3};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        Subsets theObject;
        eq(6, theObject.findSubset(numbers),0);
    }
}
// END CUT HERE
