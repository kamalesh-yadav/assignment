#include <bits/stdc++.h>
using namespace std;
// order of n
int fibbonaci(int n, int arr[])
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main()
{
    int n;
    cout << "Enter the value of n ";
    cin >> n;
    int F[n + 1];
    F[1] = F[2] = 1;
    cout<<fibbonaci(n,F)<<endl;
    return 0;
}