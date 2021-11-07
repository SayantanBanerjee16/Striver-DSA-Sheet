// PROBLEM
// https://leetcode.com/problems/majority-element-ii/

// LEETCODE | MEDIUM | ARRAY |

// Optimized Approach - T.C O(N) S.C O(1)

// Boyer-Moore Voting Algorithm Extended

// The essential concepts is you keep a counter for the majority number X. 
// If you find a number Y that is not X, the current counter should deduce 1. 
// The reason is that if there is 5 X and 4 Y, there would be one (5-4) more X than Y. 
// This could be explained as "4 X being paired out by 4 Y".


// So we can modify the algorithm to maintain two counters for two majorities. 
// But again, the two "most frequent" elements might not be the majorities.
// Over the initial algorithm, we will take care of who might pe candidates as majority elements.
// Lastly, we will loop through to take the actual frequency of both the candidates.
// The answer would be accordingly if frequency > N / 3.


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // Part 1 :- check for two majority candidates
        
        int num1 = 0;
        int count1 = 0;
        int num2 = nums[0];
        int count2 = 1;
        
        for(int i = 1 ; i < nums.size() ; i++){
            if(num1 == nums[i]){
                count1++;
            }else if(num2 == nums[i]){
                count2++;
            }else if(count1 == 0){
                count1 = 1;
                num1 = nums[i];
            }else if(count2 == 0){
                count2 = 1;
                num2 = nums[i];
            }else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        
        // Part 2 :- Check for the candidates actual frequency 
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == num1){
                count1++;
            }else if(nums[i] == num2){
                count2++;
            }
        }
        
        // Part 3 :- Based on the actual frequency, add them to the final ans vector.
        
        vector<int> ans;
        if(count1 > nums.size() / 3){
            ans.push_back(num1);
        }
        if(count2 > nums.size() / 3){
            ans.push_back(num2);
        }
        
        return ans;
    }
};