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

const int N = 1e5+5;

void SANew(char* s, int n, int* sa)
{
  struct L {
    static void Sort(int* h, int m, int* k, int* v, int n, int* r)
    {
      fill(h, h+m, 0);
      for (int i = 0; i < n; i++) h[k[v[i]]]++;
      for (int i = 1; i < m; i++) h[i] += h[i-1];
      for (int i = n-1; i >= 0; i--) r[--h[k[v[i]]]] = v[i];
    }
  };
  static int mem[3*N];
  int *ci = sa, *ti = mem, *cr = ti+N, *tr = cr+N;
  int m = 0;
  for (int i = 0; i < n; i++) {
    ti[i] = i;
    cr[i] = s[i];
    m = max(m, s[i]+1);
  }
  L::Sort(tr, m, cr, ti, n, ci);
  for (int l = 1; l < n; l <<= 1) {
    int p = 0;
    for (int i = 0; i < l; i++) ti[p++] = n-1-i;
    for (int i = 0; i < n; i++)
      if (ci[i]-l >= 0)
        ti[p++] = ci[i]-l;
    L::Sort(tr, m, cr, ti, n, ci);
    m = 0;
    tr[ci[0]] = m++;
    for (int i = 1; i < n; i++)
      if (cr[ci[i]] == cr[ci[i-1]]
          && ci[i]+l < n && ci[i-1]+l < n
          && cr[ci[i]+l] == cr[ci[i-1]+l])
        tr[ci[i]] = m-1;
      else
        tr[ci[i]] = m++;
    swap(cr, tr);
  }
}

void Kasai(char* s, int* sa, int n, int* he)
{
  static int id[N];
  for (int i = 0; i < n; i++) id[sa[i]] = i;
  int k = 0;
  for (int i = 0; i < n; i++)
    if (id[i] > 0) {
      while (k < n && s[i+k] == s[sa[id[i]-1]+k]) k++;
      he[id[i]] = k;
      if (k > 0) k--;
    }
}

char s[N];
int sa[N], he[N];

int main()
{
  scanf("%s", s);
  int ns = strlen(s);
  SANew(s, ns, sa);
  // for (int i = 0; i < ns; i++) puts(s+sa[i]);
  Kasai(s, sa, ns, he);
  // for (int i = 0; i < ns; i++) printf("%d%c", he[i], i < ns-1? ' ': '\n');
  return 0;
}
