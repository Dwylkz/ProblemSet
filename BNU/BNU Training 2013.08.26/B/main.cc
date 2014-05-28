#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
const int N = 100;

char b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    printf("Case %d: ", Case);
    string o, o1 = "", o2 = "", o3 = "", n;
    cin >> o >> n;
    for (int i = 0; i < o.length(); i++)
      if (isalpha(o[i])) {
        o1 += o[i]^32;
        o2 += o[i];
        o3 += o[i]^32;
      } else o1 += o[i];
    if (o == n) printf("Login successful.");
    else {
      printf("Wrong password.");
      if (o1 == n) printf(" Please, check your caps lock key.");
      else if (o2 == n) printf(" Please, check your num lock key.");
      else if (o3 == n) printf(" Please, check your caps lock and num lock keys.");
    }
    puts("");
  }
  return 0;
}
