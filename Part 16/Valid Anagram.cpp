// PROBLEM :- https://leetcode.com/problems/valid-anagram/

// LEETCODE | EASY | STRING

// Solution 1 :- T.C. O(NlogN) S.C. O(1)
// Sort both the strings. If they are same, then they are anagram.

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Solution 2 :- T.C. O(N) S.C. O(N)
// Store the character frequencies of both the strings.
// For first string, increment in the hash-map, and for the second string, decrement in the hash-map.
// Finally for all the keys in the hash-map, all frequencies should be zero.

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> freq;
        for(int i = 0 ; i < s.length() ; i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        
        for(auto itr : freq){
            if(itr.second != 0)
                return false;
        }
        
        return true;
    }
};

// Solution 3 :- T.C. O(N) S.C. O(26 == 1)
// Logic same as before. But instead of using a Hash-Map, 
// Use a vector of 26 places to store the frequency of the given input which consist only lowercase letters.

// NOTE :- Solution 2 is more generalized one.

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        
        if(s.length() != t.length())
            return false;
        
        for(int i=0 ; i < s.length() ; i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        for(int i=0 ; i < 26 ; i++){
            if(freq[i] != 0)
                return false;
        }
        
        return true;
    }
};