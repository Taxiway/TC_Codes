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

class GoodCompanyDivTwo
{
public:
	int countGood(vector <int> superior, vector <int> workType);
};

int GoodCompanyDivTwo::countGood(vector <int> superior, vector <int> workType)
{
    int ret = 0;
    int n = sz(superior);
    for (int i = 0; i < n; ++i) {
        set<int> st;
        bool bad = false;
        for (int j = 0; j < n; ++j) {
            if (j == i || superior[j] == i) {
                if (st.count(workType[j])) bad = true;
                st.insert(workType[j]);
            }
        }
        if (!bad) ++ret;
    }
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Shiny has a company.
There are N employees in her company.
The employees are numbered 0 through N-1 in order in which they joined the company.



Employee 0 is the only employee with no boss.
Every other employee has precisely one direct boss in the company.
You are given a vector <int> superior with N elements.
Element 0 of superior will be -1 to denote that employee 0 has no boss.
For each i between 1 and N-1, inclusive, element i of superior will be the number of the boss of employee i.



For each employee, their boss joined the company before them.
Formally, for each i between 1 and N-1, inclusive, superior[i] will be between 0 and i-1, inclusive.



Each employee only does one type of work.
You are given a vector <int> workType with N elements.
(Different integers represent different types of work.)



Each employee of the company has their own department.
The department of employee x is formed by employee x and all the employees such that x is their boss.
Formally, for any y different from x, employee y belongs into the department of employee x if and only if superior[y]=x.
Note that if superior[z]=y and superior[y]=x, employee z does not belong into the department of employee x.



A department is called diverse if no two employees in the department do the same type of work.
Compute and return the number of diverse departments in Shiny's company.


DEFINITION
Class:GoodCompanyDivTwo
Method:countGood
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countGood(vector <int> superior, vector <int> workType)


CONSTRAINTS
-superior will contain between 1 and 100 elements, inclusive.
-workType will contain the same number of elements as superior.
-Each element of workType will be between 1 and 100, inclusive.
-superior[0] will be -1.
-For each valid i>0, superior[i] will be between 0 and i-1, inclusive.


EXAMPLES

0)
{-1, 0}
{1, 2}

Returns: 2

The department of employee 0 contains employees 0 and 1.
The department of employee 1 contains employee 1 only.
Both departments are diverse.

1)
{-1, 0}
{1, 1}

Returns: 1

The departments are the same as in Example 0.
However, now the department of employee 0 is not diverse: it contains two employees who do the same type of work.
Only the department of employee 1 is now diverse.

2)
{-1, 0, 1, 1}
{1, 4, 3, 2}

Returns: 4

Note that in this test case the department of employee 0 contains only employees 0 and 1. Employees 2 and 3 do not belong into the department of employee 0.

3)
{-1, 0, 1, 0, 0}
{3, 3, 5, 2, 2}

Returns: 4



4)
{-1, 0, 1, 1, 1, 0, 2, 5}
{1, 1, 2, 3, 4, 5, 3, 3}

Returns: 7



5)
{-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4}
{4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8}

Returns: 27



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
        int superiorARRAY[] = {-1, 0};
        vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
        int workTypeARRAY[] = {1, 2};
        vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
        GoodCompanyDivTwo theObject;
        eq(0, theObject.countGood(superior, workType),2);
    }
    {
        int superiorARRAY[] = {-1, 0};
        vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
        int workTypeARRAY[] = {1, 1};
        vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
        GoodCompanyDivTwo theObject;
        eq(1, theObject.countGood(superior, workType),1);
    }
    {
        int superiorARRAY[] = {-1, 0, 1, 1};
        vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
        int workTypeARRAY[] = {1, 4, 3, 2};
        vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
        GoodCompanyDivTwo theObject;
        eq(2, theObject.countGood(superior, workType),4);
    }
    {
        int superiorARRAY[] = {-1, 0, 1, 0, 0};
        vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
        int workTypeARRAY[] = {3, 3, 5, 2, 2};
        vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
        GoodCompanyDivTwo theObject;
        eq(3, theObject.countGood(superior, workType),4);
    }
    {
        int superiorARRAY[] = {-1, 0, 1, 1, 1, 0, 2, 5};
        vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
        int workTypeARRAY[] = {1, 1, 2, 3, 4, 5, 3, 3};
        vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
        GoodCompanyDivTwo theObject;
        eq(4, theObject.countGood(superior, workType),7);
    }
    {
        int superiorARRAY[] = {-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4};
        vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
        int workTypeARRAY[] = {4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8};
        vector <int> workType( workTypeARRAY, workTypeARRAY+ARRSIZE(workTypeARRAY) );
        GoodCompanyDivTwo theObject;
        eq(5, theObject.countGood(superior, workType),27);
    }
}
// END CUT HERE
