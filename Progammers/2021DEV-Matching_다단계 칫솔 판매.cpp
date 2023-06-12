//https://school.programmers.co.kr/learn/courses/30/lessons/150365
/*
방향이 4가지 k가 최대 2500이라 DFS 가 힘들어 보일 수 있지만 안 되는 경우가 많아 백트래킹으로 풀 수 있다.

1. 남은 움직임 수가 현재 위치에서 목표지점까지의 거리보다 적으면 가지치기

2. 남은 움직임 수에서 현재 위치에서 목표지점까지의 거리를 뺐을 때 홀수번 남으면 가지치기

    - 이는 어디서든 최단 루트에서 벗어났다가 돌아오는데 짝수번이 필요하기 때문이다.

3. Down -> Left -> Right -> Up 순으로 확인

*/
#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, r, c, k;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };
char ds[4] = { 'd','l','r','u' };
bool judge = false;
string answer = "";
string result = "impossible";
int get_dist(int cx, int cy)
{
    return abs(r - cx) + abs(c - cy);
}

void dfs(int cnt, int cx, int cy)
{
    if (!judge)
    {
        int dist = get_dist(cx, cy);

        if ((k - cnt) < dist)return;
        if ((k - cnt - dist) % 2 == 1)return;

        if (cnt == k)
        {
            if (cx == r && cy == c)
            {
                judge = true;
                result = answer;
            
            }

            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx<1 || nx>n || ny<1 || ny>m)continue;
            answer += ds[i];
            dfs(cnt + 1, nx, ny);
            answer.pop_back();
        }
    }



}


string solution(int _n, int _m, int _x, int _y, int _r, int _c, int _k) {
    n = _n, m = _m, x = _x, y = _y, r = _r, c = _c, k = _k;
    dfs(0, x, y);

    return result;
}