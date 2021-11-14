// PROBLEM :- https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// LEETCODE | MEDIUM | LINKED LIST

// Solution 1 :- T.C. - O(N) 2 pass S.C. O(1)
// Count total number (TOT) of nodes, and delete while traversal on the next turn from (TOT - n) position

// Solution 2 :- T.C. - O(N) 1 pass S.C. O(1)
// Mantain 2 pointers, SLOW and FAST. 
// Make FAST pointer initially move n position.
// Then SLOW and FAST pointers go hand in hand, until FAST pointer meets the last position.
// Then delete the asserted node by making SLOW point to its next of next location.

// Edge case :- What if n == length of the list? Here we need to remove the first element of the list. 
// Take care of it separately.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(n--){
            fast = fast->next;
        }
        
        if(fast == NULL){ // edge case
            return slow->next;
        }
        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */