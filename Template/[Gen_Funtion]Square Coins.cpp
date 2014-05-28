#include<cstdio>

int main()
{
	int i,j,k,n;
	int a[301],b[301];
	int s[18]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
	while ((scanf("%d",&n)!=EOF) && n)
	{
		for (i=0;i<301;i++)
		{
			a[i]=0;
			b[i]=0;
		}
		a[0]=1;
		b[0]=1;
		for (i=1;i<=17;i++)
		{
			for (j=0;j<n;j++)
				for (k=1;j+k*s[i]<=n;k++)
					b[j+k*s[i]]+=a[j];
			for (j=0;j<=n;j++)
				a[j]=b[j];
		}
		printf("%d\n",a[n]);
	}
	return 0;
}