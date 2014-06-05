#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;

string s[] = {"50", "80", "170", "20", "200", "110"};

int n;

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
#if 0
  bool vis[12] = {0};
  for (int i = 1; i < 200000000; i++) {
    int l = log10(i)+1;
    if (i % 210 == 0 && !vis[l]) {
      printf("%d\n", i);
      vis[l] = 1;
    }
  }
#endif
	for ( ; ~scanf("%d", &n); ) { 
    if (n < 3) puts("-1");
    else if (n == 3) puts("210");
    else {
      int r = (n-4)%6;
      putchar('1');
      for (int i = 0; i < n-s[r].length()-1; i++)
        putchar('0');
      puts(s[r].data());
    }
  }
	return 0;
}
