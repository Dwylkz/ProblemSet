#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e6+5;

int Add(int a, int b, int mod)
{
  return ((a+b)%mod+mod)%mod;
}

int Mul(int a, int b, int mod)
{
  return (1ll*a*b)%mod;
}

int l, a, b, ma[N], mb[N], p[N];
char n[N];

void Hash(int* m, int mod)
{
  m[0] = (n[0]-'0')%mod;
  for (int i = 1; i < l; i++)
    m[i] = Add(Mul(m[i-1], 10, mod), n[i]-'0', mod);
}

int main()
{
  scanf("%s%d%d", n, &a, &b);
  l = strlen(n);
  Hash(ma, a);
  Hash(mb, b);
  p[0] = 1;
  for (int i = 1; i < N; i++)
    p[i] = Mul(p[i-1], 10, b);
  for (int i = 1; i < l; i++)
    if (n[i] != '0' && ma[i-1] == 0 && Add(mb[l-1], Mul(-mb[i-1], p[l-i], b), b) == 0) {
      puts("YES");
      string foo = n;
      puts(foo.substr(0, i).data());
      puts(foo.substr(i).data());
      return 0;
    }
  puts("NO");
  return 0;
}
