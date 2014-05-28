#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 1000+10;

struct a_t {
  string n;
  int r, c;
  a_t(string _n = 0, int _r = 0, int _c = 0):
    n(_n), r(_r), c(_c) {}
  friend bool operator < (a_t lhs, a_t rhs) {
    return lhs.c > rhs.c;
  }
};
vector<a_t> a;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  a.clear();
  for (int k = 1; ~scanf("%d", &n), n; ) {
    map<string, bool> m;
    for (int i = 0; i < n; i++) {
      char b[30+10];
      int c, j;
      scanf("%s%d", b, &c);
      for (j = 0; j < a.size(); j++)
        if (a[j].n == string(b)) {
          a[j].c = c;
          break;
        }
      if (j == a.size()) a.push_back(a_t(b, -1, c));
      m[b] = 1;
    }
    for (int i = 0; i < a.size(); i++)
      if (m.find(a[i].n) == m.end()) a[i].c = 0;
    sort(a.begin(), a.end());
    printf("----------------WEEK %d----------------\n", k++);
    for (int i = 0; i < a.size(); i++) {
      if (i < 5) {
        string s;
        if (a[i].r == -1) s = "*NEW*";
        else if (a[i].r < i) s = "*DOWN*";
        else if (a[i].r == i) s = "*STAY*";
        else if (a[i].r > i) s = "*UP*";
        printf("%d.%-8s%s\n", i+1, s.data(), a[i].n.data());
      }
      a[i].r = i;
    }
  }
  return 0;
}
