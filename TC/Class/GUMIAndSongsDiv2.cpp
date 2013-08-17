#include <vector>
#include <algorithm>
using namespace std;
class GUMIAndSongsDiv2 {
public:
	struct song {
		int t, d;
		friend bool operator < (song lhs, song rhs) {
			return lhs.t < rhs.t;
		}
	};
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		int rv = 0;
		vector<int> &d = duration, &t = tone;
		int l = tone.size(), bl = 1<<l;
		for (int i = 0; i < bl; i++) {
			vector<song> s;
      int tt = 0;
			for (int j = 0; j < l; j++) {
				if (i>>j&1) {
					s.push_back((song){t[j], d[j]});
          tt += d[j];
				}
			}
			sort(s.begin(), s.end());
      if (s.size()) tt += s.back().t-s[0].t;
      if (tt <= T) rv = max(rv, (int)s.size());
		}
		return rv;
	}
};
