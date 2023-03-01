//https://www.acmicpc.net/problem/18808
#include <bits/stdc++.h>

using namespace std;
int n,m; //노트북 세로 가로 
int k; //스티커 개수
int r,c; //모눈종이 행의 개수 열의 개개수
int notebook[42][42];
int sticker[12][12];
int result;


void print_notebook()
{
     cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<notebook[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void print_sticker()
{
     cout<<"\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<sticker[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void rotate(int row,int column)
{
    int temp[12][12]={0,};
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            temp[j][row-1-i]=sticker[i][j];
        }
    }
    
    memcpy(sticker,temp,sizeof(temp));
    
    swap(r,c);
}

bool sticker_match(int r_offset,int c_offset)
{
    for(int l=0;l<r;l++)//스티커 노트북에 매칭
   {
     for(int m=0;m<c;m++)
    {
        if(sticker[l][m]==1&&notebook[l+r_offset][m+c_offset]==1)
           return false;
     }
  }
  
  return true;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
 cin>>n>>m>>k;
  for(int i=0;i<k;i++)
  {
      cin>>r>>c;
     
        memset(sticker,0,sizeof(sticker));
          
            for(int j=0;j<r;j++)
               for(int k=0;k<c;k++)
                    cin>>sticker[j][k];
                    
          // print_sticker();
                    
      for(int t=0;t<4;t++)
      {
          
            int r_offset=n-r;
            int c_offset=m-c;
            
            int r_offset_y=0;
            int c_offset_y=0;
            
            bool judge=true;
            
            if(r_offset<0||c_offset<0)
            {
               
                 rotate(r,c);
                 continue;
            }
            
            for(int j=0;j<=r_offset;j++)
            {
                for(int k=0;k<=c_offset;k++)
                {
                   judge=sticker_match(j,k);
                   if(judge==true)
                   {
                         r_offset_y=j;
                         c_offset_y=k;
                         //cout<<"offset"<<j<<" "<<k<<"\n";
                         break;
                   }
                 
                }
                if(judge==true)
                    break;
                
                  
            }
            
            if(judge==false)
            {
              
                 rotate(r,c);
            }
            
            else{
                 for(int j=0;j<r;j++)
                 {
                     for(int k=0;k<c;k++)
                     {
                         if(sticker[j][k]==1)
                         notebook[j+r_offset_y][k+c_offset_y]=sticker[j][k];
                     }
                 }
                    
                    break;
                      
            }
            
      }
      
      //print_notebook();
     
    //print_sticker();

  }
 
 
   for(int j=0;j<n;j++)
      {
           for(int k=0;k<m;k++)
             {
                 if(notebook[j][k]==1)
                   result++;
             }
      }
    cout<<result;   
  

    return 0;
}
