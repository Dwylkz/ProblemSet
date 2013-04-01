#include<iostream>
using namespace std;
#define min(x,y) x<y?x:y

int dps[1500][2],n;
int fath[1500];

int dfs(const int &root)
{
	int i;
	bool lea=1;
	for (i=0;i<n;i++)
	{
		if (fath[i]==root)
		{
			lea=0;
			dfs(i);
			dps[root][0]+=dps[i][1];
			dps[root][1]+=min(dps[i][0],dps[i][1]);
		}
	}
	if (lea)
	{
		dps[root][0]=0;
		dps[root][1]=1;
	}
	else
		dps[root][1]++;
	return 0;
}

int main()
{
	int i,nod,roa,pot;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0;i<n;i++) 
		{
			fath[i]=-18;
			dps[i][0]=dps[i][1]=0;
		}
		for (i=0;i<n;i++)
		{
			scanf("%d:(%d)",&nod,&roa);
			while (roa--)
			{
				scanf("%d",&pot);
				fath[pot]=nod;
			}
		}

		//printf("outinput\n\n");

		i=0;
		while (fath[i]>0) i++;
		dfs(i);
		printf("%d\n",min(dps[i][0],dps[i][1]));
	}
	return 0;
}