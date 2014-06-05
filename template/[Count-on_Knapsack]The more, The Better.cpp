#include<iostream>
using namespace std;

int n,father[202],value[202];

void Cls (int *arr,int n)
{ while (n>=0) arr[n--]=0; }

void DFS_DP(int root,int *dp,int m)
{
	int i,j,k,*T_dp=new int [m+1];
	if (root!=0) m--;
	for (i=1;i<=n;i++) 
		if (father[i]==root)
		{
			Cls(T_dp,m); DFS_DP(i,T_dp,m);
			for (j=m;j>=1;j--)
				for (k=1;k<=j;k++)
					if (dp[j]<dp[j-k]+T_dp[k])
						dp[j]=dp[j-k]+T_dp[k];
		}
	if (root!=0) for (i=m+1;i>=1;i--) dp[i]=dp[i-1]+value[root];
}

int main()
{
	int m,i,a,b,dp[202];
	while (scanf("%d%d",&n,&m),n||m)
	{
		Cls(father,n); father[0]=-1;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			father[i]=a; value[i]=b;
		}
		value[0]=0; Cls(dp,n);
		DFS_DP(0,dp,m);
		printf("%d\n",dp[m]);
	}
	return 0;
}