// PROBLEM :- https://leetcode.com/problems/add-two-numbers/

// LEETCODE | MEDIUM | LINKED LIST

// Solution :- T.C and S.C. :- O(max(M, N)) -> where M and N are length of both lists respectively.

// Approach :- Elementary addition technique simulated through a linked list traversals. 
//             Fetch corresponding position, get the value, add it, add carry if available, and then set the value to the respective position in the list. 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int add = l1->val + l2->val + carry;
            carry = add / 10;
            add = add - (carry * 10);
            cur->next = new ListNode(add);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        while(l1 != NULL){
            int add = l1->val + carry;
            carry = add / 10;
            add = add - (carry * 10);
            cur->next = new ListNode(add);
            cur = cur->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            int add = l2->val + carry;
            carry = add / 10;
            add = add - (carry * 10);
            cur->next = new ListNode(add);
            cur = cur->next;
            l2 = l2->next;
        }
        
        if(carry > 0){
            cur->next = new ListNode(carry);
            cur = cur->next;
        }
        
        return dummyHead->next;
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