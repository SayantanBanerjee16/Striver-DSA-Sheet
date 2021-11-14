// PROBLEM :- https://leetcode.com/problems/merge-two-sorted-lists/

// LEETCODE | EASY | LINKED LIST

// Solution 1 :- T.C O(N) S.C O(1) -> RECURSIVE (Advantage -> more easy to write. Disadvantage -> takes recursive stack calling space)

// Lets say you have two nodes from both list. Compare both and choose the shorter one.
// The rest of both sorted lists are merged in similar manner, and point it to the choosen node in this call.
// Return from the function with the chosen node.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* n1, ListNode* n2) {
        if(n1 == NULL && n2 == NULL){
            return NULL;
        }else if(n1 == NULL){
            return n2;
        }else if(n2 == NULL){
            return n1;
        }else{
            if(n1->val < n2->val){
                n1->next = mergeTwoLists(n1->next, n2);
                return n1;
            }else{
                n2->next = mergeTwoLists(n1, n2->next);
                return n2;
            }
        }
    }
};

// Solution 2 :- T.C O(N) S.C O(1) -> ITERATIVE

// Maintain 2 pointers. L1 and L2. L1 always point to lesser value, L2 always points to greater value.
// What if L1 points to greater value ? Swap L1 and L2.

// Now idea is to traverse L1 until it founds a node with a higher value of L2.
// Mantain a PREV pointer behind L1.
// Thus when L1 founds a node greater value than L2, PREV points to L2.

// Now repeat this process until both lists exhaust.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        if(l1->val > l2->val){
            swap(l1, l2);
        }
        
        ListNode* startNode = l1;
        
        while(l1 != NULL && l2 != NULL){
            
            ListNode *temp = l1;
            
            while(l1 != NULL && l1->val <= l2 -> val){
                temp = l1;
                l1 = l1->next;
            }
            
            temp->next = l2;
            
            swap(l1, l2);
            
        }
        
        return startNode;
        
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