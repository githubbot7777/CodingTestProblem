/*
파괴되지 않은 건물 
문제 : https://school.programmers.co.kr/learn/courses/30/lessons/92344
해설 : https://tech.kakao.com/2022/01/14/2022-kakao-recruitment-round-1/#%EB%AC%B8%EC%A0%9C-6-%ED%8C%8C%EA%B4%B4%EB%90%98%EC%A7%80-%EC%95%8A%EC%9D%80-%EA%B1%B4%EB%AC%BC
*/


#include <bits/stdc++.h>

using namespace std;

/*
skill의 각 행은 [type, r1, c1, r2, c2, degree]
type=1 적의공격, type=2 아군의 치유1
내구도>=1 파괴되지않은 건물
*/
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>>temp(board.size()+1, vector<int>(board[0].size()+1, 0));
   
    for (int i = 0; i < skill.size(); i++)
    {
            int type = skill[i][0];
            int r1 = skill[i][1];
            int c1 = skill[i][2];
            int r2 = skill[i][3];
            int c2 = skill[i][4];
            int degree = skill[i][5];

            if (type == 1)
                degree *= -1;
            
            temp[r1][c1] += degree;
            temp[r1][c2 + 1] += -degree;
            temp[r2 + 1][c1] += -degree;
            temp[r2 + 1][c2 + 1] += degree;
            
 
    }
    //위에서 아래로 누적합
    for (int i = 1; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].size(); j++)
        {
            temp[i][j] = temp[i - 1][j]+temp[i][j];
        }
    }
    //왼쪽에서 오른쪽으로 누적합
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 1; j < temp[i].size(); j++)
        {
            temp[i][j] = temp[i][j - 1] + temp[i][j];
        }
    }
    //원래의 배열에 누적합 한것 더하기
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            board[i][j] = board[i][j] + temp[i][j];
            if (board[i][j] >0)
                answer++;
        }
    }
    return answer;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> board = {{5, 5, 5, 5, 5}, { 5, 5, 5, 5, 5}, { 5, 5, 5, 5, 5}, { 5, 5, 5, 5, 5 }};
    vector<vector<int>> skill= { {1,0,0,3,4,4}, { 1,2,0,2,3,2}, { 2,1,0,3,1,2}, { 1,0,1,3,3,1 } };

   cout<<solution(board, skill);
        return 0;
}



