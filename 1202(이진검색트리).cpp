#include<bits/stdc++.h>

using namespace std;
//https://www.acmicpc.net/problem/1202

int n, k;//보석수, 가방수
multiset<int>bags;
pair<int, int>jewels[300003];//<가격,무게>
long long ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> jewels[i].second >> jewels[i].first;
    while (k--)
    {
        int n;
        cin >> n;
        bags.insert(n);
    }
    sort(jewels, jewels + n);
    for (int i = n - 1; i >= 0; i--)
    {
        int weight, price;
        tie(price, weight) = jewels[i];
        auto it = bags.lower_bound(weight);
        if (it == bags.end())continue;
        ans += price;
        bags.erase(it);
    }
    cout << ans;
    return 0;
}