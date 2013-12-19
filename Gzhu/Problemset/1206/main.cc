#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n;

bool isPrime(int x) {
  for (int i = 2; 1ll*i*i <= x; i++)
    if (x%i == 0) return 0;
  return 1;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    puts(n > 1 && isPrime(n)? "Yes": "No");
  }
  return 0;
}
