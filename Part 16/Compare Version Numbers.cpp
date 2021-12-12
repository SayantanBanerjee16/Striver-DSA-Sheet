// PROBLEM :- https://leetcode.com/problems/compare-version-numbers/

// LEETCODE | MEDIUM | STRINGS

// Solution :- T.C. O(N + M) S.C. O(N + M)

// Extract corresponding parts, convert each to integers, and check which side is bigger.
// If no side is bigger, repeat for all other parts.
// Note :- If a string ends, all corresponding parts for other parts is equal to 0.

// Side Note :- Beware of implementation based edge cases.


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int itr1 = 0;
        int itr2 = 0;
        
        int n = version1.length();
        int m = version2.length();
        
        while(itr1 < n && itr2 < m){
            
            string cur1 = "0";
            while(itr1 < n && version1[itr1] != '.'){
                cur1 += version1[itr1];
                itr1++;
            }
            
            string cur2 = "0";
            while(itr2 < m && version2[itr2] != '.'){
                cur2 += version2[itr2];
                itr2++;
            }
            
            if(itr1 < n && version1[itr1] == '.')
                itr1++;
            
            if(itr2 < m && version2[itr2] == '.')
                itr2++;
            
            int rev1 = stoi(cur1);
            int rev2 = stoi(cur2);
            
            if(rev1 > rev2){
                return 1;
            }else if(rev1 < rev2){
                return -1;
            }
        }
    
        
        if(itr1 == n && itr2 == m)
            return 0;
        else if(itr1 == n){

            while(itr2 < m){
                string cur2 = "0";
                while(itr2 < m && version2[itr2] != '.'){
                    cur2 += version2[itr2];
                    itr2++;
                }
                if(itr2 < m && version2[itr2] == '.')
                    itr2++;
                int rev2 = stoi(cur2);
                if(rev2 > 0){
                    return -1;
                }
            }
            
            return 0;
            
        }else{

            while(itr1 < n){
                string cur1 = "0";
                while(itr1 < n && version1[itr1] != '.'){
                    cur1 += version1[itr1];
                    itr1++;
                }
                if(itr1 < n && version1[itr1] == '.')
                    itr1++;
                
                int rev1 = stoi(cur1);
                if(rev1 > 0){
                    return 1;
                }
            }
            
            return 0;
            
        }
    }
};