#include <map>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;

LL gcd(LL a, LL b) {
  return b? gcd(b, a%b): a;
}

int n, a[N];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    sort(a, a+n);
    LL sum = 0;
    for (int i = 0; i < n; i++) sum += 1LL*a[i]*((4*i+3)-2*n);
    LL f = gcd(sum, n);
    cout << sum/f << " " << n/f << endl;
  }
	return 0;
}
