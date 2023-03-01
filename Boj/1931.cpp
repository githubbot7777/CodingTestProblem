/*
https://www.acmicpc.net/problem/1931
pair 정렬하면 first 순으로 정렬하고 first 같으면 second순으로 오름차순 정렬해준다.
*/
#include <bits/stdc++.h>
using namespace std;
int n; 
list <pair<int, int>> a;//[end time, start time]



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> t;
        int n1, n2;
        cin >> n1 >> n2;
        t.first = n2;
        t.second = n1;
        a.push_back(t);

    }
   
    a.sort();
    int ans = 0;
    int t = 0;
   
    for (auto i : a)
    {
        if (t > i.second)continue;
        ans++;
        t = i.first;
    }
    cout << ans;
    return 0;

}