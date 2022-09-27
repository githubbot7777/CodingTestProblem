/*

*/


#include <bits/stdc++.h>

using namespace std;

/*
binary_search stl 존재한다
주어진 범위내에 원소가 들어있는지 여부를 O(lg N)에 true 혹은 false로 알려준다.
오름차순으로 정렬되어 있어야한다.
*/

int a[100002];
int n,m;

int search(int num)
{

    int left = 0; 
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] < num)
        {
            left = mid + 1;
        }
        else if (a[mid] > num)
        {
            right = mid - 1;
        }
        else {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;

    sort(a, a + n);
    while (m--)
    {
        int num;
        cin >> num;
       
        cout << binary_search(a,a+n,num) << "\n";
    }
   
        return 0;
}



