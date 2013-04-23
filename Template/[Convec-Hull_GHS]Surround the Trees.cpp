#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAXI 111

class point
{
public :
	double x, y;

	point(double tx = 0.0, double ty = 0.0)
	{
		x = tx;
		y = ty;
	}

	double dis() 
	{ 
		return sqrt(pow(x, 2) + pow(y, 2)); 
	};

	point operator - (point &o)
	{
		return point(x - o.x, y - o.y);
	}

	double operator * (point &o) 
	{
		return x * o.y - y * o.x;
	}
}ps[MAXI];

vector<point> chul;
int n;

bool cmp(point &a, point &b)
{
	double cp = (ps[0] - a) * (b - a);

	if (cp == 0) return (a - ps[0]).dis() > (b - ps[0]).dis();
	else  if (cp < 0)  return 1;
	return 0;
}

double GHS()
{
	int i, idm;
	double tsu = 0.0;

	for (idm = i = 0; i < n; i++)
		if (ps[i].y == ps[idm].y && ps[i].x < ps[idm].x || ps[i].y < ps[idm].y)
			idm = i;
	swap(ps[idm], ps[0]);
	sort(ps + 1, ps + n, cmp);
	chul.clear();
	chul.push_back(ps[0]);
	chul.push_back(ps[1]);
	for (i = 2; (ps[0] - ps[1]) * (ps[i] - ps[1]) == 0; i++);
	chul.push_back(ps[i]);
	for (i++; i < n; i++)
	{
		while ((chul[chul.size() - 2] - chul[chul.size() - 1]) * (ps[i] - chul[chul.size() - 1]) >= 0)
			chul.pop_back();
		chul.push_back(ps[i]);
	}
	for (i = 0; i < chul.size(); i++)
		tsu += (chul[(i + 1) % chul.size()] - chul[i]).dis(); 

	return tsu;
}

int main()
{
	int i;

	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
		if (n == 2) printf("%.2lf\n", ps[1] - ps[0]);
		else if (n ==  1) printf("0\n");
		else printf("%.2lf\n", GHS());
	}

	return 0;
}