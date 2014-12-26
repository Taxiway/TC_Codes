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

class WakingUpEasy
{
public:
	int countAlarms(vector <int> volume, int S);
};

int WakingUpEasy::countAlarms(vector <int> volume, int S)
{
    int i = 0;
    for (i = 0; i < 100000; ++i) {
        int j = i % (sz(volume));
        S -= volume[j];
        if (S <= 0) {
            break;
        }
    }
    return i + 1;
}

// BEGIN CUT HERE

/*
// PROBLEM STATEMENT
// Alex is sleeping soundly. At any moment, his sleepiness can be characterized by an integer. You are given an int S that represents Alex's initial sleepiness.

Unfortunately, several alarms are going to disturb him. These alarms will be ringing in a cyclic order. Each alarm is characterized by its volume.

You are given a list of alarm volumes in a vector <int> volume in the order in which the alarms are going to ring. Every minute the first alarm on the list rings, and Alex's sleepiness instantly decreases by its volume. The alarm is then moved to the end of the alarm list.

While Alex's sleepiness is positive, he's still sleeping. Once it becomes less than or equal to zero, Alex immediately wakes up.

Return the number of alarms after which Alex will wake up.


DEFINITION
Class:WakingUpEasy
Method:countAlarms
Parameters:vector <int>, int
Returns:int
Method signature:int countAlarms(vector <int> volume, int S)


CONSTRAINTS
-volume will contain between 1 and 50 elements, inclusive.
-Each element of volume will be between 1 and 100, inclusive.
-S will be between 1 and 10000, inclusive.


EXAMPLES

0)
{5, 2, 4}
13

Returns: 4


Initially, Alex's sleepiness is 13, and the list of alarms is {5, 2, 4}.
After the first alarm, Alex's sleepiness is 8. The list of alarms becomes {2, 4, 5}.
After the second alarm, Alex's sleepiness is 6. The list of alarms becomes {4, 5, 2}.
After the third alarm, Alex's sleepiness is 2. The list of alarms becomes {5, 2, 4}.
After the fourth alarm, Alex's sleepiness is -3, so Alex wakes up.



1)
{5, 2, 4}
3

Returns: 1

The first alarm is enough here.

2)
{1}
10000

Returns: 10000

The only alarm has to ring 10000 times before Alex finally wakes up.

3)
{42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37,
  92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36,
  95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69}
9999

Returns: 203



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
        int volumeARRAY[] = {5, 2, 4};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUpEasy theObject;
        eq(0, theObject.countAlarms(volume, 13),4);
    }
    {
        int volumeARRAY[] = {5, 2, 4};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUpEasy theObject;
        eq(1, theObject.countAlarms(volume, 3),1);
    }
    {
        int volumeARRAY[] = {1};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUpEasy theObject;
        eq(2, theObject.countAlarms(volume, 10000),10000);
    }
    {
        int volumeARRAY[] = {42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37,
             92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36,
             95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69};
        vector <int> volume( volumeARRAY, volumeARRAY+ARRSIZE(volumeARRAY) );
        WakingUpEasy theObject;
        eq(3, theObject.countAlarms(volume, 9999),203);
    }
}
// END CUT HERE
