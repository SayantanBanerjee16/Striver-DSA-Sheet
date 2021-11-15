// PROBLEM :- https://leetcode.com/problems/rotate-list/

// LEETCODE | MEDIUM | LINKED LIST

// Solution :- T.C. O(N) S.C O(1)

// First count (CNT) the number of nodes.
// Now we know every CNT times, the list retains to the initial position. So K = K % CNT.
// If K = 0, awesome, no rotation, return head as it is.

// Now lets suppose K = 2 in the list 1->2->3->4->5->NULL.
// Last 2 nodes comes in front of list.
// So device a strategy to split the list at K nodes from back (1->2->3->NULL and 4->5->NULL)
// Now attach 5 (last node) next to 1 (initial head).
// And return 4 (new head).
// Where to split ? After CNT - K - 1 iterations from start HEAD.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int cnt = 0;
        ListNode* trav = head;
        ListNode* lastNode = head;
        
        while(trav != NULL){
            cnt++;
            lastNode = trav;
            trav = trav->next;
        }
        
        k %= cnt;
        
        if(k == 0){
            return head;
        }
        
        int skip = cnt - k - 1;
        
        trav = head;
        
        while(skip--){
            trav = trav->next;
        }
        
        ListNode *newHead = trav->next;
        trav->next = NULL;
        
        lastNode->next = head;
        
        return newHead;
        
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