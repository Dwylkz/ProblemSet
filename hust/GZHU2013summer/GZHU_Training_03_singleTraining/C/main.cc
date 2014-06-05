#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
//   for ( ; ; ) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
      int A = a[1]*10 + a[2], B = a[4]*10 + a[5], C = a[7]*10 + a[8];
      if (a[0]*B*C + a[3]*A*C + a[6]*A*B == A*B*C)
        for (int i = 0; i < 9; i++)
          printf("%d%c", a[i], i<8? ' ': '\n');
    } while (next_permutation(a, a + 9));
//   }
  return 0;
}
