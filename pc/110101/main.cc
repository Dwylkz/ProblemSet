// be careful with the bound like i, j when problem description
// doesn't metion that i <= j.
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

const int N = 1e6+5;

typedef long long LL;

int DFS(int n)
{
  // cerr << n << endl;
  if (n == 1)
    return 1;
  if (n%2)
    return DFS(n*3+1)+1;
  return DFS(n/2)+1;
}

int main()
{
  int i, j;
  while (~scanf("%d%d", &i, &j)) {
    int l = i, r = j;
    if (i > j)
      swap(i, j);

    int maxval = 0;
    for (int k = i; k <= j; k++)
      maxval = max(maxval, DFS(k));
    printf("%d %d %d\n", l, r, maxval);
  }
  return 0;
}
