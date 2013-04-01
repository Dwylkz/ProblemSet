#include<iostream>
using namespace std;
struct st
{
    int left,right;
    int sum;
}a[1000000];
int max(int c,int d)
{
    if(c>d)
        return c;
    return d;
}
void build(int s,int t,int n)
{
      int mid;
      a[n].sum=0;
      a[n].left=s;
      a[n].right=t;
      if(s==t)
          return ;
      mid=(s+t)/2;
      build(s,mid,n*2);
      build(mid+1,t,n*2+1);
      return ;
}
void insert(int s,int step,int k)
{
    if(a[step].left==a[step].right)
    {
        a[step].sum=k;
        return ;
    }
    int mid=(a[step].left+a[step].right)/2;
    if(s>mid)
        insert(s,step*2+1,k);
    else
        insert(s,step*2,k);
    a[step].sum=max(a[step*2].sum,a[step*2+1].sum);
}
int search(int s,int t,int step)
{
    int maxi = -(0x7fffffff);
    if(s<=a[step].left&&a[step].right<=t) return a[step].sum;
    int mid=(a[step].left+a[step].right)/2;
    if (s <= mid) maxi = max(maxi, search(s, t, step << 1));
    if (mid < t) maxi = max(maxi, search(s, t, (step << 1) + 1));
        return maxi;
}
int main()
{
    int i,n,m,f,g,h,max;
    char c[2];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&f);
            insert(i,1,f);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%1s%d%d",c,&g,&h);
            if(c[0]=='Q')
            {
                max=search(g,h,1);
                printf("%d\n",max);
            }
            if(c[0]=='U')
            {
                insert(g,1,h);
            }
        }
    }
    return 0;
}
