// PROBLEM :- https://leetcode.com/problems/palindrome-partitioning/

// LEETCODE | MEDIUM | BIT MASKING / RECURSION

// Solution 1 :- T.C. O(N * 2^N) Aux S.C. O(1) -> RECURSIVE

// At any general start point, check for the next palindromic end point from that start point. 
// If fetched, insert it into current list and recursively call for the remaining part.
// Suppose in ABACDEDC, at ABA we have a palindrome partition, add it to list and call for remaining CDEDC.
// If whole string can be divided as such, insert into the output vector.
// Else if can't be divided, backtrack.

// Solution 2 :- T.C. O(N * 2^N) Aux S.C. O(N) -> ITERATIVE

// In a string of N length. There are N - 1 gaps. 
// Partition the string in these gaps in every way possible.
// How? Use bit masking -> Generate binary of (0 to 2 ^ N-1). 
// In one sequence, let it be 0110001.
// Make a partition at that gap where it gives 1.

// Once for one partition, after we have the partition, divide the string. 
// For string of length 8, with 0110001 masking, divide it as [AB C DEFG H]
// Now check if all the parts are palindromic or not. If yes, add it to output vector.

class Solution {
public:
    
    bool checkPalindrome(string cur){
        int low = 0;
        int high = cur.length() - 1;
        
        while(low < high){
            if(cur[low] != cur[high]){
                return false;
            }
            low++;
            high--;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
            
        int N = s.length();
        int gaps = N - 1;
        
        for(int bitNum = 0 ; bitNum < (1 << gaps) ; bitNum++){
            
            int current = bitNum;
            vector<int> mask(gaps, 0);
            int itr = 1;
            
            for(int j = 0 ; j < gaps ; j++){
                if(itr & current){
                    mask[j] = 1;
                }
                itr = itr << 1;
            }
            
            bool allPalindrome = true;
            
            vector<string> currentPartitioning;
            
            string cur = "";
            cur += s[0];
            
            for(int i = 0 ; i < gaps ; i++){
                if(mask[i] == 1){
                    allPalindrome = allPalindrome & checkPalindrome(cur);
                    currentPartitioning.push_back(cur);
                    cur = "";
                    cur += s[i + 1];
                }else{
                    cur += s[i + 1];
                }
            }
            
            allPalindrome = allPalindrome & checkPalindrome(cur);
            currentPartitioning.push_back(cur);
            
            if(allPalindrome){
                output.push_back(currentPartitioning);
            }
            
            
        }
        
        return output;
        
    }
};