// PROBLEM :- https://leetcode.com/problems/power-of-two/

// LEETCODE | EASY | BITS

// Solution 1 :- T.C. O(logN) S.C. O(1)

// Any power of 2 number have 1 bit as '1', rest all '0'.
// So check for the count of number of bits with '1'.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0)
            return false;
        
        int noOfOneBits = 0;
        while(n != 0){
            if(n & 1){
                noOfOneBits++;
            }
            n = n >> 1;
        }
        
        if(noOfOneBits == 1){
            return true;
        }else{
            return false;
        }
    }
};

// Solution 2:- T.C. O(1)S.C. O(1)

// Any power of 2 (X) has format '100000...0000'
// X - 1 has format '11111...1111' (1 bit less than no of bits in X -> all set to '1')
// We can see X & X - 1 = 0 when X is a power of 2.

// Proof :- for any general number X which is not power of 2, MSB of (X - 1) would be same to MSB of X.
//          So X & X - 1 != 0 at that case.
//          Now if X is power of 2, MSB of (X - 1) will be '0'. Thus AND of both numbers gives 0.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0)
            return false;
        
        if((n & (n - 1)) == 0){
            return true;
        }else{
            return false;
        }
    }
};