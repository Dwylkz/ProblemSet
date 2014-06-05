#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 32;

char s[N];
int f[N][2];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int k = 1; k <= T; k++) {
    scanf("%s", s);
    int l = strlen(s);
    f[0][0] = 1;
    memset(f+1, 0, sizeof(f[0])*l);
    for (int i = 0; i < l; i++) {
      if (s[i]-'0'&1 == 0) f[i+1][0]++;
      else f[i+1][1]++;
      for (int j = 0; j < 2; j++) {
        int o = j*10+s[i]-'0';
        f[i+1][o&1] += f[i][j];
      }
    }
    int sum = 0;
    for (int i = 1; i <= l; i++) sum += f[i][0];
    printf("%d. %d %d\n", k, sum, l*(l+1)/2-sum);
  }
  return 0;
}
