//https://school.programmers.co.kr/learn/courses/30/lessons/77485
//행렬 테두리 회전하기 (구현문제)
#include <bits/stdc++.h>

using namespace std;
int m[102][102];

void pr(int rows, int columns) {
    cout << '\n';
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
            cout << m[i][j] << ' ';

        cout << '\n';
    }

}
void turn(int x, int y, int xx, int yy) {
    int temp = m[x][y];
    for (int i = x; i < xx; i++)
        m[i][y] = m[i + 1][y];

    for (int i = y; i < yy; i++)
        m[xx][i] = m[xx][i + 1];

    for (int i = xx - 1; i >= x; i--)
        m[i + 1][yy] = m[i][yy];

    for (int i = yy - 1; i >= y; i--)
        m[x][i + 1] = m[x][i];

    //시계 방향 회전 후 마지막 변에서 의도한 값과 다른 값이 넣어짐
    //따라서 원래 값 temp에 저장 후 회전 하고 올바른 값 넣어줌
    m[x][y + 1] = temp;

}


int min_val(int x, int y, int xx, int yy) {
    int ret = 102 * 102;
    for (int i = x; i <= xx; i++)
        ret = min(m[i][y], ret);

    for (int i = y; i <= yy; i++)
        ret = min(m[xx][i], ret);

    for (int i = xx; i >= x; i--)
        ret = min(m[i][yy], ret);

    for (int i = yy; i >= y; i--)
        ret = min(m[x][i], ret);

    return ret;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt = 1;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            m[i][j] = cnt++;


    for (auto q : queries) {
        int x = q[0], y = q[1], xx = q[2], yy = q[3];
        turn(x, y, xx, yy);

        int ans = min_val(x, y, xx, yy);
        answer.push_back(ans);

    }
    return answer;
}