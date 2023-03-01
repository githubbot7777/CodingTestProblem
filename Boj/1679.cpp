/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
int n,k;
int m[100002];
queue<int> q;
int main()
{
    cin>>n>>k;
    fill(m,m+100001,-1);
    
    q.push(n);
    m[n]=0;
   
    while(m[k]==-1)
    {
        int cur=q.front();
        q.pop();
      
        
        for(int nxt:{cur-1,cur+1,cur*2})
        {
            if(nxt<0||nxt>100000)
                continue;
            if(m[nxt]>=0)
                continue;
            
            q.push(nxt);
            m[nxt]=m[cur]+1;
         
    
           
        }
    }
    
    cout<<m[k];

    return 0;
}
