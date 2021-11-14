// PROBLEM :- https://leetcode.com/problems/reverse-linked-list/

// LEETCODE | EASY | LINKED LIST

// Solution 1 :- T.C O(N) S.C O(1) -> RECURSIVE (Advantage -> more easy to write. Disadvantage -> takes recursive stack calling space)

// A->B->C->D->E->NULL.
// Now currently at B.
// Let's say we have reversed C to E RECURSIVELY.
// We have E->D->C->NULL.
// We now have C and B pointer.
// Simply make B->next = NULL and C->next = B.
// We made E->D->C->B->NULL.
// Return B pointer (as previous call from A needs B pointer to attach A next to B).

// Note :- Store the updated reverse head in another pointer, which will point to start of the reversed list.

class Solution {
public:
    
    ListNode* reverseHead;
    
    ListNode* recurse(ListNode* node) {
        
        if(node->next == NULL){
            reverseHead = node;
            return node;
        }

        ListNode* reverse = recurse(node->next);
        node->next = NULL;
        reverse->next = node;
        return node;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        recurse(head);
        return reverseHead;
    }
};

// Solution 2 :- T.C O(N) S.C O(1) -> ITERATIVE

// The idea is very simple, we maintain 3 pointers, current, next and previous, abbreviated as cur, n and prev respectively. All the events occur in a chain.

// Preassign: assign prev=NULL, cur=head .

// Below are the steps:
// First we initialize n to be the node after cur. i.e (n=cur->next).
// Then we make cur->next point to prev (next node pointer).
// Then we make prev now point to (one node ahead) the cur node.
// At last we move cur also one node ahead to n.
// Follow the same steps untill the head points to NULL i.e there is no node to reverse. The prev pointer will be the last non null node and hence the answer

// Credit :- https://leetcode.com/problems/reverse-linked-list/discuss/1449712/Easy-C%2B%2BJavaPythonJavaScript-Explained%2BAnimated

class Solution {
public:
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