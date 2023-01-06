//https://www.acmicpc.net/problem/1715
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n;
    int ans = 0;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        pq.push(t);
        
    }
    
    while (pq.size()>1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);

    }
    cout << ans;
}