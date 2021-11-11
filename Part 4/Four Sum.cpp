// PROBLEM :- https://leetcode.com/problems/4sum/

// LEETCODE | MEDIUM | ARRAY

// Solution :- T.C :- O(N^3) S.C :- cant_understand

// Logic :- Find 2 sum in sorted array in O(N). Then two outer loops to make it 4 sum.


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        set<vector<int>> tempSet;
        
        if(nums.size() <= 3){
            return ans;
        }
        
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() - 3; i++){
            for(int j = i + 1 ; j < nums.size() - 2 ; j++){
                
                int fetched = nums[i] + nums[j];
                int left = target - fetched;
                
                int low = j + 1;
                int high = nums.size() - 1;
                
                while(low < high){
                    if(left == nums[low] + nums[high]){
                        vector<int> temp = {nums[i], nums[j], nums[low], nums[high]};
                        sort(temp.begin(), temp.end());
                        tempSet.insert(temp);
                        low++;
                        high--;
                    }else if(left > nums[low] + nums[high]){
                        low++;
                    }else{
                        high--;
                    }
                }
                
                
            }
        }
        
        for(auto itr : tempSet){
            ans.push_back(itr);
        }
        
        return ans;
        
    }
};