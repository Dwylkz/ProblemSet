#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
#define M 2005
#define inf 1e16
#define eps 1e-8

const double EP = 1E-10 ;
const double PI = 3.14159265;

struct point{
    int i;
	double x;
	double y;
	double angel;
	point(double a=0, double b=0) { x=a; y=b;}
}p[M], ch[M];

struct line{
	point s;
	point e;
	line(point a, point b) { s=a; e=b;}
	line() { }
};

inline double dist(point a,point b)					//返回两点之间欧氏距离
{
	return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

double multiply(point a,point b,point c)				//返回ca叉乘cb
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

double dotmultiply(point a,point b,point c)			//返回ca点乘cb
{
	return (a.x-c.x)*(b.x-c.x)+(a.y-c.y)*(b.y-c.y);
}

double relation(point p,line l)
{
	line tl;
	tl.s=l.s;
	tl.e=p;
	return dotmultiply(tl.e,l.e,l.s)/(dist(l.s,l.e)*dist(l.s,l.e));
}

point perpendicular(point p,line l)		//求点C到线段AB所在直线的垂足P
{
	double r=relation(p,l);
	point tp;
	tp.x=l.s.x+r*(l.e.x-l.s.x);
	tp.y=l.s.y+r*(l.e.y-l.s.y);
	return tp;
}
//求点p到线段l的最短距离,并返回线段上距该点最近的点np
double ptolinedist (point p,line l, point &np)
{	//注意：np是线段l上到点p最近的点，不一定是垂足
	double r=relation(p,l);
	if(r<0)
	{
		np=l.s;
		return dist(p,l.s);
	}
	if(r>1)
	{
		np=l.e;
		return dist(p,l.e);
	}
	np=perpendicular(p,l);
	return dist(p,np);
}

double multi (point a, point b, point c)		//ab叉乘 bc
{
	double x1, y1, x2, y2;
	x1 = b.x - a.x;
	y1 = b.y - a.y;
	x2 = c.x - b.x;
	y2 = c.y - b.y;
	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	return x1*y2 - x2*y1;
}

bool cmp (point a, point b)
{
	if (fabs (a.y-b.y) < eps)
		return a.x < b.x;
	return a.y < b.y;
}

bool cmp2 (point a, point b)
{
	if (fabs (a.angel-b.angel) < eps)
	{
		if (fabs (a.x-b.x) < eps)
			return a.y < b.y;
		return a.x < b.x;
	}
	return a.angel < b.angel;
}

bool has[M];

int main()
{
    #if 1
        freopen("kidx.txt", "rt", stdin);
    #endif
    int t, n, i, j, top;
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &n);
        for (i = 0; i < n; i++)
            scanf ("%lf%lf", &p[i].x, &p[i].y), p[i].i = i;
        sort (p, p+n, cmp);

        for (i = 1; i < n; i++)
            p[i].angel = atan2 (p[i].y-p[0].y, p[i].x-p[0].x);
        sort (p+1, p+n, cmp2);

        //for (i = 0; i < n; i++) cout << p[i].x << " --- " << p[i].y << endl;

        memset (has, false, sizeof(has));
        ch[0] = p[0], ch[1] = p[1], ch[2] = p[2];
        has[ch[0].i] = has[ch[1].i] = has[ch[2].i] = true;
        top = 3;
        for (i = 3; i < n; i++)
        {
            while (top > 2 && multi (ch[top-2], ch[top-1], p[i]) < 0)
                has[ch[top-1].i] = false, top--;
            ch[top++] = p[i];
            has[p[i].i] = true;
        }
        //cout << top << endl;
        ch[top++] = ch[0];
        for (i = 0; i < n; i++)
        {
            if (has[p[i].i]) continue;
            double mins = inf;
            int v;
            for (j = 1; j < top; j++)
            {
                if (fabs (multi (ch[j-1], ch[j], p[i])) < eps) continue;
                point tmp;
                line tl (ch[j-1], ch[j]);
                double tp = ptolinedist (p[i], tl, tmp);
                if (tp < mins) mins = tp, v = j;
            }
            for (j = top - 1; j >= v; j--)
                ch[j+1] = ch[j];
            ch[v] = p[i];
            top++;
        }
        printf ("%d", ch[0].i);
        for (i = 1; i < top-1; i++)
            printf (" %d", ch[i].i);
        printf ("\n");
    }
    return 0;
}
