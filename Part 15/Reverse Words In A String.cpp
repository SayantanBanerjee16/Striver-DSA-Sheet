// PROBLEM :- https://leetcode.com/problems/reverse-words-in-a-string/

// LEETCODE | MEDIUM | STRINGS, TWO POINTERS

// Solution 1 :- T.C. O(N) S.C. O(N)
// Extract each word separately, reverse it and put them in another output string.

// Solution 2 :- T.C. O(N) S.C. O(1) -> IN PLACE

// Take input sentence as -> "       I    AM A HERO  "
// Reverse whole sentence -> "  OREH A MA    I       "
// Then reverse each word -> "  HERO A AM    I       "
// Use 2 pointer approach to reverse whole sentence & words in place.

// How to take care of extra space in between and either sides?
// Again use 2 pointer approch to left-shift each characters to the leftside of string wherever possible.
// so      "  HERO A AM    I       "
// becomes "HERO A AM I            "
// Now return the substring upto wherever the final string is present. 
// (Alternative of this is to resize the string upto that many places, and return the final string.)
// Ans :- "HERO A AM I" 


class Solution {
public:
    
    void reverse(string &str, int left, int right){
        while(left < right){
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }
    }
    
    
    string reverseWords(string str) {
        
        int N = str.length();
            
        int left = 0;
        int right = str.length() - 1;
        
        reverse(str, left, right);
        
        left = 0;
        for(int i = 0 ; i < N ; i++){
            if(str[i] == ' '){
                int right = i - 1;
                if(left < right){
                    reverse(str, left, right);
                }
                left = i + 1;
            }
        }
        
        right = N - 1;
        if(left < right){
            reverse(str, left, right);
        }
        
        int replacePtr = 0;
        bool wordBefore = false;
        
        for(int i = 0 ; i < N ; i++){
            if(str[i] != ' '){
                wordBefore = true;
                str[replacePtr] = str[i];
                replacePtr++;
            }else{
                if(wordBefore){
                    str[replacePtr] = str[i];
                    replacePtr++; 
                    wordBefore = false;
                }
            }
        }
        
        if(str[replacePtr - 1] == ' ')
            return str.substr(0, replacePtr - 1);
        else
            return str.substr(0, replacePtr);
        
    }
};