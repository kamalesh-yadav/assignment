#include <bits/stdc++.h>
using namespace std;
// dp[n+1][W+1]={-1} using loop.....complexity is O(n^2).
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapsack(int W, int wt[], int val[], int n, int **dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    // Base condition
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n] <= W)
    {
        dp[n][W] = max(val[n] + knapsack(W - wt[n], wt, val, n - 1, dp), 0 + knapsack(W, wt, val, n - 1, dp));
        return dp[n][W];
    }
    else
    {
        dp[n][W] = knapsack(W, wt, val, n - 1, dp);
        return dp[n][W];
    }
    return dp[n][W];
}
int knapsackk(int W,int wt[],int val[],int n)
{
    // double pointer to declare the table dynamically
    int** dp;
    dp=new int*[n];
    // loop to create the table dynamically
    for(int i = 0;i<n ; i++)
    {
        dp[i]=new int[W+1];
    }
    // loop to initially filled the table with -1
    for(int i = 0; i<n ; i++)
    {
        for(int j = 0; j<W+1; j++)
        {
            dp[i][j]=-1;
        }
    }
    return knapsack(W,wt,val,n-1,dp);
}
int main()
{
    int val[] = {60, 100, 120}; // 10+20=160, 20+30=220, 10+30=180
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsackk(W, wt, val, n) << endl;
    return 0;
}