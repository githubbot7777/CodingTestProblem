/*
https://www.acmicpc.net/problem/2217

*/
#include <bits/stdc++.h>
using namespace std;
int n; 
int arr[100005];




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0;i <n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    
    int result = 0;
    for (int i = 1; i <=n; i++)
    {
        result = max(arr[n-i]*i, result);
    }

    cout << result;

        return 0;
}