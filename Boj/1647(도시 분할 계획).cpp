

#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1647
using namespace std;
int v, e;
vector<int>p(100002, -1);
int find(int x)
{
    if (p[x] < 0)return x;
    return p[x] = find(p[x]);
}

int is_diff(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b)return 0;
    if (a < b)p[a] = b;
    else p[b] = a;
    return 1;
}
tuple<int, int, int> edge[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = { cost,a,b};
    }
    sort(edge, edge + e);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff(a, b))continue;
        
        cnt++;
        ans += cost;
        //두개의 마을로 분리해야함으로 기존 v-1개 간선 선택된 상태에서 가장 큰 weight인 간선 제외해야함
        if (cnt == v - 2)break;
       
    }
    cout << ans;

  

}