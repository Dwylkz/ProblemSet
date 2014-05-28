#include <cstdio>
#include <cstring>
const int MAXN = 1 << 17;
typedef int AI[MAXN];
//Global
int s, b;
//BIA
AI d, kd;
void Init(){
	memset(d, 0, sizeof d);
	memset(kd, 0, sizeof kd);
}
void Draw(int _d, int l, int r, int _kd = 0){
	for (_kd = _d * l++; l < MAXN; l += -l & l) d[l] += _d, kd[l] += _kd;
	for (_kd = _d * (++r), r++; r < MAXN; r += -r & r) d[r] -= _d, kd[r] -= _kd;
}
int Ask(int l, int r, int res = 0, int k = 0){
	for (k = l; l; l -= -l & l) res -= k * d[l] - kd[l];
	for (k = ++r; r; r -= -r & r) res += k * d[r] - kd[r];
	return res;
}
//Find Kth
int Kth(int k, int l, int r){
	while (l < r){
		int m = (l + r) >> 1, s = Ask(l, m);
		if (k <= s) r = m;
		else k -= s, l = m + 1;
	}
	return l;
}
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	while (scanf("%d%d", &s, &b), s || b){
		Init();
		Draw(1, 0, s + 1);
		while (b--){
			int x, y;
			scanf("%d%d", &x, &y);
			Draw(-1, x, y);
			x = Kth(Ask(0, x - 1), 0, x - 1),
			y = Kth(1, y + 1, s + 1);
			printf(x < 1? "* ": "%d ", x);
			printf(y > s? "*\n": "%d\n", y);
		}
		puts("-");
	}
	return 0;
}
