#include <cstdio>
#include <cstring>
const int MAXN = 1e5 + 5;
typedef long long LL;
typedef LL ALL[MAXN];
//Global
int b, p, l, n;
ALL t, B, N, F;
//QuickPowerMod
LL QPM(LL a, LL p, LL m){
	LL t = a;
	for (a = 1; p; t = t * t % m, p >>= 1)
		if (p & 1) a = a * t % m;
	return a;
}
//BIA
void Add(LL k, int x){
	for (; x <= l; x += -x & x) t[x] = (t[x] + k) % p;
}
LL Sum(int x, int y){
	LL l = 0, r = 0;
	for (x--; x; x -= -x & x) l = (l + t[x]) % p;
	for (; y; y -= -y & y) r = (r + t[y]) % p;
	return (r - l + p) % p;
}
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
#endif
	while (scanf("%d%d%d%d", &b, &p, &l, &n), b || p || l || n){
		memset(t, 0, sizeof t);
		memset(F, 0, sizeof F);
		B[0] = 1;
		for (int i = 1; i < l; i++) B[i] = (b * B[i - 1]) % p;
		while (n--){
			char op[2];
			int x, y;
			scanf("%1s%d%d", op, &x, &y);
			if (op[0] == 'E'){
				Add(B[l - x] * (y - F[x] + p) % p, x);
				F[x] = y;
			}
			else printf("%lld\n", Sum(x, y) * QPM(B[l - y], p - 2, p) % p);
		}
		puts("-");
	}
	return 0;
}
