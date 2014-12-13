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

class NamingConvention
{
public:
	string toCamelCase(string variableName);
};

string NamingConvention::toCamelCase(string variableName)
{
	string ret = "";
	bool gao = false;
	for (int i = 0; i < sz(variableName); ++i) {
		if (variableName[i] == '_') gao = true;
		else {
			if (gao) {
				gao = false;
				ret += (variableName[i] - 'a' + 'A');
			} else {
				ret += variableName[i];
			}
		}
	}
	return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// In most programming languages variable names cannot contain spaces.
If we want a variable name that consists of two or more words, we have to encode the spaces somehow.
In this problem, we will look at two ways of doing so: Snake Case and Camel Case.
When using Snake Case, we just replace each space by an underscore ('_').
When using Camel Case, we capitalize the first letter of each word except for the first one, and then we remove all spaces.


For example, suppose that we want to declare a variable called "good morning world" (quotes for clarity).
In Snake Case, we would write this variable as "good_morning_world", while in Camel Case it would be "goodMorningWorld".


You are given a string variableName.
This string contains a valid variable name written in Snake Case.
Return the same variable name in Camel Case.

DEFINITION
Class:NamingConvention
Method:toCamelCase
Parameters:string
Returns:string
Method signature:string toCamelCase(string variableName)


CONSTRAINTS
-variableName will contain between 1 and 50 characters.
-Each character of variableName will be 'a'-'z' or '_'.
-The first and last character of variableName will not be '_'.
-variableName will not contain two consecutive underscores ('_').


EXAMPLES

0)
"sum_of_two_numbers"

Returns: "sumOfTwoNumbers"

We have 4 words: "sum", "of", "two", "numbers". So the answer is "sum" + "Of" + "Two" + "Numbers".

1)
"variable"

Returns: "variable"

Note that if we have only 1 word, then the varaible name will remain same.

2)
"t_o_p_c_o_d_e_r"

Returns: "tOPCODER"



3)
"the_variable_name_can_be_very_long_like_this"

Returns: "theVariableNameCanBeVeryLongLikeThis"



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
        NamingConvention theObject;
        eq(0, theObject.toCamelCase("sum_of_two_numbers"),"sumOfTwoNumbers");
    }
    {
        NamingConvention theObject;
        eq(1, theObject.toCamelCase("variable"),"variable");
    }
    {
        NamingConvention theObject;
        eq(2, theObject.toCamelCase("t_o_p_c_o_d_e_r"),"tOPCODER");
    }
    {
        NamingConvention theObject;
        eq(3, theObject.toCamelCase("the_variable_name_can_be_very_long_like_this"),"theVariableNameCanBeVeryLongLikeThis");
    }
}
// END CUT HERE
