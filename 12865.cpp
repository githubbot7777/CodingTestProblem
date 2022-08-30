/*
https://www.acmicpc.net/problem/12865

https://www.youtube.com/watch?v=nLmhmB6NzcM&t=741 
01 knapsack 점화식으로 dp로 풀었다. 
*/
#include <bits/stdc++.h>
using namespace std;
int n,k; 
int a[102][100002];
int w[102];
int p[102];





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>k;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> p[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j - w[i] < 0)
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = max(a[i - 1][j], a[i - 1][j - w[i]] + p[i]);

        }
    }
    cout << a[n][k];

        return 0;
}
