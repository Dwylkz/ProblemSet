#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

namespace algo
{

namespace string
{

void MakeKmp(const char* s, const int n, int p[])
{
  int i = 1;
  int j = -1;
  p[0] = j;
  while (i < n)
  {
    if (s[i] == s[j+1])
    {
      p[i] = j+1;
      i++;
      j++;
    }
    else if (j == -1)
    {
      p[i] = j;
      i++;
    }
    else
    {
      j = p[j];
    }
  }
}

void MakeKmpTest()
{
  puts("\n***** KMP *****");
  
  const char pat[] = "aabbcaabba";
  int p[sizeof(pat)/sizeof(char)];
  int npat = strlen(pat);
  MakeKmp(pat, npat, p);
  printf("pat=(%s)\n", pat);
  for (int i = 0; i < npat; i++)
  {
    printf("%d%c", p[i], i < npat-1? ' ': '\n');
  }

  const char str[] = "aabbcaabbaaabbcaabcbaaabbcaabba";
  int nstr = strlen(str);
  printf("str=(%s)\n", str);
  int i = 0;
  int j = -1;
  while (i < nstr)
  {
    if (str[i] == pat[j+1])
    {
      i++;
      j++;
      if (j+1 == npat)
      {
        j = p[j];
        printf("match: last=%d, suffix=(%s)\n", i, str+(i-npat));
      }
    }
    else if (j == -1)
    {
      i++;
    }
    else
    {
      j = p[j];
    }
  }
}

struct AcA
{
  struct Node
  {
    map<int, Node*> succ;
    Node* fail;
    int len;
    int ac;

    Node* Init()
    {
      succ.clear();
      fail = NULL;
      len = 0;
      ac = 0;
      return this;
    }
  };

  Node pool[2<<15];
  Node* top;
  Node* root;

  void Init()
  {
    top = pool;
    root = top->Init();
    top++;
  }

  void Add(const char s[])
  {
    Node* x = root;
    for (int i = 0; s[i]; i++)
    {
      char c = s[i];
      if (!x->succ.count(c))
      {
        x->succ[c] = top->Init();
        top++;
      }
      x = x->succ[c];
    }
    x->len = strlen(s);
    x->ac = 1;
    printf("suck: str=(%s) size=%ld\n", s, top-pool);
  }

  void Make()
  {
    vector<Node*> q;
    root->fail = NULL;
    for (auto& p: root->succ)
    {
      q.push_back(p.second);
      q.back()->fail = root;
    }
    for (int i = 0; i < q.size(); i++)
    {
      Node* u = q[i];
      for (auto& p: u->succ)
      {
        char c = p.first;
        Node* v = p.second;
        Node* fail = u->fail;
        while (fail != NULL && !fail->succ.count(c))
        {
          fail = fail->fail;
        }
        if (fail == NULL) 
        {
          v->fail = root;
        }
        else
        {
          v->fail = fail->succ[c];
          v->ac += v->fail->ac;
          v->len = max(v->fail->len, v->len);
        }
        q.push_back(v);
      }
    }
  }

  void Match(const char s[])
  {
    Node* x = root;
    for (int i = 0; s[i]; i++)
    {
      char c = s[i];
      while (x != NULL && !x->succ.count(c))
      {
        x = x->fail;
      }
      if (x == NULL)
      {
        x = root;
      }
      else
      {
        x = x->succ[c];
        if (x->ac > 0)
        {
          printf("match: ac=%d pos=%d len=%d from=(%s)\n", x->ac, i, x->len,  s+(i+1-x->len));
        }
      }
    }
  }
};

void MakeAcATest()
{
  puts("\n***** Ac Automaton *****");
  const char* pats[] = {
    "ab",
    "bc",
    "abcbc",
    "cd;//,",
    "cdjkcjdk",
    NULL
  };
  const char* str = "abcd;//,cdjabcbcdjkcjdkkcjdkcdjkcjdkcd;//,";
  AcA aca;
  aca.Init();
  for (int i = 0; pats[i]; i++)
  {
    aca.Add(pats[i]);
  }
  aca.Make();
  printf("str=(%s)\n", str);
  aca.Match(str);
}

void Manacher(const char s[], const int& n, int p[])
{
  int mi = 0;
  int ml = 1;
  p[mi] = ml;
  for (int i = 1; i < n; i++)
  {
    int& l = p[i];
    if (mi+ml > i)
    {
      l = min(p[mi-(i-mi)], mi+ml-i);
    }
    else
    {
      l = 1;
    }
    while (i-l >= 0 && i+l < n && s[i-l] == s[i+l])
    {
      l++;
    }
    if (l > ml)
    {
      ml = l;
      mi = i;
    }
  }
}

void ManacherTest()
{
  puts("\n***** ManacherTest *****");
  const char str[] = "#a#b#a#b#a#b#a#b#a#;#a#";
  int p[sizeof(str)/sizeof(char)];
  Manacher(str, strlen(str), p);
  printf("str=(%s)\n", str);
  for (int i = 0; str[i]; i++) printf("%d%c", p[i], str[i+1]? ' ': '\n');
}

void MakeSA(const char s[], int n, int p[])
{
  struct Aux
  {
    void Sort(int *s, int *k, int n, int m, int* r)
    {
    }

    void Core(int *s, int n, int* p, int* id)
    {
      int sigma = max_element(s, s+n);
      for (int i = 0; i < n; i++) p[i] = i;
      Sort(p, s, n, sigma, id);
      for (int l = 1; l < n; l <<= 1)
      {
      }
    }
  };
}

void Kasai(const char s[], int p[], int n, int h[])
{
}

void SuffixArrayTest()
{
  puts("\n***** SuffixArray *****");
}

int MinimumNotaion(const char s[], const int& n)
{
  int i = 0;
  int j = 1;
  int l = 0;
  while (l < n)
  {
    int ti = (i+l)%n;
    int tj = (j+l)%n;
    if (s[ti] == s[tj])
    {
      l++;
    }
    else if (s[ti] > s[tj])
    {
      i = (ti+1)%n;
      l = 0;
    } 
    else
    {
      j = (tj+1)%n;
      l = 0;
    }
    if (i == j) j = (j+1)%n;
  }
  return i;
}

void MinimumNotaionTest()
{
  puts("\n***** MinimumNotaion *****");
  const char str[] = "babbababba";
  const int n = strlen(str);
  printf("str=(%s)\n", str);
  int pos = MinimumNotaion(str, n);
  printf("pos=%d\n", pos);
  for (int i = 0; i < n; i++) putchar(str[(i+pos)%n]);
  puts("");
}

void Test()
{
  puts("\n----- string begin -----");
  MakeKmpTest();
  MakeAcATest();
  ManacherTest();
  SuffixArrayTest();
  MinimumNotaionTest();
}

} /* string */

void Test()
{
  string::Test();
}

} /* algo */

int main(int argc, char** argv)
{
  algo::Test();
  return 0;
}
