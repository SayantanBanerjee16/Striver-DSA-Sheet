// PROBLEM :- https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

// GFG | MEDIUM | GREEDY, HEAP, DISJOINT SET

// Solution 1:- T.C. O(N * DAYS) S.C O(N)

// Sort through the jobs in decending order of their profit.
// Choose ith job, and place it at the first unused day from DAY deadline until DAY 1.

class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, [](Job &j1, Job &j2){
            return j1.profit > j2.profit;
        });
        
        vector<bool> daysUsed(101, false);
        
        int ansProfit = 0;
        int jobsUsed = 0;
        
        for(int i = 0 ; i < n ; i++){
            int deadline = arr[i].dead;
            int profit = arr[i].profit;
            for(int j = deadline ; j >= 1 ; j--){
                if(daysUsed[j] == false){
                    daysUsed[j] = true;
                    ansProfit += profit;
                    jobsUsed++;
                    break;
                }
            }
        }
        
        return {jobsUsed, ansProfit};
        
    } 
};

// Solution 2 :- Using Disjoing Set. T.C. O(NlogN) S.C O(N)
// https://www.cdn.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/