/*
https://www.acmicpc.net/problem/12852
*/


#include <bits/stdc++.h>

using namespace std;

/*
경로 추적을 위한 pre배열 선언해서 선택한것을 기록후
순회하면서 따라간다.
*/
int n;
int a[1000002];
int pre[1000002];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a[1] = 0;
   
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i-1]+1;
        pre[i] = i - 1;
        if (i % 3 == 0&& a[i / 3] + 1 < a[i])
        {
           
                a[i] = a[i / 3] + 1;
                pre[i] = i / 3;
           
        }
     
        if (i % 2 == 0&& a[i / 2] + 1 < a[i])
        {
           
                a[i] = a[i / 2] + 1;
                pre[i] = i / 2;
           
        }
           
        
           
    }
   
    cout << a[n]<<"\n";
  

    int cur = n;
    while (1)
    {
        cout << cur << ' ';
        if (cur == 1)break;
        cur = pre[cur];
    }
        return 0;
}



