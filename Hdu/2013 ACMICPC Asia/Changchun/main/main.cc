#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <numeric>
using namespace std;
typedef set<string> ss_t;
#define _i(t) t::iterator

ss_t m;
void dfs(string x) {
  if (m.count(x)) return ;
  m.insert(x);
  string o = "", e = "";
  for (int i = 0; i < x.length(); i++)
    if (i&1) e += x[i];
    else o += x[i];
  dfs(o+e);
  dfs(e+o);
}
void go(int x) {
  string t = "";
  for (int i = 1; i <= x; i++) t += i+'0';
  m.clear();
  dfs(t);
  printf("has %ld:\n", m.size());
  for (_i(ss_t) i = m.begin(); i != m.end(); i++) {
    for (int j = 0; j < i->length(); j++)
      printf(" %2d", (*i)[j]-'0');
    puts("");
  }
}

int main() {
  go(8);
  return 0;
}
