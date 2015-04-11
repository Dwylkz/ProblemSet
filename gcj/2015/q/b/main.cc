#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e3+5;

int h[N];

int main()
{
  int T;
  scanf("%d", &T);
  for (int kas = 1; kas <= T; kas++) {
    int d;
    scanf("%d", &d);
    memset(h, 0, sizeof(h));
    int maxv = 0;
    for (int i = 0; i < d; i++) {
      int p;
      scanf("%d", &p);
      maxv = max(maxv, p);
      h[p]++;
    }
    int ans = maxv;
    for (int i = maxv-1; i > 0; i--) {
      int sum = 0;
      for (int j = i+1; j <= maxv; j++)
        sum += h[j]*((j+i-1)/i-1);
      ans = min(ans, sum+i);
    }
    printf("Case #%d: ", kas);
    printf("%d\n", ans);
  }
  return 0;
}
