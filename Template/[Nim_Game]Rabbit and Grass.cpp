#include<iostream>
using namespace std;

int main()
{
	int m,n,nim;
	while (scanf("%d",&m) && m)
	{
		nim=0;
		while (m--) 
		{
			scanf("%d",&n);
			nim^=n;
		}
		puts(nim==0?"Grass Win!":"Rabbit Win!");
	}
	return 0;
}