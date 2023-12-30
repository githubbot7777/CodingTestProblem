//programmers.co.kr/learn/courses/30/lessons/43164#
#include <bits/stdc++.h>

using namespace std;

vector<string> answer;
vector<bool> visited;
bool check=false;
void dfs(string cur, int cnt, vector<vector<string>>&t)
{
   if(cnt==t.size())
   {
       check=true;
   }
   answer.push_back(cur);
    
   for(int i=0;i<t.size();i++){
       string fr=t[i][0];
       string to=t[i][1];
       
       if(!visited[i]&&fr==cur)
       {
            visited[i]=true; 
            dfs(to,cnt+1,t);
           
          if(!check)
         {
           answer.pop_back();
           visited[i]=false;
         }
           
       }     
   }
}


vector<string> solution(vector<vector<string>> tickets) {
    for(int i=0;i<tickets.size();i++)
        visited.push_back(false);
   
    sort(tickets.begin(),tickets.end());
   
   dfs("ICN",0,tickets);
   
    return answer;
}
