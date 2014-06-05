//Kimady::S.X.Dwylkz
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
//Namespace
namespace dtd{
	//Constant
	const long long INFLL = ~0uLL>>1;
	const int INFI = ~0u>>1;
	const int MAXN = 100;
	const int MAXM = 100;
	const int MOD = 1e4+7;
	//Type Definition
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef AI AI2[MAXM];
	typedef AB AB2[MAXM];
	typedef AD AD2[MAXM];
	typedef ALL ALL2[MAXM];
	typedef ALD ALD2[MAXM];
}
using namespace std;
using namespace dtd;
//Macro
#define Bug puts("Here")

//Module_Group
//usage: MG<long long prim_>
template<long long m> struct MG {
	typedef long long LL;
	LL x;
	//constructor
	//usage: MG(long long vaule)
	MG(LL _x = 0): x(_x % m) {
	}
	friend MG operator + (MG p, MG q) {
		return (p.x + q.x) % m;
	}
	friend MG operator - (MG p, MG q) {
		return MG((p.x + q.x + m) % m);
	}
	friend MG operator * (MG p, MG q) {
		return MG((p.x * q.x) % m);
	}
	friend MG operator / (MG p, MG q) {
		MG a(1);
		LL b = m - 2;
		for (; b; b >>= 1) {
			if (b & 1) {
				a = a * q;
			}
			q = q * q;
		}
		return p * a;
	}
};
//MOP
template<class T> struct MOP{
	typedef vector<T> VK;
	typedef vector<VK> MT;
	int n, m;
	MT M;
	//this[row]
	//return row-r
	VK & operator [] (int r) {
		return M[r];
	}
	//this.mul(value, row);
	//rth-row multiply k
	VK & mul(T k, int r) {
		for (int i = 0; i < m; i++) {
			M[r][i] *= k;
		}
		return M[r];
	}
	//MOP(row, column, init_value, init_array);
	//construct a Matrix with n row, m columns
	//if it has no init_array,
	//there would be a diagonal-Matrix with init_value
	MOP(int _n, int _m, T k = T(0), T **a = 0): n(_n), m(_m) {
		M.resize(n);
		for (int i = 0; i < n; i++) {
			M[i].resize(m);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a) {
					M[i][j] = *((T*)a + i * m + j);
				} else {
					M[i][j] = T(i == j) * k;
				}
			}
		}
	}
	//this.rsw(ith-row, jth-row);
	//swap row i and row j
	MOP & rsw(int i, int j) {
		swap(M[i], M[j]);
		return *this;
	}
	//this.rad(pth-row, qth-row)
	//qth-row add pth-row
	MOP & rad(int p, int q) {
		for (int i = 0; i < m; i++) {
			M[p][i] += M[q][i];
		}
		return *this;
	}
	//this.oup()
	//display the Matrix
	MOP & oup() {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				printf(" %lld", M[i][j]);
			}
			puts("");
		}
		puts("");
		return *this;
	}
	//this Matrix multiply k
	MOP & operator *= (T k) {
		for (int r = 0; r < n; r++) {
			mul(r, k);
		}
		return *this;
	}
	//p add q
	friend MOP operator + (MOP p, MOP q) {
		if (p.n != q.n || p.m != q.m){
			puts("Invaild Add!\n");
			return MOP(0, 0);
		}
		MOP r(p.n, q.m);
		for (int i = 0; i < p.n; i++) {
			for (int j = 0; j < q.m; j++) {
				r[i][j] = p[i][j] + q[i][j];
			}
		}
		return r;
	}
	//p multiply q
	friend MOP operator * (MOP p, MOP q) {
		if (p.m != q.n){
			puts("Invaild Mul!\n");
			return MOP(0, 0);
		}
		MOP r(p.n, q.m);
		for (int i = 0; i < p.n; i++) {
			for (int j = 0; j < q.m; j++) {
				for (int k = 0; k < p.m; k++) {
					r[i][j] = r[i][j] + p[i][k] * q[k][j];
				}
			}
		}
		return r;
	}
};

//Global
typedef MG<MOD> mod_int;
typedef MOP<mod_int> Matrix;
int n;

/*
void mul(int a[4][4], int b[4][4], int c[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				c[i][j] += a[i][k] * b[k][j] % MOD;
				c[i][j] %= MOD;
			}
		}
	}
}

int qmod(int R[2][4][4], int p)
{
	int X[2][4][4] = {
		1, 0, 0, 0,
		0, 1, 1, 0,
		0, 0, 0, 1,
		1, 2, 1, 1
	};
	int rx = 0, rr = 0;
	while (p) {
		if (p & 1) {
			mul(X[rx], R[rr], R[rr ^ 1]);
			rr ^= 1;
		}
		mul(X[rx], X[rx], X[rx ^ 1]);
		rx ^= 1;
		p >>= 1;
	}
	return rr;
}
*/

Matrix qmod(Matrix a, LL p)
{
	Matrix r(a.n, a.m, 1);
	for (; p; p >>= 1) {
		if (p & 1) {
			r = a * r;
		}
#if 0
		puts("a = ");
		(a*a).oup();
		puts("r = ");
		r.oup();
#endif
		a = a * a;
	}
	return r;
}



//Main
int main()
{
#if 0
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		if (n == 1) {
			puts("1");
		} else if (n == 2) {
			puts("2");
		} else {
			mod_int A[4][1] = {
				2,
				0,
				1,
				2,
			};
			mod_int X[4][4] = {
				1, 0, 0, 0,
				0, 1, 1, 0,
				0, 0, 0, 1,
				1, 2, 1, 1
			};
#if 0
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					//printf("(%10d %10d)", &X[i][j], ((mod_int*)X + i * 4 + j));
					printf("%10lld", *((mod_int*)X + i * 4 + j));
				}
				puts("");
			}
			Matrix(4, 4, 0, (mod_int**)X).oup();
			Matrix(4, 1, 0, (mod_int**)A).oup();
#endif
			//int rx = qmod(X, n - 2);
			//mul(X[rx], A[0], A[1]);
			Matrix R = qmod(Matrix(4, 4, 0, (mod_int**)X), n - 2),
				   B = R * Matrix(4, 1, 0, (mod_int**)A);
#if 0
			mod_int a1(3), a2(2), a3(4);
			printf("%lld + %lld * %lld = %lld\n", a1, a2, a3, a1 + a2 * a3);
			R.oup();
			B.oup();
#endif
			printf("%lld\n", B[3][0]);
		}
	}
	return 0;
}
