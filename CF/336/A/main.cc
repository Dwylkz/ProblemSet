#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
const int maxn = 2e3 + 10;

int x, y;

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &x, &y); ) {
    int z = abs(x) + abs(y);
#define sig(x) ((x>0)? 1: -1)
    pair<int, int> A = make_pair(0, z*sig(y)),
      B = make_pair(z*sig(x), 0);
    if (A > B) swap(A, B);
    printf("%d %d %d %d\n", A.first, A.second, B.first, B.second);
  }
	return 0;
}
