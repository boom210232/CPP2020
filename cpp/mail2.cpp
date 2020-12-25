#include<iostream>
#include<vector>
 
using namespace std;

int total, cases, N, u, v , best, answer;
vector<int> graph, sum;
vector<bool> visit;
 
int dfs(int u) {
    visit[u] = true;
    total = 0;
    if(graph[u] != -1 && !visit[graph[u]])
        total = total + 1 + dfs(graph[u]);
    visit[u] = false;
    return sum[u] = total;
}
 
int main() {
    cin >> cases;
    for(int t=1; t<=cases; t++) {
        cin >> N;
		visit.assign(N, false);
        sum.assign(N, -1);
        graph.assign(N, -1);
        for(int i=1; i <=N; i++) {
            cin >> u >> v;
            graph[u-1] = v-1;
        }
        answer = 0;
		best = 0;
        for(int i=1; i<=N; i++) {
            if(sum[i-1] == -1) {
            	dfs(i-1);
			}
            if(best<sum[i-1]) {
                answer = i-1;
                best = sum[i-1];
            }
        }
        answer++;
        cout << "Case " << t << ": " << answer << endl;
    }
}
