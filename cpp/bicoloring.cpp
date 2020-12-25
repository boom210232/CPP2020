#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

int n, m;
bool bipartite = true;
vector<int> adj[MAX_N];
int deg[MAX_N];

bool visited[MAX_N];
int color[MAX_N];

void read_input()
{
  cin >> n;
  if (n==0) return;
  cin >> m;
  bipartite = true;
  for(int i=0; i<n; i++) {
    deg[i] = 0;
    color[i] = 0;
  }
  for(int i=0; i<m; i++) {
    int u,v;
    scanf("%d %d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

void init()
{
    for(int i=0; i<n; i++) 
    {
        adj[i].clear();
        visited[i] = false;
    }
}

void dfs(int u, int cor)
{
  visited[u] = true;
  color[u] = cor;
  for(int i=0; i<deg[u]; i++) {
    int v = adj[u][i];
    if(!visited[v]) {
        if (cor == 2) dfs(v, 1);
        else dfs(v, 2);
    } else {
        if (color[v] == cor) {
            bipartite = false;
        }
    }
  }
}

int main()
{
    while(true) {
        read_input();
        if (n == 0) break;
        init();
        dfs(0, 1);
        if (bipartite) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
}
