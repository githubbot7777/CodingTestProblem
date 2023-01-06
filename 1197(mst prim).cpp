
#define X first
#define Y second

#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1197
using namespace std;
int v, e;
//         <비용,정점번호>
vector<pair<int, int>> adj[10005];
// chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
bool chk[10005];
int cnt = 0;//현재 선택된 간선의 수
//tuple<int,int,int> : [비용,정점1,정점2]
priority_queue< tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>> > pq;


//프림 알고리즘


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    while (e--)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost,v});
        adj[v].push_back({cost,u});
    }

    chk[1] = 1;
    for (auto nxt : adj[1])
        pq.push({ nxt.X,1,nxt.Y });
    
    int ans = 0;
    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b])continue;
        cout << cost << ' ' << a << ' ' << b << '\n';
        ans += cost;
        chk[b] = 1;
        cnt++;
        for (auto nxt : adj[b]) {
            if (!chk[nxt.Y])
                pq.push({ nxt.X,b,nxt.Y });
        }
    }
    cout << ans;

}
