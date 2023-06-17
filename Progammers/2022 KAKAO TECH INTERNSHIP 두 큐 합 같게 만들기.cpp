//문제:https://school.programmers.co.kr/learn/courses/30/lessons/118667
//풀이참고:https://a-littlecoding.tistory.com/123

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    ll answer = 0;
    
    ll tot1=0,tot2=0;
    for(int i:queue1)
        tot1+=i;
    for(int i:queue2)
        tot2+=i;
    
    ll total=tot1+tot2;
    if(total%2==1)
        return -1;
    //q1과 q2 배열의 모든 요소를 바꿀때 len(q1)*2 횟수 소요
    //다시 원래대로 돌려 놓으면 len(q1)*2 소요
    ll limit=queue1.size()*4;
    
    list<int> l1(queue1.begin(),queue1.end());
    list<int> l2(queue2.begin(),queue2.end());

    while(1)
    {
        if(tot1<tot2)//점수 높은 곳에서 빼서 낮은곳에 넣기
        {
           ll del=l2.front();
           l2.pop_front();
           l1.push_back(del);
           tot2-=del;
           tot1+=del;
           answer++;
        }else if(tot1>tot2){
           ll del=l1.front();
           l1.pop_front();
           l2.push_back(del);
           tot1-=del;
           tot2+=del;
           answer++;
        }else{
           break;
        }
        
      if(answer==limit)
          return -1;    
    }

    return answer;
}
