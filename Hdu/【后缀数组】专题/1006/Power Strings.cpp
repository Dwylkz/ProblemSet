#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define LLU long long
#define MAXN (3000010)
#define MAXT (4400)
#define INFI MAXN
#define SHIFT (0)

struct SA
{
    int ws[MAXN],wa[MAXN],wb[MAXN],wv[MAXN],sa[MAXN],wd[MAXN],rank[MAXN],height[MAXN],a[MAXN],f[MAXN];
    char s[MAXN];

    #define F(x) ((x)/3+((x)%3==1?0:tb))
    #define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
    int c0(int *r,int a,int b)
    {
        return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
    }
    int c12(int k,int *r,int a,int b)
    {
        if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
        else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
    }
    void sort(int *r,int *a,int *b,int n,int m)
    {
        int i;
        for(i=0; i<n; i++) wv[i]=r[a[i]];
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[wv[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) b[--ws[wv[i]]]=a[i];
        return;
    }
    void dc3(int *r,int *sa,int n,int m)
    {
        int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
        r[n]=r[n+1]=0;
        for(i=0; i<n; i++) if(i%3!=0) wa[tbc++]=i;
        sort(r+2,wa,wb,tbc,m);
        sort(r+1,wb,wa,tbc,m);
        sort(r,wa,wb,tbc,m);
        for(p=1,rn[F(wb[0])]=0,i=1; i<tbc; i++)
            rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
        if(p<tbc) dc3(rn,san,tbc,p);
        else for(i=0; i<tbc; i++) san[rn[i]]=i;
        for(i=0; i<tbc; i++) if(san[i]<tb) wb[ta++]=san[i]*3;
        if(n%3==1) wb[ta++]=n-1;
        sort(r,wb,wa,ta,m);
        for(i=0; i<tbc; i++) wv[wb[i]=G(san[i])]=i;
        for(i=0,j=0,p=0; i<ta && j<tbc; p++)
            sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
        for(; i<ta; p++) sa[p]=wa[i++];
        for(; j<tbc; p++) sa[p]=wb[j++];
        return;
    }

    int cmp(int *r, int a, int b, int l)
    {
        return r[a] == r[b] && r[a+l] == r[b+l];
    }

    void ini(int *r, int l, int m)
    {
        dc3(r, sa, l, m);
        //da(r, l, m);
        calHeight(r, l - 1);
    }

    void da(int *r, int n, int m)
    {
        int i, j, p, *x = wa, *y = wb, *t;
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p)
        {
            for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
            for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
            for(i = 0; i < n; i ++) wv[i] = x[y[i]];
            for(i = 0; i < m; i ++) wd[i] = 0;
            for(i = 0; i < n; i ++) wd[wv[i]] ++;
            for(i = 1; i < m; i ++) wd[i] += wd[i-1];
            for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++)
                x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }

    void calHeight(int *r, int n)
    {
        int i, j, k = 0;
        for(i = 1; i <= n; i ++) rank[sa[i]] = i;
        for(i = 0; i < n; height[rank[i ++]] = k)
            for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
} zkl;

/*struct ST
{
    int t[20][MAXN];

    int low(int x)
    {
        int c = 0;
        while ((1 << c) <= x) c++;
        return c;
    }

    void ini(int *S, int len)
    {
        int tp, l = low(len);

        Rep(i, 0, len) t[0][i] = S[i];
        Rep(i, 1, l) Rep(j, 0, len)
        {
            tp = (1 << i >> 1);
            if (j + tp < len)
                t[i][j] = min(t[i - 1][j], t[i - 1][j + tp]);
        }
    }

    int que(int l, int r)
    {
        int j, tp;

        if (l > r) swap(l, r);
        j = low(r - l + 1) - 1;
        tp = (1 << j);
        return min(t[j][l], t[j][r - tp + 1]);
    }
} rmq;
*/

char buf[MAXN];
int len, str[MAXN], C = 0;

/*int lcp(int x, int y)
{
    int id;

    x = zkl.rank[x];
    y = zkl.rank[y];
    if (x > y) swap(x, y);
    x++;
    return rmq.que(x, y);
}*/

bool vis[MAXN];
int mini[MAXN];

void solve()
{
    int maxc = 1;

    Rep(x, 1, len)
    if ((len - 1) % x == 0 && mini[zkl.rank[x]] == len - x - 1)
        maxc = max(maxc, (len - 1)/ x);
    printf("%d\n", maxc);
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif
    int lb, bt, tmin;

    while (scanf("%s", buf), strcmp(buf, "."))
    {
        len = 0;
        lb = strlen(buf);
        Rep(i, 0, lb) str[len++] = buf[i];
        str[len++] = 0;

        zkl.ini(str, len, 512);
        //rmq.ini(zkl.height, len);
        tmin = mini[zkl.rank[0] + 1] = zkl.height[zkl.rank[0] + 1];
        Rep(i, zkl.rank[0] + 2, len) mini[i] = tmin = min(tmin, zkl.height[i]);
        tmin = mini[zkl.rank[0] - 1] = zkl.height[zkl.rank[0]];
        Rep(i, zkl.rank[0] - 2, -1) mini[i] = tmin = min(tmin, zkl.height[i]);
        #if 0
            Rep(i, 0, len)
                {
                    printf(" %d: ", zkl.sa[i]);
                    Rep(j, zkl.sa[i], len)
                    printf("%c", str[j] - SHIFT);
                    puts("");
                }
            puts("");
            printf(" height =");
            Rep(i, 0, len) printf(" %d", zkl.height[i]);
            puts("");
            puts("");
            printf(" mini =");
            Rep(i, 0, len) printf(" %d", mini[i]);
            puts("");
        #endif

        solve();
    }

    return 0;
}
