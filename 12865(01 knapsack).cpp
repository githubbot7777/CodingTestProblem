#include<bits/stdc++.h>
//https://www.acmicpc.net/problem/12865
//����https://www.youtube.com/watch?v=nLmhmB6NzcM&t=1460s
//v[price,weight]
//v[i,w]=max(v[i-1,w],v[i-1,w-w[i]]+p[i])

#define V first
#define W second
using namespace std;
int n,k;
//dp[i][j] ���� ������ �ִ� j ���Ը� ä��� �� �� 0��° ���Ǻ��� i��° ���Ǳ��� �߿��� ���Ǵ� ���ǵ��� �ִ� ��ġ ��
int dp[102][100002];

int main(int argc, char** argv)
{
	cin >> n >> k;
	vector<pair<int, int>> l(n + 1, { 0,0 });
	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;
		l[i]={ v,w };
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - l[i].W >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - l[i].W] + l[i].V);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k];
	return 0;
}
