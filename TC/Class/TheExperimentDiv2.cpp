#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 55;
class TheExperimentDiv2 {
	public:
	vector <int> determineHumidity(vector <int> intensity, int L,
			vector <int> leftEnd) {
		bool vis[maxn];
		vector<int> res(leftEnd.size());
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < leftEnd.size(); i++) {
			res[i] = 0;
			for (int j = 0; j < intensity.size(); j++) {
				if (vis[j]) {
					continue;
				}
				double id = 0.5 + j;
				if (leftEnd[i] <= id && id <= leftEnd[i] + L) {
					res[i] += intensity[j];
					vis[j] = 1;
				}
			}
		}
		return res;
	}
};
