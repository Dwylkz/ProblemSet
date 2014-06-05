#pragma comment(linker, '/STACK:65535000')
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn = 5e3 + 10;
typedef long long LL;

struct like_t {
  string name;
  int like;
  int time;
  friend bool operator < (like_t x, like_t y)
  {
    if (x.like != y.like) return x.like > y.like;
    if (x.time != y.time) return x.time > y.time;
    return x.name < y.name;
  }
};
vector<like_t> L;
map<string, int> si;

int n;
char str[maxn];

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d", &n); ) {
    L.clear();
    L.push_back((like_t){"%*%*", -1, -1});
    si.clear();
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%s%d", str, &t);
      if (!si[str]) {
        si[str] = L.size();
        L.push_back((like_t){str, 0, 0});
      }
      int id = si[str];
      L[id].like += t;
      L[id].time++;
    }
    sort(L.begin(), L.end());
    printf("%d\n", (unsigned int)L.size()-1);
    for (int i = 0; i < L.size()-1; i++)
      printf("%s %d %d\n", L[i].name.data(), L[i].like, L[i].time);
	}
	return 0;
}
