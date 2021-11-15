
// PROBLEM :- https://leetcode.com/problems/linked-list-cycle-ii/

// LEETCODE | MEDIUM | LINKED LIST

// Solution 1 :- T.C :- O(N) S.C :- O(N)

// Use a SET to store the NODES, and insert the nodes while traversing the list. If there is a cycle, you will find some node X already in the list previously. This node X is the Cyclic Intersection node.


// Solution 2 :- T.C. :- O(N) S.C :- O(1)

// Classic Tortoise Hare Problem. 

// Initialize both of the pointers at HEAD node. 
// And move SLOW pointer 1 step at a time while FAST pointer 2 step at a time.
// If there is a cycle, both pointers are bound to meet at a point.
// If FAST pointer reaches the end of the list, then there is NO CYCLE present.

// But how to find Cyclic Intersection node after finding a common node when SLOW and FAST pointers meet!
// For that take one pointer from that point and another pointer from HEAD of list.
// Skip both pointers 1 step at a time.
// Where they meet, is the Cyclic Intersection node.
// DRAW A LINKED LIST CYCLE AND OBSERVE THIS PATTERN DIAGRAMMATICALLY.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        bool isCycleFound = false;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow){
                isCycleFound = true;
                break;
            }
        }
        
        if(!isCycleFound){
            return NULL;
        }
        
        ListNode* start = head;
        ListNode* end = slow;
        
        while(start != end){
            start = start->next;
            end = end->next;
        }
        
        return start;
        
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