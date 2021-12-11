// SOLUTION :- https://leetcode.com/problems/integer-to-roman/

// LEETCODE | MEDIUM | STRING MANIPULATION

// Solution :- both T.C. and S.C. O(log(Range))

// Logic :- Roman Numeral is evaluated from big value to small value. Some exception are 4, 9, 40, 90, 400, 900.
//             All these exceptions are also included in the roman map, mapping their values too.
//             Together inside the map, now find the greatest integer which is less than or equal to current number.
//             Use the corresponding key from the map, and then subtract current num with the fetched value.
//             Repeat this process until NUM = 0.


class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman;
        roman[1] = "I";
        roman[4] = "IV";
        roman[5] = 'V';
        roman[9] = "IX";
        roman[10] = 'X';
        roman[40] = "XL";
        roman[50] = 'L';
        roman[90] = "XC";
        roman[100] = 'C';
        roman[400] = "CD";
        roman[500] = 'D';
        roman[900] = "CM";
        roman[1000] = 'M';
        
        string ans = "";
        
        while(num != 0){
            map<int, string>::iterator itr = roman.upper_bound(num);
            --itr;
            int value = itr->first;
            string curRoman = itr->second;
            num -= value;
            ans += curRoman;
        }
        
        return ans;
        
    }
};