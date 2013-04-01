#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n,m,count,bsum,a[101],c[101];
	bool dp[100001];
	while (scanf("%d%d",&n,&m),n||m)
	{
		for (i=0;i<n;i++) scanf("%d",&a[i]);
		for (i=0;i<n;i++) scanf("%d",&c[i]);
		for (i=1;i<=m;i++) dp[i]=0; 
		dp[0]=1; count=0;
		for (i=0;i<n;i++)
		{
			k=1; bsum=0;
			while (bsum<c[i])
			{
				for (j=m;j>=k*a[i];j--) 
					dp[j]|=dp[j-k*a[i]];
				bsum+=k; k<<=1;
				if (bsum+k>c[i]) k=c[i]-bsum;
			}
		}
		for (i=1;i<=m;i++) if (dp[i]) count++;
		printf("%d\n",count);
	}
	return 0;
}