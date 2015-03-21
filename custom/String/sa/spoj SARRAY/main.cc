#include <algorithm>
#include <cassert>
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

const int N = 1e5+10;

void DA(char* a, int n, int* sa)
{
  struct L {
    static void Sort(int* slot, int m, int* key, int* id, int n, int* res)
    {
      fill(slot, slot+m, 0);
      for (int i = 0; i < n; i++) slot[key[id[i]]]++;
      for (int i = 1; i < m; i++) slot[i] += slot[i-1];
      for (int i = n-1; i >= 0; i--) res[--slot[key[id[i]]]] = id[i];
    }
  };
  static int mem[3*N];
  int *ci = sa, *ti = mem, *cr = ti+N, *tr = cr+N;
  int m = 0;
  for (int i = 0; i < n; i++) {
    ti[i] = i;
    cr[i] = a[i];
    m = max(m, a[i]+1);
  }
  L::Sort(tr, m, cr, ti, n, ci);
  for (int l = 1; l < n; l <<= 1) {
    int p = 0;
    for (int i = 0; i < l; i++) ti[p++] = n-1-i;
    for (int i = 0; i < n; i++)
      if (ci[i] >= l)
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

void DC3(char* s, int n, int* sa)
{
  struct L {
    struct Cmp {
      Cmp(int* k1, int* k2): k1(k1), k2(k2) {}

      bool Cmp2(int l, int r)
      {
        return k1[l] < k1[r] || (k1[l] == k1[r] && k2[l+1] < k2[r+1]);
      }

      bool Cmp3(int l, int r)
      {
        return k1[l] < k1[r] || (k1[l] == k1[r] && Cmp2(l+1, r+1));
      }

      bool operator () (int l, int r)
      {
        return l%3 == 1? Cmp2(l, r): Cmp3(l, r);
      }

      int *k1, *k2;
    };

    static void Sort(int m, int* k, int* v, int n, int* r)
    {
      static int h[N];
      fill(h, h+m, 0);
      for (int i = 0; i < n; i++) h[k[v[i]]]++;
      for (int i = 1; i < m; i++) h[i] += h[i-1];
      for (int i = n-1; i >= 0; i--) r[--h[k[v[i]]]] = v[i];
    }

    static void DC3(int* s, int n, int* sa)
    {
      static int ts[N+3], i0[(N+2)/3];
      int* ti = sa, *i12 = sa+n, *s12 = s+n+3;
      int n0 = 0, n1 = (n+2)/3, n12 = 0, m = 1, d = (n%3 == 1); 
      for (int i = 0; i < n+d; i++) {
        m = max(m, s[i]+1);
        if (i%3 > 0) ti[n12++] = i;
      }
      s[n] = s[n+1] = s[n+2] = 0;
      Sort(m, s+2, ti, n12, i12);
      Sort(m, s+1, i12, n12, ti);
      Sort(m, s, ti, n12, i12);
      ts[i12[0]] = 0;
      for (int i = 1; i < n12; i++) {
        int l = i12[i-1], r = i12[i];
        if (s[l] == s[r] && s[l+1] == s[r+1] && s[l+2] == s[r+2]) ts[r] = ts[l];
        else ts[r] = ts[l]+1;
      }
      if (ts[i12[n12-1]]+1 < n12) {
        for (int i = 0; i < n12; i++)
          if (i < n1) s12[i] = ts[3*i+1]+1;
          else s12[i] = ts[3*(i-n1)+2]+1;
        DC3(s12, n12, i12);
        for (int i = 0; i < n12; i++) {
          if (i12[i] < n1) i12[i] = 3*i12[i]+1;
          else i12[i] = 3*(i12[i]-n1)+2;
          ts[i12[i]] = i+1;
        }
        ts[n] = ts[n+1] = ts[n+2] = 0;
      }
      for (int i = 0; i < n12; i++)
        if (i12[i]%3 == 1) ti[n0++] = i12[i]-1;
      Sort(m, s, ti, n0, i0);
      i12 += d;
      n12 -= d;
      merge(i0, i0+n0, i12, i12+n12, sa, Cmp(s, ts));
    }
  };

  static int ts[3*N+300], i12[3*N+300];
  for (int i = 0; i < n; i++) ts[i] = s[i]+1;
  L::DC3(ts, n, i12);
  for (int i = 0; i < n; i++) sa[i] = i12[i];
}

char s[N];
int sa[N];

int main()
{
  scanf("%s", s);
  int ns = strlen(s);
  // DA(s, ns, sa);
  DC3(s, ns, sa);
  for (int i = 0; i < ns; i++) {
    printf("%d\n", sa[i]);
    // printf("%d: %s\n", sa[i], s+sa[i]);
  }
  return 0;
}
