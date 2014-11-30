#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e2+5;

int n, h[N];

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    memset(h, 0, sizeof(h));
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      h[ai-1]++;
    }
    int mid = 0;
    for (int i = 1; i < n; i++)
      if (h[i] > h[mid])
        mid = i;
    printf("%d\n", mid+1);
  }
  return 0;
}
