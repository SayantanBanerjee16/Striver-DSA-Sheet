// Problem
// https://leetcode.com/problems/majority-element/

// LEETCODE | EASY | ARRAY

// Brute :- Solution 1 :- T.C O(NlogN) S.C O(1)
//      Sort and return the middle element.

// Better Brute :- Solution 2 :- T.C O(N) S.C O(N)
//      Use hashmap to store the frequency.

// Optimal :- Solution 3 :- T.C O(N) S.C O(1)
//      Use Boyer - Moore Voting Algo
//
//      Intuition - If we had some way of counting instances of the majority element as +1 
//      and instances of any other element as −1, 
//      summing them would make it obvious that the majority element is indeed the majority element.
//
//      Solution - Track CURRENT number and its COUNT occurence.
//      If CURRENT == nums[i], COUNT++
//      Else COUNT--.
//      What if COUNT == 0, then clearly the previously tracked number cannot be the greatest, 
//      knowing till this point. Update CURRENT with nums[i].

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int var = nums[0];
        int varCnt = 1;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(var == nums[i]){
                varCnt++;
            }else{
                varCnt--;
                if(varCnt == 0){
                    var = nums[i];
                    varCnt = 1;
                }
            }
        }
        
        return var;
    }
};