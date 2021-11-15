// PROBLEM :- https://leetcode.com/problems/linked-list-cycle/

// LEETCODE | EASY | LINKED LIST

// Solution 1 :- T.C :- O(N) S.C :- O(N)

// Use a SET to store the NODES, and insert the nodes while traversing the list. If there is a cycle, you will find some node X already in the list previously. This node X is the Cyclic Intersection node. 
// Return TRUE if you detect a cycle. Else if you reach the end of list, return FALSE.

// Solution 2 :- T.C. :- O(N) S.C :- O(1)

// Classic Tortoise Hare Problem. 
// Initialize both of the pointers at HEAD node. 
// And move SLOW pointer 1 step at a time while FAST pointer 2 step at a time.
// If there is a cycle, both pointers are bound to meet at a point.
// If FAST pointer reaches the end of the list, then there is NO CYCLE present.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == NULL)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */