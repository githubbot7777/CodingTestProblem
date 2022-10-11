/*
https://www.acmicpc.net/problem/1103
문제 풀이
https://kibbomi.tistory.com/169
*/


#include <bits/stdc++.h>

using namespace std;

/*

*/

int r, c;
int board[52][52];
int visited[52][52];
int dp[52][52];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result = 0;
int dfs(int row,int col)
{
    if (board[row][col] == 0)//구멍을 0으로 표시
        return 0;
    if (row < 0 || row >= r || col < 0 || col >= c)
        return 0;
    
    if (visited[row][col])
    {
        cout << -1;
        exit(0);
    }
    int& cache = dp[row][col];
    if (cache != -1)
        return cache;

    visited[row][col] = 1;

    int move = board[row][col];
    cache = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = row + dx[i] * move;
        int ny = col + dy[i] * move;
        cache = max(cache, dfs(nx, ny)+1);
    }

    visited[row][col] = 0;
    return cache;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
        {   
            if (str[j] == 'H')continue;
         
            int num = str[j] - '0';
            board[i][j] = num;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<dfs(0, 0);
   
        return 0;
}



