#include <iostream>
#include <string.h>
using namespace std;

int number, line, summation;
char map[25][25], mapB[25][25], land;

void dfs(int x, int y) {
    if(y >= line){
    	y = 0;
	}  
    if(y < 0){
    	y = line-1;
	}   
    if(x < 0 || x >= number)
        return ;
    if(mapB[x][y] != 0 || map[x][y] != land)
        return ;
    mapB[x][y] = 1;
    summation++;
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    dfs(x-1, y);
}

int main() {
		int x,y,answer = 0;
    	cin >> number >> line; 
        memset(mapB, 0, sizeof(mapB));
        for(int i = 0; i < number; i++)
            cin >> map[i];
        cin >> x >> y;
        land = map[x][y];
        dfs(x, y);
        for(int i = 0; i < number; i++) {
            for(int j = 0; j < line; j++) {
                summation = 0;
                dfs(i, j);
                if(summation > answer)
                    answer = summation;
            }
        }
        cout << answer << endl;

}
