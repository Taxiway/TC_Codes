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

class BracketExpressions
{
public:
	string ifPossible(string expression);
};

const char *str = "()[]{}";
vector<int> v;
string ss;

bool isvalid(char c)
{
    return c == '(' || c == '[' || c == '{';
}

char other(char c)
{
    for (int i = 0; i < 6; ++i) {
        if (str[i] == c) return str[i + 1];
    }
    return ' ';
}

bool check(string &s, int f, int t)
{
    if (f == t) return true;
    if (!isvalid(s[f])) return false;
    char one = s[f], two = other(s[f]);
    int ct = 1;
    for (int i = f + 1; i < t; ++i) {
        if (s[i] == one) ++ct;
        else if (s[i] == two) --ct;
        if (ct == 0) {
            return check(s, f + 1, i) && check(s, i + 1 , t);
        }
    }
    return false;
}

bool dfs(vector<int> &s, int ind)
{
    if (ind == sz(s)) {
        for (int i = 0; i < sz(s); ++i) {
            ss[v[i]] = str[s[i]];
        }
        return check(ss, 0, sz(ss));
    }
    for (int i = 0; i < 6; ++i) {
        s[ind] = i;
        if (dfs(s, ind + 1)) return true;
    }
    return false;
}

string BracketExpressions::ifPossible(string expression)
{
    vector<int> s;
    v.clear();
    ss = expression;
    for (int i = 0; i < sz(expression); ++i) {
        if (expression[i] == 'X') {
            v.push_back(i);
            s.push_back(0);
        }
    }
    if (dfs(s, 0)) return "possible";
    else return "impossible";
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// We have three types of brackets: "()", "[]", and "{}".
We are now interested in some special strings.
A string is special if all the following conditions hold:

Each character of the string is one of the six bracket characters mentioned above.
The characters of the string can be divided into disjoint pairs such that in each pair we have an opening bracket and a closing bracket of the same type.
For each pair, the opening bracket must occur to the left of the corresponding closing bracket.
For each pair, the substring strictly between the opening and the closing bracket must be a special string (again, according to this definition).


For example, the empty string is a special string: there are 0 pairs of brackets.
The string "[]" is also a special string: there is one pair of matching brackets, they are in the proper order, and the string between them (which is the empty string) is a special string.

The character 'X' (uppercase x) occurs in expression at most five times; all other characters in expression are brackets of the types mentioned above.
We want to change expression into a special string by changing each 'X' into one of the brackets.
(Different occurrences of 'X' may be changed into different brackets.)
Return "possible" (quotes for clarity) if we can do that, and "impossible" otherwise.

DEFINITION
Class:BracketExpressions
Method:ifPossible
Parameters:string
Returns:string
Method signature:string ifPossible(string expression)


CONSTRAINTS
-expression will have between 1 and 50 characters, inclusive.
-Each character in expression will be '(', ')', '[', ']', '{', '}' or 'X'.
-There will be at most 5 occurences of 'X' in expression.


EXAMPLES

0)
"([]{})"

Returns: "possible"

This is already a special string. As there are no 'X's, we do not get to change anything.

1)
"(())[]"

Returns: "possible"



2)
"({])"

Returns: "impossible"



3)
"[]X"

Returns: "impossible"

Regardless of bracket type you put instead of 'X', you cannot create a special string.

4)
"([]X()[()]XX}[])X{{}}]"

Returns: "possible"

You can replace 'X's respectively with '{', '(', ')' and '['.

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
        BracketExpressions theObject;
        eq(0, theObject.ifPossible("([]{})"),"possible");
    }
    {
        BracketExpressions theObject;
        eq(1, theObject.ifPossible("(())[]"),"possible");
    }
    {
        BracketExpressions theObject;
        eq(2, theObject.ifPossible("({])"),"impossible");
    }
    {
        BracketExpressions theObject;
        eq(3, theObject.ifPossible("[]X"),"impossible");
    }
    {
        BracketExpressions theObject;
        eq(4, theObject.ifPossible("([]X()[()]XX}[])X{{}}]"),"possible");
    }
    {
        BracketExpressions theObject;
        eq(5, theObject.ifPossible("X[["),"possible");
    }
}
// END CUT HERE
