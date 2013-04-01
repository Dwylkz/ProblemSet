#include<iostream>
using namespace std;

int main()
{
	int i,j,k,bsum,n,v[50],m[50],sum,hsu;
	bool dp[125001];
	while (scanf("%d",&n),n>-1)
	{
		sum=0; dp[0]=1;
		for (i=0;i<n;i++) 
		{
			scanf("%d%d",&v[i],&m[i]);
			sum+=v[i]*m[i];
		}
		hsu=sum>>1;
		for (i=1;i<=hsu;i++) dp[i]=0;
		for (i=0;i<n;i++)
		{
			k=1; bsum=0;
			while (bsum<m[i])
			{
				for (j=hsu;j>=k*v[i];j--)
					dp[j]=dp[j-k*v[i]];
				bsum+=k; k<<=1;
				if (bsum+k>m[i]) k=m[i]-bsum; 
			}
		}
		for (i=hsu;i>=0;i--) 
			if (dp[i]) break;
		if (sum-i>i) hsu=sum-i;
		printf("%d %d\n",hsu,sum-hsu);
	}
	return 0;
}