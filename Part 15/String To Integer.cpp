// PROBLEM :- https://leetcode.com/problems/string-to-integer-atoi/

// LEETCODE | MEDIUM | STRING MANIPULATION

// Solution : T.C. O(N), S.C. O(1)
// Implement as it says. Take care of all types of edge cases.

class Solution {
public:
    int myAtoi(string s) {
        using ll = long long;
        
        ll indexStart = -1;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != ' '){
                indexStart = i;
                break;
            }
        }
        
        if(indexStart == -1){ // edge case -> all white spaces
            return 0;
        }
        
        ll sign = 1; // positive or negative value
        if(s[indexStart] == '-'){
            indexStart++;
            sign = -1;
        }else if(s[indexStart] == '+'){
            indexStart++;
        }
        
        // once sign fixed, traverse and check for valid digits. 
        // If digit found, form the integer, also take care integer overflow.
        // Not a digit, return.
        
        ll value = 0; 
        for(int i = indexStart ; i < s.length() ; i++){
            if(!(s[i] >= '0' && s[i] <= '9')){
                return value * sign;
            }else{
                value *= 10;
                value += (s[i] - '0');
                if(sign == 1 && value > INT_MAX)
                    return INT_MAX;
                if(sign == -1 && (value * -1) < INT_MIN){
                    return INT_MIN;
                }
            }
        }
        
        return sign * value;
        
    }
};