#include <iostream>
#include <vector>
using namespace std;

int path_length(vector<int>& v, vector<int>& len, int nd) {
	if (len[nd] >= 0){
		return len[nd];
	}
	if (len[nd] == -2) {
		return len[nd] = 0;
	}
	len[nd] = -2;
	int rec = path_length(v, len, v[nd]);
	if (len[nd] == 0) {
	for (int i = v[nd]; i != nd; i = v[i]) {
	len[i] = rec+1;
		}
	}
	return len[nd] = rec+1;
}
	
int main() {
	int t,u;
	cin >> t;
	for (int ca = 1; t--; ca++) {
		int n;
		cin >> n;
		vector<int> v(n);
	for (int i = 0; i < n; i++) {
	cin >> u;
	u--;
	cin >> v[u];
	v[u]--;
	}
	vector<int> len(n, -1);
	int best = 0;
	for (int i = 0; i < n; i++) {
	if (path_length(v, len, i) > path_length(v, len, best)) {
		best = i;
		}
	}
	best++;
cout << "Case " << ca << ": " << best << endl;
}
}
