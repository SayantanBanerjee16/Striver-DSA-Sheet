// PROBLEM :- https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// LEETCODE | EASY | LINKED-LIST

// T.C. O(N) S.C O(1)

// Approach :- First create a dummy node as starting node. It points to the head of the ist.
// Traverse the list, with two pointers. PREV and TRAV. 
// PREV points to the previous node. It is responsible for forming the updated chain.
// TRAV is used to traverse the whole Linked List.

// If TRAV node value is same of last node value, PREV -> next = TRAV -> next. 
// Else , update PREV pointer location to current location by PREV = TRAV.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* trav = head;
        
        int lastValue = INT_MIN;
        
        while(trav != NULL){
            if(trav->val == lastValue){
                prev->next = trav->next;
            }else{
                prev = trav;
                lastValue = trav->val;
            }
            trav = trav->next;
        }
        
        return dummy->next;
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