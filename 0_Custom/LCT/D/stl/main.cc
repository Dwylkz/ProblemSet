#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;
  
struct TTTT{int rev,p,s[2];} t[10010];
void Sets(int p,int k,int d) {if (t[p].s[d]=k) t[k].p=p;}
int Which(int k) {return t[t[k].p].s[1]==k;}
int Root(int k) {return !((t[t[k].p].s[0]==k)||(t[t[k].p].s[1]==k));}
int n,k,x,y;
char s[11];
  
void Pushdown(int k) {
    if (t[k].rev) {
        if (t[k].s[0]) t[t[k].s[0]].rev^=1;
        if (t[k].s[1]) t[t[k].s[1]].rev^=1;
        swap(t[k].s[0],t[k].s[1]);
        t[k].rev=0;
    }
}
  
void Rotate(int k) {
    Pushdown(t[t[k].p].p);
    Pushdown(t[k].p);
    Pushdown(k);
    int p=t[k].p,d=Which(k);
    Sets(p,t[k].s[d^1],d);
    if (Root(p)) t[k].p=t[p].p;
    else Sets(t[p].p,k,Which(p));
    Sets(k,p,d^1);
}
  
void Splay(int k) {
    Pushdown(k);
    while (!Root(k))
        if (Root(t[k].p)) Rotate(k);
        else
            if (Which(k)==Which(t[k].p))
                {Rotate(t[k].p);Rotate(k);}
            else
                {Rotate(k);Rotate(k);}
}
  
void Access(int k) {
    int p=k; k=0;
    for (;p;) {
        Splay(p); Sets(p,k,1);
        k=p;
        p=t[p].p;
    }
}
  
void Evert(int k) {
    Access(k); Splay(k);
    t[k].rev^=1;
}
  
int Find(int k) {
    Access(k); Splay(k);
    while (t[k].s[0]) {k=t[k].s[0];Pushdown(k);}
    return k;
}
  
int main() {
#if 1
  freopen("input.in", "rt", stdin);
#endif
    scanf("%d%d",&n,&k);
    REP(i,k) {
        scanf("%s%d%d",s,&x,&y);
        if (!strcmp(s,"Query")) puts(Find(x)==Find(y)?"Yes":"No");
        if (!strcmp(s,"Destroy")) {Evert(x);Access(y);Splay(y);t[x].p=t[y].s[0]=0;}
        if (!strcmp(s,"Connect")) {Evert(x);t[x].p=y;}
    }
    return 0;
}
