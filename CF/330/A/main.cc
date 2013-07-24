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
const int maxn = 10 + 10;

int r, c, a[maxn][maxn];
char m[maxn][maxn];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &r, &c); ) {
    memset(a, 0, sizeof(a));
    Rep(i, 0, r) {
      scanf("%s", m + i);
    }
    Rep(i, 0, r) {
      int yes = 1;
      Rep(j, 0, c) {
        if (m[i][j] == 'S') {
          yes = 0;
          break;
        }
      }
      if (yes) {
        Rep(j, 0, c) {
          a[i][j] = 1;
        }
      }
    }
    Rep(i, 0, c) {
      int yes = 1;
      Rep(j, 0, r) {
        if (m[j][i] == 'S') {
          yes = 0;
          break;
        }
      }
      if (yes) {
        Rep(j, 0, r) {
          a[j][i] = 1;
        }
      }
    }
    int sum = 0;
    Rep(i, 0, r) {
      Rep(j, 0, c) {
        sum += a[i][j];
      }
    }
    printf("%d\n", sum);
  }
	return 0;
}
