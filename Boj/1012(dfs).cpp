//https://www.acmicpc.net/problem/1012
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
int vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n, k;
queue <pair<int, int >> q;
void bfs(int x, int y)
{
    vis[x][y] = 1;
    q.push({ x,y });
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if (vis[nx][ny] || !board[nx][ny])continue;
            vis[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        while (k--)
        {
            int x, y;
            cin >> y >> x;
            board[x][y] = 1;
        }
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1 && !vis[i][j])
                {
                    answer++;
                    bfs(i, j);
                }
            }
        }
        cout << answer<<'\n';
        memset(board, 0, sizeof(board));
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
