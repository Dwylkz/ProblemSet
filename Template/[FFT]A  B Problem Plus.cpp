#include<cmath>
#include<string>
#include<iostream>
using namespace std;
#define pi acos(-1.0) 

struct complex
{
    double r,i;
    complex (){r=i=0.0;}
    complex (double real,double image)
	{
		r=real;
		i=image;
	}
    complex operator + (complex o)
	{
		return complex(r+o.r,i+o.i);
	}
    complex operator - (complex o)
	{
		return complex(r-o.r,i-o.i);
	}
    complex operator * (complex o)
	{
		return complex(r*o.r-i*o.i,r*o.i+i*o.r);
	}
}op1[200001],op2[200001];

char a[100001],b[100001];
int sum[200001];

void brc(complex *y,int l)
{
    int i,j,k;
    j=l/2;
    for (i=1;i<l-1;i++)
    {
        if (i<j) swap(y[i],y[j]);
        k=l/2;
        while (j>=k)
        {
            j-=k;
            k/=2;
        }
        if (j<k) j+=k;
    }
}

void fft(complex *y,int l,double on)
{
    int i,j,k,m;
    complex u,t;
    brc(y,l);
    for (m=2;m<=l;m*=2)
    {
        complex wn(cos(on*2*pi/m),sin(on*2*pi/m));
        for (j=0;j<l;j+=m)
        {
            complex w(1,0);
            for (k=j;k<j+m/2;k++)
            {
                u=y[k];
                t=w*y[k+m/2];
                y[k]=u+t;
                y[k+m/2]=u-t;
                w=w*wn;
            }
        }
    } 
    if (on==-1) for (i=0;i<l;i++) y[i].r/=l;
}

int main()
{
    int l1,l2,i,l;
    while (scanf("%s %s",a,b)!=EOF)
    {
        l1=strlen(a);
        l2=strlen(b);
        l=1;
        while (l<l1*2 || l<l2*2) l*=2;
        
        for (i=0;i<l1;i++) 
        {
            op1[i].r=a[l1-i-1]-'0';
            op1[i].i=0.0;
        }
        for (;i<l;i++) op1[i].r=op1[i].i=0.0;
        for (i=0;i<l2;i++) 
        {
            op2[i].r=b[l2-i-1]-'0';
            op2[i].i=0.0;
        }
        for (;i<l;i++) op2[i].r=op2[i].i=0.0;
        fft(op1,l,1);
        fft(op2,l,1);
        for (i=0;i<l;i++) op1[i]=op1[i]*op2[i];
        fft(op1,l,-1);
        for (i=0;i<l;i++) sum[i]=op1[i].r+0.5;
        for (i=0;i<l;i++) 
        {
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
        l=l1+l2-1;
        while (sum[l]<=0 && l>0) l--;
        for (i=l;i>=0;i--) printf("%d",sum[i]);
        printf("\n");
    }
    return 0;
}

