/*
https://www.acmicpc.net/problem/1149
*/


#include <bits/stdc++.h>

using namespace std;

/*
d[n][0]=min(d[n-1][1],d[n-1][2]) i번째 집까지 칠할때 비용의 최솟값,단 i번째 집은 빨강
d[n][1]=min(d[n-1][0],d[n-1][2])
d[n][2]=min(d[n-1][0],d[n-1][1])

*/
int n;
int r[1005],g[1005],b[1005];
int d[1005][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i] >> g[i] >> b[i];
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];
    for (int i = 2; i <= n; i++)
    {
            d[i][0] = min(d[i - 1][1], d[i - 1][2])+r[i];
            d[i][1] = min(d[i - 1][0], d[i - 1][2])+g[i];
            d[i][2] = min(d[i - 1][0], d[i - 1][1])+b[i];
    }

    cout << *min_element(d[n], d[n]+3);
        return 0;
}



