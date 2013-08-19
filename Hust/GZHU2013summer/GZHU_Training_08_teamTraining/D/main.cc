#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 128;

char lcd[N][N];

void show() {
  for (int i = 0; i < 32; i++) {
    int x;
    scanf("%X", &x);
    for (int j = 0; j < 8; j++)
      if (x>>j&1) lcd[j][i] = '*';
      else lcd[j][i] = '.';
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 32; j++) {
      putchar(lcd[i][j]);
    }
    puts("");
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    show();
    show();
  }
  return 0;
}
