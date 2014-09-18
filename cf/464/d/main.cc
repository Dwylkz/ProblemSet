/* The key is realize that this problem couldn't solve
 * by data structure...
 * */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 1e5+10;
const int D = 10;
const int MOD = 1e9+7;

struct Query {
  int d;
  string t;

  void Input()
  {
    static char foo[N];
    scanf("%s", foo);
    d = foo[0]-'0';
    t = foo+3;
  }
};

struct Digit {
  int v, p;
};

int Add(int a, int b)
{
  return (a+b)%MOD;
}

int Mul(int a, int b)
{
  return 1ll*a*b%MOD;
}

void Fold(const char* s, Digit* ds, int& v, int& p)
{
  int v_ = 0;
  int p_ = 1;
  for (int i = 0; s[i]; i++) {
    int si = s[i]-'0';
    v_ = Add(Mul(v_, ds[si].p), ds[si].v);
    p_ = Mul(p_, ds[si].p);
  }

  v = v_;
  p = p_;
}

int main()
{
  char s[N];
  scanf("%s", s);

  int n;
  scanf("%d", &n);

  Query qs[N];
  for (int i = 0; i < n; i++)
      qs[i].Input();

  Digit ds[D];
  for (int i = 0; i < D; i++) {
    ds[i].v = i;
    ds[i].p = 10;
  }

  for (int i = n-1; i >= 0; i--) {
    int d = qs[i].d;
    Fold(qs[i].t.data(), ds, ds[d].v, ds[d].p);
  }

  int result, power;
  Fold(s, ds, result, power);
  printf("%d\n", result);

  return 0;
}
