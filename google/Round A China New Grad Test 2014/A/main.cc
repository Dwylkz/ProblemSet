#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e7+10;

char n[N], s[N];
int a[N];

const char *num[] = {"zero", "one", "two", "three", "four", "five",
  "six", "seven", "eight", "nine"};
const char *mul[] = {"", "", "double", "triple", "quadruple", "quintuple",
  "sextuple", "septuple", "octuple", "nonuple", "decuple"};

int main() {
#if 0
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1; T--; kas++) {
    printf("Case #%d:", kas);
    scanf("%s%s", n, s);
    int gap = 0;
    for (char *i = s, *b; b = strsep(&i, "-"); )
      sscanf(b, "%d", a+gap++);
    for (int i = 1; i < gap; i++) a[i] += a[i-1];
#if 0
    for (int i = 0; i < gap; i++) printf(" %d", a[i]);
    puts("");
#endif
    for (int i = 0, j = 0; i < gap; i++) {
      for ( ; j < a[i]; j++) {
        int digit = n[j++]-'0', count = 1;
        for ( ; j < a[i] && n[j] == digit+'0'; j++) count++;
        j--;
        putchar(' ');
        if (count < 2) printf("%s", num[digit]);
        else if (count < 11) printf("%s %s", mul[count], num[digit]);
        else {
          printf("%s", num[digit]);
          for (int k = 1; k < count; k++) printf(" %s", num[digit]);
        }
      }
    }
    puts("");
  }
  return 0;
}
