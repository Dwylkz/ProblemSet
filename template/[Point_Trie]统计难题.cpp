#include<string>
#include<iostream>
using namespace std;

struct node 
{
	node *son,*brother;
	char alph;
	int count;
};

class tire
{

private:

	node *root,*x,*w;

public:

	tire ()
	{
		make_node(root);
	}

	~tire(){};

	void make_node(node *&point)
	{
		point=new node;
		point->son=NULL;
		point->brother=NULL;
		point->count=0;
		point->alph=' ';
	}

	void Insert(char *str)
	{
		int i;
		x=root;
		for (i=0;i<strlen(str);i++)
		{
			while (x->brother!=NULL && x->alph!=str[i]) x=x->brother;
			if (x->alph==' ')
			{
				x->alph=str[i];
				make_node(w);
				x->brother=w;
			}
			x->count++;
			if (i<strlen(str)-1 && x->son==NULL)
			{
				make_node(w);
				x->son=w;
			}
			x=x->son;
		}
	}

	int Search(char *str)
	{
		int i;
		x=root;
		for (i=0;i<strlen(str);i++)
		{
			while (x!=NULL && x->alph!=str[i]) x=x->brother;
			if (x==NULL) return 0;
			else 
				if (i<strlen(str)-1) x=x->son;
		}
		return x->count;
	}

};

int main()
{
	tire zkl;
	char word[12];
	while (gets(word) && strlen(word)!=0)
	{
		zkl.Insert(word);
	}
	while (gets(word))
	{
		printf("%d\n",zkl.Search(word));
	}
	return 0;
}