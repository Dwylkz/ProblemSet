#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

int n;

struct Game
{
  typedef deque<int> Player;

  Game(): count(0), isloop(false) {}

  bool Trans()
  {
    state.insert(Encode());
    int w = p[0].front() < p[1].front(), l = 1-w;
    p[w].push_back(p[l].front()), p[l].pop_front();
    p[w].push_back(p[w].front()), p[w].pop_front();
    count++;
    if (p[l].empty()) {
      winner = w+1;
      return false;
    }
    int64_t s = Encode();
    if (state.count(s)) {
      isloop = true;
      return false;
    }
    state.insert(s);
    return true;
  }

  int64_t Encode()
  {
    int64_t s = 0;
    for (int i = 0; i < 2; i++)
      for (int pi: p[i])
        s = s*10+pi;
    s = s*100+p[0].size();
    return s;
  }

  void Read(int x)
  {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      int c;
      scanf("%d", &c);
      p[x].push_back(c-1);
    }
  }

  Player p[2];
  int count;
  int winner;
  bool isloop;
  set<int64_t> state;
};

int main()
{
  scanf("%d", &n);
  Game game;
  game.Read(0);
  game.Read(1);
  while (game.Trans()) {}
  if (game.isloop) puts("-1");
  else printf("%d %d\n", game.count, game.winner);
  return 0;
}
