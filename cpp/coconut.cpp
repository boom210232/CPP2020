#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100010;
int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input(){
	cin >> n >> m;
	for(int i=0; i<n ; i++){
		deg[i]=0;
	}
	for(int i=0; i<m ; i++){
		int u,v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		deg[u]++;
		adj[v].push_back(u);
		deg[v]++;
	}
}

bool visited[MAX_N];

void init(){
	for(int i=0; i<n;i++){
		visited[i] = false;
	}
}

void dfs(int u){
	visited[u] =true;
	for(int d=0; d<deg[u];d++){
		int v = adj[u][d];
		if(!visited[v]) {
			dfs(v);
		}
	}
}

main() {
	int count = 0;
	read_input();
	init();
	for (int i=0;i<n;i++) if(!visited[i]) count++,dfs(i);
	cout << count;
}
