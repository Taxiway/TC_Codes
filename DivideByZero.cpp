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

class DivideByZero
{
public:
	int CountNumbers(vector <int> numbers);
};

int DivideByZero::CountNumbers(vector <int> numbers)
{
	bool num[102];
	memset(num, false, sizeof(num));
	for (int i = 0; i < sz(numbers); ++i) {
		num[numbers[i]] = true;
	}
	for (int t = 0; t < 101; ++t) {
		for (int i = 1; i <= 100; ++i) {
			for (int j = 1; j < i; ++j) {
				if (num[i] && num[j]) {
					num[i / j] = true;
				}
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= 100; ++i) {
		if (num[i]) ++ret;
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Little John has a piece of paper with some distinct integers written on it.
You are given a vector <int> numbers.
The elements of numbers are the numbers written on John's paper.

John is now going to add some new numbers to his paper.
While doing so, he will be using integer division.
When doing integer division, we discard the fractional part of the result.
In this problem, we will use "div" to denote integer division.
For example, 15 div 5 = 3, and 24 div 5 = 4.

John will repeat the following process:
He will look at his paper and select two distinct numbers A and B such that A is greater than B.
He will compute C = A div B.
If C is not written on his paper yet, he will add it to the paper.

The process will stop once there is no way for John to add a new number to his paper.
Compute and return how many numbers will there be on John's paper at the end.

DEFINITION
Class:DivideByZero
Method:CountNumbers
Parameters:vector <int>
Returns:int
Method signature:int CountNumbers(vector <int> numbers)


NOTES
-The return value does not depend on the order in which John adds new numbers to his paper.


CONSTRAINTS
-numbers will contain between 1 and 100 elements, inclusive.
-Each element of numbers will be between 1 and 100, inclusive.
-The elements in numbers will be distinct.


EXAMPLES

0)
{9, 2}

Returns: 3

John starts with just 9 and 2 on his paper.
He can add the number 4, because 9 div 2 = 4.
After he adds the number 4, there will be no more numbers to add, because 9 div 4 = 2, and also 4 div 2 = 2.
Thus, at the end John's paper will contain 3 numbers: 9, 2, and 4.

1)
{8, 2}

Returns: 3



2)
{50}

Returns: 1

We only have one number. There isn't anything John can do.

3)
{1, 5, 8, 30, 15, 4}

Returns: 11



4)
{1, 2, 4, 8, 16, 32, 64}

Returns: 7



5)
{6, 2, 18}

Returns: 7

Once John has a number on his paper, he can use it when producing new numbers.
For example, in this case he can add 9 (computed as 18 div 2), and then add 1 (computed as 9 div 6).
The numbers he will have at the end are 1, 2, 3, 4, 6, 9, and 18.

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
        int numbersARRAY[] = {93, 37, 77, 96, 7, 59, 8, 90, 45, 91, 44, 58, 40, 74, 47, 35, 88, 99, 92, 66};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(0, theObject.CountNumbers(numbers),3);
    }
    {
        int numbersARRAY[] = {8, 2};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(1, theObject.CountNumbers(numbers),3);
    }
    {
        int numbersARRAY[] = {50};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(2, theObject.CountNumbers(numbers),1);
    }
    {
        int numbersARRAY[] = {1, 5, 8, 30, 15, 4};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(3, theObject.CountNumbers(numbers),11);
    }
    {
        int numbersARRAY[] = {1, 2, 4, 8, 16, 32, 64};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(4, theObject.CountNumbers(numbers),7);
    }
    {
        int numbersARRAY[] = {6, 2, 18};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(5, theObject.CountNumbers(numbers),7);
    }
}
// END CUT HERE
