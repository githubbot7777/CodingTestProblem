/*
문제: https://school.programmers.co.kr/learn/courses/30/lessons/150369?language=cpp
참고: https://school.programmers.co.kr/questions/43364

1. 배달할 물건이나, 회수할 물건이 i번째 까지 존재한다면, 당신은 반드시 i번째 까지는 적어도 한 번은 가야합니다.

2. 한 번 출발하여, 물류창고로 돌아오면, cap만큼의 배달을 수행할 수 있고, cap만큼의 물건을 회수 해 올 수 있습니다.

3. 한 곳에서 택배를 전부 배달하지 못했거나, 회수하지 못했다면, 당신은 물류창고로 돌아왔다가, 다시 같은 장소로 떠나야 합니다.

4. 거꾸로 배열을 탐색한다는 의미는, 이미 방문이 가능한 모든 지점들을 왕복했다는 가정하에 문제를 풀게 됩니다.

5. 트럭이 한 번 떠나게 되면, cap만큼의 물건을 배달할 수 있고, cap만큼의 물건을 회수 할 수 있다.


*/

long long solution(int cap,int n,vector<int> deliveries,vector<int> pickups){
  long long answer=0;
  long long d=0;
  long long p=0;
  
  for(int i=n-1;i>=0;i--)
  {
    int cnt=0;
    d-=deliveries[i];
    p-=pickups[i];
    
    while(d<0||p<0){
      d+=cap;
      p+=cap;
      cnt+=1;
    }
    
    answer+=(i+1)*2*cnt;
  }
  return answer;
}
    
