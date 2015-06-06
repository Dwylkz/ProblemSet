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

const int N = 50+5;

int n, m;
char b[N][N];

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", b[i]);
  int cnt = 0;
  for (int i = 0; i < n-1; i++)
    for (int j = 0; j < m-1; j++) {
      set<char> h;
      h.insert(b[i][j]);
      h.insert(b[i][j+1]);
      h.insert(b[i+1][j+1]);
      h.insert(b[i+1][j]);
      if (h.count('f') && h.count('a') && h.count('c') && h.count('e'))
        cnt++;
    }
  printf("%d\n", cnt);
  return 0;
}
