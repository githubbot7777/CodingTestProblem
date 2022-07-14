

#include <bits/stdc++.h>

using namespace std;


void hanoi(int n,int from,int to)
{
   
    if(n==1)
    {
        cout<<from<<" "<<to<<"\n";
        return;
    }
    
    
    hanoi(n-1,from,6-(from+to));
    cout<<from<<" "<<to<<"\n";
   
    hanoi(n-1,6-(from+to),to);
    
}

int main()
{
    int n;
    
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    hanoi(n,1,3);

    return 0;
}
