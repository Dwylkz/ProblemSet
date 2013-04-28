#include <cstdio>
#include <cctype>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 55;
typedef unsigned char UC;
typedef unsigned int UI;
typedef long long LL;
char s[maxn], p[256], b[maxn];
int binOp(char op, LL op1, LL op2, LL &res) {
	if (op == '+') {
		res = op1 + op2;
	} else if (op == '-'){
		res = op1 - op2;
	} else if (op == '*') {
		res = op1 * op2;
	} else {
		if (op2 == 0) {
			return 0;
		}
		res = op1 / op2;
	}
	return 1;
}
void toBolan(char *s, char *t) {
	stack<char> S;
	for ( ; *s; s++) {
		if (*s == ' ') {
			continue;
		}
		if (isdigit(*s)) {
			*(t++) = *s;
		} else {
			*(t++) = ' ';
			for ( ; !S.empty() && p[*s] <= p[S.top()]; S.pop()) {
				*(t++) = S.top();
			}
			S.push(*s);
		}
	}
	for ( ; !S.empty(); S.pop()) {
		*(t++) = S.top();
	}
	*t = 0;
}
int calc(char *s, LL &res) {
	vector<LL> S;
	for ( ; *s; s++) {
		if (*s == ' ') {
			continue;
		}
		if (isdigit(*s)) {
			LL op = 0;
			for ( ; *s && isdigit(*s); s++) {
				op = op * 10 + *s - '0';
			}
			s--;
			S.push_back(op);
#if 0
			printf("op = %lld\n", op);
#endif
		} else {
			LL tr;
			if (S.size() < 2 || !binOp(*s, S[S.size() - 2], S.back(), tr)) {
#if 0
				printf("%lld %c %lld = %lld\n", S[S.size() - 2], *s, S.back(), tr);
#endif
				return 0;
			}
			S.pop_back();
			S.back() = tr;
		}
	}
	res = S.back();
	return S.size() == 1;
}
int main() {
#if 1
	freopen("input.txt", "rt", stdin);
#endif
	p['*'] = p['/'] = 1;
	p['+'] = p['-'] = 0;
	while (~scanf("%s", &s)) {
		toBolan(s, b);
#if 0
		printf("%s -> %s\n", s, b);
#endif
		LL res;
		if (!calc(b, res)) {
			puts("impossible");
			continue;
		}
		printf("%lld\n", res);
	}
}
