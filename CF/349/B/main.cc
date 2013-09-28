#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int N = 10;

int v, a[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &v); ) {
    for (int i = 1; i < 10; i++) scanf("%d", a+i);
    int id = 9;
    for (int i = 8; i; i--)
      if (a[id] > a[i]) id = i;
    string rv = "";
    if (a[id] > v) rv = "-1";
    else {
      int cnt = v/a[id], rem = v%a[id];
      for (int i = 0, mx; i < cnt; i++) {
        for (mx = 9; mx > id; mx--)
          if (rem >= a[mx]-a[id]) break;
        rem -= a[mx]-a[id];
        rv += '0'+mx;
      }
    }
    cout << rv << endl;
  }
  return 0;
}
