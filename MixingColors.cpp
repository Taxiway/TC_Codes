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

class MixingColors
{
public:
	int minColors(vector <int> colors);
};

int MixingColors::minColors(vector <int> colors)
{
    vector<vector<int> > v;
    for (int i = 0; i < sz(colors); ++i) {
        vector<int> vv;
        int now = colors[i];
        for (int j = 0; j < 32; ++j) {
            vv.push_back(now & 1);
            now >>= 1;
        }
        v.push_back(vv);
    }
    for (int i = 0; i < sz(v); ++i) {
        int ind = -1, kk = -1;
        for (int k = sz(v[i]) - 1; k >= 0; --k) {
            for (int j = i; j < sz(v); ++j) {
                if (v[j][k]) {
                    ind = j;
                    kk = k;
                }
            }
        }
        if (ind == -1) {
            return i;
        }
        if (ind != i) {
            swap(v[ind], v[i]);
            for (int j = i + 1; j < sz(v); ++j) {
                if (v[j][kk]) {
                    for (int k = 0; k < sz(v[j]); ++k) {
                        v[j][k] ^= v[i][k];
                    }
                }
            }
        }
    }
    return sz(colors);
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
	Danica is an artist. She would like to paint a picture, but currently she has no colors at all.



	For the purpose of this problem, colors are represented by positive integers. You are given a vector <int> colors. The elements of colors are the colors Danica needs to paint her picture.



	There is a store that sells colors. The store has an unlimited supply of all possible colors, including colors that Danica doesn't need. Danica will buy some colors in the store. Then, she will produce other colors by mixing the colors she bought.



	Danica can only mix two colors at a time. Mixing two different colors A and B produces the color (A XOR B). Colors obtained by mixing can later be used to produce other colors.



	Danica wants to buy as few distinct colors as possible. Note that she is allowed to buy colors she does not need for the picture.



	Return the smallest number of distinct colors Danica has to buy in order to be able to obtain all the colors she needs.


DEFINITION
Class:MixingColors
Method:minColors
Parameters:vector <int>
Returns:int
Method signature:int minColors(vector <int> colors)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 15 XOR 55 is performed as follows. First, the numbers are converted to binary: 15 is 1111 and 55 is 110111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 15 becomes 001111. Then 001111 XOR 110111 = 111000 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 111000 = 56, so 15 XOR 55 = 56.


CONSTRAINTS
-colors will contain between 1 and 50 elements, inclusive.
-Each element of colors will be between 1 and 1,000,000,000, inclusive.
-All elements of colors will be distinct.


EXAMPLES

0)
{1, 7, 3}

Returns: 3

Obviously, Danica can just buy the three colors she needs. However, there are also other optimal solutions. For example, she could buy colors 1, 2, and 4 instead. Then, she can mix these colors as follows:

She already has color 1.
She can obtain color 3 by mixing colors 1 and 2: we have 1 XOR 2 = 3.
She can obtain color 7 by first mixing colors 1 and 4 to produce color 5 (as 1 XOR 4 = 5), and then mixing colors 5 and 2 (as 5 XOR 2 = 7).


1)
{10}

Returns: 1

Danica should buy color 10 only.

2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

Returns: 4

Danica can, for instance, buy colors 11, 13, 14, and 15.

3)
{534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151}

Returns: 10



4)
{4, 8, 16, 32, 64, 128, 256, 512, 1024}

Returns: 9



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
        int colorsARRAY[] = {1, 7, 3};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(0, theObject.minColors(colors),3);
    }
    {
        int colorsARRAY[] = {10};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(1, theObject.minColors(colors),1);
    }
    {
        int colorsARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(2, theObject.minColors(colors),4);
    }
    {
        int colorsARRAY[] = {534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(3, theObject.minColors(colors),10);
    }
    {
        int colorsARRAY[] = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(4, theObject.minColors(colors),9);
    }
}
// END CUT HERE
