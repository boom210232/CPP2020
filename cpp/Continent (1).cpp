#include <stdio.h>
#include <string.h>

int number, line, i, j, ans, sum;
char map[21][21], used[21][21], land;
void dfs(int x, int y) {
    if(y >= line)  y = 0;
    if(y < 0)   y = line-1;
    if(x < 0 || x >= number)
        return ;
    if(used[x][y] != 0 || map[x][y] != land)
        return ;
    used[x][y] = 1;
    sum++;
    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x+1, y);
    dfs(x, y+1);
}
int main() {
    while(scanf("%d %d", &number, &line) == 2) {
        memset(used, 0, sizeof(used));
        for(i = 0; i < number; i++)
            scanf("%s", map[i]);
        ans = 0;
        scanf("%d %d", &i, &j);
        land = map[i][j];
        dfs(i, j);
        for(i = 0; i < number; i++) {
            for(j = 0; j < line; j++) {
                sum = 0;
                dfs(i, j);
                if(sum > ans)
                    ans = sum;
            }
        }
        printf("%d\n", ans);
        break;
    }
    return 0;
}
