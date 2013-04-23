#include<stdio.h>

int main()
{
	int n,m,k,s,a,b,i,j,dp[101][101];
	while (scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
	{
		for (i=0;i<=m;i++)
			for (j=0;j<=s;j++)
				dp[i][j]=0;
		while (k--)
		{
			scanf("%d%d",&a,&b);
			for (i=b;i<=m;i++)
				for (j=s;j>=1;j--)
					if (dp[i][j]<dp[i-b][j-1]+a)
					{
						dp[i][j]=dp[i-b][j-1]+a;
					}
		}
		for (i=0;i<=m;i++)
			if (dp[i][s]>=n) break;
		printf(i>m?"-1\n":"%d\n",m-i);
	}
	return 0;
}