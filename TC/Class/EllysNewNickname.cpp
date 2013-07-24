#include <string>
#include <vector>
using namespace std;
class EllysNewNickname {
	public:
	int isVowel(char s){
		string vowel = "aeiouy";
		for (int i = 0; i < vowel.length(); i++) {
			if (vowel[i] == s) {
				return 1;
			}
		} 
		return 0;
	}
	int getLength(string nickname) {
		int cnt = 0;
		for (int i = 0; i < nickname.length(); i++) {
			if (isVowel(nickname[i])) {
				for (i++; i < nickname.length() && isVowel(nickname[i]); i++) {
					cnt++;
				}
				i--;
			}
		}	
		return nickname.length() - cnt;
	}
};
