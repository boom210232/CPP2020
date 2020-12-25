#include <iostream>
using namespace std;

char map[35][35];
bool tree, mine;
int M, N,count=0,nice = 0,perfect = 0;

void dfs(int i, int j){
    if (i < 0 || j < 0 || i > N-1 || j > M-1) return;
    if (map[i][j] == '#') return;
    else if (map[i][j] == '*') {
    	tree = true;
	}
    else if (map[i][j] == '$'){
    	mine = true;
	} 
    map[i][j] = '#';
    count++;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> map[i-1][j-1];
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            tree = false;
            mine = false;
            count = 0;
            dfs(i-1, j-1);
            if(tree and mine) {
                perfect += count;
            } 
			else if (tree or mine) {
                nice += count;
            }
        }
    }
    cout << perfect << " " << nice << endl;
}
