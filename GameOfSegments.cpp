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

class GameOfSegments
{
public:
	int winner(int N);
};

bool win[1024];
map<map<int, int>, bool> wl;

bool gao(map<int, int> mp)
{
    if (wl.find(mp) != wl.end()) {
        return wl[mp];
    }
    for (map<int, int>::iterator mi = mp.begin(); mi != mp.end(); ++mi) {
        int now = mi->first;
        int ct = mi->second;
        map<int, int> next = mp;
        if (ct == 1) {
            next.erase(next.find(now));
        } else {
            --next[now];
        }
        for (int i = 0; i + i < now - 1; ++i) {
            int a = i, b = now - a - 2;
            map<int, int> final = next;
            if (a >= 2) {
                final[a]++;
            }
            if (b >= 2) {
                final[b]++;
            }
            if (!gao(final)) {
                return wl[mp] = true;
            }
        }
    }
    return wl[mp] = false;
}

int GameOfSegments::winner(int N)
{
    int arr[] = {0, 1, 5, 9, 15, 21, 25, 29, 35, 39, 43, 55, 59, 63, 73, 77, 89, 93, 97, 107, 111};
    vector<int> v;
    for (int i = 0; arr[i] != 111; ++i) v.push_back(arr[i]);
    for (int i = 0; ; ++i) {
        if (i == sz(v)) {
            v.push_back(v[i - 5] + 34);
        }
        if (N == v[i]) {
            return 2;
        }
        if (N < v[i]) {
            return 1;
        }
    }
    return 1;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Rijél is a very wise teacher. He loves mathematics, especially games and geometry problems. Recently one of his students challenged him to the following game:

Initially, there is a polygon with N vertices drawn in the plane. The polygon is strictly convex, i.e., each internal angle is strictly smaller than 180 degrees. The vertices of the polygon are numbered 1 through N, in clockwise order.

Two players play the game on this polygon. The players take alternating turns. In each turn, the current player chooses a diagonal or a side of the polygon and draws it as a straight line segment. (A diagonal of the polygon is a line segment that connects any two non-adjacent vertices of the polygon.) The player is only allowed to choose a diagonal or a side that does not intersect any of the previously drawn segments (it must not share endpoints with any of them either). The player who cannot draw a diagonal or a side according to the above rules loses the game.

You are given the int N.

We assume that both players play the game optimally. Return 1 if the first player wins and 2 otherwise.

DEFINITION
Class:GameOfSegments
Method:winner
Parameters:int
Returns:int
Method signature:int winner(int N)


CONSTRAINTS
-N will be between 3 and 1,000, inclusive.


EXAMPLES

0)
3

Returns: 1

This polygon has zero diagonals and three sides. The first player will always win no matter which side he picks.

1)
4

Returns: 1

This polygon has four sides and two diagonals. The first player wins the game if he takes one of the diagonals, because he will leave no choice for the second player.

2)
15

Returns: 2



3)
191

Returns: 2



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
        GameOfSegments theObject;
        eq(0, theObject.winner(3),1);
    }
    {
        GameOfSegments theObject;
        eq(1, theObject.winner(4),1);
    }
    {
        GameOfSegments theObject;
        eq(2, theObject.winner(15),2);
    }
    {
        GameOfSegments theObject;
        eq(3, theObject.winner(191),2);
    }
}
// END CUT HERE
