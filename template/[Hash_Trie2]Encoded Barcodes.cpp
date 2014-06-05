#include<iostream>
#include<string>
using namespace std;

class trie
{

public :

	trie() { root = new node; }

	void insert(char *key)
	{
		int i , l = strlen(key);
		node *p = root;
		for (i=0;i<l;i++)
		{
			if (p->next[key[i]-97] == NULL)
				p->next[key[i]-97] = new node;
			p = p->next[key[i]-97];
			p->count++;
		}
	}

	int search(char *key)
	{
		int i , l = strlen(key);
		node *p = root;
		for (i=0;i<l;i++)
		{
			p = p->next[key[i]-97];
			if (p == NULL) return 0;
		}
		return p->count;
	}

protected :

	struct node
	{
		node *next[30];
		int count;

		node() 
		{ 
			count  = 0;
			memset(next , NULL ,sizeof next); 
		}
	}*root;

};

double cod[10];

char encode(double ave)
{
	int i , o = 1;
	int key = 0;
	for (i=7;i>=0;i--)
	{
		if (cod[i] >= ave)
			key += o;
		o *= 2;
	}
	return key;
}

int main()
{
	int n,m,k,id,i,sum;
	double tsu;
	char buf[35];
	while (scanf("%d%d",&n,&m) != EOF)
	{
		trie zkl;
		sum = 0;
		while (n--)
		{
			scanf("%s",buf);
			zkl.insert(buf);
		}
		while (m--)
		{
			scanf("%d",&k);
			id = 0;
			while (k--)
			{
				tsu = 0.0;
				for (i=0;i<8;i++) 
				{
					scanf("%lf",&cod[i]);
					tsu += cod[i];
				}
				buf[id++] = encode(tsu / 8.0);
			}
			buf[id] = 0;
			sum += zkl.search(buf);
		}
		printf("%d\n",sum);
	}
	return 0;
}