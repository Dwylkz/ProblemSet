#include <iostream>
#include <string>
using namespace std;

#define MAXF(x, y) (x > y? x: y)

string x, y;
int    lx, ly, **ts;

void print(int *arr, int siz)
{
	int i;

	for (i = 0; i < siz; i++)
		printf("%6d", arr[i]);
	putchar('\n');
}

void init()
{
	int i;
	
	lx = x.length();
	ly = y.length();
	ts = new int *[lx + 1];
	for (i = 0; i < lx + 1; i++)
	{
		ts[i] = new int [ly + 1];
		memset(ts[i], 0, sizeof(int) * (ly + 1));
#if 0
		print(ts[i], ly + 1);
#endif
	}
}

int dp()
{
	int i, j;
	
#if 0
	printf("test  = %d\n", MAXF(8, 7));
#endif
	for (i = 1; i <= lx; i++)
		for (j = 1; j <= ly; j++)
			if (x[i - 1] == y[j - 1])
				ts[i][j] = ts[i - 1][j - 1] + 1;
			else ts[i][j] = MAXF(ts[i][j - 1], ts[i - 1][j]);
	return ts[lx][ly];
}

int main()
{
	while (cin >> x >> y)
	{
#if 0
		printf("%s %s\n", x.c_str(), y.c_str());
#endif
		init();
		printf("%d\n", dp());
	}

	return 0;
}