#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int q; ~scanf("%d", &q); ) {
    vector<int> L, sm, mx, R;
    for (int i = 0; i < q; i++) {
      char op[2];
      scanf("%s", op);
      if (*op == 'D') {
        L.pop_back();
        sm.pop_back();
        mx.pop_back();
      } else if (*op == 'L') {
        if (!L.size()) continue;
        R.push_back(L.back());
        L.pop_back();
        sm.pop_back();
        mx.pop_back();
      } else if (*op == 'R') {
        if (!R.size()) continue;
        if (sm.size()) sm.push_back(sm.back()+R.back());
        else sm.push_back(R.back());
        if (mx.size()) mx.push_back(max(mx.back(), sm.back()));
        else mx.push_back(sm.back());
        L.push_back(R.back());
        R.pop_back();
      } else {
        int x;
        scanf("%d", &x);
        if (*op == 'I') {
          L.push_back(x);
          if (sm.size()) sm.push_back(sm.back()+x);
          else sm.push_back(x);
          if (mx.size()) mx.push_back(max(mx.back(), sm.back()));
          else mx.push_back(sm.back());
        } else if (*op == 'Q') {
          printf("%d\n", mx[x-1]);
        }
      }
    }
  }
  return 0;
}
