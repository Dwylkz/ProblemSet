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

const int N = 1e5+5;

typedef pair<int, int> PII;
typedef multiset<PII> SPii;
typedef vector<PII> VPii;

void DC3(char* s, int n, int* sa)
{
  struct L {
    struct Cmp {
      Cmp(int* k1, int* k2): k1(k1), k2(k2) {}

      bool Cmp2(int x, int y)
      {
        return k1[x] < k1[y] || (k1[x] == k1[y] && k2[x+1] < k2[y+1]);
      }

      bool Cmp3(int x, int y)
      {
        return k1[x] < k1[y] || (k1[x] == k1[y] && Cmp2(x+1, y+1));
      }

      bool operator () (int x, int y)
      {
        return x%3 == 1? Cmp2(x, y): Cmp3(x, y);
      }

      int *k1, *k2;
    };

    struct Sort {
      Sort& operator () (int m, int* k, int* v, int n, int* r)
      {
        static int h[N];
        fill(h, h+m, 0);
        for (int i = 0; i < n; i++) h[k[v[i]]]++;
        for (int i = 1; i < m; i++) h[i] += h[i-1];
        for (int i = n-1; i >= 0; i--) r[--h[k[v[i]]]] = v[i];
        return *this;
      }
    };

    static void DC3(int* s, int n, int* ti)
    {
      static int ts[N+3], i0[N];
      int n0 = 0, n1 = (n+2)/3, n12 = 0, m = 1, d = (n%3 == 1); 
      int* i12 = ti+n, *s12 = s+n+3;
      for (int i = 0; i < n+d; i++) {
        m = max(m, s[i]+1);
        if (i%3 > 0) ti[n12++] = i;
      }
      s[n] = s[n+1] = s[n+2] = 0;
      Sort()(m, s+2, ti, n12, i12)(m, s+1, i12, n12, ti)(m, s, ti, n12, i12);
      ts[i12[0]] = 0;
      for (int i = 1; i < n12; i++)
        ts[i12[i]] = ts[i12[i-1]]+Cmp(s, s).Cmp3(i12[i-1], i12[i]);
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
      Sort()(m, s, ti, n0, i0);
      i12 += d, n12 -= d;
      merge(i0, i0+n0, i12, i12+n12, ti, Cmp(s, ts));
    };
  };

  static int ts[4*N], ti[4*N];
  for (int i = 0; i < n; i++) ts[i] = s[i]+2;
  s[n] = 1;
  L::DC3(ts, n+1, ti);
  for (int i = 0; i < n; i++) sa[i] = ti[i+1];
}

void Kasai(char* s, int* sa, int n, int* h)
{
  static int inv[N];
  for (int i = 0; i < n; i++) inv[sa[i]] = i;
  int k = 0;
  h[0] = 0;
  for (int i = 0; i < n; i++)
    if (inv[i] > 0) {
      int j = sa[inv[i]-1];
      while (i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
      h[inv[i]] = k;
      if (k > 0) k--;
    }
}

char s[N];
int sa[N], h[N];
VPii in[N], out[N];

int main()
{
  scanf("%s", s);
  int n = strlen(s);
  DC3(s, n, sa);
  Kasai(s, sa, n, h);
  // for (int i = 0; i < n; i++) printf("%d, %d: %s\n", sa[i], h[i], s+sa[i]);
  for (int i = 0; i < n; i++) {
    in[i].clear();
    out[i].clear();
  }
  h[n] = 0;
  for (int i = 0; i < n; i++) {
    int len = max(h[i], h[i+1]);
    if (len < n-sa[i]) {
      len++;
      int l = sa[i];
      PII p(len, i);
      in[l].push_back(p);
      out[l+len].push_back(p);
    }
  }
  int head = 0;
  for (int i = 0; i < n; i++)
    if (sa[i] == 0) head = i;
  SPii rank;
  PII last(n, head);
  for (int i = 0; i < n; i++) {
    for (auto& p: out[i]) {
      rank.erase(rank.find(p));
      if (sa[p.second] > sa[last.second]) last = p;
    }
    for (auto& p: in[i]) rank.insert(p);
    PII t(max(i+1-sa[last.second], last.first), last.second);
    rank.insert(t);
    printf("%d %d\n", sa[rank.begin()->second]+1, rank.begin()->first);
    rank.erase(rank.find(t));
  }
  return 0;
}
