/*
https://www.acmicpc.net/problem/1012
*/


#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
/*

*/

int t, y, x, k;
int board[52][52];
vector<pair<int,int>> locations;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int result = 0;

void dfs(int cx,int cy)
{
   
    stack<pair<int, int>> s;
    if (board[cx][cy] == 0)
        return;

    result++;
    board[cx][cy] = 0;
    s.push({ cx,cy });

    while (!s.empty())
    {
        pair<int, int> cur = s.top();
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= x || ny < 0 || ny >= y)continue;
            if (!board[nx][ny])continue;
            board[nx][ny] = 0;
            //cout << "(" << nx << " " << ny << ")\n";
            s.push({ nx,ny });

        }
    }
   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    vector<int> answers;
    while (t--)
    {
        memset(board, 0, sizeof(board[0][0]) * 52 * 52);
        locations.clear();
        result = 0;
        cin >> y >> x >> k;
        for (int i = 0; i < k; i++)
        {
            int tx, ty;
            cin >> ty >> tx;
            locations.push_back({ tx,ty });
            board[tx][ty] = 1;
        }

        for (int i = 0; i < locations.size(); i++)
        {
            dfs(locations[i].X, locations[i].Y);
        }

        answers.push_back(result);
       
    }
    for (int i = 0; i < answers.size(); i++)
        cout << answers[i] << "\n";
   
        return 0;
}



