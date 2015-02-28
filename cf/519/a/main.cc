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

const int N = 8;
const int M = 8+5;

map<int, int> W = {
  {'Q', 9},
  {'R', 5},
  {'B', 3},
  {'N', 3},
  {'P', 1},
  {'K', 0},
};

char b[M][M];

int main()
{
  int nw = 0, nb = 0;
  for (int i = 0; i < N; i++) {
    scanf("%s", b[i]);
    for (int j = 0; j < N; j++) {
      if (b[i][j] == '.')
        continue;
      if (isupper(b[i][j]))
        nw += W[b[i][j]];
      else
        nb += W[toupper(b[i][j])];
    }
  }
  if (nw > nb)
    puts("White");
  else if (nb > nw)
    puts("Black");
  else
    puts("Draw");
  return 0;
}
