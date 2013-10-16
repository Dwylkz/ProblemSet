// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndGo3.cpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class FoxAndGo3 {
	static const int N = 50+10;
  static const int to[8] = {0, 1, 1, 0, 0, -1, -1, 0};
  typedef pair<int, int> pii_t;
#define _x first
#define _y second
	public:
  int n, b[N][N], in[N][N];
  int scan(int x, int y) {
    int result = 0;
    for (int i = 0; i < 4; i++) {
      int tx = x+to[i<<1], ty = y+to[i<<1|1];
      if (b[tx][ty] == '.') result++;
    }
    return result;
  }
  pii_t find(int x, int y) {
    for (int i = 0; i < 4; i++) {
      int tx = x+to[i<<1], ty = y+to[i<<1|1];
      if (b[tx][ty] == '.') return pii_t(tx, ty);
    }
    return pii_t(-1, -1);
  }
  int bfs() {
    vector<pii_t>
    for (int h = 0; h < p.size(); h++)
  }
	int maxEmptyCells(vector <string> board) {
    n = board.size();
    p.clear();
    memset(in, 0, sizeof(in));
		for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        b[i+1][j+1] = board[i][j];
        if (b[i+1][j+1] == 'o') {
          p.push_back(pii_t(i+1, j+1));
          in[i+1][j+1] = 1;
        }
      }
    for (int i = 1; i <= n; i++)
      b[0][i] = b[n+1][i] = b[i][0] = b[i][n+1] = 'x';
    int result = bfs();
	}
};
