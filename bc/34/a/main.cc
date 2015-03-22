#pragma comment(linker,"/STACK:65536000,65536000")
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int n, m;

int main()
{
  while (~scanf("%d%d", &n, &m)) {
    int minv = -1;
    for (int i = 0; i < m; i++) {
      int ai, bi;
      scanf("%d%d", &ai, &bi);
      int cny = (n+ai-1)/ai*bi;
      if (minv == -1 || minv > cny) minv = cny;
    }
    printf("%d\n", minv);
  }
  return 0;
}
