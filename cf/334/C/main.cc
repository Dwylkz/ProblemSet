#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
const int maxn = 1e5 + 10;
typedef long long LL;
const LL ub = 1e17;

LL n;
vector<LL> p;
int main()
{
  for (p.push_back(1); p.back() < ub; )
    p.push_back(p.back() * 3);
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; cin >> n; ) {
    long long ans;
    for (int i = 0; i < p.size(); i++) {
      if (n % p[i]) {
        ans = n / p[i] + 1;
        break;
      }
    }
    cout << ans << endl;
  }
	return 0;
}
