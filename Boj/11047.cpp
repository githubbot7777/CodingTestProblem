/*
https://www.acmicpc.net/problem/11047
Greedy problem
가장 가치가 높은 동전을 사용하면 동전수를 최소로 할 수있음
*/
#include <bits/stdc++.h>
using namespace std;
int n,k; //n 줄의수 k 만들어야하는 동전값
int coins[15];



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    for (int i = n - 1; i >= 0; i--)
    {
        ans += k / coins[i];
        k %= coins[i];
    }
    cout << ans;
   
    return 0;

}