#include<iostream>
using namespace std;

int main()
{
	int c,n,m;
	scanf("%d",&c);
	while (c--)
	{
		scanf("%d%d",&n,&m);
		puts(n%(m+1)?"first":"second"); 
	}
	return 0;
}
