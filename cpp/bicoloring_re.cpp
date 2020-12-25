#include <iostream>
#include <vector>

using namespace std;

int i, n, m, u, v, colour_flow[123456], degree[123456];
bool visit[123456], bicolor =true;
vector<int> adj[123456];

void inputs()
{
	cin >> n;
	if (n==0){
  	return;
  } 
  	cin >> m;
  	bicolor = true;
  	for(i=0; i<n; i++) {
    	colour_flow[i] = 0;
    	degree[i] = 0;
  	}
  	for(i=0; i<m; i++) {
    	cin >> u >> v;
    	adj[v].push_back(u);
    	adj[u].push_back(v);
    	degree[v]++;
    	degree[u]++;
  	}
}

void starter(){
    for(i=1; i<=n; i++) 
    {
        adj[i-1].clear();
        visit[i-1] = false;
    }
}

void deep_first_search(int u, int color)
{
	visit[u] = true;
	colour_flow[u] = color;
	for(i=1; i<=degree[u]; i++) {
    v = adj[u][i-1];
	if(visit[v] == true) {
        if (colour_flow[v] == color) {
            bicolor = false;
        }    
	if(visit[v] == false) {
        if (color == 2) deep_first_search(v, 1);
        else deep_first_search(v, 2);
    	} 
    }
	}
}

int main()
{
    while(true) {
        inputs();
        if (n == 0) {
        	break;
		}
        starter();
        deep_first_search(0, 1);
        if (bicolor) {
            cout << "BICOLORABLE." << endl;
        } 
		if (!bicolor) {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
}
