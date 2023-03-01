
#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/15732
//설명 https://dlwnsdud205.tistory.com/178


using namespace std;


int n, k, d, fr, to, gap;
vector<tuple<int, int, int>> l;
bool judge(int m) {
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		int f, t, g;
		tie(f,t,g) = l[i];
		if (f <= m) {
			sum += ((min(t, m) - f) / g) + 1;
		}	
	}
	return sum>=d;
}


 int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 
	 cin >> n >> k >> d;
	 for(int i=0;i<k;i++)
	 {
		 cin >> fr >> to >> gap;
		 l.push_back({fr,to,gap});
	 }
	 
	 int l=1, h=n;
	 while (l <= h)
	 {
		
		 int m = (l + h+1) / 2;
		 if (judge(m))
			 h = m-1;
		 else
			 l = m + 1;

	 }
	
	 cout << l;
	 return 0;
}


