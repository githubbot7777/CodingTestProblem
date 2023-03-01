


#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/2887
using namespace std;
int v, e;

vector<tuple<int, int, int>> edge;
vector<int>p(100002, -1);
vector<pair<int, int>> v_x, v_y, v_z;
int find(int x)
{
    if (p[x] < 0)return x;
    return p[x] = find(p[x]);
}

bool is_diff(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b)return false;
    if (a < b)p[a] = b;
    else p[b] = a;
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;
    for (int i = 1; i <=v; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v_x.push_back({ x, i });
        v_y.push_back({ y, i });
        v_z.push_back({ z, i });
    }
    /*
    n(n-1)/2 50억이고 메모리 초과 발생
    x,y,z 각각 정렬후 인접한 행성들간 비용을 구한다. (n-1)*3개 간선을 얻게됨
    */
    sort(v_x.begin(), v_x.end());
    sort(v_y.begin(), v_y.end());
    sort(v_z.begin(), v_z.end());
    for (int i = 1; i <v; i++) {
        edge.push_back({ abs(v_x[i - 1].first - v_x[i].first),v_x[i - 1].second,v_x[i].second});
        edge.push_back({ abs(v_y[i - 1].first - v_y[i].first),v_y[i - 1].second,v_y[i].second });
        edge.push_back({ abs(v_z[i - 1].first - v_z[i].first),v_z[i - 1].second,v_z[i].second });

    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int cost, u, v;
        tie(cost, u, v) = edge[i];
        if (!is_diff(u, v))continue;
        cnt++;
        ans += cost;
    }
    cout << ans;

}