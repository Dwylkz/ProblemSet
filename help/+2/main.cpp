#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

typedef long long LL;
LL f[6+5];
LL x, y, n;


int main()
{
  while (~scanf("%lld%lld%lld", &x, &y, &n)) {
    LL MOD = 1e9+7;
    f[1] = x;
    f[2] = y;
    f[3] = y-x;
    f[4] = -x;
    f[5] = -y;
    f[6] = x-y;
    n %= 6;
    if (n == 0) {
      while (f[6] < 0)
        f[6] += MOD;
      printf("%lld\n", f[6]%MOD);
    }
    else {
      while (f[n] < 0)
        f[n] += MOD;
      printf("%lld\n", f[n]%MOD);
    }
  }
  return 0;
}

/*
const int MAXN = 100000 + 10;
char a[MAXN], b[MAXN];
bool asign, bsign;
int len1, len2;
void as(){
	int i;
	if (a[0] == '-' || a[0] == '+') {
		if (a[0] == '-') asign = false;
		else asign = true;
		for (i = 0; i < len1-1; i++) a[i] = a[i+1];
		a[i] = 0;
	}
	if (a[0] == '.') {
		for (i = len1; i >= 1; i--) a[i] = a[i-1];
		a[i] = '0';
	}
	if (isdigit(a[0])) asign = true;
}
void bs(){
	int i;
	if (b[0] == '-' || b[0] == '+') {
		if (b[0] == '-') bsign = false;
		else bsign = true;
		for (i = 0; i < len2-1; i++) b[i] = b[i+1];
		b[i] = 0;
	}
	if (b[0] == '.') {
		for (i = len2; i >= 1; i--) b[i] = b[i-1];
		b[i] = '0';
	}
	if (isdigit(b[0])) bsign = true;
}
void a_beforzero(){
	int i = 0, j, pos;
	while (a[i] == '0') i++;
	pos = i;
	j = 0;
	if (!isdigit(a[i])) {
		a[j++] = '0';
		for ( ;
				pos < len1;
				pos++) a[j++] = a[pos];
	}
	else {
		while (pos < len1) a[j++] = a[pos++];
	}
	a[j] = 0;
}
void b_beforzero(){
	int i = 0, j, pos;
	while (b[i] == '0') i++;
	pos = i;
	j = 0;
	if (!isdigit(b[i])) {
		b[j++] = '0';
		for ( ;
				pos < len2;
				pos++) b[j++] = b[pos];
	}
	else {
		while (pos < len1) b[j++] = b[pos++];
	}
	b[j] = 0;
}
void a_backzero(){
	int i, j;
	for (i = 0; i < len1; i++) {
		if (a[i] == '.') {
			j = len1;
			while (a[j-1] == '0') j--;
			break;
		}
	}
}
void b_backzero(){
	int i, j;
	for (i = 0; i < len2; i++) {
		if (b[i] == '.') {
			j = len2;
			while (b[j-1] == '0') j--;
			break;
		}
	}
}
int main(){
	while (scanf("%s%s", a, b) != EOF) {
		len1 = strlen(a);
		len2 = strlen(b);
		as();
		bs();
		a_beforzero();
		b_beforzero();
		a_backzero();
		b_backzero();
		if (asign == bsign && strcmp(a, b) == 0) printf("YES\n");
		else printf("NO\n");
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	return 0;
}
*/
