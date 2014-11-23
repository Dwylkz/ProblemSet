#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 8+5;
const int B = 8;

char b[N][N];

int vec[][2] = {
  {0, 1}, {1, 0}, {0, -1}, {-1, 0},
  {1, 1}, {1, -1}, {-1, -1}, {-1, 1},
  {1, 2}, {2, 1}, {2, -1}, {1, -2},
  {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};

struct Chess {
  int start, end, len;

  Chess()
  {
  }

  Chess(int start_, int end_, int len_):
      start(start_), end(end_), len(len_)
  {
  }
};

map<char, Chess> chess;

void Init() {
  chess['P'] = Chess(6, 8, 1);
  chess['p'] = Chess(4, 6, 1);
  chess['n'] = chess['N'] = Chess(8, 16, 1);
  chess['b'] = chess['B'] = Chess(4, 8, 8);
  chess['r'] = chess['R'] = Chess(0, 4, 8);
  chess['q'] = chess['Q'] = Chess(0, 8, 8);
  chess['k'] = chess['K'] = Chess(0, 8, 1);
}

bool IsIn(int x, int y)
{
  return x >= 0 && x < B && y >= 0 && y < B;
}

bool IsCheck(Chess& _, int x, int y, char k)
{
  for (int i = 1; i <= _.len; i++)
    for (int j = _.start; j < _.end; j++) {
      int tx = x+vec[j][0]*i;
      int ty = y+vec[j][1]*i;
      if (IsIn(tx, ty) && b[tx][ty] != '.')
        return b[tx][ty] == k;
    }
  return false;
}

int Check()
{
  for (int i = 0; i < B; i++)
    for (int j = 0; j < B; j++)
      if (islower(b[i][j]) && IsCheck(chess[b[i][j]], i, j, 'K'))
        return 0;
      else if (isupper(b[i][j]) && IsCheck(chess[b[i][j]], i, j, 'k'))
        return 1;
  return 2;
}

int main()
{
  int kase = 1;
  while (true) {
    int cnt = 0;
    for (int i = 0; i < B; i++) {
      scanf("%s", b[i]);
      cnt += count(b[i], b[i]+B, '.');
    }
    if (cnt == B*B)
      break;
    const char* ans[] = {
      "white king is in check.",
      "black king is in check.",
      "no king is in check."
    };
    Init();
    printf("Game #%d: %s\n", kase++, ans[Check()]);
  }
  return 0;
}
