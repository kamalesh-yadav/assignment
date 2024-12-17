#include <bits/stdc++.h>
using namespace std;
/*Recursive code for LCS .....LCS statement is given two string and we have to
find longest subsequent.*/
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int LCS(char X[], char Y[], int n, int m)
{
    /*Base case*/
    if (n == 0 || m == 0)
    {
        return 0;
    }
    else
    {
        if (X[n - 1] == Y[m - 1])
        {
            return 1 + LCS(X, Y, n - 1, m - 1);
        }
        else
        {
            return max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
        }
    }
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int n = strlen(X);
    int m = strlen(Y);

    cout << "Length of longest subsequent : " << LCS(X, Y, n, m);
    return 0;
}