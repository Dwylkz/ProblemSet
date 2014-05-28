#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;

LL a, b;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  cin >> a >> b;
  if (b == 1) cout << a << endl;
  else {
    LL rv = 0;
    for ( ; a%b; ) {
      if (a < b) {
        swap(a, b);
        a -= b;
        rv++;
      } else {
        rv += a/b;
        a -= a/b*b;
      }
    }
    cout << rv+a/b << endl;
  }
  return 0;
}
