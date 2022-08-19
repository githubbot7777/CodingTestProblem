/*
https://www.acmicpc.net/problem/1149

*/
#include <bits/stdc++.h>
using namespace std;
int d[1005][3];
int r[1005], g[1005], b[1005];

/*
테이블 정의하기
d[i][0]=i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
d[i][1]=i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 초록
d[i][2]=i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑

점화식
d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> r[i] >> g[i] >> b[i];
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];

    for (int i = 2; i <= n; i++)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
    }


    cout << *min_element(d[n], d[n] + 3);
    //cout<<min({d[n][0],d[n][1],d[n][2]});
    //어느쪽으로 해도됨

    return 0;

}