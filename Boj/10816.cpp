/*
https://www.acmicpc.net/problem/10816
*/


#include <bits/stdc++.h>

using namespace std;

/*
binary search를 변형해서 배열에서 찾는 숫자 몇개있는지 출력 해야 하기때문에
찾는 숫자의 맨 왼쪽 index 와 맨 오른쪽 index 를 찾아 빼준다.
*/

int arr1[500002];
int n,m;
int lower_index(int find, int len)
{
    int st = 0;
    int en = len;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr1[mid] >= find)
        {
            en = mid;
        }
        else {
            st = mid + 1;
        }
    }

    return st;
}

int upper_index(int find, int len)
{
    int st = 0;
    int en = len;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr1[mid] > find)en = mid;
        else st = mid + 1;
    }

    return st;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cin >> m;

    sort(arr1, arr1 + n);
    while (m--)
    {
        int temp;
        cin >> temp;
        cout << upper_index(temp, n) - lower_index(temp, n) << " ";
      //cout<<upper_bound(a,a+n,t)-lower_bound(a,a+n,t)<<" ";
      //동일한 역활을하는 stl 함수 존재

    }
   
        return 0;
}



