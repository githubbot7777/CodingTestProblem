#include<bits/stdc++.h>
//https://www.acmicpc.net/problem/2169
using namespace std;



int r,c;
int cost[1002][1002];
int d[1002][1002][3];
//dp�� �ذ�
//0 down 1 left 2 right
int sol(int row, int col,int dir) {
	if (row < 1 || row > r || col < 1 || col > c)return -1000*1000*99;
	if (row == r && col == c)
	{
		return cost[r][c];
	}
	int& result = d[row][col][dir];
	if (result != -1)return result;
	//�ѹ� �湮�� ��湮 �ȵ�
	//�Ʒ��� ��� ��� ���Ⱑ��
	if (dir == 0)
		result = max({ sol(row+1,col,0),sol(row,col - 1,1),sol(row ,col+1,2) }) + cost[row][col];
	//�����ϰ�� ���ʰ� �Ʒ� ����
	if(dir==1)
		result = max({ sol(row,col - 1,1),sol(row + 1,col,0) }) + cost[row][col];
	//�������ϰ�� �����ʰ� �Ʒ� ����
	if (dir == 2)
		result = max({ sol(row+1,col,0),sol(row,col+1,2) }) + cost[row][col];

	return result;
}


 int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cin >> r >> c;
	 for (int i = 1; i <= r; i++)
		 for (int j = 1; j <= c; j++)
			 cin >> cost[i][j];

	 memset(d, -1, sizeof(d));
	 cout << sol(1,1,0);
	 
	 return 0;
}