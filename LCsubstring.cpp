#include <bits/stdc++.h>
using namespace std;
int LCSsubstr(char X[], char Y[], int m, int n)
{
    int LCsuff[m + 1][n + 1];
    int result = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                LCsuff[i][j] = 0;
            }
            else
            {
                if (X[i - 1] == Y[j - 1])
                {
                    LCsuff[i][j] = LCsuff[i - 1][j - 1] + 1;
                    result = max(result, LCsuff[i][j]);
                }
                else
                {
                    LCsuff[i][j] = 0;
                }
            }
        }
    }
    return result;
}
int main()
{
    char X[] = "abcOldsite";
    char Y[] = "abcNewsite";
    int m = strlen(X);
    int n = strlen(Y);
    cout << "Length of longest common substring is " << LCSsubstr(X, Y, m, n);
    return 0;
}