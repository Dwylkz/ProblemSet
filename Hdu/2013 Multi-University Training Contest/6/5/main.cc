#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
const int maxn = 5e6 + 10;
typedef long long LL;
typedef map<int, char> IC;
typedef IC::iterator ICI;

struct nt {
  IC d;
  int o;
  nt(): o(0) {}
  void set(int x, char f)
  {
    if (f == -1) f = o - 1;
    d[x] = f;
  }
  char get(int x)
  {
    int f = d.find(x) != d.end()? d[x]: 0;
    if (f == 1) return 1;
    else if (f >= o) return 0;
    return -1;
  }
  void show()
  {
    for (ICI i = d.begin(); i != d.end(); i++)
      printf("(%4d, %4d)", i->first, i->second);
    puts("");
  }
};
void nt_cat(nt **lhs, nt **rhs)
{
  if ((*lhs)->d.size() < (*rhs)->d.size()) {
    swap((*lhs), (*rhs));
    for (ICI i = (*rhs)->d.begin(); i != (*rhs)->d.end(); i++) {
      int f = (*lhs)->get(i->first);
      if (f == 1) f = 1;
      else if (i->second < (*rhs)->o) f = -1;
      (*lhs)->set(i->first, f);
    }
  } else {
    for (ICI i = (*rhs)->d.begin(); i != (*rhs)->d.end(); i++) {
      int f = (*lhs)->get(i->first);
      if (!f) {
        if (i->second == 1) f = 1;
        else if (i->second >= (*rhs)->o) f = 0;
        else f = -1;
        (*lhs)->set(i->first, f);
      }
    }
  }
}
void nt_union(nt **lhs, nt **rhs)
{
  if ((*lhs)->d.size() < (*rhs)->d.size()) swap(*lhs, *rhs);
  for (ICI i = (*rhs)->d.begin(); i != (*rhs)->d.end(); i++) {
    int f = (*lhs)->get(i->first);
    if (i->second == 1) (*lhs)->set(i->first, 1);
    else if (i->second >= (*rhs)->o) {
      if (f == -1) (*lhs)->set(i->first, 0);
    } else if (f == -1) (*lhs)->set(i->first, (*lhs)->o-2);
  }
  (*lhs)->o--;
}

// lexer
enum TT {
  END, ELSE, A, NL, U, NUM, IF 
};
const char *TT_N[] = {
  "END", "NL", "A", "U", "IF", "ELSE", "NUM"
};
struct token {
  TT t;
  int d;
  token(TT _t, string &_d)
  {
    t = _t;
    if (t == NUM) {
      d = 0;
      for (int i = 0; i < _d.length(); i++)
        d = d*10 + _d[i]-'0';
    }
#if 0
    this->show();
#endif
  }
  void show() {
    printf("( %10s, %10d )\n", TT_N[t], t == NUM? d: -1);
  }
};
char buf[maxn];
vector<token> tl;
vector<token>::iterator la;
void lexer()
{
  char *i = buf;
  string t;
  for ( ; ~(*i++ = getchar()); );
#if 0
  puts(buf);
#endif
  tl.clear();
  for (i = buf; ~*i; i++)
    if (isspace(*i)) {
      for ( ; isspace(*i); i++)
        if (*i == '\n') tl.push_back(token(NL, t));
      i--;
    } else if (isalpha(*i)) {
      for (t = ""; isalpha(*i); i++) t += *i;
      if (t == "end") tl.push_back(token(END, t));
      if (t == "a") tl.push_back(token(A, t));
      if (t == "u") tl.push_back(token(U, t));
      if (t == "if") tl.push_back(token(IF, t));
      if (t == "else") tl.push_back(token(ELSE, t));
      i--;
    } else if (isdigit(*i)) {
      for (t = ""; isdigit(*i); i++) t += *i;
      tl.push_back(token(NUM, t));
      i--;
    }
  t = "777";
  tl.push_back(token(NUM, t));
#if 0
  for (int i = 0; i < tl.size(); i++) tl[i].show();
#endif
}

