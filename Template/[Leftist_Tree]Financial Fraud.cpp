#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define MAXI 50011

struct LTT
{
	struct node
	{
		int l, r, key, dis;
	}t[MAXI];

	void clear(int n)
	{
		int i;

		for (i = 0; i <= n; i++)
			t[i].l = t[i].r = t[i].dis = -1;
	}

	int merge(int x, int y)
	{
		if (x == -1) return y;
		if (y == -1) return x;
		if (t[x].key < t[y].key)
			swap(x, y);
		t[x].r = merge(t[x].r, y);
		if (t[t[x].l].dis < t[t[x].r].dis)
			swap(t[x].l, t[x].r);
		t[x].dis = t[t[x].r].dis + 1;

		return x;
	}

	int delet(int x)
	{
		return merge(t[x].l, t[x].r);
	}
}zkl;

int main()
{
	int n, i, j, k, pid[MAXI], tid[MAXI];
	int tsu;

	while (scanf("%d", &n), n)
	{
		zkl.clear(n);
		pid[0] = tid[0] = 0;
		for (i = j = 1; i <= n; i++, j++)
		{
			scanf("%d", &zkl.t[i].key);
			pid[j] = tid[j] = i;
			while (j > 1 && zkl.t[tid[j - 1]].key > zkl.t[tid[j]].key)
			{
				--j;
				tid[j] = zkl.merge(tid[j], tid[j + 1]);
				if (((pid[j + 1] - pid[j]) % 2 == 1 && (pid[j] - pid[j - 1]) % 2 == 1))
					tid[j] = zkl.delet(tid[j]);
				pid[j] = pid[j + 1];
			}
		}

		for (tsu = 0, i = 1; i < j; i++)
			for (k = pid[i - 1] + 1; k <= pid[i]; k++)
				tsu += abs(zkl.t[k].key - zkl.t[tid[i]].key);
		printf("%d\n", tsu);
	}

	return 0;
}