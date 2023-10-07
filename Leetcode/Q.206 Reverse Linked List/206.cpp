/*//
//  This is a simple way to reverse a list node by node with 3 pointers.
//  We need a pointer which indicates current node, and 2 pointers for its previous node and next node.
//  Then we let the next node of current node be the previous node, and make current node the initial next node of current node, and previous node becomes current node.
//  Do this loop until the end of the list.
//*/


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != NULL)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};