// PROBLEM :- https://leetcode.com/problems/longest-consecutive-sequence/

// LEETCODE | MEDIUM | HASH-SET

// Solution 1 :- T.C. O(NlogN) S.C. O(1)
//      Brute -> Simply sort the array. Traverse it and find the max consecutive length.

// Solution 2 :- T.C. O(N) S.C. O(N)
//      Use Hash-set effectively. 
//      First convert the given array into a hash-set.

//      Start from a given position of the set, lets call X.
//      Now traverse upward and downward from X, i.e X + 1, X + 2,... and X - 1, X - 2 
//      Traverse upward until the element is present in the set. Else break it. Similarly downward.
//      Likewise, we will get a consecutive groups.

//      While traversing, delete the traversed elements from the set.
//      Note down the length of the current consecutive group.
//      Lastly, repeat this process until all elements are exhausted from the set.

//      NOTE :- Though it looks nested, we are processing all elements only once. So runtime O(N).

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> values;
        int maxLCS = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            values.insert(nums[i]);
        }
        
        while(!values.empty()){
            
            int cur = *values.begin();
            values.erase(cur);
            int curLen = 1;
            
            // check up from cur
            int itr = cur + 1;
            while(!values.empty()){
                if(values.find(itr) != values.end()){
                    curLen++;
                    itr++;
                    values.erase(cur);
                }else{
                    break;
                }
            }
            
            // check down from cur
            itr = cur - 1;
            while(!values.empty()){
                if(values.find(itr) != values.end()){
                    curLen++;
                    itr--;
                    values.erase(cur);
                }else{
                    break;
                }
            }
            
            
            maxLCS = max(maxLCS, curLen);
        }
        
        return maxLCS;
        
    }
};