// PROBLEM :- https://leetcode.com/problems/longest-common-prefix/

// LEETCODE | EASY | STRINGS

// NOTE :- THE OPTIMIZED ALGO OF THIS PROBLEM INVOLVES "TRIE." BUT THAT IS KEPT UNDER FUTURE TASK.

// Solution :- T.C. O(No Of Words * Min length of all words) S.C. O(1)
// Scan vertically and return the longest common prefix. Break whenever the same character doesn't matches in all strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minLen = strs[0].length();
        
        for(int i = 1 ; i < strs.size() ; i++){
            minLen = min(minLen, (int)strs[i].length());
        }
        
        string lcp = "";
        
        for(int i = 0 ; i < minLen ; i++){
            bool problematic = false;
            char ch = strs[0][i];
            for(int j = 1 ; j < strs.size() ; j++){
                if(ch != strs[j][i]){
                    problematic = true;
                    break;
                }
            }
            if(!problematic){
                lcp += ch;
            }else{
                break;
            }
        }
        
        return lcp;
        
    }
};