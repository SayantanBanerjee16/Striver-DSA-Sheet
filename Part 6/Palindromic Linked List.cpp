// PROBLEM :- https://leetcode.com/problems/palindrome-linked-list/

// LEETCODE | EASY | LINKED LIST

// Solution 1 :- T.C. O(N) S.C. O(N)
// Take all the node values into a vector and check if the resultant vector is palindrome or not.

// Solution 2 :- T.C. O(N) S.C. O(1)
// Approach :- 
// 1. Find Middle of the Linked List.
// 2. Reverse the latter half of the Linked List.
// 3. Compare corresponding nodes in the two halves of the lists.

class Solution {
public:
    // reverse a linked list code
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* n;
        
        while(cur!=NULL){
            
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
            
        }
        
        return prev;
    }
    
    // actual function which gets called to check if a list is palindrome or not
    bool isPalindrome(ListNode* head) {
        
        // find middle of the linked list
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reverse the latter half of the list
        ListNode* revHead = reverseList(slow);
        
        // traverse in each half to check is it palindrome or not
        ListNode* firstHalf = head;
        ListNode* secondHalf = revHead;
        
        while(secondHalf != NULL){
            if(firstHalf->val != secondHalf->val){
                return false; // not palindrome;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true; // palindrome
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