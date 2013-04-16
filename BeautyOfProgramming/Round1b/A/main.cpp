//Header  
#include <cstdio>  
#include <cstdlib>  
#include <iostream>  
#include <cstring>  
#include <string>  
#include <vector>  
#include <map>  
#include <algorithm>  
#include <cctype>  
#include <queue>  
#include <stack>  
#include <cmath>  
using namespace std;  
//Macro  
//STL-Alias  
#define UN(c, a) unique(c, a)  
#define MS(c, a) memset(c, a, sizeof c)  
#define FLC(c, a ,b) fill(c, c + a, b)  
#define LOS(c, a, b) lower_bound(c, a, b)  
#define UPS(c, a, b) upper_bound(c, a, b)  
//Syntax-Alias  
#define Rep(c, a, b) for (int c = (a); c < (b); c++)  
#define Nre(c, a, b) for (int c = (a); c > (b); c--)  
//DEBUG  
#define FK puts("Fu*k here!")  
#define PA(s, c, a, b, p, f){\
    printf(s);\
    Rep(c, a, b) printf(p, (f));\
    puts("");}
//Constant  
#define INFL (0x7fffffffffffffffLL)  
#define INFI (0x7fffffff)  
#define MOD ()  
#define MAXN (220)  
//Type-Alias  
typedef long long LL;  
typedef long double LD;  
typedef int AI[MAXN];  
typedef bool AB[MAXN];  
typedef double AD[MAXN];  
typedef LL ALL[MAXN];  
typedef LD ALD[MAXN];  
  
//FSG  
struct Edge  
{  
    int v, w, next;  
};  
vector<Edge> E;  
AI L;  
void G_ini()  
{  
    E.clear();  
    MS(L, -1);  
}  
void AE(int u, int v, int w)  
{  
    Edge te = {v, w, L[u]};  
    L[u] = E.size();  
    E.push_back(te);  
}  
#define Ere(c, a, L) for (int c = L[a]; c != -1; c = E[c].next)  
  
//SAP  
int SAP(int src, int snk, int V){  
    static AI dis, gap, _L, se;  
    int u = src, mxf = 0, te = 0;  
    memcpy(_L, L, sizeof L);  
    MS(dis, 0); MS(gap, 0);  
    gap[0] = V;  
    while (dis[src] < V){  
        for (int &i = _L[u]; i != -1; i = E[i].next)  
            if (E[i].w && dis[u] == dis[E[i].v] + 1) break;  
        if (_L[u] != -1){  
            u = E[se[te++] = _L[u]].v;  
            if (u == snk){  
                int _i = 0, mf = INFI;  
                Rep(i, 0, te) if (E[se[i]].w < mf){  
                    mf = E[se[i]].w; _i = i;  
                }  
                Rep(i, 0, te){  
                    E[se[i]].w -= mf; E[se[i] ^ 1].w += mf;  
                }  
                mxf += mf; te = _i;  
                u = E[se[_i] ^ 1].v;  
            }  
            continue;  
        }  
        int md = V; _L[u] = -1;  
        Ere(i, u, L) if (E[i].w && dis[E[i].v] < md){  
            md = dis[E[i].v]; _L[u] = i;  
        }  
        if (!--gap[dis[u]]) break;  
        gap[dis[u] = md + 1]++;  
        if (u != src) u = E[se[te-- - 1] ^ 1].v;  
    }  
    return mxf;  
}  


int n, m;  
  
int main()  
{  
#if 1
	freopen("input.in", "r", stdin);
#endif
    int T;  
    scanf("%d", &T);  
    for (int Case = 1; Case <= T; Case++)  
    {  
        //Initialize  
        scanf("%d%d", &n, &m); 
		printf("Case #%d:\n", Case);
        G_ini();  
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			u--;
			v--;
			AE(u, v, w);
			AE(v, u, w);
			int mxf = SAP(0, n - 1, n);
			if (mxf) {
				printf("%d %d\n", i, mxf);
			}
		}
    }  
    return 0;  
}  
