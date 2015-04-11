#include <cstdio>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int kas = 1; kas <= T; kas++) {
    int smax;
    scanf("%d", &smax);
    int up = 0, ans = 0;
    for (int i = 0; i <= smax; i++) {
      int cnt;
      scanf("%1d", &cnt);
      if (up < i) {
        ans += i-up;
        up = i;
      }
      up += cnt;
    }
    printf("Case #%d: %d\n", kas, ans);
  }
  return 0;
}
