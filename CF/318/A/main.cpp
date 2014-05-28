#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
typedef long long LL;
const int maxn = 1e5 + 10;

LL n, k;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; cin >> n >> k; ) {
    if (k - 1 < n / 2 + n % 2) {
      k = (k - 1) * 2 + 1;
    } else {
      k = (k - 1 - (n / 2 + n % 2)) * 2 + 2;
    }
    cout << k << endl;
	} 
	return 0;
}
