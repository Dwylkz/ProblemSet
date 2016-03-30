#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

static const int N = 11;
/* N+1 contour line */
static const int S = 1<<(N+1);

int h, w;
uint64_t f[N][N][S];

int main()
{
  while (scanf("%d%d", &h, &w) != EOF && !(h == 0 && w == 0)) {
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        for (int s = 0; s < S; s++)
        {
        }
      }
    }
  }

  return 0;
}
