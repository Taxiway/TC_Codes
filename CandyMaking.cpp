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

class CandyMaking
{
public:
	double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight);
};

vector<int> v, w;

double gao(double d)
{
    double ret = 0;
    for (int i = 0; i < sz(v); ++i) {
        ret += fabs(w[i] - v[i] * d);
    }
    return ret;
}

double CandyMaking::findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight)
{
    v = containerVolume, w = desiredWeight;
    double down = 0, up = 0;
    for (int i = 0; i < sz(containerVolume); ++i) {
        up = max(up, desiredWeight[i] * 1.0 / containerVolume[i]);
    }
    for (int i = 0; i < 320; ++i) {
        double left = down + (up - down) / 3, right = down + (up - down) * 2 / 3;
        double vleft = gao(left), vright = gao(right);
        if (vleft < vright) {
            up = right;
        } else {
            down = left;
        }
    }
    return gao((down + up) / 2);
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// 
Alice likes making candy.
Recently, she promised to make candy for all her classmates.
Alice has N classmates.
We will number them 0 through N-1, inclusive.



Each of the classmates brought Alice one container for the candy.
Each of the classmates also has a desired total weight of their candy.
You are given this information as two vector <int>s with N elements each: containerVolume and desiredWeight.
For each i, the volume of the container brought by classmate i is containerVolume[i] liters, and he or she expects the candy in the container to weigh desiredWeight[i] grams.



Alice has promised to fill all containers with candy completely.
However, she only has the time to make one type of candy, with constant density.
This means that she might be unable to meet the exact desired weights of candy.



Alice now needs to choose the density of the candy she is going to make.
In order to make everyone as happy as possible, Alice decided that she wants to minimize the sum of differences between desired and actual weights.
In other words:
For each classmate, we compute the positive difference between the desired and actual weight of candy they received.
Then, we sum all those differences.
Alice needs to choose the density of her candy so that this sum becomes as small as possible.



Compute and return the minimum sum  of differences between desired and actual weights.


DEFINITION
Class:CandyMaking
Method:findSuitableDensity
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight)


NOTES
-Your return value must have an absolute or a relative error at most 1e-9.


CONSTRAINTS
-N will be between 1 and 50.
-containerVolume and desiredWeight will each contain exactly N elements.
-Each element of containerVolume and desiredWeight will between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{5}
{1000}

Returns: 0.0

There is one classmate. Her container has 5 liters and she expects 1000 grams of candy. Alice should choose the density of 200 grams per liter. The sum of differences between desired and actual weights is 0.

1)
{10,10}
{1000,2000}

Returns: 1000.0

There are two classmates. They have a 10-liter container each. However, one of them wants 1000 grams of candy and the other wants 2000 grams. There is no way for Alice to satisfy both of them exactly. (Note that she must always fill all containers completely.)

There are multiple optimal choices for the density. For these choices, the sum of differences between desired and actual weights is 1000.

2)
{10,20,40}
{4000,2000,1000}

Returns: 5250.0



3)
{1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121}
{3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223}

Returns: 983673.2727272725



4)
{30621,30620,2}
{1,1,1000000}

Returns: 999999.9999673415



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
        int containerVolumeARRAY[] = {5};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {1000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(0, theObject.findSuitableDensity(containerVolume, desiredWeight),0.0);
    }
    {
        int containerVolumeARRAY[] = {10,10};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {1000,2000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(1, theObject.findSuitableDensity(containerVolume, desiredWeight),1000.0);
    }
    {
        int containerVolumeARRAY[] = {10,20,40};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {4000,2000,1000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(2, theObject.findSuitableDensity(containerVolume, desiredWeight),5250.0);
    }
    {
        int containerVolumeARRAY[] = {1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(3, theObject.findSuitableDensity(containerVolume, desiredWeight),983673.2727272725);
    }
    {
        int containerVolumeARRAY[] = {30621,30620,2};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {1,1,1000000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(4, theObject.findSuitableDensity(containerVolume, desiredWeight),999999.9999673415);
    }
}
// END CUT HERE
