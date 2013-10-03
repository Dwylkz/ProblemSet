#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000+10;

/* High Precision Integer
 * */
struct int_t {
  string d;
  int_t(string _d = "0"): d(_d) {}
  int_t(int _d) {
    static char buff[20];
    sprintf(buff, "%d", _d);
    d = buff;
  }
  static void trans(string &s) {
    for (int i = 0; i < s.length(); i++) s[i] += '0';
  }
  friend int_t &operator + (const int_t &lhs, const int_t &rhs) {
    static int_t result;
    const string &a = lhs.d, &b = rhs.d;
    string &c = result.d;
    int maxlen = max(a.length(), b.length())+1;
    c.resize(maxlen);
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < maxlen-1; i++) {
      int x = a.length() <= i? 0: a[a.length()-1-i]-'0',
          y = b.length() <= i? 0: b[b.length()-1-i]-'0';
      c[i] += x+y;
      c[i+1] += c[i]/10;
      c[i] %= 10;
    }
    if (!c[maxlen-1]) c.resize(maxlen-1);
    reverse(c.begin(), c.end());
    trans(c);
    return result;
  }
  friend int_t &operator += (const int_t &lhs, const int_t &rhs) {
    return lhs+rhs;
  }
  friend int_t &operator * (const int_t &lhs, const int_t &rhs) {
    static int_t result;
    const string &a = lhs.d, &b = rhs.d;
    string &c = result.d;
    int maxlen = a.length()+b.length();
    c.resize(maxlen);
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < a.length(); i++) {
      int x = a[a.length()-1-i]-'0';
      for (int j = 0; j < b.length(); j++) {
        int y = b[b.length()-1-j]-'0';
        c[i+j] += x*y;
        c[i+j+1] += c[i+j]/10;
        c[i+j] %= 10;
      }
    }
    for ( ; maxlen > 1 && !c[maxlen-1]; maxlen--) {}
    c.resize(maxlen);
    reverse(c.begin(), c.end());
    trans(c);
    return result;
  }
  friend int_t &operator *= (const int_t &lhs, const int_t &rhs) {
    return lhs*rhs;
  }
  const char *show() {
    return d.data();
  }
};

char buff1[N], buff2[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1, blank = 0; T--; kas++, blank = 1) {
    if (blank) puts("");
    scanf("%s%s", buff1, buff2);
    printf("Case %d:\n%s + %s = %s\n", kas, buff1, buff2,
        (int_t(buff1)+int_t(buff2)).show());
  }
  return 0;
}
