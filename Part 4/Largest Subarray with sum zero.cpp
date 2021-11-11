// PROBLEM :- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// GFG | EASY | ARRAY - PREFIX + HASHING

// Solution :- T.C. O(N) , S.C. O(N)

// Intuition -> Array Sum from (I to J) = Array Sum from (0 to J) - Array Sum from (0 to I)
// Based on this, traverse and calculate prefix sum and where prefix comes equal, compare the length between both the index.
// Store the earliest fetched prefix sum index in the hashmap.

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        
        unordered_map<int, int> mp; // <prefix_sum, index>
        int pref = 0;
        int ans = 0;
        
        mp[0] = -1;
        
        for(int i = 0 ; i < n ; i++){
            pref += A[i];
            if(mp.count(pref) == 1){
                int len = i - mp[pref];
                ans = max(ans, len);
            }else{
                mp[pref] = i;
            }
        }
        
        return ans;
        
    }
};