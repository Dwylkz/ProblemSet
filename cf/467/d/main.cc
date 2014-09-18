#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 5e5+10;
const int M = 1e5+10;

struct Node {
  int rcount;
  int length;
  Node* group;
  int in;
  int out;
  bool inpath;
  vector<Node*> to;

  bool LesserThan(const Node* rhs)
  {
    if (rcount != rhs->rcount)
      return rcount < rhs->rcount;
    return length < rhs->length;
  }

  void Assign(Node* from)
  {
    rcount = from->rcount;
    length = from->length;
  }
};

typedef long long LL;

Node nodes[N];
Node* top = nodes;
char foo[N];
int m, n;
Node* words[M];

map<string, Node*> ranker;
Node* Hash(char* str)
{
  for (int j = 0; str[j]; j++)
    str[j] = tolower(str[j]);

  if (ranker.find(str) == ranker.end()) {
    top->inpath = false;
    top->in = -1;
    top->group = top;
    top->length = strlen(str);
    top->rcount = count(str, str+top->length, 'r');
    ranker[str] = top++;
  }
  return ranker[str];
}

int stamp = 0;
vector<Node*> path;
void Tarjan(Node* u)
{
  path.push_back(u);
  u->inpath = true;
  u->in = u->out = stamp++;
  for (Node* v: u->to)
    if (v->in == -1) {
      Tarjan(v);
      u->out = min(u->out, v->out);
    }
    else if (v->inpath)
      u->out = min(u->out, v->in);

  if (u->in != u->out)
    return ;

  Node* leader = u;
  do {
    u = path.back();
    u->inpath = false;
    path.pop_back();
    u->group = leader;
    if (u->LesserThan(leader))
      leader->Assign(u);
  } while(u != leader);
}

void Dfs(Node* u)
{
  for (Node* v: u->to) {
    if (v->group == u->group)
      continue;

    Dfs(v);
    if (v->group->LesserThan(u->group))
      u->group->Assign(v->group);
  }
}

int main()
{
  int rank = 0;

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", foo);
    words[i] = Hash(foo);
  }

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", foo);
    Node* u = Hash(foo);
    scanf("%s", foo);
    u->to.push_back(Hash(foo));
  }

  for (Node* i = nodes; i < top; i++)
    if (i->in == -1)
      Tarjan(i);

  for (Node* i = nodes; i < top; i++)
    Dfs(i);

  LL rcount = 0;
  LL length = 0;
  for (int i = 0; i < m; i++) {
    rcount += words[i]->group->rcount;
    length += words[i]->group->length;
  }

  cout << rcount << " " << length << endl;
  return 0;
}
