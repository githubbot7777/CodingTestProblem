/*����
N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 20, |S| �� 1,000,000) ��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.

���
ù° �ٿ� ���� S�� �Ǵ� �κм����� ������ ����Ѵ�.*/

#include <bits/stdc++.h>

using namespace std;
int arr[20];
int n,s;
int cnt;

void func(int k,int sum)
{
    if(k==n)
    {
          if(sum==s)
          {
                cnt++;
          }
          
            
            return;
    }
 
     
     func(k+1,sum);
     func(k+1,sum+arr[k]);
}

int main()
{
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
   func(0,0);
   
   if(s==0)
    cnt--;
   
   cout<<cnt;
    return 0;
}
