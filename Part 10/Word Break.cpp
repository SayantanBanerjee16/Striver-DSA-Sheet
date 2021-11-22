// PROBLEM :- https://leetcode.com/problems/word-break/

// LEETCODE | MEDIUM | DP / BACKTRACKING (TLE)

// Solution 1 :- Backtracking (TLE due to high constraints in Leetcode)

// Linearly build up start word from the dictionary, and recursively check same from the rest.
// suppose catlovesme -> cat + lovesme. After we got that 'cat' is a word in dictionary, recursively find the rest if it can break into dictionary words.

class Solution {
public:
    
    unordered_set<string> uset;
    
    int length;
    string S;
    bool output = false;
    
    void recurse(int pos){
        if(output)
            return;
        
        string cur = "";
        for(int i = pos; i < length ; i++){
            cur += S[i];
            if(uset.count(cur) == 1){
                if(i + 1 == length){
                    output = true;
                    break;
                }else{
                    recurse(i + 1);
                }
            }
        }
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        output = false;
        S = s;
        length = s.length();
        
        uset.clear();
        for(int i = 0 ; i < wordDict.size() ; i++){
            uset.insert(wordDict[i]);
        }
        
        recurse(0);
        
        return output;
    }
};

// Solution 2 :- DP T.C. O(N^3) S.C. O(N^2)

// Lets say you have a partial string LOVECATS from a bigger string to deal with
// try to break it in each point. If both parts contributes to valid word or part of another sentence, then this sentence is also a valid one.
// this subproblem would already be took care in DP table. Use those to calculate this one.

// How??
// build up a DP matrix where Row -> start index and Col -> ending index
// dp(i, j) -> from index i of string to index j. Thus string with length (j - i + 1)
// dp(i, j) -> stores true if sentence can be broken. Else false.

// so first calculate all substrings of length 1 from each start location, then length 2 of each start locations,....and length N from 0th location.

// To calculate dp(i, j) -> it comprise of substring[i..j]
//                       -> divide the string in 2 parts at all the locations.
//                       -> simulate the sub-problem substring[i..k] and substring[k+1..j]
//                       -> use their already computed DP value from the table.
//                       -> Both part TRUE, then current sentence TRUE and continue.

// Ans -> DP[0][N - 1]


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // insert into set
        unordered_set<string> dictionary;
        for(int i = 0 ; i < wordDict.size() ; i++){
            dictionary.insert(wordDict[i]);
        }
        
        int n = s.length();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int len = 1 ; len <= n ; len++){
            for(int start = 0 ; start < n + 1 - len ; start++){
                
                string cur = s.substr(start, len);
                if(dictionary.count(cur) == 1){
                    dp[start][start + len - 1] = true;
                    continue;
                }
                
                int firstPartStart = start;
                int firstPartLength = 1;
                
                int secondPartStart = start + 1;
                int secondPartLength = cur.length() - 1;
                
                
                while(secondPartLength != 0){
                    if(dp[firstPartStart][firstPartStart + firstPartLength - 1] && dp[secondPartStart][secondPartStart + secondPartLength - 1]){
                        dp[start][start + len - 1] = true;
                        break;
                    }
                    firstPartLength++;
                    secondPartStart++;
                    secondPartLength--;
                    
                }
                
                
            }
        }
        
        return dp[0][n - 1];
    }
};