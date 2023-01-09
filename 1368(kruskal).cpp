
#define X first
#define Y second

#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1368
using namespace std;

vector<int>p(302, -1);

int find(int x) {
    if (p[x] < 0)return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if (u == v)return 0;
    if (p[u] < p[v])p[u] = v;
    else p[v] = u;
    return 1;
}
int v, e;
tuple<int, int, int> edge[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int idx = 0;
    cin >> v;
    //가상의 v+1번째 정점과 연결
    for (int i = 1; i <=v; i++)
    {
        int cost;
        cin >> cost;
        edge[idx++] = { cost,i,v+1};
    }
       
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <=v; j++)
        {
            int cost;
            cin >> cost;
            if (i >= j)continue;
               edge[idx++] = { cost,i,j };
          
        }

    }
    v++;//가상의 정점까지 포함해야 하므로 정점 수를 1 증가시킴
    sort(edge, edge + idx);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < idx; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        
        if (!is_diff_group(a, b))continue;
        ans += cost;
        cnt++;
        if (cnt == v - 1)break;
    }
    cout << ans;
    
}
