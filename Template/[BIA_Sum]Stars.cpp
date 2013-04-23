#include <vector>
#include <cstdio>
#include <memory>
#include <iostream>
#include <algorithm>
using namespace std;
#define LLD long long
#define TYPE int
#define MAXI 15011

class BIA
{
public :
	vector<int> tre;
	void ini(TYPE size)
	{
		tre.clear();
		tre.resize(size);
	}
	int operator [] (TYPE id)
	{
		return tre[id];
	}
	TYPE lowbit(TYPE id)
	{
		return id & (-id);
	}
	void update(TYPE id, TYPE add)
	{
		while (id < tre.size())
		{
			tre[id] += add;
			id += lowbit(id);
		}
	}
	TYPE query(TYPE id)
	{
		TYPE tsu = 0;
		while (id)
		{
			tsu += tre[id];
			id -= lowbit(id);
		}
		return tsu;
	}
} zkl;

struct node
{
	TYPE x, y;
};

TYPE lev[MAXI];

int main()
{
	TYPE i, n, maxi;
	vector<node> star;

	while (scanf("%d", &n) != EOF)
	{
		maxi = 0;
		star.resize(n + 1);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &star[i].x, &star[i].y);
			maxi = ++star[i].x > maxi? star[i].x: maxi;
		}
		zkl.ini(maxi + 1);
		memset(lev, 0, sizeof lev);
		for (i = 0; i < n; i++)
		{
			lev[zkl.query(star[i].x)]++;
			zkl.update(star[i].x, 1);
		}
		for (i = 0; i < n; i++)
			printf("%d\n", lev[i]);
	}

	return 0;
}
