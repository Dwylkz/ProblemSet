#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int n;

string rod(int n) {
  string s;
  if (n >= 5) {
    s = "-O|";
    n -= 5;
  } else s = "O-|";
  for (int i = 0; i < n; i++) s += "O";
  s += "-";
  for (int i = 0; i < 4-n; i++) s += "O";
  return s;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    if (!n) puts("");
    int d = 1;
    for (int t = n; t > 9; t /= 10) d++;
    for (int t = n; d--; t /= 10) puts(rod(t%10).data()); 
  }
  return 0;
}
