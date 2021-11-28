// PROBLEM :- https://leetcode.com/problems/next-greater-element-ii/

// LEETCODE | MEDIUM | STACK

// Solution :- T.C. O(N) and S.C. O(N)

// Logic :- As the given question is of circular mode, concatenate the array next to the original array.
//          Now loop over it.
//          We are keeping track of all the indexes of the array in a STACK whose Next Greater isn't found yet.
//          Lets say at a current position, the element is X.
//          If X is larger than the value of nums at index found in top of stack, then that corresponding position Next Greater is this current element. Approprately update the output array.
// Repeat the process, until stack is emptied or the X is smaller than the value of nums at index found in top of stack.
// At last, insert the current index into the stack.

// Now repeat the whole process greedily.

// Note :- have proper handling with the indexes. 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        nums.resize(2 * n);
        
        for(int i = n ; i < 2 * n ; i++){
            nums[i] = nums[i - n];
        }
        
        stack<int> indexStk;
        
        vector<int> ans(n , -1);
        
        for(int i = 0 ; i < 2 * n ; i++){
            
            int cur = nums[i % n];
            
            while(!indexStk.empty()){
                if(nums[indexStk.top() % n] < cur){
                    ans[indexStk.top() % n] = cur;
                    indexStk.pop();
                }else{
                    break;
                }
            }
            
            indexStk.push(i);
            
        }
        
        return ans;
    }
};