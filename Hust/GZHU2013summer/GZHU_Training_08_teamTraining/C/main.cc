#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <bitset>
#include <map>
#include <vector>
using namespace std;
const int N = 1e2+10;
typedef bitset<N> BS;
typedef vector<BS> VBS;
typedef map<string, int> MSI;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    VBS v;
    MSI m;
    int rank = 1, z = 0;
    for (int i = 0; i < n; i++) {
      BS b(0);
      int T;
      scanf("%d", &T);
      if (T) z = 1;
      for ( ; T--; ) {
        char buf[100];
        scanf("%s", buf);
        if (m.find(buf) == m.end()) m[buf] = rank++;
        b[m[buf]] = 1;
      }
      for (int id = 0; id < v.size(); id++) {
        if ((v[id]&b).any()) {
          b |= v[id];
          v.erase(v.begin()+id);
        }
      }
      v.push_back(b);
    }
    printf("%d\n", (int)v.size()-z);
  }
  return 0;
}
