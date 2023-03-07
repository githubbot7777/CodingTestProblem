//설명https://www.youtube.com/watch?v=tvyDu2JBTpE&t=2s
//문제https://softeer.ai/practice/info.do?idx=1&eid=635
#include<bits/stdc++.h>
#define V first
#define W second

using namespace std;
int n;
vector<pair<int, int>>node[200002];
long long subtreeSize[200002];
long long distSum[200002];

void dfs1(int cur, int parent)
{
	subtreeSize[cur] = 1;
	for (auto it : node[cur])
	{
		int child = it.V;
		int weight = it.W;
		if (child != parent)
		{
			dfs1(child, cur);
			distSum[cur] += distSum[child] + subtreeSize[child] * weight;
			subtreeSize[cur] += subtreeSize[child];
		}
	}
	return;
}

void dfs2(int cur, int parent)
{
	for (auto it : node[cur])
	{
		int child = it.V;
		int weight = it.W;
		if (child != parent)
		{
			//								weight*(n-subtreeSize[child]-subtreeSize[child])
			distSum[child] = distSum[cur] + weight * (n - 2 * subtreeSize[child]);
			dfs2(child, cur);
		}
	}
	return;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		node[x].push_back({ y,t });
		node[y].push_back({ x,t });
	}
	dfs1(1, 1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
		cout << distSum[i] << '\n';
	return 0;
}
