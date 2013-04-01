#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAXI 2000002

struct node
{
	int key, cou, num;
	node *s[2], *p;
};

class splay
{
public :
    node *root, *x, *y, *w, tre[MAXI];
	int size;

	void ini()
	{ root = NULL; size = 0; }

	void cre(node *tp, node *&tx, int key, int num)
	{
		tx = &tre[size++];
		tx->p = tp;
		tx->cou = 1;
		tx->key = key;
		tx->num = num;
		tx->s[0] = NULL;
		tx->s[1] = NULL;
	}

	void rot(node *tx, bool b)
	{
		x = tx->s[b];
		tx->s[b] = x->s[!b];
		if (x->s[!b])
			x->s[!b]->p = tx;
		x->p = tx->p;
		x->s[!b] = tx;
		tx->p = x;
		if (x->p)
		{
			b = (x->p->s[b] != tx) ^ b;
			x->p->s[b] = x;
		}
	}

	void spa(node *s)
	{
		bool lr, ll;
		while (s->p != NULL)
		{
			lr = ll = 0;
			if (root->s[lr] == s)
			{
				rot(root, lr);
				break;
			}
			else if (root->s[!lr] == s)
			{
				rot(root, !lr);
				break;
			}
			else
			{
				y = s->p->p;
				lr = y->s[lr] != s->p;
				ll = (s->p->s[lr] != s) ^ lr;
				rot(s->p, ll);
				rot(y, lr);
			}
		}
		root = s;
	}

	void ins(int key, int num)
	{
		bool lr;
		if (root == NULL)
		{
			cre(NULL, root, key, num);
			return ;
		}
		x = root;
		while (x && key != x->key)
		{
			y = x;
			lr = key > x->key;
			x = x->s[lr];
		}
		if (x == NULL)
		{
			cre(y, x, key,num);
			y->s[lr] = x;
		}
		else if (key == x->key) x->cou++;
		spa(x);
	}

	void del(int key)
	{
	    bool lr;
	    x = root;
	    while (x && x->key != key)
	    {
	        lr = key > x->key;
	        x = x->s[lr];
	    }
		if (x == NULL) return ;
		if (--x->cou) return ;
		spa(x);
		if (!root->s[0])
		{
			if (root->s[1]) root->s[1]->p = NULL;
			root = root->s[1];
		}
		else
		{
			spa(ext(root->s[0], 1));
			root->s[1] = root->s[1]->s[1];
			if (root->s[1]) root->s[1]->p = root;
		}
	}

	node * ext(node *s, bool b)
	{
		x = s;
		while (x && x->s[b])
			x = x->s[b];
		return x;
	}

} zkl;

int main()
{
	int p, k, op;
	node *sn;

	zkl.ini();
	while (scanf("%d", &op), op)
	{
		switch (op)
		{
			case 1:
				scanf("%d%d", &k, &p);
				zkl.ins(p, k);
				break;
			case 2:
				sn = zkl.ext(zkl.root, 1);
				if (sn != NULL)
				{
					printf("%d\n", sn->num);
					zkl.del(sn->key);
				}
				else printf("0\n");
				break;
			case 3:
				sn = zkl.ext(zkl.root, 0);
				if (sn != NULL)
				{
					printf("%d\n", sn->num);
					zkl.del(sn->key);
				}
				else printf("0\n");
		}
	}
#if 0
	printf("root = %d\n", zkl.root->key);
	printf("size = %d\n", zkl.size);
	for (int i = 0; i < zkl.size; i++)
		printf("key = %d num = %d\n", zkl.tre[i].key, zkl.tre[i].num);
#endif
	return 0;
}

