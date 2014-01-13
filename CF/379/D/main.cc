#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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

VI gen(int y) {
  VI x;
  if (y > 1) {
    for (int i = 0; i < 4; i++)
      x.push_back(i);
  } else {
    x.push_back(0);
    x.push_back(3);
  }
  return x;
}

int con(int m, int l, int ac, string &r) {
  r = "";
  int _ac = ac;
  if (l < 2 && ac) return 0;
  int h = m&1, t = m>>1&1;
  r += h+'0';
  if (!h && ac) {
    r += '1';
    ac--;
  }
  while (ac--) r += "01";
  while (r.size() < l-1) r += '2';
  if (r.size() > l) return 0;
  if (r.size() < l) r += t+'0';
  if (r.back() != t+'0') return 0;
  for (int i = 0; i < r.size(); i++)
    if (r[i] == '0' && i+1 < r.size() && r[i+1] == '1') {
      _ac--;
      i++;
    }
  if (_ac) return 0;
  map<char, char> to = {{'0', 'A'}, {'1', 'C'}, {'2', 'B'}};
  for_each(r.begin(), r.end(), [&](char &ch){ch = to[ch];});
  return 1;
}

int solve(string &s1, string &s2) {
  s1 = s2 = "";
  for (auto i: gen(n)) for (auto j: gen(m)) {
      Var vx = {i, 1, 0, 0},
          vy = {j, 0, 1, 0};
      for (int t = 3; t <= k; t++) {
        Var vz = vx;
        vx = vy;
        vy += vz;
      }
      for (LL a = 0; 2*a <= n; a++) 
        if ((x-vy.c-a*vy.a)%vy.b == 0) {
          LL b = (x-vy.c-a*vy.a)/vy.b;
          if (0 <= b && 2*b <= m) {
            if (con(j, n, a, s1) && con(j, n, a, s2)) return 1;
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
