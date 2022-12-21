/*
https://www.acmicpc.net/problem/2230
*/


#include <bits/stdc++.h>


using namespace std;

int m, n;
int a[100002];     
/*

*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int mn = INT_MAX;
    int st = 0, en = 0;
    for (int st = 0; st < n; st++)
    {
        while (en < n && a[en] - a[st] < m)en++;
        if (en == n)break;//en이 범위를 벗어날시 종료!!
        mn = min(mn, a[en] - a[st]);
    }
    cout << mn;

    return 0;
}



