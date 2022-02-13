// PROBLEM :- https://www.codingninjas.com/codestudio/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// CODE STUDIO | MEDIUM | DP - KNAPSACK

// Solution :- T.C. O(N * W) S.C. O(N * W)

// For each item, see if you can take that item. [value of that item + knapsack(N - 1, remaining weight)]
// Or else discard that item, [knapsack(N - 1, weight)]
// Now for current position and weight, take the maximum out of the two cases.

// Solve it recursively with memorization and later convert that into a tabular method.

int maxProfit(vector<int> &values, vector<int> &weights, int N, int W)
{
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= W ; j++){
            if(weights[i - 1] <= j){
                dp[i][j] = max(dp[i - 1][j] , values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[N][W];
}