const int ___ = -1;
int table[][12] = {
  103 , 103  ,  7   ,  ___ ,  10  , ___ ,  14  , 1   , 2   , 5   , 13  , ___ ,
  ___ ,  ___ ,  ___ ,  ___ ,  ___ , 200 ,  ___ , ___ , ___ , ___ , ___ , ___ ,
   3  ,  ___ ,  ___ ,  ___ ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  4   ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  ___ ,  ___ , 101 ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  103 , 103  ,  7   ,  ___ ,  10  , ___ ,  14  , ___ , 6   , 5   , 13  , ___ ,
  102 , 102  ,  ___ ,  ___ ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  ___ ,  ___ ,  8  ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  9   ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  104 , 104  , 104  ,  ___ , 104  , ___ , 104  , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  ___ ,  ___ ,  11 ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  12  ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  105 , 105  , 105  ,  ___ , 105  , ___ , 105  , ___ , ___ , ___ , ___ , ___ ,
  106 , 106  , 106  ,  ___ , 106  , ___ , 106  , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  15  ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  103 , 103  ,  7   ,  ___ ,  10  , ___ ,  14  , ___ , 16  , 5   , 13  , ___ ,
   19 ,  18  ,  ___ ,  ___ ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , 17  ,
  107 , 107  , 107  ,  ___ , 107  , ___ , 107  , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  20  ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  24  ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  103 , 103  ,  7   ,  ___ ,  10  , ___ ,  14  , ___ , 21  , 5   , 13  , ___ ,
   22 ,  ___ ,  ___ ,  ___ ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  ___ ,  ___ ,  ___ ,  23  ,  ___ , ___ ,  ___ , ___ , ___ , ___ , ___ , ___ ,
  109 , 109  , 109  ,  ___ , 109  , ___ , 109  , ___ , ___ , ___ , ___ , ___ ,
  108 , 108  , 108  ,  ___ , 108  , ___ , 108  , ___ , ___ , ___ , ___ , ___
};
int rl[10] = {
  2,
  3,
  2,
  0,
  3,
  3,
  1,
  4,
  2,
  5
};
int rc[10] = {
  -1,
  0,
  1,
  1,
  2,
  2,
  2,
  3,
  4,
  4,
};
nt *sp[maxn], **v;
void action_init()
{
  v = sp;
}
void action(int id)
{
  switch (id) {
    case 0:
      ++v;
      if (la->t == NUM) {
        *v = new nt();
        (*v)->set(la->d, 0);
#if 0
        printf("get NUM %d\n", (*v)->d.begin()->first);
#endif
      }
      break;
    case 1:
      v -= 2;
      break;
    case 2:
      nt_cat(v-1, v);
      delete *(v--);
      break;
    case 3:
      *(++v) = new nt();
      break;
    case 4:
      (*(v-1))->d.begin()->second = -1;
      *(v-2) = *(v-1);
      v -= 2;
      break;
    case 5:
      (*(v-1))->d.begin()->second = 1;
      *(v-2) = *(v-1);
      v -= 2;
      break;
    case 6:
      break;
    case 7:
      nt_union(v-1, v);
      delete *v;
      *(v-3) = *(v-1);
      v -= 3;
      break;
    case 8:
      *(--v) = new nt();
      break;
    case 9:
      *(v-4) = *(v-2);
      v -= 4;
      break;
    default:
      exit(2);
  }
}
int ss[maxn], *top;
void parser()
{
  for (top = &(*ss = 0); ; ) {
    int mv = table[*top][la->t];
    if (mv == ___) exit(1);
    if (mv == 200) break;
    if (mv < 100) {
      *++top = mv;
      action(0);
      la++;
    } else {
      mv -= 100;
      action(mv);
      mv = table[*(top -= rl[mv])][7+rc[mv]];
      *++top = mv;
    }
  }
#if 0
  puts("yes");
#endif
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  int T, Case = 1;
  scanf("%d\n", &T);
  lexer();
	for (la = tl.begin(); T--; ) {
    int n = la->d;
    la += 2;
#if 0
    printf("case %d\n", Case++);
#endif
    action_init();
    parser();
#if 0
    printf("pass %p %ld\n", sp[1], sp[1]->d.size());
    sp[1]->show();
#endif
    for (int i = 1; i <= n; i++)
      printf("%d%c", sp[1]->get(i), i<n? ' ': '\n');
    delete sp[1];
#if 0
    puts("");
#endif
	}
	return 0;
}
