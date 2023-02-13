#include<bits/stdc++.h>
#include<unordered_map>

//문제https://softeer.ai/practice/info.do?idx=1&eid=1204
//해설https://softeer.ai/class/algotutor/detail.do?id=84
#define ll long long
using namespace std;
int n;
ll b;
//<컴퓨터성능,컴퓨터갯수>
unordered_map<int, int> arr;

bool judge(ll m) {
	ll sum = 0;
	for (auto i:arr)
	{
		int key = i.first;
		int val = i.second;
		if (m - key > 0)
		{
			ll diff = (m - key);
			sum += (diff * diff * val);
			if (sum > b)
				return true;
		}
		
	}
	return sum > b;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> b;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		auto search = arr.find(t);
		if (search == arr.end())
			arr[t] = 1;
		else
			arr[t]+=1;
	
	}
	
	
	ll l = 1;
	ll r = 2e9;
	int result = 0;
	while (l <= r)
	{
		ll m = (l + r) / 2;
		if (judge(m))
		{
			r = m - 1;
		}
		else {
			l = m + 1;
			result = m;
		}

	}
	cout << result;
	return 0;
}
