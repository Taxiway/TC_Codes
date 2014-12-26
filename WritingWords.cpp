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

class WritingWords
{
public:
	int write(string word);
};

int WritingWords::write(string word)
{
    int ret = 0;
    for (int i = 0; i < sz(word); ++i) {
        ret += word[i] - 'A' + 1;
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Fox Ciel wants to type a word on her old cell phone. The cell phone has only one button. The letter A is typed by tapping the button once, B by tapping it twice in a row, and so on, in alphabetical order. Thus, the last letter Z is typed by tapping the button 26 times without a pause.

You are given a string word. Compute and return the answer to the following question: How many times will Ciel tap the button while typing this word?

DEFINITION
Class:WritingWords
Method:write
Parameters:string
Returns:int
Method signature:int write(string word)


NOTES
-While typing a word, Ciel has to make a short pause after typing each letter, so that the phone can tell when one letter ends and another letter begins. These pauses do not matter in this problem.


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-Each character in word will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"A"

Returns: 1

One tap types the letter A.

1)
"ABC"

Returns: 6

To type ABC, Ciel will do the following:

Tap the button once to type A.
Tap the button twice to type B.
Tap the button three times to type C.

The total number of taps is 1+2+3 = 6.

2)
"VAMOSGIMNASIA"

Returns: 143



3)
"TOPCODER"

Returns: 96



4)
"SINGLEROUNDMATCH"

Returns: 183



5)
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"

Returns: 1300



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
        WritingWords theObject;
        eq(0, theObject.write("A"),1);
    }
    {
        WritingWords theObject;
        eq(1, theObject.write("ABC"),6);
    }
    {
        WritingWords theObject;
        eq(2, theObject.write("VAMOSGIMNASIA"),143);
    }
    {
        WritingWords theObject;
        eq(3, theObject.write("TOPCODER"),96);
    }
    {
        WritingWords theObject;
        eq(4, theObject.write("SINGLEROUNDMATCH"),183);
    }
    {
        WritingWords theObject;
        eq(5, theObject.write("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"),1300);
    }
}
// END CUT HERE
