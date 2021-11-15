// PROBLEM :- https://leetcode.com/problems/intersection-of-two-linked-lists/

// LEETCODE | EASY | LINKED-LIST

// Solution 1 :- T.C. O(N + M) S.C. O(1)

// Count the number of nodes of two lists. 
// Skip the additional greater nodes from the larger list, so that equal number of nodes remain in both lists.
// Then traverse both lists together.
// If there is a match, return that NODE.
// In the end of list, if there is no match, return NULL.


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int list1count = 0;
        ListNode* tempA = headA;
        while(tempA != NULL){
            list1count++;
            tempA = tempA->next;
        }
        
        int list2count = 0;
        ListNode* tempB = headB;
        while(tempB != NULL){
            list2count++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        
        if(list2count > list1count){
            int diff = list2count - list1count;
            while(diff--){
                tempB = tempB->next;
            }
        }else if(list2count < list1count){
            int diff = list1count - list2count;
            while(diff--){
                tempA = tempA->next;
            }
        }
        
        while(tempA != NULL){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};

// Solution 2 :- T.C. O(N + M) S.C. O(1) (ALTERNATIVE APPROCH)

// Take two pointers D1 and D2 initially at head of ListA and ListB respectively.
// Start traversing in both linked list. Increement both pointers by 1 step at each step.
// Whenever D1 reaches end of ListA, make it point to ListB head.
// Similarly when D2 reaches at the end of ListB, make it point to ListA head.

// After at max 2 times whole traversal of both lists, both pointers will reach at an common intersection point. Or they simultaneously will reach at NULL, referring no intersection.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* D1 = headA;
        ListNode* D2 = headB;
        
        while(D1 != D2){
            if(D1 == NULL){
                D1 = headB;
            }else{
                D1 = D1->next;
            }
            
            if(D2 == NULL){
                D2 = headA;
            }else{
                D2 = D2->next;
            }
        }
        
        return D1;
       
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