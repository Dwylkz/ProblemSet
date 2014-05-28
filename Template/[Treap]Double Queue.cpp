#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define SNG(x) (x? -1: 1)
#define NEG(x) ((x + 1) % 2)
#define MAXI 2000002

class treap
{
public :
	struct node
	{ int key, son[2], rank, count, k; };
	node tre[MAXI];
	int root, size;

	void ini()
	{ 
		srand(111);
		root = size = -1; 
	}

	void cre(int &x, int key, int k)
	{
		x = ++size;
		tre[x].key = key;
		tre[x].count = 1;
		tre[x].k = k;
		tre[x].rank = rand();
		tre[x].son[0] = tre[x].son[1] = -1;
	}

	void rot(int &x, int b)
	{
		int y = tre[x].son[b];
		tre[x].son[b] = tre[y].son[NEG(b)];
		tre[y].son[NEG(b)] = x; x = y;
	}

	void ins(int &x, int key, int k)
	{
		int lr;
		if (x == -1)
		{ cre(x, key, k); return ; }
		if (tre[x].key == key)
		{ tre[x].count++; return ;}
		lr = key > tre[x].key;
		ins(tre[x].son[lr], key, k);
		rot(x, lr);
	}

	void del(int &x, int key)
	{
		int lr;
		if (x == -1) return ;
		if (tre[x].key == key)
		{
			if (--tre[x].count) return ;
			if (tre[x].son[0] == -1 && tre[x].son[1] == -1)
				x = -1;
			else if (tre[x].son[0] == -1) 
				x = tre[x].son[1];
			else if (tre[x].son[1] == -1)
				x = tre[x].son[0];
			else
			{
				lr = tre[tre[x].son[0]].rank < tre[tre[x].son[1]].rank;
				rot(x, lr);
				del(tre[x].son[NEG(lr)], key);
			}
		}
		else
		{
			lr = key > tre[x].key;
			del(tre[x].son[lr], key);
		}
	}

	int & ext(int b)
	{
		int p = root;
		while (p != -1 && tre[p].son[b] != -1)
			p = tre[p].son[b];
		return p;
	}
} zkl;

queue<int> ppmm;

int main()
{
	int p, k, sn, op;

	zkl.ini();
	while (scanf("%d", &op), op)
	{
		switch (op)
		{
			case 1:
				scanf("%d%d", &k, &p);
				zkl.ins(zkl.root, p, k);
				break;
			case 2:
				sn = zkl.ext(1);
				if (sn != -1) 
				{
					zkl.del(zkl.root, zkl.tre[sn].key);
					printf("%d\n", zkl.tre[sn].k);
				}
				else printf("0\n");
				break;
			case 3:
				sn = zkl.ext(0);
				if (sn != -1) 
				{
					zkl.del(zkl.root, zkl.tre[sn].key);
					printf("%d\n", zkl.tre[sn].k);
				}
				else printf("0\n");
		}
	}

	return 0;
}