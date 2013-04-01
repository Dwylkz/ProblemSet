#include<iostream>
#include<algorithm>
using namespace std;

int n;
int s[100001];
int index[100001];
int sum[21][100001];
int tree[21][100001];

class seg_tree
{
	
public:
	
    void Build(int deep,int h,int o)
    {
        sum[deep][0]=0;
        int i;
        int in_left=0;
        int in_right=0;
        int mid=(h+o+1)>>1;
		
        if (h==o) return ;
		
        for (i=h;i<=o;i++)
        {
            if (tree[deep][i]<mid)
            {
                tree[deep+1][h+in_left]=tree[deep][i];
                in_left++;
                sum[deep][i]=in_left;
            }
            else
            {
                tree[deep+1][mid+in_right]=tree[deep][i];
                in_right++;
                sum[deep][i]=in_left;
            }
        }
        Build(deep+1,h,mid-1);
        Build(deep+1,mid,o);
    }
	
    int Search(int deep,int h,int o,int sh,int so,int k)
    {
        int l,r,mid;
        if (sh==so) return tree[deep][sh];
        else 
        {
            mid=(h+o+1)>>1;
            if (sh==h) l=0;
            else l=sum[deep][sh-1];
            r=sum[deep][so];
            if (r-l>=k) 
                return Search(deep+1,h,mid-1,h+l,h+r-1,k);
            else 
                return Search(deep+1,mid,o,mid+(sh-h-l),mid+(so-h-r),k-(r-l));
        }
    }
	
};



inline bool cmp(int a,int b)
{
    if (s[a]==s[b]) return a<b;
    return s[a]<s[b];
}

int main()
{
    seg_tree zkl;
    int c,i,m,h,o,k;
	scanf("%d",&c);
	while (c--)
	{
		scanf("%d%d",&n,&m);
		
		for (i=1;i<=n;i++) 
		{
			scanf("%d",&s[i]);
			index[i]=i;
		}
		
		sort(index+1,index+1+n,cmp);
		for (i=1;i<=n;i++) tree[0][index[i]]=i;
		zkl.Build(0,1,n);
		
		while (m--)
		{
			scanf("%d%d%d",&h,&o,&k);
			i=zkl.Search(0,1,n,h,o,k);
			printf("%d\n",s[index[i]]);
		}
	}
    return 0;
}
