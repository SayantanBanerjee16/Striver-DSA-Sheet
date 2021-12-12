// PROBLEM :- https://leetcode.com/problems/count-and-say/

// LEETCODE | MEDIUM | RECURSION, STRING

// Solution :- T.C. O(2^N) S.C. O(1)

// Form recursively, for every string we need to get the previous string. And then compute the string as described in question.

class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1)
            return "1";
        
        string str = countAndSay(n - 1);
        string cur = "";
        char prev = str[0];
        int cnt = 1;
        for(int i = 1 ; i < str.size() ; i++){
            if(str[i] == prev){
                cnt++;
            }else{
                cur += to_string(cnt);
                cur += prev;
                prev = str[i];
                cnt = 1;
            }
        }
        cur += to_string(cnt);
        cur += prev;
        return cur;
    }
};