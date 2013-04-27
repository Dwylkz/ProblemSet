#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;
class EllysRoomAssignmentsDiv2 {
	public:
	static const int maxn = 1200;
	double getProbability(vector <string> ratings) {
		int hash[maxn], N = 0, elly, highest = 0;
		memset(hash, 0, sizeof(hash));
		string s = "";

		for (int i = 0; i < ratings.size(); i++) {
			s += ratings[i];
		}
		for (int j = 0; j < s.length(); j++) {
			if (isdigit(s[j])) {
				int r = 0;
				for ( ; j < s.length() &&
						isdigit(s[j]); j++) {
					r = r * 10 + s[j] - '0';
				}
				j--;
				highest = max(highest, r);
				if (!N) {
					elly = r;
				}
				if (!hash[r]) {
					printf(" %d", r);
					hash[r] = 1;
					N++;
				}
			}
		}
		puts("");
		for (int i = 1; i < maxn; i++) {
			if (hash[i]) {
	//			printf(" %d", i);
			}
			hash[i] += hash[i - 1];
		}
		puts("");
		int R = N / 20 + (N % 20);
		printf("elly = %d, highest = %d ,R = %d, N = %d\n",
				elly, highest, R, N);
		double res = 0.0;
		if (elly == highest) {
			res = 1.0;
		} else {
			if (R < hash[highest] - hash[elly - 1]) {
				res = 1.0 / (1.0 * R);
			}
		}
		return res;
	}
};
