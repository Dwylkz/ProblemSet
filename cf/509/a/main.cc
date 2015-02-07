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

using namespace std;

const int N = 10+5;

int n, c[N][N];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < N; i++)
    c[0][i] = c[i][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j < N; j++)
      c[i][j] = c[i][j-1]+c[i-1][j];
  // for (int i = 0; i < N; i++)
  //   for (int j = 0; j < N; j++)
  //     printf("%6d%c", c[i][j], j < N-1? ' ': '\n');
  printf("%d\n", c[n-1][n-1]);
  return 0;
}
