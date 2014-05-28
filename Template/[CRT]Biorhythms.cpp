#include <iostream>
#include <vector>
using namespace std;

vector<int> A, N;
int gcd(int a, int b, int &x, int &y) {
	int d, tx, ty;
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	d = gcd(b, a%b, tx, ty);
	x = ty;
	y = tx-(a/b)*ty;
	return d;
}
int mle(int a, int b, int n) {
	int d, x, y;
	d = gcd(a, n, x, y);
	if (b%d == 0) {
		x = x*b/d%n;
		return x;
	}
	return 0;
}
int crt() {
	int x = 0, n = 1, i, bi;
	for (i = 0; i < N.size(); i++) n *= N[i];
	for (i = 0; i < A.size(); i++) {
		bi = MLE(n / N[i], 1, N[i]);
		x = (x+A[i]*bi*(n/N[i]))%n;
	}
	return x;
}

int Solve(int p, int e, int i, int d)
{
	int ans, add = 23 * 28 * 33;
	A.clear();
	A.push_back(p % 23);
	A.push_back(e % 28);
	A.push_back(i % 33);
	ans = CRT();
	while (ans <= d) ans += add;
	return ans - d;
}

int main()
{
	int C, p, e, i, d, ans;

	N.clear();
	N.push_back(23);
	N.push_back(28);
	N.push_back(33);
	scanf("%d", &C);
	while (1)
	{
		scanf("%d%d%d%d", &p, &e, &i, &d);
		if (p == -1 && e == -1 && i == -1 && d == -1)
			break;
		ans = Solve(p, e, i, d);
		printf("Case %d: the next triple peak occurs in %d days.\n", C++, ans);
	}

	return 0;
}
