// PROBLEM :- https://leetcode.com/problems/roman-to-integer/

// LEETCODE | EASY | STRING MANIPULATION

// Solution :- 

// Traverse the string from left to right.

// Whenever we get a roman numeral, add it to answer value.
// But what if we get a certain roman numeral which is greater than the previous roman numeral?
// That means previous roman numeral should actually be subtracted from current roman numeral.
// So subtract that 2 times. (2 because we already added it previously)


class Solution {
public:
    int romanToInt(string str) {
        
        map<char, int> romanValue;
        romanValue['I'] = 1;
        romanValue['V'] = 5;
        romanValue['X'] = 10;
        romanValue['L'] = 50;
        romanValue['C'] = 100;
        romanValue['D'] = 500;
        romanValue['M'] = 1000;
        
        int ans = 0;
        int last = INT_MAX;
        
        for(int i = 0 ; i < str.length() ; i++){
            int curRoman = romanValue[str[i]];
            if(curRoman > last){
                ans -= 2 * last;
            }
            ans += curRoman;
            last = curRoman;
        }
        
        return ans;
        
    }
};