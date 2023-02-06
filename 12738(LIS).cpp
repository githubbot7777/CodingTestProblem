#include<bits/stdc++.h>
//https://www.acmicpc.net/problem/12738
using namespace std;



int n;
int arr[1000002];


 int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cin >> n;
	 for (int i = 0; i < n; i++)
		 cin >> arr[i];
	 /*
	  LIS의 길이를 만족하는 최대 값을 미리 저장해 놓는다.
      d[i] 는 LIS의 길이가 i인 최소 원소라고 정의하자.
      예를 들어 d[3] = 6 이라는 것은 LIS 길이3을 만족하는 마지막 원소 중 가장 작은 원소가 6이라는 것이다.
	 */
	 vector<int> d(n, 1);
	 // 최장 길이 저장
	 int maxLength = 1;
	 d[0] = arr[0];
	 for (int i = 1; i < n; i++) {
		 int left = 0;
		 int right = maxLength - 1;
		 // 이분 탐색으로 원소가 들어갈 위치를 찾는다.
		 while (left <= right) {
			 int mid = (left + right) / 2;
			 if (d[mid] == arr[i])
			 {
				 left = mid;
				 break;
			 }
			 else if (d[mid] < arr[i]) {
				 left = mid + 1;
			 }
			 else
				 right = mid - 1;
		 }
       // left는 일치한 경우 그 값을,
	   // 일치하지 않는 경우 탐색 원소보다 큰 값중 가장 작은 값의 인덱스이다.
		 d[left] = arr[i];

		 // left+1을 하는 이유는 인덱스가 0부터 시작하기 때문에
		 // 인덱스 left까지의 개수는 left+1이 된다.
		 maxLength = max(maxLength, left + 1);
	 }
	
	 cout << maxLength;
	 
	 return 0;
}