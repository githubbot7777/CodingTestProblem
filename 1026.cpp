/*
https://www.acmicpc.net/problem/1026

*/
#include <bits/stdc++.h>
using namespace std;
int n; 
int a[51], b[51];


int cmp(int a, int b)
{
    return(a > b);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];
   
    sort(a, a + n, cmp);
    sort(b, b + n);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = a[i] * b[i];
        result += temp;
    }

    cout << result;

        return 0;
}