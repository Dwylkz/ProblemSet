#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000000 + 10;
#define ls (rt<<1)
#define rs ((rt<<1)|1)
#define mid ((l+r)>>1)


int nn[4][MAXN*4];  
int t[4][MAXN*4];

void Build(int rt, int l, int r, int x) {
	nn[x][rt] = 0;
	t[x][rt] = 3;
	if(l == r) return ;
	Build(ls, l, mid, x);
	Build(rs, mid + 1, r, x);
}

void PushDown(int rt, int l, int r, int x) {
	if(l == r) return ;
	if(t[x][rt] != 3) {
		if(t[x][rt] == 0) {
			nn[x][ls] = nn[x][rs] = 0;
		}
		else if(t[x][rt] == 1) {
			nn[x][ls] = mid - l + 1;
			nn[x][rs] = r - mid;
		}
		else {
			nn[x][ls] = mid - l + 1 - nn[x][ls];
			nn[x][rs] = r - mid - nn[x][rs];
		}
		t[x][ls] = t[x][rs] = t[x][rt];
	}
}

void PushUp(int rt, int l, int r, int x) {
	if(l == r) return ;
	if(t[x][ls] == t[x][rs] && t[x][ls] != 3) {
		if(t[x][ls] == 0) {
			nn[x][rt] = 0;
		}
		else if(t[x][ls] == 1) {
			nn[x][rt] = r - l + 1;
		}
		else if(t[x][ls] == 2) {
			nn[x][rt] = r - l + 1 - nn[x][rt];
		}
		t[x][rt] = t[x][ls];
	}
	else nn[x][rt] = nn[x][ls] + nn[x][rs], t[x][rt] = 3;
}


int Query(int rt, int l, int r, int L, int R, int x) {
	PushDown(rt, l, r, x);
	if(l == L && r== R) return nn[x][rt];
	if(R <= mid) return Query(ls, l, mid, L, R, x);
	else if(L > mid) return Query(rs, mid + 1, r, L, R, x);
	else {
		return Query(ls, l, mid, L, mid, x) + Query(rs, mid + 1, r, mid + 1, R, x);
	}
	PushUp(rt, l, r, x);
}

void Update(int rt, int l, int r, int L, int R, int x, int k) {
	PushDown(rt, l, r, x);
	if(l == L && r == R) {
		t[x][rt] = k;
		if(k == 1) {
			nn[x][rt] = r - l + 1;
		}
		else if(k == 0) {
			nn[x][rt] = 0;
		}
		else if(k == 2) {
			nn[x][rt] = r - l + 1 - nn[x][rt];
		}
		return ;
	}
	if(R <= mid) Update(ls, l, mid, L, R, x, k);
	else if(L > mid) Update(rs, mid + 1, r, L, R, x, k);
	else {
		Update(ls, l, mid, L, mid, x, k);
		Update(rs, mid + 1, r, mid + 1, R, x, k);
	}
	PushUp(rt, l, r, x);
}

int two[5] = {1, 2, 4, 8, 16};

int main() {
	freopen("input.in", "r", stdin);
	int nCase, n, m, a, b, c, i, tmp, j;
	int res;
	char str[100];
	scanf("%d", &nCase);
	while(nCase--) {
		scanf("%d%d", &n, &m);
		for( j=0; j<4; j++ ) Build(1, 1, n, j);
		for( i=1; i<=n; i++ ) {
			scanf("%d", &tmp);
			for( j=0; j<4; j++ ) {
				if(tmp & two[j]) Update(1, 1, n, i, i, j, 1);
			}
		}
		while(m--) {
			//printf("---\n");
			scanf("%s", str);
			if(str[0] == 'S') {
				scanf("%d%d", &a, &b);
				a++, b++;
				res = 0;
				for( j=0; j<4; j++ ) res += Query(1, 1, n, a, b, j) * two[j];
				printf("%d\n", res);
			}
			else if(str[0] == 'X') {
				scanf("%d%d%d", &c, &a, &b);
				a++, b++;
				for( j=0; j<4; j++ ) if(c & two[j]) Update(1, 1, n, a, b, j, 2);
			}
			else if(str[0] == 'O') {
				scanf("%d%d%d", &c, &a, &b);
				a++, b++;
				for( j=0; j<4; j++ ) if(c & two[j]) Update(1, 1, n, a, b, j, 1);
			}
			else {
				scanf("%d%d%d", &c, &a, &b);
				a++, b++;
				for( j=0; j<4; j++ ) 
					if((c & two[j]) == 0) Update(1, 1, n, a, b, j, 0);
			}
#if 1
			printf("After %3s A = [ ", str);
			for (int i = 1; i <= n; i++) {
				int res = 0;
				for( j=0; j<4; j++ ) res += Query(1, 1, n, i, i, j) * two[j];
				printf(" %3d", res);
			}
			puts("]");
#endif
		}
#if 1
		puts("");
#endif
	}
	return 0;
}

