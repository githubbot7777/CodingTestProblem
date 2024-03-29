/*
https://www.acmicpc.net/problem/12852
pre dp 테이블의 경로를 저장하는 배열
1로만들기 10의 경우 경로는 [10 9 3 1]

*/
#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000004];
int pre[1000004];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    d[1] = 0;

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;


        if (i % 2 == 0&&d[i]>d[i/2]+1) {
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && d[i] > d[i / 3] + 1)
        {
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
       
    }
    cout << d[n]<<"\n";
    int cur = n;
    while (true)
    {
        cout << cur << " ";
        if (cur == 1)break;
        cur = pre[cur];
    }

   
    return 0;

}