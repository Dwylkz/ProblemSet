#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int maxn = 8+10;
typedef long long LL;
typedef unsigned int UI;

int n, h[maxn], id[maxn];
map<UI, bool> sb;

UI encode(string s)
{
  UI rv = 0;
  for (int i = 0; i < n; i++)
    rv |= s[i]<<((n-i-1)*4);
  return rv;
}
string decode(UI x)
{
  string t = "";
  for (int i = 0; i < n; i++) {
    UI v = (x>>((n-i-1)*4))&15;
    if (v <= 9) v += '0';
    else v += 'A' - 10;
    t += v;
  }
  return t;
}

bool vis[maxn];
void dfs(int i = 0, string t = "")
{
  if (i == n) {
    sb[encode(t)] = 1;
    return ;
  }
  int hash[16] = {0};
  for (int j = 0; j < n; j++)
    if (!vis[j] && !hash[h[j]]) {
      hash[h[j]] = 1;
      string tt = t;
      tt += h[j];
      vis[j] = 1;
      dfs(i+1, tt);
      vis[j] = 0;
    }
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    sb.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", h+i);
      id[i] = i;
    }
    memset(vis, 0, sizeof(vis));
    dfs();
    map<UI, bool>::iterator sbi;
    for (sbi = sb.begin(); sbi != sb.end(); sbi++) {
      string t = decode(sbi->first);
      for (int i = 0; i < t.length(); i++)
        printf("%c%c", t[i], i < t.length()-1? ' ': '\n');
    }
  }
  return 0;
}
