// THIS FILE IS NOT THE ORIGINAL FILE IN THE CONTEST.
// INSTEAD, IT IS ALTERED.

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1010][1010], visited[1010][1010];
int mov[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(){
//  freopen("explore.in", "r", stdin);
//  freopen("explore.out", "w", stdout);
    int T;
    cin >> T
    int n, m, k, x, y, d, sum = 1;
    while(T--){
        cin >> n >> m >> k >> x >> y >> d;
        sum = 1;
        memset(a, 0, sizeof a);
        memset(visited, 0, sizeof visited);
        for(int j = 1; j <= n; j++){
            for(int w = 1; w <= m; w++){
                char c = getchar();
                if(c == 'x') a[j][w] = 1;
                else a[j][w] = 0;
            }
            getchar();
        }
        visited[x][y] = 1;
        for(int q = 1; q <= k; q++){
            int nx = x+mov[d][0];
            int ny = y+mov[d][1];
            if(a[nx][ny] == 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                x = nx, y = ny;
                if(!visited[x][y]) sum++, visited[x][y] = 1;
            }else d = (d+1) % 4;
        }
        cout << sum << endl;
    }
    return 0;
}