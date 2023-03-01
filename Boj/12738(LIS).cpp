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
	  LIS�� ���̸� �����ϴ� �ִ� ���� �̸� ������ ���´�.
      d[i] �� LIS�� ���̰� i�� �ּ� ���Ҷ�� ��������.
      ���� ��� d[3] = 6 �̶�� ���� LIS ����3�� �����ϴ� ������ ���� �� ���� ���� ���Ұ� 6�̶�� ���̴�.
	 */
	 vector<int> d(n, 1);
	 // ���� ���� ����
	 int maxLength = 1;
	 d[0] = arr[0];
	 for (int i = 1; i < n; i++) {
		 int left = 0;
		 int right = maxLength - 1;
		 // �̺� Ž������ ���Ұ� �� ��ġ�� ã�´�.
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
       // left�� ��ġ�� ��� �� ����,
	   // ��ġ���� �ʴ� ��� Ž�� ���Һ��� ū ���� ���� ���� ���� �ε����̴�.
		 d[left] = arr[i];

		 // left+1�� �ϴ� ������ �ε����� 0���� �����ϱ� ������
		 // �ε��� left������ ������ left+1�� �ȴ�.
		 maxLength = max(maxLength, left + 1);
	 }
	
	 cout << maxLength;
	 
	 return 0;
}