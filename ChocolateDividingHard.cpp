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

class ChocolateDividingHard
{
public:
	int findBest(vector <string> chocolate);
};

int n, m;

int ss[100][100];

void init(vector<string> &v)
{
	for (int c = 0; c < m; ++c) {
		ss[c][0] = 0;
		for (int r = 0; r < n; ++r) {
			ss[c][r + 1] = ss[c][r] + v[r][c] - '0';
		}
	}
}

int getsum(int c, int from, int to)
{
	return ss[c][to + 1] - ss[c][from];
}

bool isok(int need)
{
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n - 1; ++k) {
				int s[4] = {0, 0, 0, 0};
				int done = 0;
				for (int x = 0; x < m; ++x) {
					s[0] += getsum(x, 0, i);
					s[1] += getsum(x, i + 1, j);
					s[2] += getsum(x, j + 1, k);
					s[3] += getsum(x, k + 1, n - 1);
					if (s[0] >= need && s[1] >= need && s[2] >= need && s[3] >= need) {
						++done;
						s[0] = s[1] = s[2] = s[3] = 0;
					}
				}
				if (done >= 4) return true;
			}
		}
	}
	return false;
}

int ChocolateDividingHard::findBest(vector <string> chocolate)
{
	n = sz(chocolate), m = sz(chocolate[0]);
	init(chocolate);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sum += chocolate[i][j] - '0';
		}
	}
	int down = 0, up = sum / 16 + 1;
	while (down + 1 < up) {
		int mid = (down + up) >> 1;
		if (isok(mid)) {
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
// Mirosz adores sweets.
He has just bought a rectangular bar of chocolate.
The bar is divided into a grid of square cells.
Different cells may have a different quality.
You are given the description of the bar in a vector <string> chocolate.
Each character in chocolate is a digit between '0' and '9', inclusive: the quality of one of the cells.

Mirosz is now going to divide the chocolate into 16 parts: one for him and one for each of his 15 friends.
He will do the division by making six cuts: three horizontal and three vertical ones.
Each cut must go between two rows or columns of cells.
Each of the 16 parts must be non-empty.
The quality of a part is the sum of the qualities of all cells it contains.

Mirosz is well-mannered and he will let his friends choose their pieces first.
His friends are even more addicted to chocolate than he is.
Therefore, they will certainly choose the pieces with higher quality first, and Mirosz will be left with the worst of the 16 pieces.

You are given the vector <string> chocolate.
Find the optimal places for the six cuts.
More precisely, compute and return the largest possible quality of Mirosz's part of the chocolate bar.

DEFINITION
Class:ChocolateDividingHard
Method:findBest
Parameters:vector <string>
Returns:int
Method signature:int findBest(vector <string> chocolate)


CONSTRAINTS
-chocolate will contain between 4 and 75 elements, inclusive. 
-All elements in chocolate will contain between 4 and 75 characters, inclusive. 
-All elements in chocolate will contain the same number of characters. 
-All elements in chocolate will contain only digits.


EXAMPLES

0)
{
"95998",
"21945",
"23451",
"99798",
"74083"
}

Returns: 3

One of two optimal ways to cut this chocolate is shown below. 

9 | 5 | 9 9 | 8 
--|---|-----|--- 
2 | 1 | 9 4 | 5 
2 | 3 | 4 5 | 1 
--|---|-----|--- 
9 | 9 | 7 9 | 8 
--|---|-----|--- 
7 | 4 | 0 8 | 3 

This way of cutting produces parts with the following qualities: 9, 5, 18, 8, 4, 4, 22, 6, 9, 9, 16, 8, 7, 4, 8, 3. The quality of the worst part (the one that Mirosz will get) is 3. 

Here is another way of cutting the same chocolate: 

9 | 5 9 | 9 | 8 
--|-----|---|--- 
2 | 1 9 | 4 | 5 
--|-----|---|--- 
2 | 3 4 | 5 | 1 
9 | 9 7 | 9 | 8 
--|-----|---|--- 
7 | 4 0 | 8 | 3  

If Mirosz cuts the chocolate in this way, the quality of his part will be 2, which is worse than 3.

1)
{
"12942",
"23456",
"99798",
"98998",
"67675"
}

Returns: 5



2)
{
"129420",
"234560",
"997980",
"989980",
"676760"
}

Returns: 6



3)
{"75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338"}

Returns: 44



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
        string chocolateARRAY[] = {
           "95998",
           "21945",
           "23451",
           "99798",
           "74083"
           };
        vector <string> chocolate( chocolateARRAY, chocolateARRAY+ARRSIZE(chocolateARRAY) );
        ChocolateDividingHard theObject;
        eq(0, theObject.findBest(chocolate),3);
    }
    {
        string chocolateARRAY[] = {
           "12942",
           "23456",
           "99798",
           "98998",
           "67675"
           };
        vector <string> chocolate( chocolateARRAY, chocolateARRAY+ARRSIZE(chocolateARRAY) );
        ChocolateDividingHard theObject;
        eq(1, theObject.findBest(chocolate),5);
    }
    {
        string chocolateARRAY[] = {
           "129420",
           "234560",
           "997980",
           "989980",
           "676760"
           };
        vector <string> chocolate( chocolateARRAY, chocolateARRAY+ARRSIZE(chocolateARRAY) );
        ChocolateDividingHard theObject;
        eq(2, theObject.findBest(chocolate),6);
    }
    {
        string chocolateARRAY[] = {"75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338"};
        vector <string> chocolate( chocolateARRAY, chocolateARRAY+ARRSIZE(chocolateARRAY) );
        ChocolateDividingHard theObject;
        eq(3, theObject.findBest(chocolate),44);
    }
}
// END CUT HERE
