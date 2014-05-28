#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INFI (1<<31)-1

struct node 
{ 
	double x,y; 
	bool operator < (node o) { return x<o.x; }
}s[100000];

bool cmp( int a, int b) { return s[a].y<s[b].y; }

double MiN( double a, double b) { return a<b?a:b; } 

double dis( node a, node b) { return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); }

double Bin_search(int h,int o)
{
	if (o-h<1) return INFI;
	if (o-h==1) return dis(s[h],s[o]);
	double delta,mini;
	int i,j,mid=(h+o)/2;
	delta=mini=MiN(Bin_search(h,mid),Bin_search(mid+1,o));
	int *y=new int [o-h+1];
	int l=0;
	for (i=h;i<=o;i++)
		if (s[i].x>s[mid].x-delta && s[i].x<s[mid].x+delta)
			y[l++]=i;
	sort(y,y+l,cmp);
	for (i=0;i<l;i++)
		for (j=i+1;j<l && j<i+7;j++)
			mini=MiN(dis(s[y[i]],s[y[j]]),mini);
	return mini;
}

int main()
{
	int i,n;
	while (scanf("%d",&n),n)
	{
		for (i=0;i<n;i++) scanf("%lf%lf",&s[i].x,&s[i].y);
		sort(s,s+n); 
		printf("%.2lf\n",Bin_search(0,n-1)/2.0);
	}
	return 0;
}
