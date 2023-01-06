
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1260
using namespace std;

int v, e,start;
vector<int>adj[1002];
int vis[1002];


void dfs(int start)
{
   
    vis[start] = 1;
    cout << start << ' ';
    for (int i : adj[start])
    {
        if (vis[i])continue;
        dfs(i);
    }
}

void bfs(int start)
{
    fill(vis, vis + 1002, 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << ' ';
        for (int i : adj[v])
        {
            if(vis[i])continue;
            vis[i] = 1;
            q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> v >> e>>start;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
    for (int i = 1; i <= v; i++)
        sort(adj[i].begin(), adj[i].end());
   
    dfs(start);
    cout << '\n';
    bfs(start);
  
}
