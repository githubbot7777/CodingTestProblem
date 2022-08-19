/*
https://www.acmicpc.net/problem/2579

*/
#include <bits/stdc++.h>
using namespace std;

int s[305];//계단 높이 저장하는 배열
int n;
int d[305];//dp 테이블
/*
d[i]=i번째 계단까지 올라섰을때 밟지 않을 계단의 합의 최솟값, 단 
i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함

점화식: d[i]=min(d[i-2],d[i-3])+s[i]*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        tot += s[i];
    }
    if (n <= 2)
    {
        cout << tot;
        return 0;
    }
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for (int i = 4; i <= n - 1; i++)
        d[i] = min(d[i - 2], d[i - 3]) + s[i];
    /*
    마지막 도착 계단은 반드시 밟아야 한다고 했으니 
    가장 마지막으로 선택될 밟지 않은 
    계단은 N-1번째 계단이거나 N-2번째 계단입니다. 
    그래서 계단에 적힌 점수의 합에서 
    min(D[N-1], D[N-2])를 빼면 그게 정답입니다.
    */
    cout << tot - min(d[n - 1], d[n - 2]);


    return 0;

}