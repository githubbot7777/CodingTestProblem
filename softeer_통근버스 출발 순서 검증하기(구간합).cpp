#include<bits/stdc++.h>
//https://softeer.ai/practice/info.do?idx=1&eid=654
//����https://softeer.ai/community/view.do?idx=731&cd=edu&pageNo=1
#define ll long long
using namespace std;


int num[5002];
int n;
int main(int argc, char** argv)
{
	cin >> n;
	for (int i = 1; i <=n; i++)
		cin >> num[i];
	/*
	������ �ڿ��� X(1��X��N)�� ���Ͽ�, arr[X][j]�� j ��°���� �����ʿ� �ִ� ���ڵ� ��, x ���� ���� ���� �͵��� ������� ������ �� �ֽ��ϴ�.
	*/
	vector<vector<int>> arr(n + 2, vector<int>(n + 2, 0));
	for (int x = 1; x <= n; x++)
	{
	
		for (int j = n - 1; j >=1; j--)
		{
			int add = (num[j+1] < x) ? 1 : 0;
			arr[x][j] = arr[x][j + 1] + add;
		}
	}
	ll result = 0;

	for (int i = 1; i <n-1; i++)
	{
		for (int j = i + 1; j <n; j++)
		{
			if (num[i] < num[j])
				result += arr[num[i]][j];
		}
	}

	cout << result;
	return 0;
}