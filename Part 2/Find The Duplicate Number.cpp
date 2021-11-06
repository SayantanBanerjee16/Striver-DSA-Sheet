// PROBLEM :-
// https://leetcode.com/problems/find-the-duplicate-number/

// LEETCODE | MEDIUM | ARRAY MAPPING / TORTOISE HARE VARIATION

// Solution 1 :- T.C O(NlogN) , S.C O(1) -> Sort the array and compare consecutive elements.

// Solution 2 :- T.C O(N), S.C O(N) -> Use hashmap / another vector to store the count of elements.

// Solution 3 :- T.C O(N), S.C O(1)
// We know that array elements are from 1 to N only. And there are N + 1 elements in total.
// What if we can arrange 1,2,3...,N to their respective index 1,2,3,...,N etc.
// Then Index 0 would contain the duplicate one.

// Algo to do this,
// Take nums[0] and nums[nums[0]].
// if equal, this is the duplicate one.
// Else, swap them and repeat the whole process again until found.

// Why this works?
// LETS nums[0] = 2 and nums[nums[0]] = nums[2] = 3,
// So zeroth index contains 2 and second index contains 3. After swapping index 2 contains 2.
// Likewise, we will be repeating the process, providing each index with its equivalent number.
// LETS nums[0] = 4 and nums[nums[0]] = nums[4] = 4,
// So both location having same number, we are certain that this is the duplicate element.


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(true){
            if(nums[0] == nums[nums[0]]){
                return nums[0];
            }else{
                swap(nums[0], nums[nums[0]]);
            }
        }
        return -1; // never reached
    }
};


// Solution 4 :- T.C O(N), S.C O(1)
// 2 slow-fast pointers -> tortoise Hare Variation
// Algo similar to finding the intersection point in a Linked List Cycle

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tortoise = nums[0];
        int hare = nums[0];
        
        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(tortoise != hare);
        
        tortoise = nums[0];
        
        while(tortoise != hare){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};