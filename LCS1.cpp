#include <bits/stdc++.h>
using namespace std;
/* memoized code for LCS */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int LCS(char X[], char Y[], int m, int n, vector<vector<int>> &dp)
{
    if (m == 1 || n == 1)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (X[m - 1] == Y[n - 1])
    {
        return dp[m][n] = 1 + LCS(X, Y, m - 1, n - 1, dp);
    }
    else
    {
        return dp[m][n] = max(LCS(X, Y, m, n - 1, dp), LCS(X, Y, m - 1, n, dp));
    }
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << "length of LCS is " << LCS(X, Y, m, n, dp);

    return 0;
}