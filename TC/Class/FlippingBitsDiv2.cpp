// BEGIN CUT HERE
PROBLEM STATEMENT
Goose Tattarrattat has a sequence B of bits.
Tattarrattat also has a favorite positive integer M.
M divides the number of bits in B.

Tattarrattat wants to have a sequence in which all the bits are 1s.
She will produce such a sequence in a sequence of steps.
In each step she can do one of the following three types of changes to the sequence:


Flip any bit (from 1 to 0 or from 0 to 1).
Flip the first k*M bits, for any positive integer k.
Flip the last k*M bits, for any positive integer k.


For example, suppose that B="110100001001" and M=4.
There are 17 different sequences Tattarrattat can produce from this B in a single step.
Among those sequences are "100100001001" (flipped the second bit), "001011111001" (flipped the first 2*M bits), and "110100000110" (flipped the last M bits).

You are given a vector <string> S and the int M.
Concatenate all elements of S to obtain one long string.
This string will represent the sequence B: each of its characters will be either '0' or '1'.
Return the minimal number of steps required to obtain a sequence that consists of 1s only.

DEFINITION
Class:FlippingBitsDiv2
Method:getmin
Parameters:vector <string>, int
Returns:int
Method signature:int getmin(vector <string> S, int M)


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element of S will contain between 1 and 50 characters, inclusive.
-Each character in each element of S will be '0' or '1'.
-M will be between 1 and 2500.
-M will be a divisor of N, where N is the number of characters in S.


EXAMPLES

0)
{"00111000"}
1

Returns: 2

There are several optimal solutions.
For example, she can flip the first 5*1 bits (obtaining "11000000") and then the last 6*1 bits (obtaining "11111111").
Another solution: she can flip the first 2*1 bits (obtaining "11111000") and then the last 3*1 bits (obtaining "11111111").

1)
{"00111000"}
2

Returns: 3



2)
{"111111"}
3

Returns: 0

This sequence already consists of 1s only, so no steps are necessary.

3)
{"00100"}
5

Returns: 2



4)
{"00010","11010110","1010111","110001010","0110001100"
,"000110110","011010101","00","111","100"}

13

Returns: 31

Don't forget to concatenate the elements of S.

// END CUT HERE
#line 90 "FlippingBitsDiv2.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define DX(x) 	((int)x.size())
#define WJ 	push_back
#define WC	pop_back
#define DD(x)	x::iterator
#define KS(x)	x.begin()
#define JS(x)	x.end()

class FlippingBitsDiv2 {
	static const int N = 1e5;
	public:
	int getmin(vector <string> S, int M) {
		
	}
};
