/*
https://www.acmicpc.net/problem/1477
*/
#include <bits/stdc++.h>
using namespace std;
int n, m, l;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;

    vec.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vec.push_back(t);
    }
   
    vec.push_back(l);
    sort(vec.begin(), vec.end());
    
    int left = 1;
    int right = l - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int count = 0;
        for (int i = 1; i < vec.size(); i++)
        {
            int length = vec[i] - vec[i - 1];
            count += (length / mid);
            if (length % mid == 0)
                count--;

        }
        if (count > m)
        {
            left = mid + 1;
            
        }
        else {
            right = mid - 1;
        }
    }
    cout << left;
        return 0;
}