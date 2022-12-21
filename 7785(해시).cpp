#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
//https://www.acmicpc.net/problem/7785

int n;

bool cmp(string a, string b)
{
    if (a.compare(b) > 0)
        return true;
    else
        return false;
}
int main()
{
    unordered_set<string> list;
    vector<string> vec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter")
        {
            list.insert(s1);
        }
        else
            list.erase(list.find(s1));
    }

   
    for (auto it : list) {
        vec.push_back(it);
    }
    sort(vec.begin(), vec.end(), cmp);

    for (auto it : vec) {
        cout << it << "\n";
    }

    return 0;
}