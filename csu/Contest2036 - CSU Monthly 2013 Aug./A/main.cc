#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100+10;
typedef unsigned long long LL;

LL gcd(LL a, LL b) {
  return b? gcd(b, a%b): a;
}

char s[N], a[N], b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    LL o = 1, oo = 1, aa = 0, bb = 0;
    if (*(s+2) == '(') {
      a[0] = 0;
      sscanf(s+3, "%[^)]", b);
    } else {
      sscanf(s+2, "%[^(]", a);
      sscanf(s+2+strlen(a)+1, "%[^)]", b);
    }
    for (int t = strlen(b); t--; ) o *= 10;
    for (int t = strlen(a); t--; ) oo *= 10;
    for (int i = 0, la = strlen(a); i < la; i++)
      aa = aa*10+a[i]-'0';
    for (int i = 0, lb = strlen(b); i < lb; i++)
      bb = bb*10+b[i]-'0';
    LL A = aa*(o-1)+bb, B = (o-1)*oo, g = gcd(A, B);
    cout << A/g << "/" << B/g << endl;
  }
  return 0;
}
