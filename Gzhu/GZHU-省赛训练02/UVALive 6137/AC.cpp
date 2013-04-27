#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char mp[55][55];
int n,m,tot;
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
bool vis[2505];
int match[2505];
vector<int> g[2555];
bool judge(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<m&&mp[x][y]=='.')
        return true;
    return false;
}
int dfs(int k)
{
    for(int i=0; i<g[k].size(); i++)
    {
        int j=g[k][i];
        if(!vis[g[k][i]])
        {
            vis[g[k][i]]=true;
            if(match[j]==-1||dfs(match[j]))
            {
                match[j]=k;
                match[k]=j;
                return 1;
            }
        }
    }
    return 0;
}
int work()
{
    if(tot&1)
        return 1;
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=0; i<n*m; i++)
    {
        if(mp[i/m][i%m]=='X')
            continue;
        //cout<<i<<endl;
        if(match[i]==-1)
        {
            //cout<<"i"<<i<<endl;
            memset(vis,0,sizeof(vis));
            if(dfs(i)==0)
            {
                return 1;
            }
        }
    }
    //cout<<ans<<endl;
    //if(ans*2==tot)
        return 2;
    //return 1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        tot=0;
        for(int i=0; i<n*m; i++)
            g[i].clear();
        for(int i=0; i<n; i++)
            scanf("%s",mp[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mp[i][j]=='.')
                {
                    tot++;
                    for(int k=0; k<4; k++)
                        if(judge(i+dx[k],j+dy[k]))
                            g[i*m+j].push_back((i+dx[k])*m+j+dy[k]);
                }
        printf("%d\n",work());
    }
}
