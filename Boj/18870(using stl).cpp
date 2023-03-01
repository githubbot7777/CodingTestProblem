/*
https://www.acmicpc.net/problem/18870
*/


#include <bits/stdc++.h>

using namespace std;

/*
[2,4,-10,4,-9] 나보다 작은수가 몇개 있는지?
1. 정렬
2. 중복제거
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
    //unique()는 배열 뒷쪽에 중복된값을 한번에 모아두고 그 쓰레기값 시작점의 포인터를 반환한다 
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    
    //lower_bound()는 찾는값의 첫번째로 나오는 지점의 포인터 반환 
    for (int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
   
        return 0;
}



