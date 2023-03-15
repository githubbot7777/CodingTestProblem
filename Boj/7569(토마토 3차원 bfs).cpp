
//https://www.acmicpc.net/problem/7569
//유형 bfs
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[105][105][105];
int vis[105][105][105];
int n,m,h;
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<tuple<int, int, int>> Q;

void bfs()
{
    while (!Q.empty())
    {
        auto [cx, cy, cz] = Q.front(); Q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            int nz = cz+dz[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (vis[nx][ny][nz]>=0)continue;
            vis[nx][ny][nz] = vis[cx][cy][cz] + 1;
            Q.push({ nx,ny,nz });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> m>>n>>h;
    for (int k = 0; k < h; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {   
                int n;
                cin >> n;
                board[k][i][j]=n;
                if(n==1)
                    Q.push({ k,i,j });
                if (n == 0)
                    vis[k][i][j] = -1;
             
            }

    
     bfs();
  
        
    int mx = 0;
    for (int k = 0; k < h; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                mx = max(mx, vis[k][i][j]);
                if (vis[k][i][j] < 0)
                {
                    cout << -1;
                    return 0;
                }
            }

    cout << mx;



    return 0;
}