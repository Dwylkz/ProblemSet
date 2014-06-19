#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
const int N = 26;

string s;

int main()
{
  cin.sync_with_stdio(0);
  while(getline(cin, s)) {
		int cnt[N] = {0};
		for (auto si: s)
			if (islower(si))
				cnt[si-'a']++;

		cout << count_if(cnt, cnt+N, [&](int x){return x;}) << endl;
  }
  return 0;
}
