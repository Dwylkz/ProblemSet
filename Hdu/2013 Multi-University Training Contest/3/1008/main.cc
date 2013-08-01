#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 16;
const int inf32 = 0x7fffffff;
typedef long long LL;

char s[maxn];
int power[1<<maxn];
int f[1<<maxn];

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  for (int i = 0; i < maxn; i++)
    power[1<<i] = i;
	for ( ; ~scanf("%s", s); ) {
    int l = strlen(s), bl = 1<<l;
    for (int i = 0; i < bl; i++) f[i] = inf32;
    for (int i = f[0] = 0; i < bl; i++) {
      for (int j = 0; j < bl; j++) {
      }
    }
	}
	return 0;
}
