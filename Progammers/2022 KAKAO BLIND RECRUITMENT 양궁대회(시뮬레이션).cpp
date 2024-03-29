#include <bits/stdc++.h>

using namespace std;
// a가 b보다 더 좋은 배치일 경우 true
bool cmp(vector<int>& a,vector<int>& b){
    for(int i=11;i>=0;i--)
        if(a[i]!=b[i])return a[i]>b[i];
    return false;
}

vector<int> solution(int n, vector<int> info) {
  //라이언이 가장 큰 점수 차이로 우승 할 수 있는 결과를 저장
  //ret[0..10] : 10-i점에서 라이언이 맞힌 화살의 수, ret[11] : 점수 차이
    vector<int> ret(12,-1);
    vector<int> brute(n+10); //중복 조합을 위한 값(칸막이 : 1)
    fill(brute.begin()+n,brute.end(),1);//10개의 칸막이를 배치
    do{
        //arrow[0..10]에 중복 조합의 결과 저장
        vector<int> arrow;//ret과 같은 형식
        int before=-1;
        for(int i=0;i<n+10;i++){
            if(brute[i]){
                arrow.push_back(i-before-1);
                before=i;
            }
        }
        arrow.push_back(n+10-before-1);
        int score=0;
        for(int i=0;i<=10;i++){
            if(arrow[i]>info[i])
                score+=(10-i);
            else if(info[i]!=0)
                score-=(10-i);
        }
        if(score<=0)continue;
        arrow.push_back(score);
        if(cmp(arrow,ret)) ret=arrow;
        
    }while(next_permutation(brute.begin(),brute.end()));
    if(ret[0]==-1)return vector<int>({-1});
    ret.pop_back();

    return ret;
}
