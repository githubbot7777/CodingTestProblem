/*
https://www.acmicpc.net/problem/11659
prefix sum(구간합)사용

*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000004], d[1000004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i - 1] << "\n";
    }
   
    return 0;

}