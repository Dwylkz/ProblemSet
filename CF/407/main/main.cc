#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int N = 15e2+10;

bool look(int a, int b, int &ax, int &ay, int &bx, int &by) {
	for (int x = -N; x < N; x++)
		for (int y = -N; y < N; y++)
			if (x*x+y*y == a*a+b*b) { 
				for (int w = -N; w < N; w++)
					for (int z = -N; z < N; z++)
						if (w*w+z*z == a*a
								&& (z-y)*(z-y)+(w-x)*(w-x) == b*b
								&& x && y && w && z) {
							ax = x;
							ay = y;
							bx = w;
							by = z;
							return true;
						}
			}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
	int a, b;
  for ( ; ~scanf("%d%d", &a, &b); ) {
		int ax, ay, bx, by;
		if (look(a, b, ax, ay, bx, by)) {
			printf("YES\n%d %d\n%d %d\n%d %d\n",
					0, 0,
					ax, ay,
					bx, by);
		} else puts("NO");
  }
  return 0;
}
