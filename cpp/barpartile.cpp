#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BLACK = 0;
int WHITE = 1;
int UNKNOWN = 2;

int main()
{  
    int n;
    while (cin >> n, n != 0)
    {
        vector<vector<int> > G(n);
        vector<int> color(n, UNKNOWN);
        bool isBipartite = true;
        int l;
        cin >> l;
        while ( l-- )
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        queue<int> q;
        color[0] = BLACK;
        q.push(0);
        while (!q.empty() && isBipartite)
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); ++i)
            {
                int v = G[u][i];
                if (color[v] == color[u])
                {
                    isBipartite = false;
                    break;
                }
                else if (color[v] == UNKNOWN)
                {
                    color[v] = 1 - color[u]; 
                    q.push(v);
                }
            }
        }
        if (isBipartite)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
