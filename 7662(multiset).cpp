#include<bits/stdc++.h>

using namespace std;
//https://www.acmicpc.net/problem/7662


multiset<int>s;
int t, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--)
    {
        s.clear();
        cin >> k;
        while (k--)
        {
            char c;
            int n;
            cin >> c >> n;
            if (c == 'I')
                s.insert(n);
            else {
                if (s.empty())continue;
                if (n > 0)//최댓값 삭제
                    s.erase(prev(s.end()));
                else 
                    s.erase(s.begin());
                
            }
        }
        if (s.empty())
            cout << "EMPTY" << "\n";
        else {
            auto max = prev(s.end());
            auto min = s.begin();
            cout << *max << " " << *min << "\n";

        }
    }

    return 0;
}