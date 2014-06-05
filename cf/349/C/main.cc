#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
typedef long long LL;

int n, a[N];

bool look(LL x) {
  LL sm = 0;
  for (int i = 0; i < n; i++) 
    if (x >= a[i]) sm += x-a[i];
    else return 0;
  return sm >= x;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    LL lb = 0, ub = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      ub += a[i];
    }
    LL rv = ub;
    for ( ; lb <= ub; ) {
      LL m = lb+ub>>1;
      if (look(m)) {
        rv = m;
        ub = m-1;
      } else lb = m+1;
    }
    cout << rv << endl;
  }
  return 0;
}
