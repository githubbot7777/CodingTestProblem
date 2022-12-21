#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//https://www.acmicpc.net/problem/1620

int n,m;
unordered_map<string, int> u_map;
string keys[100002];
vector<string> ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        u_map.insert({ str,i });
        keys[i] = str;
    }
  
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
       
        if (isdigit(t[0]))
            ans.push_back(keys[stoi(t)]);
        else {
            int val = u_map[t];
            ans.push_back(to_string(val));
        }
        
    }

    for (auto it : ans)
        cout << it << "\n";

    return 0;
}