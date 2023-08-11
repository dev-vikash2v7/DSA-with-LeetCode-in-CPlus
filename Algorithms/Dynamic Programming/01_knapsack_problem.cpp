// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else 
                K[i][w] = max(val[i-1]  + K[i - 1][w - wt[i-1]]  ,  K[i - 1][w]);
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                                  + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    return K[n][W];
}

// OPTIMISED KNAPSACK -  SPACE-COMPLEXITY O(2*W)

// Driver Code
int main()
{
	int profit[] = { 10,15,40 };
	int weight[] = {1,2,3 };
	// int profit[] = { 60, 100, 120 };
	// int weight[] = {10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);

	cout << knapSack(W, weight, profit, n);

	return 0;
}

// This code was improved by Udit Singla
