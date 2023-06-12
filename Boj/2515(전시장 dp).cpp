//https://www.acmicpc.net/problem/2515
//참고https://kibbomi.tistory.com/115
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, s;
vector<pair<int, int>> v;
vector<int> lim;
vector<int> dp;

int main()
{
	cin >> n >> s;
	v.resize(n + 1);
	lim.resize(n + 1);
	dp.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int h, c;
		cin >> h >> c;
		v[i].first = h;
		v[i].second = c;
	}

	sort(v.begin(), v.end());
	//8 10 15 17 20 26
	for (int i = 1; i <= n; i++) {
		for (lim[i] = lim[i - 1]; lim[i] < i; ++lim[i])
			if (v[i].first - v[lim[i]].first < s)break;
		lim[i]--;
	}

	for (int i = 1; i <= n; i++)
		dp[i] = max(dp[i - 1], dp[lim[i]] + v[i].second);

	cout << dp[n];
}