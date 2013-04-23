#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (1100)

int n, m, B[MAXN][MAXN]; 
int mv[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

bool chk(int x, int y)
{
	Rep(i, 0, 8) if (!B[x + mv[i][0]][y + mv[i][1]]) return 0;
	return 1;
}	

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif

	while (~scanf("%d%d", &n, &m))
	{
		bool yes = 0;
		int id = -1;
		memset(B, 0, sizeof B);
		Rep(r, 1, m + 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (!yes)
			{
				B[x][y] = 1;
				yes |= chk(x, y);
				Rep(i, 0, 8)
				{
					int tx = x + mv[i][0], ty = y + mv[i][1];
					if (B[tx][ty]) yes |= chk(tx, ty);
				}
				if (yes) id = r;
			}
		}
		printf("%d\n", id);
	}

	return 0;
}
