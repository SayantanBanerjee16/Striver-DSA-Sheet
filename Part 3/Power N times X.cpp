// PROBLEM :-
// https://leetcode.com/problems/powx-n/

// LEETCODE | MEDIUM | BINARY EXPONENTIATION

// Solution -> T.C O(log N) S.C O(1)
//      Do binary exponentiation to reduce time complexity from brute (which is linear multiplication)


class Solution {
public:
    
    double pwr(double x, long long n) {
        if (!n) return 1;
        if (n & 1) return (x * pwr(x * x, (n - 1) / 2));
        else return pwr(x * x, n / 2);
    }
    
    double myPow(double x, int n) {
        long long n2 = n;
        
        double ans = pwr(x, abs(n2));
        
        if(n < 0){
            ans = 1 / ans;
        }
        
        return ans;
    }
};