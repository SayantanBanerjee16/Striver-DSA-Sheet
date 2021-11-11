// PROBLEM :- https://leetcode.com/problems/3sum/

// LEETCODE | MEDIUM | ARRAY

// Solution :- T.C :- O(N^2) S.C :- cant_understand

// Logic :- Find 2 sum in sorted array in O(N). Then one outer loops to make it 3 sum.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        set<vector<int>> tempSet;
        
        if(nums.size() <= 2){
            return ans;
        }
        
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() - 2; i++){
        
            int left = -1 * nums[i];

            int low = i + 1;
            int high = nums.size() - 1;

            while(low < high){
                if(left == nums[low] + nums[high]){
                    vector<int> temp = {nums[i], nums[low], nums[high]};
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
        
        for(auto itr : tempSet){
            ans.push_back(itr);
        }
        
        return ans;
        
    }
};