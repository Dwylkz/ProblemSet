#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

double GetPx()
{
	static char buf[BUFSIZ];
	scanf("%s", buf);
	static char a[BUFSIZ], b[BUFSIZ];
	sscanf(buf, "%[0-9.]%s", a, b);
	double c = atof(a);
	string d = b;
	if (d == "m") {
		c *= 1e3;
	}
	else if (d == "dm") {
		c *= 1e2;
	}
	else if (d == "cm") {
		c *= 1e1;
	}
	else if (d == "mm") {
		c *= 1.0;
	}
	else if (d == "um") {
		c *= 1e-3;
	}
	else if (d == "nm") {
		c *= 1e-6;
	}
	return c;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
		double a = GetPx();
		double b = GetPx();
		double c = GetPx();
		printf("Case %d: %.2fpx\n", cas, c*a/b);
  }
  return 0;
}
