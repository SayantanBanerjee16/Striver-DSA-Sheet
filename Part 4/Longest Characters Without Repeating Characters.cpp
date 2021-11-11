// PROBLEM :- https://leetcode.com/problems/longest-substring-without-repeating-characters/solution/

// LEETCODE | MEDIUM | SLIDING WINDOW + HASHING

// Solution 1 :- T.C. O(N) -> 2 pass S.C. O(1)

// Approch :- Mantain a sliding window through 2 pointers marking the boundaries.
//      Also keep the track of the characters in the sliding window in a set.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        int low = 0;
        int high = -1;
        
        unordered_set<char> uset;
        
        for(int i = 0 ; i < s.length() ; i++){
            
            high++;
            char ch = s[i];
            
            if(uset.count(ch) == 1){
                while(low < high){
                    if(s[low] == ch){
                        low++;
                        break;
                    }else{
                        low++;
                    }
                }
            }
            
            uset.insert(ch);
            
            ans = max(ans, high - low + 1);
            
        }
        
        return ans;
        
    }
};

// Solution 2 :- T.C. O(N) -> 1 pass S.C. O(1)

// Approch :- Mantain a sliding window through 2 pointers marking the boundaries.
//      Instead of a set marking the characters in a window, use a map which holds the index of a character.
//      Whenever a duplicate appears, jump to the next of the index of the duplicated character.
//      Note :- jump only when the duplicated is present inside the current window.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        int low = 0;
        int high = -1;
        
        unordered_map<char, int> mp;
        
        for(int i = 0 ; i < s.length() ; i++){
            
            high++;
            char ch = s[i];
            
            if(mp.count(ch) == 1){
                
                int index = mp[ch];
                
                if(index >= low && index <= high)
                    low = mp[ch] + 1;
            }
            
            mp[ch] = i;
            
            ans = max(ans, high - low + 1);
            
        }
        
        return ans;
        
    }
};