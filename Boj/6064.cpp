/*
https://www.acmicpc.net/problem/6064        
O(LCM(N, M))이고 LCM(N, M)은 최대 NM이니 O(NM)이다
N,M이 최대 400000이어서 시간초과이다.
1부터 LCM(N, M)까지를 다 보는 대신에 
M으로 나눈 나머지가 x인 목록만을 변수 i에 넣고 for문을 돌리면 
LCM(N, M) / M개의 수만 확인을 하면 되고, LCM(N, M) / M은 최대 N이기 때문에 시간 내에 잘 돌아간다.

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