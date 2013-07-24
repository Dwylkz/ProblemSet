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
const int maxn = 2e3 + 10;

int n;
char t[maxn << 1];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%s", &n, t); ) {
    int tl = strlen(t), sum = 0;
    for (int i = 0; i < tl; i += n) {
      if (i > 3) {
        if (t[i - 1] == t[i - 2] && t[i - 2] == t[i - 3]) {
          sum++;
        }
      }
    }
    printf("%d\n", sum);
  }
	return 0;
}
