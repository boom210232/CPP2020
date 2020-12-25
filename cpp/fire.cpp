#include <iostream>
#include <list>
#include <vector>
using namespace std;
int count = 0,N,K,x,y;
bool land[10001][10001];
int directiony[4] = {0, 0, 1,-1};
int directionx[4] = {1,-1, 0, 0};

bool inbound(int x, int y) {
    if ( x > N-1 || y > N-1|| x < 0 || y < 0){
    	return false;
	} 
    return true;
}

void bfs(list<int> &X, list<int> &Y, bool land[10001][10001])
{
    list<int> listY;
    list<int> listX;
    while(!X.empty()) {
        y = Y.front();
        x = X.front();
        Y.pop_front();
        X.pop_front();
        if (!land[x][y]) {
            land[x][y] = true;
            for (int i=1; i<=4; i++) {
                if (inbound(x+directionx[i-1], y+directiony[i-1])) {
                    listY.push_back(y+directiony[i-1]); 
					listX.push_back(x+directionx[i-1]);    
                }
            }
        }
    }
    if (!listX.empty()) {
        count++;
        bfs(listX, listY, land);
    }
}


int main()
{
    cin >> N >> K;
    list<int> LX;
    list<int> LY;
    for (int i=1; i<=K; i++) {
        cin >> x >> y;
        y = y-1;
		x = x-1;
        LX.push_back(x);
        LY.push_back(y);
    }
    bfs(LX, LY, land);
    cout << count-1 << endl;
}
