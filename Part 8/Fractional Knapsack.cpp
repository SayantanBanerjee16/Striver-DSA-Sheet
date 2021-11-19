// PROBLEM :- https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// GFG | MEDIUM | GREEDY

// Solution :- T.C. O(NlogN) S.C. O(1)

// Solution :- Sort the array in accordance to the maximum value per weight accordance.
//	       Choose the knapsack greedily with the highest value per weight.
//             If total knapsack can be included, take it.
//             if not, take how much it is possible. And break from the loop.

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, [](Item &i1, Item &i2){
            double val1 = (i1.value * 1.0) / i1.weight;
            double val2 = (i2.value * 1.0) / i2.weight;
            return val1 < val2;
        });
        
        double ans = 0;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if(W >= arr[i].weight){
                ans += arr[i].value;
                W -= arr[i].weight;
            }else{
                 double val = (arr[i].value * 1.0) / arr[i].weight;
                 ans += val * W;
                 break;
            }
        }
        
        return ans;
    }
        
};