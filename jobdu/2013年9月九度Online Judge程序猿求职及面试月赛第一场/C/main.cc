#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e6+10;

int next[N],extand[N];  
char S[N],T[N];  
void GetNext(const char *T){  
  int len=strlen(T),a=0;  
  next[0]=len;  
  while(a<len-1 && T[a]==T[a+1]) a++;  
  next[1]=a;  
  a=1;  
  for(int k=2;k<len;k++){  
    int p=a+next[a]-1,L=next[k-a];  
    if( (k-1)+L >= p){  
      int j = (p-k+1)>0 ? (p-k+1) : 0;  
      while(k+j<len && T[k+j]==T[j]) j++;  
      next[k]=j;  
      a=k;   
    }   
    else  
      next[k]=L;   
  }   
}   
void GetExtand(const char *S,const char *T){  
  GetNext(T);  
  int slen=strlen(S),tlen=strlen(T),a=0;   
  int MinLen = slen < tlen ? slen : tlen;  
  while(a<MinLen && S[a]==T[a]) a++;  
  extand[0]=a;  
  a=0;  
  for(int k=1;k<slen;k++){  
    int p=a+extand[a]-1, L=next[k-a];  
    if( (k-1)+L >= p){  
      int j= (p-k+1) > 0 ? (p-k+1) : 0;  
      while(k+j<slen && j<tlen && S[k+j]==T[j]) j++;  
      extand[k]=j;  
      a=k;   
    }  
    else   
      extand[k]=L;   
  }   
}   

char a[N], b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s%s", a, b); ) {
    int rv = 0, la = strlen(a), lb = strlen(b);
    GetExtand(a, b);
    for (int i = 0; i < la; i++)
      if (extand[i] == la-i)
        rv = max(rv, extand[i]);
#if 0
    for (int i = 0; i < la; i++) {
      printf(" %3d", extand[i]);
    }
    puts("");
#endif
#if 0
    for (int i = 0; i < lb; i++) {
      printf(" %3d", extand[i]);
    }
    puts("");
#endif
    printf("%d\n", rv);
  }
  return 0;
}
