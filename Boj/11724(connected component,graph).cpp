
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/11724
using namespace std;

int v, e;
vector<int>adj[1002];
int vis[1002];
int ans = 0;

void dfs(int start)
{
   
    vis[start] = 1;
    for (int i : adj[start])
    {
        if (vis[i])continue;
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
        
    }

    cout << ans;
}
