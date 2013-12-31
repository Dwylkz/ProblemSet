#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<int> VI;
typedef long long LL;

int k, x, n, m;

struct Var {
  int m;
  LL a, b, c;
  void operator += (Var &o) {
    a += o.a;
    b += o.b;
    c += o.c;
    if (!(o.m>>1&1) && (m&1)) c++;
    m = (o.m&1)-(m&1);
  }
};

void gen(VI &x, int y) {
  if (y > 1) {
    for (int i = 0; i < 4; i++)
      x.push_back(i);
  } else {
    x.push_back(0);
    x.push_back(3);
  }
}

string con(int m, int l, int ac) {
  int _ac = ac;
  if (l < 2 && ac) return "";
  string r = "";
  int h = m&1, t = m>>1&1;
  r += h+'0';
  if (!h && ac) {
    r += '1';
    ac--;
  }
  while (ac--) r += "01";
  while (r.size() < l-1) r += r.back();
  if (r.size() > l) return "";
  if (r.size() < l) r += t+'0';
  if (r.back() != t+'0') return "";
  for (int i = 0; i < r.size(); i++)
    if (r[i] == '0' && i+1 < r.size() && r[i+1] == '1') {
      _ac--;
      i++;
    }
  if (_ac) return "";
  for_each(r.begin(), r.end(), [](char &ch){ch = ch=='0'? 'A': 'C';});
  return r;
}

int solve(string &s1, string &s2) {
  VI l, r;
  gen(l, n);
  gen(r, m);
  s1 = s2 = "";
  for (int i = 0; i < l.size(); i++)
    for (int j = 0; j < r.size(); j++) {
      Var vx = {l[i], 1, 0, 0},
          vy = {r[j], 0, 1, 0};
      for (int t = 3; t <= k; t++) {
        Var vz = vx;
        vx = vy;
        vy += vz;
      }
      for (LL a = 0; 2*a <= n; a++) 
        if ((x-vy.c-a*vy.a)%vy.b == 0) {
          LL b = (x-vy.c-a*vy.a)/vy.b;
          if (0 <= b && 2*b <= m) {
            s1 = con(l[i], n, a);
            s2 = con(r[j], m, b);
            if (s1 != "" && s2 != "") return 1;
            s1 = s2 = "";
          }
        }
    }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", &k, &x, &n, &m); ) {
    string s1, s2;
    if (solve(s1, s2)) cout << s1 << endl << s2 << endl;
    else cout << "Happy new year!" << endl;
  }
  return 0;
}
