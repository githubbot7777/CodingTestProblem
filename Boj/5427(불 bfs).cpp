
//https://www.acmicpc.net/problem/5427
//유형 bfs

#include <bits/stdc++.h>

using namespace std;

char board[1002][1002];
int vis[1002][1002];
int vis_f[1002][1002];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int t, w, h;


void init()
{
    memset(vis, 0, sizeof(vis));
    memset(vis_f, 0, sizeof(vis_f));
}
   
void bfs_f(queue<pair<int, int>>& Q)
{

    while (!Q.empty())
    {
        auto [cx, cy] = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
            if (vis_f[nx][ny] || board[nx][ny] == '#')continue;
            vis_f[nx][ny] = vis_f[cx][cy] + 1;
            Q.push({ nx,ny });
        }
    }
}

void pr_visit()
{
    cout << "fire\n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << vis_f[i][j];
        }
        cout << '\n';
    }
     cout << "visit\n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << vis[i][j];
        }
        cout << '\n';
    }
}
void bfs(queue<pair<int, int>>& Q)
{
 
    while (!Q.empty())
    {
        auto [cx, cy] = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];
            //다음에 방문할곳이 밖으로 나갔으면 맵 경계에 있다.
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                cout << vis[cx][cy] << '\n';
                return;
            }
        
            if (board[nx][ny] == '.' && !vis[nx][ny])
            {
                if (vis_f[nx][ny] > vis[cx][cy] + 1 || vis_f[nx][ny] == 0)
                {
                    vis[nx][ny] = vis[cx][cy] + 1;
                    Q.push({ nx,ny });
                }
            }
          
        }
    }
    

        cout << "IMPOSSIBLE" << '\n';
   
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> w >> h;
        init();
        queue<pair<int, int>> Q;
        queue<pair<int, int>> QF;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char c;
                cin >> c;
                board[i][j]=c;
                if (c == '@')
                {
                    Q.push({ i,j });
                    vis[i][j] = 1;
                }

                if (c == '*')
                {
                   QF.push({ i,j });
                   vis_f[i][j] = 1;
                }
            }
        }
       bfs_f(QF);
       bfs(Q);
      // pr_visit();
    }
    return 0;
}


