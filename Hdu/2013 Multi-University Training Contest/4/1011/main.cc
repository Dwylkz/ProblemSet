#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

const int nn = 2, mm = 2, sgl = nn*mm;
int sg[sgl];
void decode(int x)
{
}
void encode(int x, int m[nn][mm])
{
}
void sg_init()
{
  memset(sg, 0, sizeof(sg));
  int bl = 1<<(nn*mm), t1[nn][mm], t2[nn][mm];
  for (int i = 1; i < bl; i++) {
    decode(i, t1);
    for (int i = 0; i < nn; i++)
      for (int j = 0; j < mm; j++)
        if (t1[i][j]) {
          memcpy(t2, t1, sizeof(t1));
        }
  }
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ; ) {
	}
	return 0;
}
