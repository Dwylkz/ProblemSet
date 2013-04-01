#include<iostream>
using namespace std;

int main()
{
	int i,j;
	int C[26][28];
	__int64 dp[14],count;
	dp[0]=0; dp[1]=0; dp[2]=1;
	for (i=3;i<14;i++) dp[i]=(i-1)*(dp[i-2]+dp[i-1]);
	C[0][0]=1; C[0][1]=0;
	for (i=1;i<26;i++)
	{
		C[i][0]=1;
		for (j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		C[i][i+1]=0;
	}
	//printf("%I64d\n",C[25][24]);
	while (scanf("%d",&j),j)
	{
		count=1;
		for (i=2;i<=j/2;i++) count+=C[j][i]*dp[i];
		printf("%I64d\n",count);
	}
	return 0;
}