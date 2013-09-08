// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel is teaching her friend Jiro to play Go.
Ciel has just placed some white and some black tokens onto a board.
  She now wants Jiro to find the best possible move.
(This is defined more precisely below.)


  You are given a vector <string> board.
  Character j of element i of board represents the cell (i,j) of the board:
  'o' is a cell with a white token, 'x' a cell with a black token, and '.' is an empty cell.
  At least one cell on the board will be empty.


  Jiro's move will consist of adding a single black token to the board.
  The token must be placed onto an empty cell.
  Once Jiro places the token, some white tokens will be removed from the board according to the rules described in the next paragraphs.


  The white tokens on the board can be divided into connected components using the following rules:
  If two white tokens lie in cells that share an edge, they belong to the same component.
  Being in the same component is transitive: if X lies in the same component as Y and Y lies in the same component as Z, then X lies in the same component as Z.


  Each component of white tokens is processed separately.
  For each component of white tokens we check whether it is adjacent to an empty cell.
(That is, whether there are two cells that share an edge such that one of them is empty and the other contains a white token from the component we are processing.)
  If there is such an empty cell, the component is safe and its tokens remain on the board.
  If there is no such empty cell, the component is killed and all its tokens are removed from the board.


  Jiro's score is the total number of white tokens removed from the board after he makes his move.
  Return the maximal score he can get for the given board.


  DEFINITION
  Class:FoxAndGo
  Method:maxKill
  Parameters:vector <string>
  Returns:int
Method signature:int maxKill(vector <string> board)


  NOTES
  -The position described by board does not have to be a valid Go position. In particular, there can already be components of white tokens that have no adjacent empty cell.
  -Please ignore official Go rules. The rules described in the problem statement are slightly different. For example, in this problem the black tokens cannot be killed, and it is allowed to place the black token into any empty cell.


  CONSTRAINTS
  -n will be between 2 and 19, inclusive.
  -board will contain exactly n elements.
  -Each element in board will contain exactly n characters.
  -Each character in board will be 'o', 'x' or '.'.
  -There will be at least one '.' in board.


  EXAMPLES

  0)
{".....",
  "..x..",
  ".xox.",
  ".....",
  "....."}


Returns: 1

To kill the only white token, Jiro must place his black token into the cell (3,2). (Both indices are 0-based.)

  1)
{"ooooo",
  "xxxxo",
  "xxxx.",
  "xxxx.",
  "ooooo"}


Returns: 6

By placing the token to the cell (2,4) Jiro kills 6 white tokens. The other possible move only kills 5 tokens.

2)
{".xoxo",
  "ooxox",
  "oooxx",
  "xoxox",
  "oxoox"}


Returns: 13

There is only one possible move. After Jiro makes it, all the white tokens are killed.

3)
{".......",
  ".......",
  ".......",
  "xxxx...",
  "ooox...",
  "ooox...",
  "ooox..."}


Returns: 9

Regardless of where Jiro moves, the 9 white tokens in the lower left corner will be killed.

4)
{".......",
  ".xxxxx.",
  ".xooox.",
  ".xo.ox.",
  ".xooox.",
  ".xxxxx.",
  "......."}


Returns: 8



5)
{"o.xox.o",
  "..xox..",
  "xxxoxxx",
  "ooo.ooo",
  "xxxoxxx",
  "..xox..",
  "o.xox.o"}


Returns: 12



6)
{".......",
  "..xx...",
  ".xooox.",
  ".oxxox.",
  ".oxxxo.",
  "...oo..",
  "......."}

Returns: 4



7)
{".ox....",
  "xxox...",
  "..xoox.",
  "..xoox.",
  "...xx..",
  ".......",
  "......."}


Returns: 5



8)
{"...................",
  "...................",
  "...o..........o....",
  "................x..",
  "...............x...",
  "...................",
  "...................",
  "...................",
  "...................",
  "...................",
  "...................",
  "...................",
  "...................",
  "...................",
  "................o..",
  "..x................",
  "...............x...",
  "...................",
  "..................."}


Returns: 0



// END CUT HERE
#line 192 "FoxAndGo.cpp"
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
const int N = 19+10;
const int M = N*N;

class FoxAndGo {
  public:
    vector<string> b;
    int n, m, cc[M], ec[M], cci, g[N][N], cnt, sm[N][N];
    int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool chk(int x, int y) {
      return 0 <= x && x < n && 0 <= y && y < m;
    }
    void dfs(int x, int y) {
      cnt++;
      g[x][y] = cci;
      for (int i = 0; i < 4; i++) {
        int tx = x+mv[i][0], ty = y+mv[i][1];
        if (chk(tx, ty) && g[tx][ty] == -1 && b[tx][ty] == 'o')
          dfs(tx, ty);
      }
    }
    int maxKill(vector <string> board) {
      b = board;
      n = b.size(), m = b[0].size();
      cci = 0;
      memset(g, -1, sizeof(g));
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (b[i][j] == 'o' && g[i][j] == -1) {
            cnt = 0;
            dfs(i, j);
            cc[cci++] = cnt;
          }
      memset(ec, 0, sizeof(ec));
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (b[i][j] == '.') {
            int v[M] = {0};
            for (int k = 0; k < 4; k++) {
              int tx = i+mv[k][0], ty =j+mv[k][1];
              if (chk(tx, ty) && b[tx][ty] == 'o' && !v[g[tx][ty]]) {
                ec[g[tx][ty]]++;
                v[g[tx][ty]] = 1;
              }
            }
          }
      memset(sm, 0, sizeof(sm));
      int rv = 0;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (b[i][j] == '.') {
            int v[M] = {0};
            for (int k = 0; k < 4; k++) {
              int tx = i+mv[k][0], ty = j+mv[k][1];
              if (chk(tx, ty) && b[tx][ty] == 'o' && ec[g[tx][ty]] == 1 && !v[g[tx][ty]]) {
                sm[i][j] += cc[g[tx][ty]];
                v[g[tx][ty]] = 1;
              }
            }
          }
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (b[i][j] == '.') rv = max(rv, sm[i][j]);
#if 1
      printf("info:\n");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
          printf(" %2d", g[i][j]);
        puts("");
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
          printf(" %2d", sm[i][j]);
        puts("");
      }
      for (int i = 0; i < cci; i++)
        printf("%d: %d, %d\n", i, cc[i], ec[i]);
      puts("");
#endif
      for (int i = 0; i < cci; i++)
        if (!ec[i]) rv += cc[i];
      return rv;
    }
};
