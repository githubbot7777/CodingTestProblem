/*
https://www.acmicpc.net/problem/6064        
O(LCM(N, M))�̰� LCM(N, M)�� �ִ� NM�̴� O(NM)�̴�
N,M�� �ִ� 400000�̾ �ð��ʰ��̴�.
1���� LCM(N, M)������ �� ���� ��ſ� 
M���� ���� �������� x�� ��ϸ��� ���� i�� �ְ� for���� ������ 
LCM(N, M) / M���� ���� Ȯ���� �ϸ� �ǰ�, LCM(N, M) / M�� �ִ� N�̱� ������ �ð� ���� �� ���ư���.

*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)return b;

    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int sol(int m, int n, int x, int y)
{
    if (x == m)x = 0;
    if (y == n)y = 0;
    int l = lcm(m, n);
    for (int i = x; i <= l; i+=m)
    {
        if (i == 0)continue;
        if (i % n == y)
            return i;
    }

    return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << sol(m, n, x, y) << "\n";
    }
    
        return 0;
}