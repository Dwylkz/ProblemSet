#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2010
int n,a[N],b[N],bL,c[N],cL;char s[N*N];
int main(int argc,char**argv)
{
	FILE*fi=fopen(argv[1],"r");
	int _;fscanf(fi,"%d",&_);
	while(_--)
	{
		fscanf(fi,"%d",&n);n/=2;
		for(int i=0;i<n*2;i++)fscanf(fi,"%d",a+i);
		bL=cL=0;
		scanf("%s",s);
		if(strlen(s)!=n*2){puts("WA");return 0;}
		for(int i=0;i<n*2;i++)
			if(s[i]=='0')b[bL++]=a[i];else
			if(s[i]=='1')c[cL++]=a[i];else {puts("WA");return 0;}
		if(bL!=n||cL!=n){puts("WA");return 0;}
		for(int i=0;i<n;i++)
			if(b[i]!=c[i]){puts("WA");return 0;}
	}
	puts("AC");
	return 0;
}