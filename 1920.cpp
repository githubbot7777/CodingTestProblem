/*

*/


#include <bits/stdc++.h>

using namespace std;

/*
binary_search stl �����Ѵ�
�־��� �������� ���Ұ� ����ִ��� ���θ� O(lg N)�� true Ȥ�� false�� �˷��ش�.
������������ ���ĵǾ� �־���Ѵ�.
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



