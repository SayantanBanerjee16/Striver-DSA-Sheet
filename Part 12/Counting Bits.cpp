// PROBLEM :- https://leetcode.com/problems/counting-bits/

// LEETCODE | EASY | BITS

// Solution 1 :- T.C. O(Nlog(N)) S.C. O(1) -> log(N) -> number of bits in the number. 

// Traverse through all numbers, and check for count no of bits set in each number.
// Solution involved Builtin functions of GCC compiler

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i = 0 ; i <= n ; i++){
            int no_of_bits_set_in_current_number = __builtin_popcount(i);
            ans.push_back(no_of_bits_set_in_current_number);
        }
        
        return ans;
    }
};

// Solution 2 :- T.C. O(N) S.C. O(1)

// Observe
// 0 : 000
// 1 : 001
// 2 : 010
// 3 : 011
// 4 : 100
// 5 : 101

// Find 6 -> In 6 remove the MSB equivalence number (here 4) , leftover is 2. 
// Find 13 -> In 13 remove the MSB equivalence number (here 8) , leftover is 5.

// Thus use DP to formulate the current number bits count.

// Note :- Any number power of 2, bits count is 1.
//         Any general number MSB equivalence number is EQUAL to the greatest power of 2 less than that number.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        dp.push_back(0);
        
        int lastPowerOfTwo = -1;
        
        for(int i = 1 ; i <= n ; i++){
            if((i & (i - 1)) == 0){
                lastPowerOfTwo = i;
                dp.push_back(1);
            }else{
                dp.push_back(dp[i - lastPowerOfTwo] + 1);
            }
        }
        
        return dp;
    }
};