#include<bits/stdc++.h>

#define INF 10000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define EPS 1e-9

#define lli long long int

const double pi = acos(-1.0);

using namespace std;

int n, m, k;

struct edge {
  int u, v, w;
  edge() {}
  edge(int a, int b, int c) : u(a), v(b), w(c) {}
  bool operator < (const edge& o) const {
    if (u == o.u)
      if (v == o.v)
        return w < o.w;
      else
        return v < o.v;
    return u < o.u;
  }
};

int dmst(vector<edge>&edges, int root, int n) {
  int ans = 0;
  int total_node = n;

  while (true) {
    vector<int> lo(total_node, INF), pi(total_node, INF);
    int sz = edges.size();
    for (int i = 0; i < sz; ++i) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      if (w < lo[v] && u != v) {
        lo[v] = w;
        pi[v] = u;
      }
    }
    lo[root] = 0;
    sz = lo.size();
    for (int i = 0; i < sz; ++i) {
      if (i == root) continue;
      if (lo[i] == INF) return -1;
    }
    int cur_id = 0;
    vector<int> id(total_node, -1), mark(total_node, -1);
    for (int i = 0; i < total_node; i++) {
      ans += lo[i];
      int u = i;
      while (u != root && id[u] < 0 && mark[u] != i) {
        mark[u] = i;
        u = pi[u];
      }
      if (u != root && id[u] < 0) {
        for (int v = pi[u]; v != u; v = pi[v]) {
          id[v] = cur_id;
        }
        id[u] = cur_id++;
      }
    }
    if (cur_id == 0) break;
    for (int i = 0; i < total_node; i++) {
      if (id[i] < 0) id[i] = cur_id++;
    }
    sz = edges.size();
    for (int i = 0; i < sz; i++) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      edges[i].u = id[u];
      edges[i].v = id[v];
      if (id[u] != id[v]) {
        edges[i].w -= lo[v];
      }
    }
    total_node = cur_id;
    root = id[root];
  }
  return ans;
}

int main(int argc, char const *argv[])
{
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d %d %d", &n, &m, &k);

    int u, v, w;
    edge vr;
    vector<edge> edges;
    for (int j = 1; j <= m; j++) {
      scanf("%d %d %d", &vr.u, &vr.v, &vr.w);
      edges.push_back(vr);
    }
    int ans = dmst(edges, k, n);
    if (ans < 0) {
      printf("Case %d: impossible\n", i);
    }
    else
      printf("Case %d: %d\n", i, ans);
  }

  return 0;
}