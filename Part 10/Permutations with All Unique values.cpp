// PROBLEM :- https://leetcode.com/problems/permutations/

// LEETCODE | MEDIUM | BACKTRACKING

// Solution :- T.C. and S.C. O(N!) 

// Lets say current array is [1 2 -1 4 -1 6] and current vector lets suppose [3, 5].
// (Why -1? These elements are already processed)
// Recurse at 1 :- call array will be [-1 2 -1 4 -1 6] and current vector [3,5,1] and similarly solve for rest permutations recursively.
// Once done, while backtracking, change the call array to [1 2 -1 4 -1 6] and current vector to initial [3,5].
// Simulate a recursive backtracking logic similarly.

// When to end recursive calls? 
// When at one iteration we have used up all the array elements.

class Solution {
public:
    
    void recurse(int used, int N, vector<int>& nums, vector<int>& current, vector<vector<int>> &output){
        if(used == N){
            output.push_back(current);
            return;
        }
        
        for(int i = 0 ; i < N ; i++){
            if(nums[i] != -1){
                int temp = nums[i];
                current.push_back(nums[i]);
                nums[i] = -1;
                
                recurse(used + 1, N, nums, current, output);
                
                current.pop_back();
                nums[i] = temp;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> output;
        vector<int> current;
        int N = nums.size();
        int used = 0;
        recurse(0, N, nums, current, output);
        cout<<call<<endl;
        return output;
        
    }
};