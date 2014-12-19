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

class CostOfDancing
{
public:
	int minimum(int K, vector <int> danceCost);
};

int CostOfDancing::minimum(int K, vector <int> danceCost)
{
    int ret = 0;
    sort(all(danceCost));
    for (int i = 0; i < K; ++i) ret += danceCost[i];
    return ret;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Gustavo studies at the Byteversity (one of the best universities in Byteland). He's also very keen on dancing, so he decided to enroll at a dance school.

The school offers many different courses, each teaching one dance. Different courses may have different costs. You are given a vector <int> danceCost. The elements of danceCost are the costs of all courses offered at the dance school.

Gustavo would like to learn exactly K of those dances. He is a poor student, so his only priority is to pay as little as possible for the courses.

You are given the int K and the vector <int> danceCost. Compute and return the smallest possible total cost of learning K dances.

DEFINITION
Class:CostOfDancing
Method:minimum
Parameters:int, vector <int>
Returns:int
Method signature:int minimum(int K, vector <int> danceCost)


CONSTRAINTS
-danceCost will contain between 1 and 1,000 elements, inclusive.
-Each element of danceCost will be between 1 and 1,000, inclusive.
-K will be between 1 and the number of elements in danceCost, inclusive.


EXAMPLES

0)
2
{1, 5, 3, 4}

Returns: 4

Gustavo must pay for exactly two out of the four given courses. The cheapest possibility is to pay 1 for one course and then 3 for another course. The total cost is 1+3 = 4.

1)
3
{1, 5, 4}

Returns: 10

Gustavo has no choice here. He has to pay for all three courses, which costs 1+5+4 = 10.

2)
1
{2, 2, 4, 5, 3}

Returns: 2

Among all 5 possible courses he can take, the cheapest one is either the course #0 or course #1 (0-based).

3)
39
{973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801}

Returns: 20431



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
        int danceCostARRAY[] = {1, 5, 3, 4};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(0, theObject.minimum(2, danceCost),4);
    }
    {
        int danceCostARRAY[] = {1, 5, 4};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(1, theObject.minimum(3, danceCost),10);
    }
    {
        int danceCostARRAY[] = {2, 2, 4, 5, 3};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(2, theObject.minimum(1, danceCost),2);
    }
    {
        int danceCostARRAY[] = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
            703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(3, theObject.minimum(39, danceCost),20431);
    }
}
// END CUT HERE
