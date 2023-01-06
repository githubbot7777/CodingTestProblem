
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/2252
using namespace std;


vector<int> adj[32002];
vector<int> result;
int in_degree[32002];
int n,m;


void toplogical() {
    queue<int> q;
    //1-indexed
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int i : adj[cur])
        {
            in_degree[i]--;
            if (in_degree[i] == 0)
                q.push(i);
        }
            
    }
   
   
        for (auto x : result)cout << x << ' ';
   
        
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }
    toplogical();
}
