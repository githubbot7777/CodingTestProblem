/*
https://www.acmicpc.net/problem/18870
*/


#include <bits/stdc++.h>

using namespace std;

/*
[2,4,-10,4,-9] ������ �������� � �ִ���?
1. ����
2. �ߺ�����
3. binary_search
*/
int n;
int x[1000005];
vector<int> uni;//unique

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        uni.push_back(x[i]);
    }
    
    sort(uni.begin(), uni.end());
    //unique()�� �迭 ���ʿ� �ߺ��Ȱ��� �ѹ��� ��Ƶΰ� �� �����Ⱚ �������� �����͸� ��ȯ�Ѵ� 
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    
    //lower_bound()�� ã�°��� ù��°�� ������ ������ ������ ��ȯ 
    for (int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
   
        return 0;
}



