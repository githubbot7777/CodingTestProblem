/*
https://www.acmicpc.net/problem/1806
*/


#include <bits/stdc++.h>


using namespace std;

int n, s;
int a[100002];     
/*

*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int tot = a[0];
    int mn = INT_MAX;
    int st = 0, en = 0;
    for (; st < n; st++)
    {
        while (tot < s && en < n) {
            en++;
            if (en != n)tot += a[en];
        }
     
        if (en == n)break;
       
        mn = min(mn, en - st + 1);
        tot -= a[st];
    }
    if (mn == INT_MAX)
        cout << 0;
    else
        cout << mn;

    return 0;
}



