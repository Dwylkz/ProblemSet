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
      int *k1, *k2;

      Cmp(int* k1, int* k2): k1(k1), k2(k2) {}

      static bool Cmp2(int* k1, int* k2, int l, int r)
      {
        return k1[l] < k1[r] || (k1[l] == k1[r] && k2[l+1] < k2[r+1]);
      }

      static bool Cmp3(int* k1, int* k2, int l, int r)
      {
        return k1[l] < k1[r] || (k1[l] == k1[r] && Cmp2(k1, k2, l+1, r+1));
      }

      static bool Equal(int* k, int l, int r)
      {
        return k[l] == k[r] && k[l+1] == k[r+1] && k[l+2] == k[r+2];
      }

      bool operator () (int l, int r)
      {
        return l%3 == 1? Cmp2(k1, k2, l, r): Cmp3(k1, k2, l, r);
      }
    };

    static void Sort(int* h, int m, int* k, int* v, int n, int* r)
    {
      fill(h, h+m, 0);
      for (int i = 0; i < n; i++) h[k[v[i]]]++;
      for (int i = 1; i < m; i++) h[i] += h[i-1];
      for (int i = n-1; i >= 0; i--) r[--h[k[v[i]]]] = v[i];
    }

    static void Init(int* k, int* v, int n, int c, int& m)
    {
      for (int i = 0; i < n; i++) {
        v[i] = 3*i+c;
        m = max(m, k[v[i]]+1);
      }
    }

    static void Print(int* k, int n, int* w, int* v, int m)
    {
      for (int i = 0; i < m; i++) {
        printf("%2d: ", v[i]);
        if (v[i]%3 == 1) printf("(%2d, %2d): ", k[v[i]], w[v[i]+1]);
        else if (v[i]%3 == 2) printf("(%2d, %2d, %2d): ", k[v[i]], k[v[i]+1], w[v[i]+2]);
        else printf("(%2d, %2d) (%2d, %2d, %2d): ", k[v[i]], w[v[i]+1], k[v[i]], k[v[i]+1], w[v[i]+2]);
        for (int j = v[i]; j < n; j++)
          putchar(k[j]);
        puts("");
      }
      puts("----");
    }

    static void DC3(int n, int* cr, int* ci, int* i12)
    {
      static int tr[N], ti[N], i0[N];
      for (int i = 0; i < 3; i++) cr[n+i] = 0;
      int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n12 = n1+n2, m = 1;
      Init(cr, ti, n1, 1, m);
      Init(cr, ti+n1, n2, 2, m);
      Sort(ci, m, cr+2, ti, n12, i12);
      Sort(ci, m, cr+1, i12, n12, ti);
      Sort(ci, m, cr, ti, n12, i12);

      m = 1;
      tr[i12[0]] = m++;
      for (int i = 1; i < n12; i++)
        tr[i12[i]] = Cmp::Equal(cr, i12[i], i12[i-1])? m-1: m++;

      if (m < n12) {
        for (int i = 0; i < n1; i++) cr[n+i] = tr[i*3+1];
        for (int i = 0; i < n2; i++) cr[n+n1+i] = tr[i*3+2];
        DC3(n12, cr+n, ci, i12+n12);
        for (int i = 0; i < n12; i++)
          if (ci[i] < n1) tr[3*ci[i]+1] = i;
          else tr[3*(ci[i]-n1)+2] = i;
        for (int i = 0; i < 3; i++) cr[n+i] = tr[n+i] = 0;
      }

      m = 1;
      Init(cr, i0, n0, 0, m);
      Sort(ci, n12, tr+1, i0, n0, ti);
      Sort(ci, m, cr, ti, n0, i0);

      printf("n12=%d, n0=%d\n", n12, n0);
      Print(cr, n, tr, i12, n12);
      Print(cr, n, tr, i0, n0);

      merge(i12, i12+n12, i0, i0+n0, ci, Cmp(cr, tr));
    }
  };

  static int cr[3*N], i12[3*N];
  for (int i = 0; i < n; i++) cr[i] = s[i];
  L::DC3(n, cr, sa, i12);
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
    // printf("%d\n", sa[i]);
    printf("%d: %s\n", sa[i], s+sa[i]);
  }
  return 0;
}
