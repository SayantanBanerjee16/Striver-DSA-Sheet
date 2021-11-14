// PROBLEM :- https://leetcode.com/problems/middle-of-the-linked-list/

// LEETCODE | EASY | LINKED LIST

// Solution :- T.C O(N) S.C. O(1)

// Mantain 2 pointers. SLOW (skip 1 step at a time) and FAST (skip 2 step at a time)
// Middle node is the node SLOW is pointing when FAST is at the last node or at the end NULL position

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
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