
#define X first
#define Y second

#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1197
using namespace std;
int v, e;
//         <���,������ȣ>
vector<pair<int, int>> adj[10005];
// chk[i] : i��° ������ �ּ� ���� Ʈ���� �����ִ°�?
bool chk[10005];
int cnt = 0;//���� ���õ� ������ ��
//tuple<int,int,int> : [���,����1,����2]
priority_queue< tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>> > pq;


//���� �˰���


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
