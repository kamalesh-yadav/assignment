#include <bits/stdc++.h>
using namespace std;
// n^2 complexity
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsackk(int W, int wt[], int val[], int n)
{
    int i;
    int w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else
            {
                if (wt[i - 1] <= w)
                {
                    K[i][w] = max(val[i - 1] + K[i][w - wt[i - 1]], K[i - 1][w]);
                }
                else
                {
                    K[i][w] = K[i - 1][w];
                }
            }
        }
    }
    return K[n][W];
}

int main()
{
    int val[] = {1,30}; 
    int wt[] = {1,50};
    int W = 100;
    int n = sizeof(val) / sizeof(val[0]);
    cout <<"DP result equal to "<< knapsackk(W, wt, val, n) << endl;
    return 0;
}