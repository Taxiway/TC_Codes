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

class EmployManager
{
public:
	int maximumEarnings(vector <int> value, vector <string> earning);
};

int EmployManager::maximumEarnings(vector <int> value, vector <string> earning)
{
    int ret = 0;
    int n = sz(value);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ret -= earning[i][j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        int lose = 0;
        for (int j = 0; j < n; ++j) {
            lose += earning[i][j] - '0';
        }
        if (lose > value[i]) {
            ret += (lose - value[i]);
        }
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Shiny wants to hire some managers for her company.
There are N candidates, numbered 0 through N-1.
She can employ any subset of these candidates, including possibly none or all of them.

For each of the candidates we know an amount in dollars Shiny must pay if she wants to hire that candidate.
You are given a vector <int> value with N elements.
For each i, value[i] is the amount in dollars Shiny has to pay if she wants to hire candidate i.

For each pair i < j of candidates we also know a value E(i,j) with the following meaning:

If both i and j are employed, the company will earn E(i,j) dollars.
However, if neither i nor j are employed, they will cooperate to harm the company, which will cost the company E(i,j) dollars.

If one of them is employed and the other isn't, nothing happens.
All the values E(i,j) are between 0 and 9, inclusive.

For your convenience, we also define E(i,i)=0 and E(j,i)=E(i,j) for all i and j.

You are given the above values E(i,j) encoded as a vector <string> earning with N elements, each consisting of N characters.
For each i and j, earning[i][j] is the character ('0'-'9') that represents the value E(i,j).

You are given the vector <int> value and the vector <string> earning.
Compute and return the largest total profit (i.e., earnings minus costs) the company can obtain by hiring a suitable subset of candidates.



DEFINITION
Class:EmployManager
Method:maximumEarnings
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int maximumEarnings(vector <int> value, vector <string> earning)


CONSTRAINTS
-value will contain between 1 and 50 elements, inclusive.
-earning will contain the same number of elements as value.
-The length of each element of earning will be the same as the number of elements in value.
-Each character in each element of earning will be a digit ('0'-'9').
-Each element of value will be between 0 and 1000, inclusive.
-For each i, earning[i][i] will be '0'.
-For each i and j, earning[i][j] will be equal to earning[j][i].


EXAMPLES

0)
{1, 1}
{"02", "20"}

Returns: 0

Hiring both managers is the optimal solution in this example.

1)
{2, 2}
{"01", "10"}

Returns: -1

Here it is best not to hire any manager.

2)
{1, 2, 3, 4}
{"0121", "1021", "2201", "1110"}

Returns: -1



3)
{2, 2, 0, 1, 4, 0, 1, 0, 0, 4}
{"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"}

Returns: 156



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
        int valueARRAY[] = {1, 1};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"02", "20"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(0, theObject.maximumEarnings(value, earning),0);
    }
    {
        int valueARRAY[] = {2, 2};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"01", "10"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(1, theObject.maximumEarnings(value, earning),-1);
    }
    {
        int valueARRAY[] = {1, 2, 3, 4};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"0121", "1021", "2201", "1110"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(2, theObject.maximumEarnings(value, earning),-1);
    }
    {
        int valueARRAY[] = {2, 2, 0, 1, 4, 0, 1, 0, 0, 4};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(3, theObject.maximumEarnings(value, earning),156);
    }
}
// END CUT HERE
