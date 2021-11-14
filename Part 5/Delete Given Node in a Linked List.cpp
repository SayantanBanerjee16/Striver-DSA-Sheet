// PROBLEM :- https://leetcode.com/problems/delete-node-in-a-linked-list/

// LEETCODE | EASY | LINKED-LIST

// T.C O(1) S.C O(1)
// Weird Problem

// A -> B -> C -> D -> E -> F -> NULL
// We want to delete C and we have access to C only. Not HEAD (A).

// Solution :- Copy Value of D in C. And point C->E (C->next = C->next->next).

// Edge Case :- This solution won't work if it is the tail node to be asked for deletion. And the question also specefies that the tail node won't be asked to delete.


class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
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