// p -> q => !q -> !p
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int n, a, b, p[N], f[N];
map<int, int> m;
set<int> h;

int Find(int x)
{
  if (x == f[x])
    return x;
  return f[x] = Find(f[x]);
}

void Union(int x, int y)
{
  f[Find(x)] = Find(y);
}

int main()
{
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", p+i);
    m[p[i]] = i;
    h.insert(p[i]);
  }

  int fa = n, fb = n+1;
  for (int i = 0; i < n+2; i++)
    f[i] = i;

  for (int i = 0; i < n; i++) {
    int ra = a-p[i];
    int rb = b-p[i];
    if (h.count(ra))
      Union(m[p[i]], m[ra]);
    else
      Union(m[p[i]], fb);

    if (h.count(rb))
      Union(m[p[i]], m[rb]);
    else
      Union(m[p[i]], fa);
  }

  if (Find(fa) == Find(fb)) {
    puts("NO");
    return 0;
  }

  puts("YES");
  for (int i = 0; i < n; i++)
    printf("%d%c", Find(i) == Find(fa)? 0: 1, i < n-1? ' ': '\n');
  return 0;
}
