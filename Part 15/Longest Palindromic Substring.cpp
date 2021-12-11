// PROBLEM :- https://leetcode.com/problems/longest-palindromic-substring/

// LEETCODE | MEDIUM | STRING, EXPANSION THROUGH CENTER

// Optimized Solution:- T.C. O(N^2) S.C. O(1)

// Solution :- Lets say a part of substring ABA is palindrome. We need to get a bigger palindrome!!
//             Check in both neighbours of _ABA_. If they satisfy to be palindrome, store it, nd repeat. Else break.

// What's the starting point? 
// Start from each array position, and go on checking either side. [For ODD length palindrome]
// Also we can start from middle of each array position, and go on checking either side. [For EVEN length palindrome]

// Store maxPalindromicLength after each iteration and also the start index of where the curPalindromicLength is greater than  maxPalindromicLength. Using the START INDEX and total max length, we can get the required answer.

class Solution {
public:
    
    void findExpansionPalindromic(string &str, int left, int right, int N, int &maxPalindromicLength, int &startIndex){
        
        int curPalindromicLength = 0;
        while(left >= 0 && right < N){
            if(str[left] != str[right]){
                break;
            }
            if(left == right){
                curPalindromicLength++;
            }else{
                curPalindromicLength+=2;
            }
            left--;
            right++;
        }
        
        if(maxPalindromicLength < curPalindromicLength){
            maxPalindromicLength = curPalindromicLength;
            startIndex = left + 1;
        }
        
    }
    
    
    string longestPalindrome(string str) {
        
        int maxPalindromicLength = 1;
        int N = str.length();
        int startIndex = 0;
        
        for(int i = 0 ; i < N ; i++){
            findExpansionPalindromic(str, i, i, N, maxPalindromicLength, startIndex);
        }
        
        for(int i = 1 ; i < N ; i++){
            findExpansionPalindromic(str, i - 1, i , N, maxPalindromicLength, startIndex);
        }
        
        return str.substr(startIndex, maxPalindromicLength);
        
    }
};