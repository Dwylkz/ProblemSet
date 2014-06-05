#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e7+10;

long long C[N];
long long delta[N];
long long nodd[N];

void Init()
{
  for (int i = 1; i < N; i += 2)
    for (int j = i; j < N; j += i)
      nodd[j]++;

  delta[1] = 0;
  for (int i = 2; i < N; i++)
    delta[i] = delta[i-1]+nodd[i-1];
  for (int i = 1; i < N; i++)
    delta[i]++;

  C[0] = 1;
  for (int i = 1; i < N; i++)
    C[i] = C[i-1]+delta[i];
}

int main()
{
  cin.sync_with_stdio(false);

  Init();
  int T;
  cin >> T;
  for (int kas = 1; kas <= T; kas++) {
    int n;
    cin >> n;
    cout << "Case #" << kas << ":\n" << C[n] << endl;
  }
  return 0;
}
