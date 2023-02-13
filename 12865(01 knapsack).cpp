#include<bits/stdc++.h>
//https://www.acmicpc.net/problem/12865
//설명https://www.youtube.com/watch?v=nLmhmB6NzcM&t=1460s
//v[price,weight]
//v[i,w]=max(v[i-1,w],v[i-1,w-w[i]]+p[i])

#define V first
#define W second
using namespace std;
int n,k;
//dp[i][j] 에는 가방을 최대 j 무게를 채우려 할 때 0번째 물건부터 i번째 물건까지 중에서 사용되는 물건들의 최대 가치 합
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
