/*
https://www.acmicpc.net/problem/11047
Greedy problem
���� ��ġ�� ���� ������ ����ϸ� �������� �ּҷ� �� ������
*/
#include <bits/stdc++.h>
using namespace std;
int n,k; //n ���Ǽ� k �������ϴ� ������
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