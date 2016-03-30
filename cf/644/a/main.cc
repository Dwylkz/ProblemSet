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

const int N = 100+5;

int n;
int a;
int b;
int p[N][N];

int main()
{
  scanf("%d%d%d", &n, &a, &b);
  if (n > a*b) 
  {
    puts("-1");
    return 0;
  }
  int i = 0;
  int j = 0;
  for (int k = 1; k <= n; k++)
  {
    int rj = j;
    if (i%2 == 1)
    {
      rj = b-j-1;
    }
    p[i][rj] = k;
    j += 1;
    if (j == b)
    {
      i += 1;
      j = 0;
    }
  }
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      printf("%d%c", p[i][j], j < b-1? ' ': '\n');
    }
  }
  return 0;
}
