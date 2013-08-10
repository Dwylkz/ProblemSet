#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
int n,a[N],b[N],c[N];
int main(int argc,char**argv)
{
	FILE*fi=fopen(argv[1],"r");
	int _;fscanf(fi,"%d",&_);
	while(_--)
	{
		fscanf(fi,"%d",&n);
		for(int i=0;i<n;i++)fscanf(fi,"%d",b+i);
		for(int i=0;i<n;i++)scanf("%d",a+i);
		for(int i=0;i<n;i++)scanf("%d",c+i);
		for(int i=0;i<n;i++)if((a[i]+b[i])%n!=c[i]){puts("WA");return 0;}
		sort(a,a+n);
		sort(c,c+n);
		for(int i=0;i<n;i++)if(a[i]!=i||c[i]!=i){puts("WA");return 0;}
	}
	puts("AC");
	return 0;
}