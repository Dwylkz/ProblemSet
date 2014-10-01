#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 2e5+10;

struct Node {
  vector<Node*> to;
  vector<Node*> rto;

  int color;
  int in;
  int out;
  bool inpath;
  Node* group;

  int indegree;
  int outdegree;

  void Init()
  {
    to.clear();
    rto.clear();

    color = -1;
    in = out = -1;
    inpath = false;
    group = this;

    indegree = outdegree = 0;
  }
};

Node nodes[N];
int n, a, b, p[N];
unordered_map<int, int> rp;

void Add(int u, int v)
{
  nodes[2*u].to.push_back(nodes+2*v);
  nodes[2*u+1].to.push_back(nodes+2*v+1);
}

int Build()
{
  for (int i = 0; i < n; i++) {
    auto pa = rp.find(a-p[i]);
    auto pb = rp.find(b-p[i]);
    if (pa == rp.end() && pb == rp.end())
      return -1;
    if (pa != rp.end())
      Add(i, pa->second);
    if (pb != rp.end())
      Add(i, pb->second);
  }
  return 0;
}

int stamp = 0;
vector<Node*> path;
void Tarjan(Node* u)
{
  u->in = u->out = stamp++;
  u->inpath = true;
  path.push_back(u);
  for (auto& v: u->to)
    if (v->in == -1) {
      Tarjan(v);
      u->out = min(u->out, v->out);
    }
    else if (v->inpath)
      u->out = min(u->out, v->in);

  if (u->in != u->out)
    return ;

  Node* group = u;
  do {
    u = path.back();
    path.pop_back();
    u->inpath = false;
    u->group = group;
  } while (u != group);
}

int Check()
{
  for (int i = 0; i < n; i++)
    if (nodes[2*i].group == nodes[2*i+1].group)
      return -1;
  return 0;
}

void Dfs(Node* u)
{
  u->color = 1;
  nodes[(u-nodes)^1].color = 0;
  for (auto& v: u->rto)
    Dfs(v);
}

void Color()
{
  for (Node* u = nodes; u < nodes+2*n; u++)
    if (u == u->group)
      for (auto& v: u->to)
        v->group->rto.push_back(u->group);

  for (Node* u = nodes; u < nodes+2*n; u++)
    if (u == u->group) {
      sort(u->rto.begin(), u->rto.end());
      u->rto.erase(unique(u->rto.begin(), u->rto.end()), u->rto.end());
    }

  vector<Node*> seq;
  for (Node* u = nodes; u < nodes+2*n; u++)
    if (u == u->group)
      for (auto& v: u->rto) {
        u->outdegree++;
        v->indegree++;
      }

  for (Node* u = nodes; u < nodes+2*n; u++)
    if (u == u->group && u->indegree == 0)
      seq.push_back(u);

  for (auto& u: seq)
    for (auto& v: u->to) {
      v->indegree--;
      if (v->indegree == 0)
        seq.push_back(v);
    }

  for (auto& u: seq)
    if (u->color == -1)
      Dfs(u);
}

int main()
{
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", p+i);
    rp[p[i]] = i;
    nodes[2*i].Init();
    nodes[2*i+1].Init();
  }

  if (Build() != 0) {
    printf("NO");
    return 0;
  }

  for (int i = 0; i < 2*n; i++)
    if (nodes[i].in == -1)
      Tarjan(nodes+i);

  if (Check() != 0) {
    printf("NO");
    return 0;
  }

  Color();
  puts("YES");
  for (int i = 0; i < n; i++)
    printf("%d%c", nodes[2*i].color == 1? 1: 0, i < n-1? ' ': '\n');
  return 0;
}
