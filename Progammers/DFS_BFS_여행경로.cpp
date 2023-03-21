//programmers.co.kr/learn/courses/30/lessons/43164#
#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> tickets;
int vis[10005];
int n;
vector<string> answer;

bool is_end_trip()
{
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            return false;
    }
    return true;
}

bool dfs(string cur)
{
    if (is_end_trip())
        return true;

    for (int i = 0; i < n; i++)
    {
        string st = tickets[i][0];
        string en = tickets[i][1];
        if (st == cur && !vis[i])
        {
            vis[i] = 1;
            answer.push_back(en);
            bool judge = dfs(en);
            if (judge)
                return true;
            //티켓을 다 쓸 수 없다면 방문처리 해체, 리스트에서 제거
            vis[i] = 0;
            answer.pop_back();
        }
    }
    return false;
}


vector<string> solution(vector<vector<string>> t) {
    tickets = t;
    n = tickets.size();
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    dfs("ICN");

    return answer;
}