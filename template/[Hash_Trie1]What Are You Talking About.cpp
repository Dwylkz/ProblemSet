#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define MAXI 3030

class Trie
{
public :
	struct node
	{
		string key;
		node *next[30];
	} *root, **p;
	Trie() { Cre(root); }
	void Cre(node *&x)
	{
		int i;
		x = new node;
		x->key = "-1";
		for (i = 0; i < 30; i++)
			x->next[i] = NULL;
	}
	void Ins(char *key, char *tra)
	{
		int i;
		p = &root;
		for (i = 0; key[i]; i++)
		{
			p = &((*p)->next[key[i] - 'a']);
			if (*p == NULL) Cre(*p);
		}
		(*p)->key = tra;
	}
	string Que(const char *key)
	{
		int i;
		p = &root;
		for (i = 0; key[i]; i++)
		{
			p = &((*p)->next[key[i] - 'a']);
			if (*p == NULL) break;
		}
		if (*p) return (*p)->key;
		else return "-1";
	}
}zkl;

int main()
{
	char a[MAXI], b[MAXI], ste[MAXI];
	string w1, w2;
	int i;

	scanf("%s", ste);
	while (scanf("%s", a), strcmp(a, "END"))
	{
		scanf("%s", b);
		zkl.Ins(b, a);
	}

	scanf("%s", ste);
	getchar();
	while (gets(ste))
	{
		if (!strcmp(ste, "END"))
			break;
		w1 = "";
		strcat(ste, "\n");
		for (i = 0; i < strlen(ste); i++)
			if (isalpha(ste[i]))
				w1 += ste[i];
			else
			{
				if (w1 != "")
				{
					w2 = zkl.Que(w1.c_str());
					if (w2 == "-1") printf("%s", w1.c_str());
					else printf("%s", w2.c_str());
					w1 = "";
				}
				printf("%c", ste[i]);
			}
	}

	return 0;
}