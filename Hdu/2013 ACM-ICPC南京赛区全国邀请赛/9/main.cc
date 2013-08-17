#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef map<string, string> mss_t;
const int N = 512;

int n;
char b[N], x[N], y[N], z[N], w[N];

void parse() {
  bool msg = 1, end = 0;
  mss_t env;
  for ( ; n--; ) {
    gets(b);
    bool ep = 1;
    for (char *i = b; *i; i++) if (!isspace(*i)) {
      ep = 0;
      break;
    }
    if (end || ep) continue;
    sscanf(b, "%[^ \t=]%s%s%[^\"]", x, y, z, w);
    string lhs = "", mhs = "", rhs = "";
    lhs = strtok(b, " \t=");
    char *i = strtok(0, "\" \t");
    if (i) mhs = i;
    if (i = strtok(0, " \t")) {
      rhs = i;
      if (rhs[0] == '"' && rhs[rhs.length()-1] != '"') rhs = rhs+strtok(0, "\"")+"\"";
    }
#if 1
    printf("psliat = %d get %s %s %s\n", 0, lhs.data(), mhs.data(), rhs.data());
#endif
    if (mhs == "=") {
      if (lhs[0] == '$') env[lhs] = rhs;
      else if (env.find(lhs) != env.end()) {
        if (msg) printf("WARNING: Constant %s Already Defined!\n", lhs.c_str());
      } else env[lhs] = rhs;
    } else if (lhs == "Print") {
      if (env.find(mhs) != env.end()) {
        string &t = env[mhs];
        puts(t.c_str());
      } else {
        if (mhs[0] == '$') {
          puts("NULL");
          if (msg) printf("NOTICE: Undefined Variable %s.\n", mhs.c_str());
        } else {
          puts(mhs.c_str());
          if (msg) printf("NOTICE: Undefined Constant %s.\n", mhs.c_str());
        }
      }
    } else if (lhs == "Dump") {
      if (env.find(mhs) != env.end()) {
        string &t = env[mhs];
        printf("%s: %s\n", t[0] == '"'? "string": "integer", t.c_str());
      } else {
        if (mhs[0] == '$') {
          puts("NULL");
          if (msg) printf("NOTICE: Undefined Variable %s.\n", mhs.c_str());
        } else {
          printf("string: \"%s\"\n", mhs.c_str());
          if (msg) printf("NOTICE: Undefined Constant %s.\n", mhs.c_str());
        }
      }
    } else if (lhs == "Errmsg") {
      if (mhs == "ON") msg = 1;
      else msg = 0;
    } else if (lhs == "Panic") {
      puts("Script was KILLED.");
      end = 1;
    }
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T, f = 0;
  scanf("%d", &T);
  for ( ; T--; ) {
    if (f) puts("");
    f = 1;
    scanf("%d", &n);
    gets(b);
    parse();
  }
  return 0;
}
