#include <iostream>
#include <string>
using namespace std;
#define MAXI 11

class BST
{
public :
	struct node
	{
		int key;
		node *son[2];
	} *root, space[3 * MAXI];
	int id;
	void Init() { root = NULL; id = 0; }
	void Bulid(char *s)
	{
		int i;
		Init();
		for (i = 0; i < strlen(s); i++)
			Insert(s[i]);
	}
	void Create(node *&x, int key)
	{
		x = &space[id++];
		x->key = key;
		x->son[0] = NULL;
		x->son[1] = NULL;
	}
	void Insert(int key)
	{
		bool lr;
		node *x = root, *y, *w;
		if (root == NULL)
		{ Create(root, key); return ; }
		while (x != NULL)
		{
			y = x;
			lr = key > x->key;
			x = x->son[lr];
		}
		Create(w, key);
		y->son[lr] = w;
	}
	void Ftra(node *x, string &s)
	{
		if (x == NULL) return ;
		s += x->key;
		Ftra(x->son[0], s);
		Ftra(x->son[1], s);
	}
	void Mtra(node *x, string &s)
	{
		if (x == NULL) return ;
		Mtra(x->son[0], s);
		s += x->key;
		Mtra(x->son[1], s);
	}
	bool operator == (BST o)
	{
		 string s1, s2;
		 Ftra(root, s1);
		 Ftra(o.root, s2);
		 if (s1 != s2) return 0;
		 Mtra(root, s1);
		 Mtra(o.root, s2);
		 if (s1 != s2) return 0;
		 return 1;
	}
}zkl, tzk;

int main()
{
	int n;
	char ch[MAXI];

	while (scanf("%d", &n), n)
	{
		scanf("%s", ch);
		zkl.Bulid(ch);
		while (n--)
		{
			scanf("%s", ch);
			tzk.Bulid(ch);
			puts(zkl == tzk? "YES": "NO");
		}
	}

	return 0;
}