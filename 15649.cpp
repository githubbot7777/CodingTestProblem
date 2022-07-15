
//문제 n과 m 
#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    
    for(int i = 1; i <= n; i++){ // 1부터 n까지의 수에 대해
    if(!isused[i]){ // 아직 i가 사용되지 않았으면
      arr[k] = i; // k번째 수를 i로 정함
      isused[i] = 1; // i를 사용되었다고 표시
      func(k+1); // 다음 수를 정하러 한 단계 더 들어감
      isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
        }
    }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}
