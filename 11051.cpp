/*
https://www.acmicpc.net/problem/11051       
nCk=n-1Ck+n-1Ck-1; 조합 성질 이용
*/
#include <bits/stdc++.h>
using namespace std;

int d[1002][1002];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= 1000; i++)
    {
        d[i][i] = 1;
        d[i][0] = 1;
        for (int j = 1; j <i; j++)
        {
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1])%10007;
        }
    }

    cout << d[n][k];
    
        return 0;
}