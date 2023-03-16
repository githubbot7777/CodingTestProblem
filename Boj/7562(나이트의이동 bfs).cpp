
//https://www.acmicpc.net/problem/7562
//유형 bfs
#include <bits/stdc++.h>

using namespace std;
int vis[302][302];
int dir[8][2] = { {-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2} };
int t,n;

void init_vis()
{
    for (int i = 0; i < n; i++)
     fill(vis[i], vis[i] + n, -1);
}
int bfs(int sx, int sy, int ex, int ey)
{
    queue<pair<int, int>> Q;
    vis[sx][sy] = 0;
    Q.push({ sx,sy });
    int result = 0;
    while (!Q.empty())
    {
        auto [cx,cy] = Q.front(); Q.pop();
     
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
            if (vis[nx][ny]>=0)continue;
            vis[nx][ny] = vis[cx][cy] + 1;
            if (nx == ex && ny == ey)
            {
                result = vis[nx][ny];
                break;
            }
               
           
            Q.push({ nx,ny });
        }
    }
   
    return result;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        init_vis();
        int sx, sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;
        int leng = bfs(sx, sy, ex, ey);
        cout << leng << '\n';
    }
    
    return 0;
}