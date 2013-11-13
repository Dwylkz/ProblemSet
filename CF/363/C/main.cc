#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int N = 2e5+10;

char s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int l = strlen(s), p = -1;
    string result = "";
    for (int i = 0; i < l; i++)
      if (s[i] == p) {
        for (i++; s[i] && s[i] == p; i++) {}
        i--;
        int rl = result.length();
        if (rl > 2 && result[rl-2] == result[rl-3])
          continue;
        result += p;
      } else result += p = s[i];
    puts(result.data());
  }
  return 0;
}
